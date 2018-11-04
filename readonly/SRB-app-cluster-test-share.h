/*
 * colorful.h
 *
 * Created: 2017/8/29 22:12:28
 *  Author: lee-home
 */ 


#ifndef __SRB_APP_CLUSTER_TEST_SHARE_H_
#define __SRB_APP_CLUSTER_TEST_SHARE_H_
	
#define NODENAME test001

namespace NODENAME
{
//----------------datas----------------	
#ifdef __MASTER__
#undef NODENAME
#endif
	
#ifdef __MAPPING_DECLEAR__

uint8 mapping0[] = {3,3,5,6,7,1,2,3};
uint8 mapping1[] = {0,3,1,2,3};
uint8 mapping2[] = {0,3,1,2,3};
uint8 mapping3[] = {0,3,1,2,3};

#endif
	
union sColor{
	uint32 u24:24;
	uint8 u8[4];
	struct{
		uint8 b;
		uint8 r;
		uint8 g;
	};
};	

struct sDataBase
{
	uint8 reset:4;
	uint8 estop:4;
};

struct sDataRs 
{
	sDataBase base;
	sColor color_in;
	sColor color_out;
	uint8 alpha;
};


//------------cluster---------------
struct csTest{
	uint32 u24:24;
	uint8 u8[3];
	struct{
		uint8 b;
		uint8 r;
		uint8 g;
	};
};
struct csTiming{
	uint8 add_per_ms;
	uint8 dec_per_ms;
	uint16 low_ms;
	uint16 period;
};


}
#endif /* __SRB_APP_CLUSTER_TEST_SHARE_H_ */

