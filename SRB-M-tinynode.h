#ifndef __SRB_M_TINYNODE_H_
#define __SRB_M_TINYNODE_H_

#include "readonly/SRB-share-const.h"

class SrbTinyNode
{

private:


public:
	uint8 address;
	uint8 *datas;
	sStaticMapping * mapping[4];

	SrbTinyNode();
	static void SRBinit();
	void access(uint8 port_num);
	};






#endif /* __SRB_M_TINYNODE_H_ */
