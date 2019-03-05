/*
 * colorful.h
 *
 * Created: 2017/8/29 22:12:28
 *  Author: lee-home
 */ 


#ifndef __SRB_APP_Changer_SHARE_H_
#define __SRB_APP_Changer_SHARE_H_
	           //123456789abcdef
#define NODENAME Changer
	 
	 
namespace NODENAME
{
		
#define DM0 {7,3,3,4,5,6,7,8,9,0,1,2}
#define M1 {6,3,4,5,6,7,8,9,0,1,2}
#define M2 {4,3,6,7,8,9,0,1,2}
#define M3 {7,3,3,4,5,6,7,8,9,0,1,2}
	

#ifdef __MAPPING_DECLEAR__		
	#ifdef DM0 	
		#ifndef __MASTER__	
			uint8 mapping0[30];
		#endif		
	#else 
		uint8 mapping0[] = M0;
	#endif

	#ifdef DM1 	
		#ifndef __MASTER__	
			uint8 mapping1[30];
		#endif		
	#else 
		uint8 mapping1[] = M1;
	#endif
		
	#ifdef DM2 	
		#ifndef __MASTER__	
			uint8 mapping2[30];
		#endif		
	#else 
		uint8 mapping2[] = M2;
	#endif

	#ifdef DM3 	
		#ifndef __MASTER__	
			uint8 mapping3[30];
		#endif		
	#else 
		uint8 mapping3[] = M3;
	#endif		
#endif


#ifdef __MASTER__
	#undef NODENAME
	#undef M0
	#undef M1
	#undef M2
	#undef M3
	#undef DM0
	#undef DM1
	#undef DM2
	#undef DM3
#endif
		

		
		
		
		
//----------------datas----------------	
struct sByteStatus{
	uint8 low_power:1;
	uint8 noPower:1;
	uint8 chargeing:1;
	uint8 charge_power_good:1;
	uint8 charge_done:1;
};
struct sDataRs 
{
	uint16 beep_time;
	uint8 charge_enable;
	sByteStatus status;
	uint16 battery_voteage;
	uint16 charge_voteage;
	uint16 temperature;
	uint16 battery_1_voteage;
	uint16 battery_2_voteage;
	uint16 battery_3_voteage;
	
};

#define voltageToAdc(voltage) (((uint16)(voltage*10.0))<<8)
struct csConfig{
	uint16 low_power_threshold;
};

struct csADC{
	uint16 adc_fix;	
};


}
#endif /* __SRB_APP_Changer_SHARE_H_ */

