#include <util/delay.h>
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO/DIO_Interface.h"
#include "../MCAL/ADC/ADC_Interface.h"
#include "../HAL/LCD/LCD_Interface.h"

int main(void)
{
	u16 DigitalValue = 0;
	u16 AnalogValue = 0;
	u16 TempValue = 0;
	LCD_voidInit();
	ADC_voidInit();
	DIO_voidSetPinDirection(PORTB,PIN0,OUTPUT);
	DIO_voidSetPinValue(PORTB,PIN0,HIGH);
	while(1)
	{
		DigitalValue = ADC_u16ReadSynchronus(ADC0);
		AnalogValue = (DigitalValue * 5000UL) / 1024UL;
		LCD_voidClearDisplay();
		LCD_voidGoTo_XY(0,0);
		LCD_voidWriteString("POT = ");
		LCD_voidWrite_u32Number(AnalogValue);
		LCD_voidWriteString(" mv");

		DigitalValue = ADC_u16ReadSynchronus(ADC1);
		AnalogValue  = (DigitalValue * 5000UL) / 1024UL;
		TempValue    =  AnalogValue / 10UL;
		LCD_voidGoTo_XY(1,0);
		LCD_voidWriteString("T = ");
		LCD_voidWrite_u32Number(TempValue);
		LCD_voidWriteString(" C");


		DigitalValue = ADC_u16ReadSynchronus(ADC2);
		AnalogValue = (DigitalValue * 5000UL) / 1024UL;
		LCD_voidWriteString(" - A=");
		LCD_voidWrite_u32Number(AnalogValue);
		if(AnalogValue >= 2000UL) {
			DIO_voidSetPinValue(PORTB,PIN0,HIGH);
		} else {
			DIO_voidSetPinValue(PORTB,PIN0,LOW);
		}
		_delay_ms(300);
	}
	return 0 ;
}
