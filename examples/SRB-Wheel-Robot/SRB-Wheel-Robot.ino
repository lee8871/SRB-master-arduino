//---------------- SRB 节点的初始化 ---------------------------------
#include <lee.h>
#include <Led.h>
#include <SRB-M-tinynode.h>



#define __MASTER__
#define __MAPPING_DECLEAR__
#include <readonly/SRB-app-dumotor-share.h>



//---------------- SRB 节点的初始化 ---------------------------------
SrbTinyNode node_motor; //定义一个节点
Du_Motor::sDataRs motor_data; //定义一个双电机模块的数据空间
void nodeInit(){
    //节点初始化设置
    node_motor.address = 4;//设置节点地址
    node_motor.datas = (uint8*)(&motor_data);//设置节点数据空间
    node_motor.mapping[1] = (sMapping*)(Du_Motor::mapping1);//设置节点访问映射表
    //初始化完毕
}

//--------- system -----------------------------
void setup() {
    SrbTinyNode::SRBinit();//这个函数初始化SRB总线,不论有多少个节点都只需要初始化一次.
    nodeInit();
}
int phase = 0;
#define sub_period 3000//ms
void loop() {
    phase++;
    if(phase <1*(sub_period/10)){
      //机器人低速前进.
      //注意因为轮式机器人往往有镜像的结构,机器人像一个方向运行时,一个电机正转则另一个反转.
      motor_data.ma.speed = 100;
      motor_data.ma.brake = 0;
      motor_data.mb.speed = 100;
      motor_data.mb.brake = 0;
    }
    else   if(phase <2*sub_period/10)   {
      //机器人高速前进.
        motor_data.ma.speed = 150;
      motor_data.ma.brake = 0;
        motor_data.mb.speed = 150;
      motor_data.mb.brake = 0;
    }
    else   if(phase <3*sub_period/10)    {
      //机器人滑行.
        motor_data.ma.speed = 0;
      motor_data.ma.brake = 0;
        motor_data.mb.speed = 0;
      motor_data.mb.brake = 0;
    }



    else   if(phase <4*sub_period/10)    {
      //机器人低速后退.
      motor_data.ma.speed = -100;
      motor_data.ma.brake = 0;
      motor_data.mb.speed = -100;
      motor_data.mb.brake = 0;
    }
    else   if(phase <5*sub_period/10)    {
      //机器人高速后退.
      motor_data.ma.speed = -150;
      motor_data.ma.brake = 0;
      motor_data.mb.speed = -150;
      motor_data.mb.brake = 0;
    }
    else   if(phase <6*(sub_period/10))    {
      //机器人刹车.相对于滑行,刹车状态会让机器人立即停车
        motor_data.ma.speed = 1000;
      motor_data.ma.brake = 1;
        motor_data.mb.speed = 1000;
      motor_data.mb.brake = 1;
    }



    else   if(phase <7*(sub_period/10))    {
      //机器人旋转
      //轮式机器人通常通过左右车轮差速实现转动.
      motor_data.ma.speed = 100;
      motor_data.ma.brake = 0;
      motor_data.mb.speed = -100;
      motor_data.mb.brake = 0;
    }
    else   if(phase <8*(sub_period/10))    {
      //机器人滑行.
        motor_data.ma.speed = 0;
      motor_data.ma.brake = 0;
        motor_data.mb.speed = 0;
      motor_data.mb.brake = 0;
    }
    else   if(phase <9*(sub_period/10))    {
      //机器人转弯
      motor_data.ma.speed = 100;
      motor_data.ma.brake = 0;
      motor_data.mb.speed = 150;
      motor_data.mb.brake = 0;
    }
    else   if(phase <10*(sub_period/10))    {
      //机器人滑行.
        motor_data.ma.speed = 0;
      motor_data.ma.brake = 0;
        motor_data.mb.speed = 0;
      motor_data.mb.brake = 0;
    }
    else    {
      phase = 0;
    }

    node_motor.access(1);//将刚刚写好的数据发往电机.
    delay(10);
}
