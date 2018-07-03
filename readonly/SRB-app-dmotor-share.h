/*
 * colorful.h
 *
 * Created: 2017/8/29 22:12:28
 *  Author: lee-home
 */ 


#ifndef __SRB_APP_DMOTOR_SHARE_H_
#define __SRB_APP_DMOTOR_SHARE_H_
	
#define NODENAME dMotor
	 

namespace NODENAME
{
//----------------datas----------------	
#ifdef __MASTER__
#undef NODENAME
#endif

	
#ifdef __STATIC_MAPPING_DECLEAR__
sStaticMapping mapping0 = {0,4,{0,1,2,3}};
sStaticMapping mapping1 = {0,4,{2,3,0,1}};
sStaticMapping mapping2 = {0,4,{0,1,2,3}};
sStaticMapping mapping3 = {0,4,{2,3,0,1}};
#endif

#ifdef __STATIC_MAPPING_DECLEAR_ARDUINO__
uint8 mapping0[] = {0,4,0,1,2,3};
uint8 mapping1[] = {0,4,2,3,0,1};
#endif
union sMotor
{
	uint16 u16;
	struct	{
		uint16 speed:14;
		uint16 _no_used_2:2;
	};
	struct {
		uint8 _no_used_0;
		uint8 _no_used_1:6;
		uint8 dir:2;
	};
};		
struct sDataRs 
{
	sMotor ma;
	sMotor mb;
};

//------------cluster---------------
struct csMotorSet{
	uint16 min_pwm_a;
	uint16 min_pwm_b;
	uint16 period:14;
	uint16 _n0_used:2;
};


}
#endif /* __SRB_APP_DMOTOR_SHARE_H_ */

