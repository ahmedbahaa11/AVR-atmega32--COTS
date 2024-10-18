/*
 * traffic_light.c
 *
 * Created: 10/18/2024 10:06:24 PM
 * Author : Mostafa Samir
 */ 
#define F_CPU 8000000UL
#include <util/delay.h>
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO/DIO_Interface.h"
#include "../HAL/LED/LED_Interface.h"
#include "../HAL/LCD/LCD_Interface.h"
#include "../MCAL/DIO/DIO_Interface.h"

int main(void)
{	
	LED_voidInit_Led_Pin (PORTA,PIN0); //RED
	LED_voidInit_Led_Pin (PORTA,PIN1); //YELLOW
	LED_voidInit_Led_Pin (PORTA,PIN2); //GREEN
	
	// Config_Pull_Up_Pin
	DIO_voidSetPinDirection(PORTB,PIN0,INPUT);
	DIO_voidSetPinValue(PORTB,PIN0,HIGH);
	
    LCD_voidInit ();
	LCD_voidGoTo_XY (0,0);
	LCD_voidWriteString (" Eng :");
	LCD_voidGoTo_XY (1,0);
	LCD_voidWriteString ("Mostafa Samir");
	 _delay_ms(1000);
    while (1) 
    {
		
		u8 button = DIO_u8GetPinValue(PORTB,PIN0);
		if (button == 1)
		{
			
			//
			LCD_voidClearDisplay ();
			LCD_voidGoTo_XY (0,0);
			LCD_voidWriteString (" RED ON");
			
			LED_voidStatus_Led_Pin(PORTA,PIN0,ON);
			_delay_ms(500);
			LED_voidStatus_Led_Pin(PORTA,PIN0,OFF);	
					
		}
		else
		{
			
			//
			LCD_voidClearDisplay ();
			LCD_voidGoTo_XY (0,0);
			LCD_voidWriteString (" YELLOW ON");
			
			LED_voidStatus_Led_Pin(PORTA,PIN1,ON);
			_delay_ms(500);
			LED_voidStatus_Led_Pin(PORTA,PIN1,OFF);
			
		}		
		
    }
}

