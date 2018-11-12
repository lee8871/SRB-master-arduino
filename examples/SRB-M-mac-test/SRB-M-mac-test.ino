
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
    SrbTinyNode::SRBinit();
    nodeInit();
}

void loop() {
    motor_data.ma.u16 = 140;
    //前面的负号是因为两个车轮的机械结构对称,车前运行时,电机一个正转一个反转
    motor_data.mb.u16 = 150;
    node_motor.access(1);//将刚刚写好的数据发往电机.
    delay(20);
}
