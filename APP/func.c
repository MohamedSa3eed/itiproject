#include "config.h"
#include "../MCAL/DIO/DIO_INTERFACE.h"
#include "../MCAL/EXT/EXT_INTERFACE.h"
#include "../MCAL/TIMER/TIMER_INTERFACE.h"
#include "../MCAL/GI/GI_INTERFACE.h"
#include "../HAL/LCD/LCD_INTERFACE.h"
#include "../HAL/KEYPAD/KPD_PRIVATE.h"
#include "../MCAL/ADC/ADC_INTERFACE.h"
#include "../HAL/LCD/LCD_CONFIG.h"
#include "avr/delay.h"

#include "../HAL/KEYPAD/KPD_CONFIG.h"
#include "../HAL/KEYPAD/KPD_INTERFACE.h"
void openDoor(void);
void openFan(void);
u8 getOption(void);
u32 getPass(void);
u8 Login(void);
void loginInit(void);
void roomOptions(void);
u8 checkUser1Pass(void);
u8 checkUser2Pass(void);
u8 checkUser3Pass(void);
void room1On(void);
void room1Off(void);
void room2On(void);
void room2Off(void);
void room3On(void);
void room3Off(void);
void options(void);
void WrongPass(void);
void rigthPass(void);
void wrongOption(void);
void closeFan(void);
void ldrCheck(void);

u32 savedpass1 = 1111;
u32 savedpass2 = 2222;
u32 savedpass3 = 0000;

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
	PWM_CTC_VALUE(0);
}

u8 Login(void)
{
	loginInit();
	ldrCheck();
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
		wrongOption();
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
		break ;
	}

	case  Back :
	{
		Login();
		break ;
	}
	default:
	{
		LCD_WriteString(" Wrong Option");
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
	default :
	{
		wrongOption();
	}
	}
	LCD_WriteCommand(clear);
	options();
}

void rigthPass(void)
{
	LCD_WriteString(" Right Pass");
	_delay_ms(1000);
	LCD_WriteCommand(clear);

}


void WrongPass(void)
{
	LCD_WriteString(" Wrong Pass");
	_delay_ms(1000);
	LCD_WriteCommand(clear);

}
void ldrCheck()
{
	u16 reading = MADC_u8StartConversion(ADC_CHANNEL_1);
		u16 volt_reading =((reading*5000UL)/1024);
		if(volt_reading < 3000 )
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
void wrongOption(void)
{
	LCD_WriteString("Wrong Option");
			_delay_ms(100);
	LCD_WriteCommand(clear);
}

