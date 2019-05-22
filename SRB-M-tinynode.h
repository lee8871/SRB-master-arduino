#ifndef __SRB_M_TINYNODE_H_
#define __SRB_M_TINYNODE_H_

#include "readonly/SRB-share-const.h"
#include <lee.h>
#define SHOW_ADDR_LOW     0xF3
#define SHOW_ADDR_HIGH		0xF4
#define SHOW_ADDR_CLOSE		0xF5
class SrbTinyNode
{
private:


public:
	uint8 address;
	uint8 *datas;
	sMapping * mapping[4];

	SrbTinyNode();
	static void SRBinit();
	void access(uint8 port_num);
	static void addressLedDisplayBroadcast(uint8 cmd);
	};






#endif /* __SRB_M_TINYNODE_H_ */
