#include "../../LIB/STD_TYPES.h" // beacuse this h-file not in the same folder of c-file.
#include "../../LIB/BIT_MATH.h"
#ifndef  EXT_INTERFACE_H
#define  EXT_INTERFACE_H

void EXTI_voidInt0Init(void);

void EXTI_voidInt1Init(void);

void EXTI_voidInt2Init(void);
u8 ExtEnable(u8 ExtIndex,u8 EdgeSense);
u8 SetCallBack(void(*Lpf)(void),u8 index);



#define EXT_INT0         0
#define EXT_INT1         1
#define EXT_INT2         2

/* Macros for Edge Source */
#define EXT_RAISING_EDGE		0
#define EXT_FALLING_EDGE		1
#define EXT_ANY_LOGICAL			2
#define EXT_LOW_LEVEL			3
#endif
