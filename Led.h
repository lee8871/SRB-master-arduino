#ifndef __LED_H_
#define __LED_H_

#include <lee.h>
#include <avr/io.h>

#define PORTx PORTE
#define DDRx DDRE
#define bit_ bit6
#define instance_name red
#include "code/led-cpp.ih.h"

#define PORTx PORTB
#define DDRx DDRC
#define bit_ bit6
#define instance_name green
#include "code/led-cpp.ih.h"

#define PORTx PORTD
#define DDRx DDRD
#define bit_ bit7
#define instance_name yellow
#include "code/led-cpp.ih.h"

class no_led
{
public :
	inline void on();
	inline void off();
	inline void tog();
	inline void init();
};
inline void no_led::on(){}
inline void no_led::off(){}
inline void no_led::tog(){}
extern no_led no_led;

void ledInit();

#endif /* __LED_H_ */