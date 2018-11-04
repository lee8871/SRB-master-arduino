
#define __ARDUINO__
#include <lee.h>
#include <Led.h>

#include <SRB-M-tinynode.h>

#define __MASTER__
#define __STATIC_MAPPING_DECLEAR_ARDUINO__
#include <readonly/SRB-app-cluster-test-share.h>
#include <readonly/SRB-app-dmotor-share.h>

// the setup routine runs once when you press reset:
SrbTinyNode node6;
test001::sDataRs node6_datas;

SrbTinyNode node_motor;
dMotor::sDataRs motor_data;

void node6Init()
{
    node6.address = 0x09;
    node6.datas = (uint8*)(&node6_datas);
    node6.mapping[0] = (sStaticMapping*)(test001::mapping0);
    node6.mapping[1] = (sStaticMapping*)(test001::mapping1);

    node_motor.address = 0x03;
    node_motor.datas = (uint8*)(&motor_data);
    node_motor.mapping[0] = (sStaticMapping*)(dMotor::mapping0);
    node_motor.mapping[1] = (sStaticMapping*)(dMotor::mapping1);
}
int r = 11;   
int g = 10;   
int b = 9;   



uint8 colorpPhase1024(uint16 phase);

uint16 getSpeed1024(int value);

void setup() {
    SrbTinyNode::SRBinit();
    node6Init();
    pinMode(r, OUTPUT);
    pinMode(g, OUTPUT);
    pinMode(b, OUTPUT);
    pinMode(A0, INPUT_PULLUP);
}

// the loop routine runs over and over again forever:
uint16 c_num = 50;
uint16 temp;
int x;
int y;
int z;

void loop() {
    c_num++;
    c_num%=1024;
    
    x = analogRead(A1);
    y = analogRead(A2);
    z = analogRead(A3);
    /***********************
    node6_datas.color_in.r = x/4;
    node6_datas.color_in.g = y/4;
    node6_datas.color_in.b = z/4;  
    //******************************/
    if(digitalRead(A0) == LOW)
    {
    motor_data.ma.u16 = getSpeed1024(x);
    motor_data.mb.u16 = getSpeed1024(y);
    }
    c_num = z;
    node6_datas.color_in.r = colorpPhase1024((c_num)%1024);
    node6_datas.color_in.g = colorpPhase1024((c_num + (1024/3))%1024);
    node6_datas.color_in.b = colorpPhase1024((c_num + (1024/3)*2)%1024);  
       
    analogWrite(r, node6_datas.color_out.r);
    analogWrite(g, node6_datas.color_out.g);
    analogWrite(b, node6_datas.color_out.b);
      
    node6.access(0);
    node_motor.access(1);
    //************************************************************************/  
    delay(2);
}
uint16 getSpeed1024(int value)
{
    dMotor::sMotor m;
    if(value>512+100)
    {
      m.speed = value-512;
      m.dir = 0;
    }
    else if(value<512-100)
    {      
        m.speed = 512 - value;
        m.dir = 3;
    }
    else
    {
      m.speed = 0;
      m.dir = 1;
    }
    
      m.speed *= 2;
    return m.u16;
}


uint8 colorpPhase1024(uint16 phase)
{
    phase = phase%1024;
    if(phase >= 256*3){
      return(phase - 256*3);
    }
    else if(phase <= 255){
      return 255 - phase;
    }
    else{
      return 0;
    }  
}

