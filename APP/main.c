#include "../MCAL/DIO/DIO_INTERFACE.h"
#include "../MCAL/EXT/EXT_INTERFACE.h"
#include "../MCAL/TIMER/TIMER_INTERFACE.h"
#include "../MCAL/GI/GI_INTERFACE.h"
#include "../HAL/LCD/LCD_INTERFACE.h"
#include "../HAL/LCD/LCD_CONFIG.h"
#include "../MCAL/ADC/ADC_INTERFACE.h"
#include "avr/delay.h"

#include "../HAL/KEYPAD/KPD_CONFIG.h"
#include "../HAL/KEYPAD/KPD_INTERFACE.h"

int main ()
{
	// columns pin direction as output
	DIO_SetPinDirection(KPD_PORT, KPD_COLUMN0_PIN, DIO_OUTPUT);
	DIO_SetPinDirection(KPD_PORT, KPD_COLUMN1_PIN, DIO_OUTPUT);
	DIO_SetPinDirection(KPD_PORT, KPD_COLUMN2_PIN, DIO_OUTPUT);
	DIO_SetPinDirection(KPD_PORT, KPD_COLUMN3_PIN, DIO_OUTPUT);

	// rows pins direction as input
	DIO_SetPinDirection(KPD_PORT, KPD_ROW1_PIN, DIO_INPUT );
	DIO_SetPinDirection(KPD_PORT, KPD_ROW1_PIN, DIO_INPUT );
	DIO_SetPinDirection(KPD_PORT, KPD_ROW2_PIN, DIO_INPUT );
	DIO_SetPinDirection(KPD_PORT, KPD_ROW3_PIN, DIO_INPUT );

	// setting all high
	DIO_SetPortValue(KPD_PORT,0xff);

	//rooms
	DIO_SetPinDirection(PORTB, DIO_PIN4, DIO_OUTPUT);
	DIO_SetPinDirection(PORTB, DIO_PIN5, DIO_OUTPUT);
	DIO_SetPinDirection(PORTB, DIO_PIN6, DIO_OUTPUT);


	LCD_Init();
	MADC_voidInit(); // initial the ADC
	DIO_SetPinDirection(PORTA, DIO_PIN1, DIO_INPUT); //ldr input

	u8 flag =0 ;
	while (flag ==0 )
	{

		flag = Login();
		LCD_WriteData(KPD_GetPressedKey() + '0');
	}




	return 0;
}/*
	DIO_SetPortDirection(PORTD,DIO_OUTPUT);
	DIO_SetPinDirection(PORTB,3,DIO_OUTPUT);
	while(1)
	{
		DIO_SetPortValue(PORTD,0b01000000);
		PWM_INIT_FAST();
		for(int i=10;i<255;i++)
		{
			PWM_CTC_VALUE(i);
			_delay_ms(100);
		}


	}

 */






































/*
	u8 Local_u8PressedKey;

	DIO_SetPinDirection(KPD_PORT,KPD_COLUMN0_PIN,DIO_OUTPUT);
	DIO_SetPinDirection(KPD_PORT,KPD_COLUMN1_PIN,DIO_OUTPUT);
	DIO_SetPinDirection(KPD_PORT,KPD_COLUMN2_PIN,DIO_OUTPUT);
	DIO_SetPinDirection(KPD_PORT,KPD_COLUMN3_PIN,DIO_OUTPUT);


	DIO_SetPinDirection(KPD_PORT,KPD_ROW0_PIN,DIO_LOW);
	DIO_SetPinDirection(KPD_PORT,KPD_ROW1_PIN,DIO_LOW);
	DIO_SetPinDirection(KPD_PORT,KPD_ROW2_PIN,DIO_LOW);
	DIO_SetPinDirection(KPD_PORT,KPD_ROW3_PIN,DIO_LOW);

	DIO_SetPortValue(KPD_PORT,0xff);

	LCD_Init();
	//LCD_WriteString("Hanan");

	while(1)
	{
		u8 x =0;
		Local_u8PressedKey = KPD_u8GetPressedKey();
		while(Local_u8PressedKey!=KPD_NO_PRESSED_KEY)
		{
			x =1;
			//LCD_WriteString("Hanan");
			LCD_WriteData(Local_u8PressedKey + '0');
			_delay_ms(20);

			if(x==1)
				break;



		}




	}
}
 */






























/*
	DIO_SetPinDirection(PORTD,5,DIO_OUTPUT);
	TIMER1_INT();
	Timer1SetAngle_A(0);
	while(1)
	{

	}
}


void Tog_Led(void)
	{
		static u8 flag =0;
		if(flag==0)
		{
			DIO_SetPinValue (PORTA,0,DIO_HIGH);
			flag =1;
		}

		else
		{
			DIO_SetPinValue (PORTA,0,DIO_LOW);
			flag =0;
		}

	}





 */





/**** LAB2 *****/
/*
  LCD_Init();
	u8 x =0;
	u8 y =0;

	while(1)
	{
	while(y<11){
	LCD_GoToXY(x,y++);
	LCD_WriteString("Hanan");
	_delay_ms(500);
	LCD_SendCommand(0x01);
	_delay_ms(0.000001);
	}
	while(y!=0)//Hanan
	{
		LCD_GoToXY(x,y--);
		LCD_WriteString("Hanan");
		_delay_ms(500);
		LCD_SendCommand(0x01);
		_delay_ms(0.000001);
	}
	}


	return 0;
 */
















/*
		 Toggle led every 1 sec using interrupt

		GI_Enable();

		DIO_SetPinDirection(PORTA,0,DIO_OUTPUT);
		 Set CallBackFUnction
		Timer0_SetCallBack(&Tog_Led,0);
		//ExtEnable(0,EXT_ANY_LOGICAL);
		TIMER0_INT();
		while(1);
		return 0;



	void Tog_Led(void)
	{
		static u8 flag =0;
		if(flag==0)
		{
			DIO_SetPinValue (PORTA,0,DIO_HIGH);
			flag =1;
		}

		else
		{
			DIO_SetPinValue (PORTA,0,DIO_LOW);
			flag =0;
		}

 */
