#ifndef  PWM_PRIVATE_H
#define  PWM_PRIVATE_H

#define  TIMSK_REG 		(*((u8*) 0x59))
#define  TIFR_REG 		(*((u8*) 0x58))
#define  TCCR0_REG 		(*((u8*) 0x53))
#define  TCNT0_REG 		(*((u8*) 0x52))
#define  OCR0_REG 		(*((u8*) 0x5C))
#define  SREG_REG		(*((u8*) 0x5F))


#endif