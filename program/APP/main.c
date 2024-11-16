#include <util/delay.h>
#include <stdbool.h>
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO/DIO_Interface.h"
#include "../HAL/LED/LED_Interface.h"
#include "../MCAL/TIMERS/TIMER0/TIMER0_Interface.h"
#include "../MCAL/TIMERS/TIMER1/TIMER1_Interface.h"
#include "../MCAL/GIE/GIE_Interface.h"
#include "../MCAL/WDT/WDT_Interface.h"
#include "../HAL/SERVO_MOTOR/SERVO_Interface.h"

void action1(void);
int main(void)
{
	// TIMER0_voidInit();
	TIMER1_voidInit();
	// GIE_void_GI_Enable(ON);

	SERVO_voidRotateSpecificAngle_OC1A(90);
	while(1)
	{
		for(u8 i = 0; i < 180 ; i++)
		{
			SERVO_voidRotateSpecificAngle_OC1A(i);
			_delay_ms(50);
		}
	}
	return 0 ;
}

void action1(void)
{
	LED_voidToggle_Led_Pin(PORTC,PIN1);
}
