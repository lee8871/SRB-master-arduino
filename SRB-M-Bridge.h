#ifndef __SRB_M_BRIDGE_H_
#define __SRB_M_BRIDGE_H_
#ifdef bit
	#undef bit
#endif
#include <arduino.h>
#include <lee.h>

class SrbBridge
{

private:
	void nextRead(uint8 port_num);
	void recv(uint8 port_num);

	void access();
	uint8 checkByteRecv(void);

	uint8 SendAddr = 0x00;
	uint8 sno;
	uint8 is_addr;
	uint8 Send_counter;
	uint8 Escaping;
	Stream* stream_to_pc;
public:
	void run();
	SrbBridge();
	void SrbBridgeinit(Stream * stp);
};


extern SrbBridge srb_bridge;



#endif /* __SRB_M_BRIDGE_H_ */
