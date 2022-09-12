#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_
/****************************************************************
 name           : 	ADC_voidInit                        
 description    : 	init ADC  		                                         
 parameter      :   none		                        		     
 return         : 	none                                                                               
****************************************************************/
void MADC_voidInit(void);


/****************************************************************
 name           : 	ADC_u8StartConversion                        
 description    : 	return ADC converstion result  		                                         
 parameter      :   Copy_u8Channel -> to select channel(0 -> 7)		                        		     
 return         : 	u8 channel result                                                                               
****************************************************************/
u16 MADC_u8StartConversion(u8 Copy_u8Channel);

/****************************************************************
 define channel options 
****************************************************************/
#define ADC_CHANNEL_0 0
#define ADC_CHANNEL_1 1
#define ADC_CHANNEL_2 2
#define ADC_CHANNEL_3 3
#define ADC_CHANNEL_4 4
#define ADC_CHANNEL_5 5
#define ADC_CHANNEL_6 6
#define ADC_CHANNEL_7 7

#endif 
