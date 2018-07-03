

#ifndef __SRB_SHARE_BASE_CLUSTER_H_
#define __SRB_SHARE_BASE_CLUSTER_H_



struct csBase
{
	uint8 addr;
	uint8 name[17];
};


struct csInfo
{
	uint8 version_BCD[2];
	uint8 node_type[8];
};	
//
struct csError
{
	uint16 file;
	uint16 line;
	uint8 description[24];
};

#endif /* __SRB_SHARE_BASE_CLUSTER_H_ */

