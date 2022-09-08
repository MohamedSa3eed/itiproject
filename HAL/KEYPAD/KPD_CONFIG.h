#ifndef KPD_CONFIG_H
#define KPD_CONFIG_H

//port that KPD is connected to :
#define KPD_PORT    PORTC

// flag for not pressing on KPD :
#define KPD_NOT_PRESSED 0xff

// KPD values configuration :
#define KPD_VALUES {  {7,8,9,'/'} , {4,5,6,'x'} , {1,2,3,'-'} , {0,0,'=','+'} }

// columns configuration :
#define KPD_COLUMN0_PIN 		DIO_PIN0
#define KPD_COLUMN1_PIN		    DIO_PIN1
#define KPD_COLUMN2_PIN 		DIO_PIN2
#define KPD_COLUMN3_PIN 		DIO_PIN3

//rows configuration :
#define KPD_ROW0_PIN 			DIO_PIN4
#define KPD_ROW1_PIN 			DIO_PIN5
#define KPD_ROW2_PIN 			DIO_PIN6
#define KPD_ROW3_PIN			DIO_PIN7


#endif
