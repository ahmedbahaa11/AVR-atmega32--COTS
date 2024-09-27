#define F_CPU 8000000UL
#include "../LIB/STD_TYPES.h"
#include "../SRV/FreeRTOS/FreeRTOS.h"
#include "../SRV/FreeRTOS/task.h"
#include "../MCAL/DIO/DIO_Interface.h"
#include "../HAL/LED/LED_Interface.h"
void Func1 (void);
void Func2 (void);
void Func3 (void);
int main(void)
{
	DIO_voidSetPinDirection(PORTC,PIN0,OUTPUT);
	DIO_voidSetPinDirection(PORTC,PIN1,OUTPUT);
	DIO_voidSetPinDirection(PORTC,PIN2,OUTPUT);
	xTaskCreate( &Func1 , NULL , 200 , NULL , 0 , NULL );
	xTaskCreate( &Func2 , NULL , 200 , NULL , 1 , NULL );
	xTaskCreate( &Func3 , NULL , 200 , NULL , 2 , NULL );
	vTaskStartScheduler();
	while(1)
	{
	}
	return 0 ;
}
void Func1 (void)
{
	while(1)
	{
		LED_voidToggle_Led_Pin(PORTC,PIN0);
		vTaskDelay( 1000 );
	}
}
void Func2 (void)
{
	while(1)
		{
		LED_voidToggle_Led_Pin(PORTC,PIN1);
			vTaskDelay( 2000 );
		}
}
void Func3 (void)
{
	while(1)
	{
		LED_voidToggle_Led_Pin(PORTC,PIN2);
		vTaskDelay( 3000 );
	}
}
