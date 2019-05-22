#ifndef _lee_h
#define _lee_h


//位操作符号
#define set |=
#define clr &=~
#define SET set
#define CLR clr

#ifndef bit
	#define bit(i) ( 1 << (i) )
#endif
#ifndef bit
	#error bit
#endif
#define nbit(i) (0)

//
//位掩码定义
#define bit0 bit(0)
#define bit1 bit(1)
#define bit2 bit(2)
#define bit3 bit(3)
#define bit4 bit(4)
#define bit5 bit(5)
#define bit6 bit(6)
#define bit7 bit(7)


#define yes 1
#define no 0
#define fail 1
#define done 0
#define null 0




typedef unsigned char uint8;
typedef unsigned short int uint16;
typedef unsigned long int uint32;
typedef signed char int8;
typedef signed short int int16;
typedef signed long int int32;

typedef union
{
	uint32 u32;
	uint32 u24:24;
	uint8 u8[4];
	uint16 u16[2];
}u32to8;

typedef union
{
	uint32 u24:24;
	uint8 u8[3];
}u24to8;

typedef union
{
	uint16 u16;
	void* v;
	uint8 u8[2];
}u16to8;

#endif
