#include "interface.h"
#include "config.h"
#include "../MCAL/DIO/DIO_INTERFACE.h"
#include "../MCAL/EXT/EXT_INTERFACE.h"
#include "../MCAL/TIMER/TIMER_INTERFACE.h"
#include "../MCAL/GI/GI_INTERFACE.h"
#include "../HAL/LCD/LCD_INTERFACE.h"
#include "../HAL/KEYPAD/KPD_interface.h"
#include "../HAL/KEYPAD/KPD_config.h"
#include "../HAL/KEYPAD/KPD_PRIVATE.h"
#include "../MCAL/ADC/ADC_INTERFACE.h"
#include "../HAL/LCD/LCD_CONFIG.h"
#include "avr/delay.h"

u32 savedpass1 = 1111;
u32 savedpass2 = 2222;
u32 savedpass3 = 0000;
static u8 state = 1;
void openDoor(void)
{


	DIO_SetPinDirection(PORTD,5,DIO_OUTPUT);
	TIMER1_INT();
	Timer1SetAngle_A(180);
}


void closeDoor(void)
{

	DIO_SetPinDirection(PORTD,5,DIO_OUTPUT);
	PWM_INIT_FAST();
	Timer1SetAngle_A(90);
}



void openFan(void)
{

	state = 1;
	u16 Local_AnaloglValue,Local_DigitalValue;
	DIO_SetPinDirection(PORTA,0,DIO_INPUT);
	MADC_voidInit();
	DIO_SetPinDirection(PORTB,3,DIO_OUTPUT);



	Local_DigitalValue = MADC_u8StartConversion(0);
	Local_AnaloglValue = (Local_DigitalValue * 5000UL)/1024;

	if(Local_AnaloglValue>270)
	{
		TIMER1_INT();
		PWM_INIT_FAST();
		PWM_CTC_VALUE(Local_DigitalValue*10);
		_delay_ms(100);
	}


}
void closeFan(void)
{
	state = 0;
	PWM_CTC_VALUE(0);
}

u8 Login(void)
{
	loginInit();

	u8 user = getOption();  //get user from keypad
	LCD_WriteCommand(clear);
	LCD_GoToXY(0, 0);
	switch (user)
	{
	case user1:
	{
		if (checkUser1Pass() == 1)
		{
			rigthPass();
			options();
			return 0 ;
		}
		else
		{
			LCD_WriteString("no tries left");
			_delay_ms(100);
			LCD_WriteCommand(clear);
			LCD_WriteString("try again after");
			LCD_GoToXY(1, 6);
			LCD_WriteString("20 sec");
			_delay_ms(1000);
			LCD_WriteCommand(clear);
			return 0 ;
		}
		break;

	}
	case user2:
	{
		if (checkUser2Pass() == 1)
		{
			rigthPass();
			options();
			return 0 ;

		}
		else
		{
			LCD_WriteString("no tries left");
			_delay_ms(300);
			LCD_WriteCommand(clear);
			LCD_WriteString("try again after");
			LCD_GoToXY(1, 6);
			LCD_WriteString("20 sec");
			_delay_ms(4000);
			LCD_WriteCommand(clear);
			return 0 ;
		}
		break;

	}
	case user3:
	{
		if (checkUser3Pass() == 1)
		{
			rigthPass();
			options();

			return 0 ;

		}
		else
		{
			LCD_WriteString("no tries left");
			_delay_ms(100);
			LCD_WriteCommand(clear);
			LCD_WriteString("try again after");
			LCD_GoToXY(1, 6);
			LCD_WriteString("20 sec");
			_delay_ms(4000);
			LCD_WriteCommand(clear);
			return 0 ;
		}
		break;

	}
	default :
		LCD_WriteString("Wrong Option");
		_delay_ms(700);
		return 0 ;
	}

}

void loginInit(void)
{
	LCD_GoToXY(0, 0);
	LCD_WriteString ("  >>welcome<<");
	_delay_ms(100);
	LCD_WriteCommand(clear);
	//_delay_ms(50);
	LCD_WriteString ("  >>welcome<<");
	_delay_ms(100);
	LCD_WriteCommand(clear);
	_delay_ms(100);
	LCD_WriteString("1-user1 2-user2");
	LCD_GoToXY(1, 0);
	LCD_WriteString("3-user3  ");
}
u8 checkUser1Pass(void)
{
	u8 tries = TRIES ;
	while (tries)
	{
		u32 pass = getPass();
		//get password form user
		if (pass == savedpass1)
		{
			return 1 ;
		}
		else
		{
			WrongPass();
			tries -- ;
		}
	}
	return 0;
}

u8 checkUser2Pass(void)
{
	u8 tries = TRIES ;
	while (tries)
	{
		u32 pass = getPass();
		//get password form user
		if (pass == savedpass2)
		{
			return 1 ;
		}
		else
		{
			WrongPass();
			tries -- ;
		}
	}
	return 0;
}

u8 checkUser3Pass(void)
{
	u8 tries = TRIES ;
	while (tries)
	{
		u32 pass = getPass();
		//get password form user
		if (pass == savedpass3)
		{
			return 1 ;
		}
		else
		{
			WrongPass();
			tries -- ;
		}
	}
	return 0;
}
void options(void)
{
	LCD_WriteString("1-Rooms 2-Door");
	LCD_GoToXY(1, 0);
	LCD_WriteString("3-Fan   4-Back");
	_delay_ms(100);
	u8 option = getOption();
	_delay_ms(100);
	LCD_WriteCommand(clear);
	switch (option)
	{
	case Rooms :
	{
		roomOptions();
		options();
		break;
	}
	case Door :
	{
		LCD_WriteString("1-open  2-close");
		u8 option = getOption();


		if(option == on)
		{
			openDoor();
			LCD_WriteCommand(clear);
			_delay_ms(20);
			options();
		}
		else if(option == off)
		{
			closeDoor();
			LCD_WriteCommand(clear);
			_delay_ms(20);
			options();
		}
		break;
	}
	case Air :
	{
		LCD_WriteString("1-open  2-close");
		u8 option = getOption();


		if(option == on)
		{
			openFan();
			LCD_WriteCommand(clear);
			_delay_ms(20);
			options();
		}
		else if(option == off)
		{
			closeFan();
			LCD_WriteCommand(clear);
			_delay_ms(20);
			options();
		}
	}

	case  Back :
	{
		Login();
		break ;
	}
	default:
	{
		LCD_WriteString(" Wrong Option");
		_delay_ms(700);
		LCD_WriteCommand(clear);
		options();
	}
	}
	LCD_GoToXY(0, 0);

}
u8 getOption(void)
{
	u8 KPD_PressedKey;
	while(1)
	{
		do
		{
			KPD_PressedKey = KPD_GetPressedKey();
		}
		while (KPD_PressedKey == KPD_NOT_PRESSED);

		break;
	}
	return KPD_PressedKey;
}
u32 getPass(void)
{
	u32 pass = 0;
	u8 passLong = PASS_LONG ;
	LCD_WriteString(" Pass : ");
	while(passLong-- )
	{
		pass *=10 ; //to put the next cahracter in the next place
		pass += getOption() ;
		LCD_WriteData('*');
		_delay_ms(100);
	}
	LCD_WriteCommand(clear);
	return pass ;
}
void room1On(void)
{
	DIO_SetPinValue(PORTB, DIO_PIN4, DIO_HIGH);
}
void room1Off(void)
{
	DIO_SetPinValue(PORTB, DIO_PIN4, DIO_LOW);
}
void room2On(void)
{
	DIO_SetPinValue(PORTB, DIO_PIN5, DIO_HIGH);
}
void room2Off(void)
{
	DIO_SetPinValue(PORTB, DIO_PIN5, DIO_LOW);
}
void room3On(void)
{
	DIO_SetPinValue(PORTB, DIO_PIN6, DIO_HIGH);
}
void room3Off(void)
{
	DIO_SetPinValue(PORTB, DIO_PIN6, DIO_LOW);
}
void roomOptions(void)
{
	LCD_WriteString("1-Room1  2-Room2");
	LCD_GoToXY(1, 0);
	LCD_WriteString("3-Room3 ");
	u8 option = getOption();
	LCD_WriteCommand(clear);
	LCD_WriteString(" 1-on   2-off");
	switch (option)
	{
	case Room1 :
	{
		u8 state = getOption();
		if(state == on)
		{
			room1On();
		}
		else if(state == off)
		{
			room1Off();
		}
		break;
	}
	case Room2 :
	{
		u8 state = getOption();
		if(state == on)
		{
			room2On();
		}
		else if(state == off)
		{
			room2Off();
		}

		break;
	}
	case Room3 :
	{
		u8 state = getOption();
		if(state == on)
		{
			room3On();
		}
		else if(state == off)
		{
			room3Off();
		}
		break;
	}
	}
	LCD_WriteCommand(clear);
	options();
}

void rigthPass(void)
{
	LCD_WriteString(" Right Pass");
	_delay_ms(500);
	LCD_WriteCommand(clear);

}


void WrongPass(void)
{
	LCD_WriteString(" Wrong Pass");
	_delay_ms(500);
	LCD_WriteCommand(clear);

}

void ldrCheck(void)
{
	u16 Local_AnaloglValue,Local_DigitalValue;

	DIO_SetPinDirection(PORTB,3,DIO_OUTPUT);
	DIO_SetPinDirection(PORTA,1,DIO_INPUT);
	MADC_voidInit();
	u16 reading = MADC_u8StartConversion(ADC_CHANNEL_1);
	u16 volt_reading =((reading*5000UL)/1024);

	if(volt_reading > 3500)
	{
		room1On();
		room2On();
		room3On();
	}

	else
	{
		room1Off();
		room2Off();
		room3Off();
	}




}

void ControlFan(void)
{
	u16 Local_AnaloglValue,Local_DigitalValue;
	DIO_SetPinDirection(PORTA,0,DIO_INPUT);
	MADC_voidInit();
	DIO_SetPinDirection(PORTB,3,DIO_OUTPUT);



	Local_DigitalValue = MADC_u8StartConversion(0);
	Local_AnaloglValue = (Local_DigitalValue * 5000UL)/1024;
	//u8 s = stateShow(PORTA ,0);
	if(Local_AnaloglValue>430 && state!=0 )
	{
		TIMER1_INT();
		PWM_INIT_FAST();
		PWM_CTC_VALUE((Local_AnaloglValue/10)*3);
		_delay_ms(5);
	}
	else
	{
		DIO_SetPinDirection(PORTB,3,DIO_INPUT);
		PWM_CTC_VALUE(0);
	}



}

void keypadinit(void)
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
	DIO_SetPinDirection(PORTA,1,DIO_OUTPUT);
	DIO_SetPinDirection(PORTD,2,DIO_INPUT);
	DIO_SetPinDirection(PORTA,2,DIO_OUTPUT);
	DIO_SetPinDirection(PORTD,3,DIO_INPUT);
	GI_Enable();
	SetCallBack(&ldrCheck,EXT_INT0);
	SetCallBack(&ControlFan,EXT_INT1);
	ExtEnable(EXT_INT0,EXT_ANY_LOGICAL);
	ExtEnable(EXT_INT1,EXT_ANY_LOGICAL);

}
