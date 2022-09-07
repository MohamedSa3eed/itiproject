#include "../LIB/STD_TYPES.h"
#include </usr/avr/include/avr/delay.h>
#include "../MCAL/DIO/DIO_INTERFACE.h"
#include "../HAL/LCD/LCD_INTERFACE.h"
#include "../HAL/LCD/LCD_CONFIG.h"
#include "../HAL/KPD/KPD_INTERFACE.h"
#include "../HAL/KPD/KPD_CONFIG.h"

#define TRIES 3 
#define PASS_LONG 4
typedef enum 
{
	user1 =1 ,
	user2 =2 ,
	user3 =3 
}USER;

typedef enum
{
	Rooms =1 ,
	Door  =2 ,
	Air   =3 ,
	Back  =4
}OPTIONS;
typedef enum
{
	Room1 =1 ,
	Room2 =2 ,
	Room3 =3
}ROOMS;
typedef enum
{
	on  =1 ,
	off =2
}STATE;
u32 savedpass1 = 1111;
u32 savedpass2 = 2222;
u32 savedpass3 = 0000;

u8 Login();
u8 checkUser1Pass();
u8 checkUser2Pass();
u8 checkUser3Pass();
void options();
u8 getOption();
u32 getPass();


int main ()
{
	// columns pin direction as output
	DIO_SetPinDiriction(KPD_PORT, KPD_COLUMN0_PIN, OUTPUT);
	DIO_SetPinDiriction(KPD_PORT, KPD_COLUMN1_PIN, OUTPUT);
	DIO_SetPinDiriction(KPD_PORT, KPD_COLUMN2_PIN, OUTPUT);
	DIO_SetPinDiriction(KPD_PORT, KPD_COLUMN3_PIN, OUTPUT);

	// rows pins direction as input
	DIO_SetPinDiriction(KPD_PORT, KPD_ROW0_PIN, INPUT );
	DIO_SetPinDiriction(KPD_PORT, KPD_ROW1_PIN, INPUT );
	DIO_SetPinDiriction(KPD_PORT, KPD_ROW2_PIN, INPUT );
	DIO_SetPinDiriction(KPD_PORT, KPD_ROW3_PIN, INPUT );

	// setting all high
	DIO_SetPortValue(KPD_PORT, PORT_HIGH);

	//rooms
	DIO_SetPinDiriction(PORTB, PIN4, OUTPUT);
	DIO_SetPinDiriction(PORTB, PIN5, OUTPUT);
	DIO_SetPinDiriction(PORTB, PIN6, OUTPUT);


	LCD_Init();
	u8 flag =0 ;
	while (flag ==0 )
	{ flag = Login();}




	return 0;
}
u8 Login()
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
	u8 user = getOption();  //get user from keypad
	LCD_WriteCommand(clear);
	LCD_GoToXY(0, 0);
	switch (user)
	{
	case user1:
	{
		if (checkUser1Pass() == 1)
		{
			LCD_WriteString("Right Pass");
			_delay_ms(100);
			LCD_WriteCommand(clear);
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
			LCD_WriteString("Right Pass");
			_delay_ms(100);
			LCD_WriteCommand(clear);
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
			LCD_WriteString("Right Pass");
			_delay_ms(100);
			LCD_WriteCommand(clear);
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
		_delay_ms(100);
		return 0 ;
	}

}

u8 checkUser1Pass()
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
			LCD_WriteString("Wrong Pass");
			_delay_ms(100);
			LCD_WriteCommand(clear);
			tries -- ;
		}
	}
	return 0;
}

u8 checkUser2Pass()
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
			LCD_WriteString("Wrong Pass");
			_delay_ms(100);
			LCD_WriteCommand(clear);
			tries -- ;
		}
	}
	return 0;
}

u8 checkUser3Pass()
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
			LCD_WriteString("Wrong Pass");
			_delay_ms(100);
			LCD_WriteCommand(clear);
			tries -- ;
		}
	}
	return 0;
}
void options()
{
	LCD_WriteString("1-Rooms 2-Door");
	LCD_GoToXY(1, 0);
	LCD_WriteString("3-Air   4-Back");
	u8 option = getOption();
	LCD_WriteCommand(clear);
	switch (option)
	{
	case Rooms :
	{
		roomOptions();
		break;
	}
	case Door :
	{
	//	DoorOptions();
		break ;
	}
	case Air :
	{
		//airOptions();
		break ;
	}
	case  Back :
	{
		Login();
		break ;
	}
	default:
	{
		LCD_WriteString("Wrong Option");
		LCD_WriteCommand(clear);
		options();
	}
	}
	LCD_GoToXY(0, 0);

}
u8 getOption()
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
u32 getPass()
{
	u32 pass = 0;
	u8 passLong = PASS_LONG ;
	LCD_WriteString("Pass : ");
	while(passLong-- )
	{
		pass *=10 ; //to put the next cahracter in the next place
		pass += getOption() ;
		LCD_WriteData('*');
		_delay_ms(50);
	}
	LCD_WriteCommand(clear);
	return pass ;
}
void room1On()
{
	DIO_SetPinValue(PORTB, PIN4, HIGH);
}
void room1Off()
{
	DIO_SetPinValue(PORTB, PIN4, LOW);
}
void room2On()
{
	DIO_SetPinValue(PORTB, PIN5, HIGH);
}
void room2Off()
{
	DIO_SetPinValue(PORTB, PIN5, LOW);
}
void room3On()
{
	DIO_SetPinValue(PORTB, PIN6, HIGH);
}
void room3Off()
{
	DIO_SetPinValue(PORTB, PIN6, LOW);
}
void roomOptions()
{
	LCD_WriteString("1-Room1  2-Room2");
	LCD_GoToXY(1, 0);
	LCD_WriteString("3-Room3  ");
	u8 option = getOption();
	LCD_WriteCommand(clear);
	LCD_WriteString("1-on   2-off");
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
