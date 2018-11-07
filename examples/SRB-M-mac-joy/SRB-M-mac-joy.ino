
#define __ARDUINO__
#include <lee.h>
#include <Led.h>
#include <PS2X_lib.h>  //for v1.6


#include <SRB-M-tinynode.h>

#define __MASTER__
#define __MAPPING_DECLEAR__
#include <readonly/SRB-app-cluster-test-share.h>
#include <readonly/SRB-app-dmotor-share.h>


//------------ PS2 遥控器有关的初始化 -------------------------
/******************************************************************
 * set pins connected to PS2 controller:
 *   - 1e column: original 4r*
 *   - 2e colmun: Stef?
 * replace pin numbers by the ones you use
 ******************************************************************/
#define PS2_DAT        18  //14
#define PS2_CMD        19  //15
#define PS2_SEL        20  //16
#define PS2_CLK        21  //17
/******************************************************************
 * select modes of PS2 controller:
 *   - pressures = analog reading of push-butttons
 *   - rumble    = motor rumbling
 * uncomment 1 of the lines for each mode selection
 ******************************************************************/
#define pressures   true
//#define pressures   false
//#define rumble      true
#define rumble      false
PS2X ps2x; // create PS2 Controller Class
byte vibrate = 0;
//right now, the library does NOT support hot pluggable controllers, meaning
//you must always either restart your Arduino after you connect the controller,
//or call config_gamepad(pins) again after connecting the controller.
void ps2JoyInit()
{
  //PS2 Joy init
    while(ps2x.config_gamepad(PS2_CLK, PS2_CMD, PS2_SEL, PS2_DAT, pressures, rumble) != 0)
    {
      delay(500);
      green.tog();
    }
}



//---------------- SRB 节点的初始化 ---------------------------------
SrbTinyNode node_motor; //定义一个节点
Du_Motor::sDataRs motor_data; //定义一个双电机模块的数据空间
void nodeInit(){
    //节点初始化设置
    node_motor.address = 4;//设置节点地址
    node_motor.datas = (uint8*)(&motor_data);//设置节点数据空间
    node_motor.mapping[0] = (sStaticMapping*)(Du_Motor::mapping0);//设置节点访问映射表
    node_motor.mapping[1] = (sStaticMapping*)(Du_Motor::mapping1);//设置节点访问映射表
    //初始化完毕
}

//--------- system -----------------------------
void setup() {
    SrbTinyNode::SRBinit();
    nodeInit();
    ps2JoyInit();
}

void loop() {
    ps2x.read_gamepad(false, vibrate);//采集手柄数据
    //这两个手柄数据对应手柄的左侧二维摇杆
    int x = ps2x.Analog(PSS_LX);//读取手柄X轴数据
    int y = ps2x.Analog(PSS_LY);//读取手柄Y轴数据
//读取到的数据是0到255,松开手柄读到的是128.
    x-=128;
    y-=128;//电机为左右差速,设置电机速度到节点数据
    //ma表示 motorA,mb表示motorB
    motor_data.ma.u16 = joy2Motor((y-x));
    //前面的负号是因为两个车轮的机械结构对称,车前运行时,电机一个正转一个反转
    motor_data.mb.u16 = joy2Motor(-(y+x));
    node_motor.access(1);//将刚刚写好的数据发往电机.
    delay(20);
}
//根据读取到的电机速度, 转换为发往电机的数值
uint16 joy2Motor(int val){
  Du_Motor::sMotor m;
  if(val<0)  {  //首先确定方向,并且将速度都变成正数
    val = -val;
    m.dir = MOTOR_DIR_REVERSE;
  }
  else  {
    m.dir = MOTOR_DIR_FOWARD;
  }
  if(val >200)  {//速度的最大值能达到255,将最大值设为200
    val = 200;
  }
  if(val <2)  {//手柄的读数有时会有误差,因此将小于2都设置为0
    m.speed = 0;
  }
  else  {//其他情况的设置, 电机在PWM大于120的情况下才能转起来。
    m.speed = 120 + val*2 ;
  }
  return m.u16;
}
