
#include "package.h"  //LN33的数据包格式
#include "lee.h" //自定义数据
#include "DL_LN3X.h"//LN33模块的头文件
#include "uart.h"//自定义串口数据处理的头文件

//函数声明
void recievePkg(sPkg* pkg);//包接收函数
void loopReceive();//每10ms循环持续接收包

//用来读取数据的一个包数据
/*newPkg(3) redPkg={
  .length = 7,//包长度
  .src_port = 0x90,//源目的端口
  .dis_port = 0x32,//目的端口
  .remote_addr = 0x0000,//发送数据的目的地址 0000为本地地址
  .data = {0,10,20}//三个数据内容分别是0,10,20
};*/
//用来存放湿度传感数据的包数据
newPkg(1) THPkg={
  .length = 5,
  .src_port = 0x90,
  .dis_port = 0x32,
  .remote_addr = 0x4d57,//地址为0x4d57的节点
  .data = {0}
};

void setup() {
  // put your setup code here, to run once:

  uartInit();//串口初始化
  sei();//开始串口中断
}

void loop() {
  // put your main code here, to run repeatedly:
      for(int i = 0;i<400;i++)//4s的时间持续接收数据
    {     
      _delay_ms(10);//延时10ms
      loopReceive();//循环接收数据
    }
    //readTh();//读取湿度传感器的数值
    THPkg.dis_port = 0xa0;//发送给0xa0端口
   // THPkg.data[0] = (uint8)Temperature;//将湿度传感器读取的温度数据放入要发送的包中
   THPkg.data[0] = 10;
    sendPkg((sPkg*)(&THPkg));//发送数据
    //redOn();//指示灯变红
    for(int i = 0;i<100;i++) //延时1s持续接收数据
    {
      _delay_ms(10);
      loopReceive();
    }   
    THPkg.dis_port = 0xa1; //将接收端口改为0xa1
   // THPkg.data[0] = (uint8)Humidity;//传入传感器采集到的湿度值
    THPkg.data[0] = 20;
    sendPkg((sPkg*)(&THPkg));//再次发送信息
    //redOff();//红灯灭
    for(int i = 0;i<100;i++)//延时1s接收可能收到的回复
    {
      _delay_ms(10);
      loopReceive();
    }
  }

//这个函数需要在工作中不断被调用,它会尝试一次接收包,
//如果接收成功就交个recievePkg处理,并再次尝试,直到收不到新的包
void loopReceive()
{
  sPkg* pkg;
  pkg = getNextPkg();
  while(pkg != NULL)
  {
    recievePkg(pkg);
    pkg = getNextPkg();
  }
}

//收到一个包后会调用这个函数,这个函数根据包的目的端口选择相应的程序进行处理
void recievePkg(sPkg* pkg)
{
  switch(pkg->dis_port)
  {
    case 0xb0:    
    if(pkg->data[0] == 0x01)
    {
      //greenTog();
    }
    break;
    default:
    break;    
  }
}
