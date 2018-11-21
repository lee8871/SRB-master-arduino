//---------------- SRB 节点的初始化 ---------------------------------
#define __ARDUINO__
#include <lee.h>
#include <Led.h>
#include <PS2X_lib.h>  //for v1.6
#include <SRB-M-tinynode.h>

#define __MASTER__
#define __MAPPING_DECLEAR__
#include <readonly/SRB-app-cluster-test-share.h>
#include <readonly/SRB-app-dmotor-share.h>



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
    SrbTinyNode::SRBinit();//这个函数初始化SRB总线,不论有多少个节点都只需要初始化一次.
    nodeInit();
}
int phase = 0;
void loop() {
    phase++;
    if(phase <100){
      //机器人低速前进.
      //注意因为轮式机器人往往有镜像的结构,机器人像一个方向运行时,一个电机正转则另一个反转.
      motor_data.ma.speed = 110;
      motor_data.ma.dir = MOTOR_DIR_FOWARD;
      motor_data.mb.speed = 110;
      motor_data.mb.dir = MOTOR_DIR_REVERSE;
    }
    else   if(phase <200)   {
      //机器人高速前进.
        motor_data.ma.speed = 200;
        motor_data.ma.dir = MOTOR_DIR_FOWARD;
        motor_data.mb.speed = 200;
        motor_data.mb.dir = MOTOR_DIR_REVERSE;
    }
    else   if(phase <300)    {
      //机器人滑行.
        motor_data.ma.speed = 0;
        motor_data.ma.dir = MOTOR_DIR_FREE;
        motor_data.mb.speed = 0;
        motor_data.mb.dir = MOTOR_DIR_FREE;
    }

    
    
    else   if(phase <400)    {
      //机器人低速后退.  
      motor_data.ma.speed = 110;
      motor_data.ma.dir = MOTOR_DIR_REVERSE;
      motor_data.mb.speed = 110;
      motor_data.mb.dir = MOTOR_DIR_FOWARD;
    }   
    else   if(phase <500)    {
      //机器人高速后退.  
      motor_data.ma.speed = 200;
      motor_data.ma.dir = MOTOR_DIR_REVERSE;
      motor_data.mb.speed = 200;
      motor_data.mb.dir = MOTOR_DIR_FOWARD;
    }
    else   if(phase <600)    {
      //机器人刹车.相对于滑行,刹车状态会让机器人立即停车
        motor_data.ma.speed = 1000;
        motor_data.ma.dir = MOTOR_DIR_BRAKE;
        motor_data.mb.speed = 1000;
        motor_data.mb.dir = MOTOR_DIR_BRAKE;
    }    
    

    
    else   if(phase <700)    {
      //机器人旋转
      //轮式机器人通常通过左右车轮差速实现转动.
      motor_data.ma.speed = 110;
      motor_data.ma.dir = MOTOR_DIR_FOWARD;
      motor_data.mb.speed = 110;
      motor_data.mb.dir = MOTOR_DIR_FOWARD;
    }   
    else   if(phase <800)    {
      //机器人滑行.
        motor_data.ma.speed = 0;
        motor_data.ma.dir = MOTOR_DIR_FREE;
        motor_data.mb.speed = 0;
        motor_data.mb.dir = MOTOR_DIR_FREE;
    }
    else   if(phase <1000)    {
      //机器人转弯
      motor_data.ma.speed = 110;
      motor_data.ma.dir = MOTOR_DIR_FOWARD;
      motor_data.mb.speed = 220;
      motor_data.mb.dir = MOTOR_DIR_REVERSE;
    }
    else   if(phase <1100)    {
      //机器人滑行.
        motor_data.ma.speed = 0;
        motor_data.ma.dir = MOTOR_DIR_FREE;
        motor_data.mb.speed = 0;
        motor_data.mb.dir = MOTOR_DIR_FREE;
    }
    else    {
      phase = 0;
    }
    
    node_motor.access(1);//将刚刚写好的数据发往电机.
    delay(10);
}

