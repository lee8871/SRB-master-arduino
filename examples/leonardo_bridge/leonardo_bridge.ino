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

#include <SRB-M-Bridge.h>
#include <SoftwareSerial.h>

//使用其他开发板则需要使用其他串口形式
//SoftwareSerial mySerial(9,8); // RX, TX
void setup() {
  // Adjust baudrate here
  Serial.begin(2500000);
  srb_bridge.SrbBridgeinit(&Serial);
  srb_bridge.run();
}
void loop(){}
