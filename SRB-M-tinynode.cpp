#define __ARDUINO__

#include <lee.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include <Led.h>
#include <CRC8.h>



#include "readonly/SRB-share-const.h"
#include "SRB-M-mac.h"
#include "SRB-M-tinynode.h"

void SrbTinyNode::SRBinit()
{
    ledInit();
	srbPhyInit();
}



void SrbTinyNode::access(uint8 port_num)
{
	if(port_num>3)
	{
		return;
	}
	send(port_num);
	recv(port_num);
}

void SrbTinyNode::send(uint8 port_num)
{
	uint8 * table = mapping[port_num]->table;
	table += mapping[port_num]->up_len;
	
	uint8 *d = datas;
	
	uint8 down_len = mapping[port_num]->down_len;
	
	
	SendAddr = address;
	Send_pkg.bfc.port = 0;
	Send_pkg.bfc.length = down_len;
	
	for(uint8 i = 0; i<down_len;i++)
	{
		Send_pkg.data[i] = d[*table];
		table++;	
	}	
	mstBeginSend();
}
#define COUNTER_LEN 250
void SrbTinyNode::recv(uint8 port_num)
{	
	uint8 * table = mapping[port_num]->table;
	uint8 *d = datas;
	
	uint8 up_len = mapping[port_num]->up_len;
	
	uint8 timer = 0;		
	while(Bus_state == BS_SENDING)
	{
		timer++;
		if(timer >= COUNTER_LEN){
			Bus_state = BS_SEND_TIMEOUT;
			return;
		}	
	}
	while(Bus_state >= BS_SEND_DONE)
	{
		timer++;
		if(timer >= COUNTER_LEN){
			Bus_state = BS_RECV_TIMEOUT;
			return;
		}	
	}
	if(up_len >	Recv_pkg.bfc.length)
	{
		up_len = Recv_pkg.bfc.length;
	}	
	for(uint8 i=0; i<up_len; i++){
		d[*table]=Recv_pkg.data[i]; 
		table++;
	}
	Bus_state = BS_IDLE;	
}


SrbTinyNode::SrbTinyNode()
{
}









