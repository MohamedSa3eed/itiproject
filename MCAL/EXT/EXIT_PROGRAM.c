#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "EXT_INTERFACE.h"
#include "EXT_PRIVATE.h"
#include "EXT_CONFIG.h"
 
 /* Array Of Global pointer to function */
 void(*EXT[3])(void) = {0,0,0};


u8 ExtEnable(u8 ExtIndex,u8 EdgeSense)
{
	u8 Local_ErrorState = 1;
	switch(ExtIndex)
	{
	case EXT_INT0:
	switch(EdgeSense)
	{
		case EXT_RAISING_EDGE:
		SET_BIT(MCUCR,MCUCR_ISC00);
		SET_BIT(MCUCR,MCUCR_ISC01);
		SET_BIT(GICR,GICR_INT0);
		break;
		
		case EXT_FALLING_EDGE:
		CLR_BIT(MCUCR,MCUCR_ISC00);
		SET_BIT(MCUCR,MCUCR_ISC01);
		SET_BIT(GICR,GICR_INT0);
		break;
		
		case EXT_LOW_LEVEL:
		CLR_BIT(MCUCR,MCUCR_ISC00);
		CLR_BIT(MCUCR,MCUCR_ISC01);
		SET_BIT(GICR,GICR_INT0);
		break;
		
		case EXT_ANY_LOGICAL:
		SET_BIT(MCUCR,MCUCR_ISC00);
		CLR_BIT(MCUCR,MCUCR_ISC01);
		SET_BIT(GICR,GICR_INT0);
		break;
		default : Local_ErrorState =0;
	}
	
	break;
	
	
	case EXT_INT1:
	switch(EdgeSense)
	{
		case EXT_RAISING_EDGE:
		SET_BIT(MCUCR,MCUCR_ISC10);
		SET_BIT(MCUCR,MCUCR_ISC11);
		SET_BIT(GICR,GICR_INT1);
		break;
		
		case EXT_FALLING_EDGE:
		CLR_BIT(MCUCR,MCUCR_ISC10);
		SET_BIT(MCUCR,MCUCR_ISC11);
		SET_BIT(GICR,GICR_INT1);
		break;
		
		case EXT_LOW_LEVEL:
		CLR_BIT(MCUCR,MCUCR_ISC10);
		CLR_BIT(MCUCR,MCUCR_ISC11);
		SET_BIT(GICR,GICR_INT1);
		break;
		
		case EXT_ANY_LOGICAL:
		SET_BIT(MCUCR,MCUCR_ISC10);
		CLR_BIT(MCUCR,MCUCR_ISC11);
		SET_BIT(GICR,GICR_INT1);
		break;
		
		default : Local_ErrorState =0;
	}
	break;
	
	
	case EXT_INT2:
	switch(EdgeSense)
	{
		case EXT_RAISING_EDGE:
		SET_BIT(MCUCSR,MCUCSR_ISC2);
		SET_BIT(GICR,GICR_INT2);
		break;
		
		case EXT_FALLING_EDGE:
		CLR_BIT(MCUCSR,MCUCSR_ISC2);
		SET_BIT(GICR,GICR_INT2);
		break;
		default : Local_ErrorState =0;
	}
	break;
	default : Local_ErrorState =0;
	}
	return Local_ErrorState; 
}


u8 SetCallBack(void(*Lpf)(void),u8 index)
{
	u8 Local_ErrorState = 1;
	if((index<=EXT_INT2) && (Lpf!=0))
	{
	EXT[index] = Lpf;
	}
	else
	{
		Local_ErrorState = 0;
	}
	return Local_ErrorState;
}

/* prototype for ISR of EXT0*/
void __vector_1(void)   __attribute__((signal));
void __vector_1(void)  
{
	if(EXT[EXT_INT0]!=0)
	{
		EXT[EXT_INT0]();
	}
	
}


/* prototype for ISR of EXT1*/
void __vector_2(void)   __attribute__((signal));
void __vector_2(void)  
{
	if(EXT[EXT_INT1]!=0)
	{
		EXT[EXT_INT1]();
	}
}


/* prototype for ISR of EXT2*/
void __vector_3(void)   __attribute__((signal));
void __vector_3(void)  
{
	if(EXT[EXT_INT2]!=0)  // sure that the pointer contain an address
	{
		EXT[EXT_INT2]();
	}
}


