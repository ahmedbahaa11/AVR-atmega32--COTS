#include<util/delay.h>
/* Include Header Files From LIB */
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
/* Include Header Files From MCAL Layer */
#include"../MCAL/DIO/DIO_Interface.h"
#include"../MCAL/GIE/GIE_Interface.h"
#include"../MCAL/USART/USART_Interface.h"
/* Include Header Files From HAL Layer */
#include"../HAL/LED/LED_Interface.h"
u8 Recieved = 0;
void txIndication (void);

int main()
{

	USART_voidInit ();
	GIE_void_GI_Enable(ON);
	LED_voidInit_Led_Pin(PORTC,PIN0);
	LED_voidInit_Led_Pin(PORTC,PIN1);
	DIO_voidSetPinValue(PORTC,PIN0,LOW);
	USART_voidSendData('A');USART_voidSendData('h');USART_voidSendData('m');USART_voidSendData('e');USART_voidSendData('d');USART_voidSendData(' ');
	USART_voidSendData('B');USART_voidSendData('a');USART_voidSendData('h');USART_voidSendData('a');USART_voidSendData('a');USART_voidSendData(' ');
	USART_voidSendData('-');USART_voidSendData('-');USART_voidSendData('-');USART_voidSendData('>');USART_voidSendData('>');USART_voidSendData(' ');


	while(1)
	{
		// USART_voidSendData(',');
		USART_voidAsyncSendData(',',txIndication);
		_delay_ms(1000);
		// USART_voidRecieveData(&Recieved);
		USART_voidAsyncRecieveData (&Recieved);
		if (Recieved == 's' )
		{
			DIO_voidSetPinValue(PORTC,PIN0,HIGH);
			_delay_ms(100);
			DIO_voidSetPinValue(PORTC,PIN0,LOW);
			Recieved = 0 ;
		}
	}
}

void txIndication (void)
{
	DIO_voidSetPinValue(PORTC,PIN1,HIGH);
	_delay_ms(100);
	DIO_voidSetPinValue(PORTC,PIN1,LOW);
}