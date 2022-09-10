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



#ifndef APP_INTERFACE_H_
#define APP_INTERFACE_H_

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
void ldrCheck(void);
void room3On(void);
void room3Off(void);
void options(void);
void WrongPass(void);
void rigthPass(void);
void closeFan(void);
void ldrCheck(void);
void ControlFan(void);
void keypadinit(void);
#endif /* APP_INTERFACE_H_ */
