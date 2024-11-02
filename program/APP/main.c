#include <util/delay.h>
#include <stdbool.h>
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO/DIO_Interface.h"
#include "../HAL/LED/LED_Interface.h"
#include "../MCAL/TIMERS/TIMER0/TIMER0_Interface.h"
#include "../MCAL/GIE/GIE_Interface.h"
#include "../MCAL/WDT/WDT_Interface.h"

void action1(void);
int main(void)
{
	TIMER0_voidInit();
	// GIE_void_GI_Enable(ON);
	LED_voidInit_Led_Pin(PORTB,PIN3);

	// LED_voidInit_Led_Pin(PORTC,PIN0);
	// LED_voidStatus_Led_Pin(PORTC,PIN0,ON);
	// LED_voidInit_Led_Pin(PORTC,PIN1);
	// LED_voidStatus_Led_Pin(PORTC,PIN1,ON);
	// bool flag = true;
	TIMER0_voidsetDutyCycle_PWM(90);
	while(1)
	{
		// LED_voidToggle_Led_Pin(PORTC,PIN0);
		// TIMER0_delay_ms(200);
		// LED_voidToggle_Led_Pin(PORTC,PIN0);
		// TIMER0_delay_ms(200);
		// LED_voidToggle_Led_Pin(PORTC,PIN0);
		// TIMER0_delay_ms(200);
		// LED_voidToggle_Led_Pin(PORTC,PIN0);
		// TIMER0_delay_ms(200);
		// while(flag)
		// {

		// }
	}
	return 0 ;
}

void action1(void)
{
	LED_voidToggle_Led_Pin(PORTC,PIN1);
}
