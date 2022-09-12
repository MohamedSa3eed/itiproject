#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "TIMER_PRIVATE.h"
#include "TIMER_INTERFACE.h"
#include "TIMER_CONFIG.h"


/*Global Pointer to Function*/

static void (*PF_Timer0)(void) = 0;
void TIMER0_INT(void)
{
	/* Select Normal Mode */
	CLR_BIT(TCCR0_REG,3);
	CLR_BIT(TCCR0_REG,6);
	
	
	/* enable Global Interrupt */
	//SET_BIT(SREG_REG,7);
	
	
	
	/*Enable Overflow Interrupt */
	SET_BIT(TIMSK_REG,0);
	
	/*Select Prescaller Value*/
	TCNT0_REG = 192;
	
	
	
	/*Select Prescaller-> 8 */
	CLR_BIT(TCCR0_REG,0);
	SET_BIT(TCCR0_REG,1);
	CLR_BIT(TCCR0_REG,2);
	
	
}

/*Prototupe for ISR of Timer0 OVF*/

void __vector_11(void)__attribute__((signal));
void __vector_11(void)
{
	
	static u16 counter =0;
	counter++;
	if(counter==3907)
	{
		/* preload Value */
		TCNT0_REG = 192;
		counter =0;
		if(PF_Timer0!=0)
		{
			PF_Timer0();
		}
		
	}
}


u8 Timer0_SetCallBack(void(*Lpf)(void),u8 index)
{
	u8 ErrorState = 1;
	if(Lpf!=0)
	{
		PF_Timer0=Lpf;
	}
	else
	{
		ErrorState = 0;
	}
	return ErrorState;
}

void TIMER1_INT(void)
{
	/* Select TIMER1 MODE ==> 14 */
	CLR_BIT(TCCR1A_REG,0);
	SET_BIT(TCCR1A_REG,1);
	SET_BIT(TCCR1B_REG,3);
	SET_BIT(TCCR1B_REG,4);
	
	
	/* Select HW Action on OC1A pin==< Non Inverting */
	CLR_BIT(TCCR1A_REG,6);
	SET_BIT(TCCR1A_REG,7);
	
	/* Set Top Value in ICR1 */
	ICR1_REG = 19999;
 
	/* Set Angle of Servo Motor */
	 OCR1A_REG= 1999; // to produce period time = 20 mSec (desired time/tick time)
	
	/*Select Prescaller-> 8 */
	CLR_BIT(TCCR1B_REG,0);
	SET_BIT(TCCR1B_REG,1);
	CLR_BIT(TCCR1B_REG,2);
}
void Timer1SetAngle_A(u16 OCRA)
{
	u16 Angle = (5.6 * OCRA) + 999;
	OCR1A_REG = Angle;
}
