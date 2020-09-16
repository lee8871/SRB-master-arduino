#ifndef __SRB_APP_SpeedMotor_SHARE_H_
#define __SRB_APP_SpeedMotor_SHARE_H_

namespace srb{
#define NODE_VERSION {1,0,0}
#define NODE_TYPE SpeedMotor
namespace NODE_TYPE{

#define DM0	{8,6,6,7,8,9,10,11,12,13,14,0,1,2,3,4,5}
#define M1	{8,6,6,7,8,9,10,11,12,13,14,0,1,2,3,4,5}
#define M2	{0,2,0,2}
#define M3	{0,4,2,3,0,1}


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

	namespace eDIR{
	enum eDIR{
		Forward=0,
		Reverse=1,
		Brake=2,
		Free=3,
		Null=4,
	};
	};


struct sDataRs
{
	int16 set_speed;
	int16 set_displacement; 
	int16 set_acceleration;
	int16 get_sensor_speed;
	int32 get_odometer;
	int16 get_move_to; 
	int16 get_pwm; 
	
};

enum eLoseBehabior{
	LOSE_BEHAVIOR_FREE=0,
	LOSE_BEHAVIOR_BRAKE=1,
};
struct csConnection{
	uint8 lose_control_10ms:7;
	uint8 lose_behavior:1;
};
struct csPid{
	uint16 k1;
	uint16 k0;
	int16 kp;
	int16 ki;
	int16 kd;
	uint32 speed_dividend;
};

struct csFeedforwardCurve{
	uint16 maxSpeed;
	uint16 pwm[9];
};

struct csTestPwm{
	uint8 Direction;
	uint16 Pwm;
};
}}//namespace


#endif /* __SRB_APP_SpeedMotor_SHARE_H_ */
