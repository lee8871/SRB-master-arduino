#ifndef __SRB_APP_DMOTOR_SHARE_H_
#define __SRB_APP_DMOTOR_SHARE_H_
//Node name should less than 16 :  
	           //0123456789abcdef 
#define NODENAME Du_Motor
	 
	 
namespace NODENAME
{

		
#define M0	{0,4,0,1,2,3};
#define M1	{0,4,2,3,0,1};
#define M2	{0,4,0,1,2,3};
#define M3	{0,4,2,3,0,1};
	

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
		







#define MOTOR_DIR_FOWARD 0
#define MOTOR_DIR_REVERSE 3
#define MOTOR_DIR_BRAKE 1
#define MOTOR_DIR_FREE 2
union sMotor
{
	uint16 u16;
	struct	{
		int16 speed:15;
		uint16 _no_used_2:1;
	};
	struct {
		uint8 _no_used_0;
		uint8 _no_used_1:7;
		uint8 brake:1;
	};
};		

struct sDataRs 
{
	sMotor ma;
	sMotor mb;
};

//------------cluster---------------
#define LOSE_BEHAVIOR_KEEP 2
#define LOSE_BEHAVIOR_BRAKE 1
#define LOSE_BEHAVIOR_FREE 0
struct csMotorSet{
	uint16 min_pwm_a;
	uint16 min_pwm_b;
	uint16 period;
	uint8 lose_control_ms;
	uint8 lose_behavior;
};
#define ADJ_DISABLE 0
#define ADJ_255 1
#define ADJ_1000 2
#define ADJ_10000 3

struct csMotorAdj{
	uint8 Adj;
	uint8 TogMotorA;
	uint8 TogMotorB;
};

}


//----------------datas----------------	


#endif /* __SRB_APP_DMOTOR_SHARE_H_ */

