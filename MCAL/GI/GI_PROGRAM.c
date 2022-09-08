#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "GI_INTERFACE.h"

#define SREG_REG  	*(( volatile u8*)0x5F)

void GI_Enable(void)
{
		SET_BIT(SREG_REG,7);
}

void GI_DisEnable(void)
{
		CLR_BIT(SREG_REG,7);
}
