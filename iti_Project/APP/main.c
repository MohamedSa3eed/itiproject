#include "interface.h"
#include "../MCAL/DIO/DIO_INTERFACE.h"
#include "../MCAL/EXT/EXT_INTERFACE.h"
#include "../MCAL/TIMER/TIMER_INTERFACE.h"
#include "../MCAL/GI/GI_INTERFACE.h"
#include "../HAL/LCD/LCD_INTERFACE.h"
#include "../HAL/LCD/LCD_CONFIG.h"
#include "../HAL/KEYPAD/KPD_interface.h"
#include "../HAL/KEYPAD/KPD_config.h"
#include "../MCAL/ADC/ADC_INTERFACE.h"
#include "avr/delay.h"

int main ()
{

	keypadinit();
	u8 flag =0 ;
	while (flag ==0 )
	{
		flag = Login();

	}

	return 0;
}


















































