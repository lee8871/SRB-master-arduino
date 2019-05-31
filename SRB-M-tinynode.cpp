#include <lee.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <Led.h>
#include <CRC8.h>
#include "readonly/SRB-share-const.h"
#include "SRB-M-mac.h"
#include "SRB-M-tinynode.h"
using namespace srb;

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
	uint8 * table;
	uint8 *d;
	uint8 len;

	cli();
	masterSendAddr(address);

	table = mapping[port_num]->table;
	table += mapping[port_num]->up_len;
	d = datas;
	len = mapping[port_num]->down_len;

	sBfc bfc;
	bfc.port = port_num;
	bfc.length = len;
	masterSendBfc(bfc.byte);

	for(uint8 i = 0; i<len;i++)
	{
		masterSendData(d[*table]);
		table++;
	}
	masterSendCrc();

	table = mapping[port_num]->table;
	d = datas;

	len = mapping[port_num]->up_len;
	masterWaitBfc();
	if(masterRecvPkg()==done)
	{
		if(len > Recv_pkg.bfc.length)
		{
			len = Recv_pkg.bfc.length;
		}
		for(uint8 i=0; i<len; i++){
			d[*table]=Recv_pkg.data[i];
			table++;
		}
	}
	sei();
}

void SrbTinyNode::addressLedDisplayBroadcast(uint8 cmd)
{
	cli();
	masterSendAddr(0xff);
	sBfc bfc;
	bfc.port = SC_PORT_CFG;
	bfc.length = 2;
	masterSendBfc(bfc.byte);
	masterSendData(0);
	masterSendData(cmd);
	masterSendCrc();
	sei();
}


SrbTinyNode::SrbTinyNode()
{
}
