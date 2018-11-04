/*******   About software    ************
  UART-SRB-bridge for Arduino Leonardo.
  It for PC connect to SRB by UART.
  The UART is too slow to run SRB in full speed.
  The bridge is just for config SRB device.

  本程序用于需要使用电脑上的 SRB Bridge的情况。
  UART的速度比SRB慢,
  这个程序不能支持电脑端程序的全速运行,
  只能用于参数配置.
  lee8871@126.com
****************************************/

#include "lee.h"
#include <SRB-M-Bridge.h>
#include <SRB-M-mac.h>
#include <SRB-M-tinynode.h>

#include <SoftwareSerial.h>
//Leonardu的USB转串口也可以使用,但是Windows下,USB转串口的工作不太稳定。
SoftwareSerial mySerial(9,8); // RX, TX
void setup() {
  // Adjust baudrate here
  mySerial.begin(57600);
  srb_bridge.SrbBridgeinit(&mySerial);
  srb_bridge.run();
}
void loop(){}
