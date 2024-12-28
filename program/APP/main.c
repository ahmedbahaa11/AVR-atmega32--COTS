#include <util/delay.h>
#include <stdbool.h>
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO/DIO_Interface.h"
#include "../HAL/LED/LED_Interface.h"
#include "../MCAL/WDT/WDT_Interface.h"

int main(void)
{
	DIO_voidSetPinDirection(PORTA, PIN0, OUTPUT);
	DIO_voidSetPinDirection(PORTA, PIN1, OUTPUT);
	DIO_voidSetPinValue(PORTA, PIN0, LOW);
	DIO_voidSetPinValue(PORTA, PIN1, HIGH);
	_delay_ms(2000);
	DIO_voidSetPinValue(PORTA, PIN1, LOW);
	while(1)
	{
		// Code

		WDT_voidEnable();
			for(u8 i = 0; i < 10 ; i++)
			{
				DIO_voidTogglePinValue(PORTA, PIN0);
				_delay_ms(100);
			}
			WDT_voidReset();
		WDT_voidDisable();

		for(u8 i = 0; i < 40 ; i++)
		{
			DIO_voidTogglePinValue(PORTA, PIN1);
			_delay_ms(100);
		}
	}
	return 0 ;
}
