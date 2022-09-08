#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "PWM_CONFIG.h"
#include "PWM_PRIVATE.h"
#include "PWM_INTERFACE.h"

void PWM_INIT_FAST(void)
{
	/* SELECT FAST PWM MODE */
	SET_BIT(TCCR0_REG,6);
	SET_BIT(TCCR0_REG,3);
	
	
	/* NON-INVERTING */
	CLR_BIT(TCCR0_REG,4);
	SET_BIT(TCCR0_REG,5);
	
	
	/*Select Prescaller-> 8 */
	CLR_BIT(TCCR0_REG,0);
	SET_BIT(TCCR0_REG,1);
	CLR_BIT(TCCR0_REG,2);
	
}

void PWM_INIT_PHASE_CORRECT(void)
{
	/* SELECT FAST PWM MODE */
	SET_BIT(TCCR0_REG,6);
	CLR_BIT(TCCR0_REG,3);


	/* NON-INVERTING */
	CLR_BIT(TCCR0_REG,4);
	SET_BIT(TCCR0_REG,5);


	/*Select Prescaller-> 8 */
	CLR_BIT(TCCR0_REG,0);
	SET_BIT(TCCR0_REG,1);
	CLR_BIT(TCCR0_REG,2);

}

void PWM_CTC_VALUE(u8 Value)
{
	OCR0_REG = Value;
}
