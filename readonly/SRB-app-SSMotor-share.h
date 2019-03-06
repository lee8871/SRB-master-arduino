#ifndef __SRB_APP_SPEED_SENSOR_MOTOR_SHARE_H_
#define __SRB_APP_SPEED_SENSOR_MOTOR_SHARE_H_
	           //123456789abcdef
#define NODENAME SS_Motor
	 
	 
namespace NODENAME
{
//----------------datas----------------	
#ifdef __MASTER__
#undef NODENAME
#endif


#define DM0 {7,3,3,4,5,6,7,8,9,0,1,2}
#ifdef __MAPPING_DECLEAR__
uint8 mapping0[30];
uint8 mapping1[] = {6,3,4,5,6,7,8,9,0,1,2};
uint8 mapping2[] = {4,3,6,7,8,9,0,1,2};
uint8 mapping3[] = {7,3,3,4,5,6,7,8,9,0,1,2};
#endif

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
#endif /* __SRB_APP_SPEED_SENSOR_MOTOR_SHARE_H_ */

