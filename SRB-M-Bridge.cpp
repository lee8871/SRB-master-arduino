

#define __ARDUINO__

#include <lee.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include <Led.h>
#include <CRC8.h>





#include "readonly/SRB-share-const.h"
#include "SRB-M-mac.h"
#include "SRB-M-Bridge.h"

#define C_EMPTY 0
#define C_NEXT 1
#define C_GOT 2

static const uint8* const recv_pkg_u8 = (uint8*)(&Recv_pkg);
static uint8* const send_pkg_u8 = (uint8*)(&Send_pkg);

void SrbBridge::run()
{
	while(1)
	{
		while(checkByteRecv() != C_GOT);
		access();
	}
}

uint8 SrbBridge::checkByteRecv(void)
{
	int a;
	a = stream_to_pc->read();
	if(a>=0){
		uint8 data = a;
		if(data == SC_ESCAPE){
			Escaping = yes;
		}
		else{
			if(Escaping == no){
				if(is_addr == no){
					if(Send_counter<MAX_PKG_LEN){
						send_pkg_u8[Send_counter++] = data;
						if(Send_counter == Send_pkg.bfc.length+2){
							return C_GOT;
						}
					}
				}
				else{
					is_addr = no;
					SendAddr = data;
				}
			}
			else{
				Escaping = no;
				if(data == SC_EE){
					if(Send_counter<MAX_PKG_LEN){
						send_pkg_u8[Send_counter++] = SC_ESCAPE;
						if(Send_counter == Send_pkg.bfc.length+2){
							return C_GOT;
						}
					}
				}
				else{
					sno = data;
					is_addr = yes;
					Send_counter=0;
				}
			}
		}
		return C_NEXT;
	}
	return C_EMPTY;
}


void SrbBridge::access()
{
	cli();
	masterSendAddr(SendAddr);
	masterSendBfc(Send_pkg.bfc.byte);
	uint8 len = Send_pkg.bfc.length;
	for(uint8 i = 0; i<len;i++)
	{
		masterSendData(Send_pkg.data[i]);
	}
	masterSendCrc();

	masterWaitBfc();
	if(masterRecvPkg()==done)
	{
		stream_to_pc->write(SC_ESCAPE);
		stream_to_pc->write(sno);
		len = Recv_pkg.bfc.length+2;
		for(uint8 i = 0; i<len; i++)
		{
			if(recv_pkg_u8[i] == SC_ESCAPE)
			{
				stream_to_pc->write(SC_ESCAPE);
				stream_to_pc->write(SC_EE);
			}
			else{
				stream_to_pc->write(recv_pkg_u8[i]);
			}
		}
	}
	else
	{
		stream_to_pc->write(SC_ESCAPE);
		stream_to_pc->write(sno);
		stream_to_pc->write(SC_ESCAPE);
		stream_to_pc->write(0xf8);
	}
	sei();
}

SrbBridge::SrbBridge()
{
}

void SrbBridge::SrbBridgeinit(Stream * stp)
{
    ledInit();
	srbPhyInit();
	stream_to_pc = stp;
}
SrbBridge srb_bridge;
