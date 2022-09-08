#ifndef  TIMER_PRIVATE_H
#define  TIMER_PRIVATE_H

#define  TIMSK_REG 		(*((u8*) 0x59))
#define  TIFR_REG 		(*((u8*) 0x58))
#define  TCCR0_REG 		(*((u8*) 0x53))
#define  TCNT0_REG 		(*((u8*) 0x52))
#define  OCR0_REG 		(*((u8*) 0x5C))

#define  OCR0_REG 		(*((u8*) 0x5C))

#define  TCCR1A_REG 	(*((u8*) 0x4F))
#define  TCCR1B_REG 	(*((u8*) 0x4E))

#define  TCNT1H_REG 	(*((u8*) 0x4D))
#define  TCNT1L_REG 	(*((u8*) 0x4C))
#define  TCNT1_REG      (*((u16*)0x4C))

#define  OCR1AH_REG 	(*((u8*) 0x4B))
#define  OCR1BL_REG 	(*((u8*) 0x4A))
#define  OCR1A_REG      (*((u16*)0x4A))

#define  ICR1H_REG 		(*((u8*) 0x47))
#define  ICR1L_REG 		(*((u8*) 0x46))
#define  ICR1_REG       (*((volatile u16*)0x46))


#endif
