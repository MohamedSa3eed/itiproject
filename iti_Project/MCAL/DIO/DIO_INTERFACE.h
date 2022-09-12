#include "../../LIB/STD_TYPES.h" // beacuse this h-file not in the same folder of c-file.
#include "../../LIB/BIT_MATH.h"

#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

void DIO_SetPinDirection(u8 Port, u8 Pin, u8 Direction);
void DIO_SetPinValue (u8 Port, u8 Pin,u8 Value);
u8   DIO_GetPinValue  (u8 Port, u8 Pin);
void DIO_SetPortDirection(u8 port, u8 Direction); 
void DIO_SetPortValue(u8 Port, u8 Value);

enum PORT
{
	PORTA = 0 ,
	PORTB = 1 ,
	PORTC = 2 ,
	PORTD = 3
};
 enum DIRECTION
 {
	 DIO_INPUT  = 0 ,
	 DIO_OUTPUT = 1
 };
 
 enum PIN
 {
	 DIO_PIN0 = 0 ,
	 DIO_PIN1 = 1 ,
	 DIO_PIN2 = 2 ,
	 DIO_PIN3 = 3 ,
	 DIO_PIN4 = 4 ,
	 DIO_PIN5 = 5 ,
	 DIO_PIN6 = 6 ,
	 DIO_PIN7 = 7
	 
 };
 
 enum VALUE
 {
	 DIO_HIGH = 1,
	 DIO_LOW  = 0 
	 
 };
 enum PORT_DIRICTION
 {
     PORT_INPUT  = 0 ,
     PORT_OUTPUT = 0xff ,
     LAST_4OUTPUT = 0xf0
 };

 #define DIO_PORT_VAL  0xff
 

#endif
