#ifndef __SRB_APP_DMOTOR_SHARE_H_
#define __SRB_APP_DMOTOR_SHARE_H_

namespace srb{
#define NODE_VERSION {0,0,0}
#define NODE_TYPE PhotoElecX4
namespace NODE_TYPE{

#define DM0	{9,0,	0,1,2,3,4,5,6,7, 8}
#define M1	{9,0,	0,1,2,3,4,5,6,7, 8}
#define M2	{8,0,	0,1,2,3,4,5,6,7}
#define M3	{8,0,	0,1,2,3,4,5,6,7}


#ifdef BUILD_FOR_SRB_MASTER
	static const uint8 Dynamic_mapping0[] = DM0;
	static const uint8 Mapping1[] = M1;
	static const uint8 Mapping2[] = M2;
	static const uint8 Mapping3[] = M3;


	#undef DM0
	#undef DM1
	#undef DM2
	#undef DM3

	#undef M0
	#undef M1
	#undef M2
	#undef M3

	#define _TO_STRING(n) #n
	#define TO_STRING(n) _TO_STRING(n)
	static const char Node_name[] = TO_STRING(NODE_TYPE);
	#undef NODE_TYPE
	#undef TO_STRING
	#undef _TO_STRING

	static const char Node_version[2] = NODE_VERSION;
	#undef NODE_VERSION
#endif


struct sDataRs
{
	int	peValue[4];
	uint8 phase;
	uint8 led_status;
};

struct csCycleLedStatus{
	uint8 cycle_length;
	uint8 led_status_table[16];
};

}}//namespace


#endif /* __SRB_APP_DMOTOR_SHARE_H_ */
