/*
 * swip_space.h
 *
 * Created: 2017/8/26 14:52:28
 *  Author: lee
 */


#ifndef __CRC8_H_
#define __CRC8_H_

#include "lee.h"
#include <avr/pgmspace.h>

extern const uint8 Crc_table[256] PROGMEM;


#define crcInput(cc,nd) do{cc = pgm_read_byte(Crc_table + (cc^nd));}while(0)



#endif /* __CRC8_H_  */
