#include <util/delay.h>
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO/DIO_Interface.h"
#include "../MCAL/TIMERS/TIMER0/TIMER0_Interface.h"
#include "../HAL/LED/LED_Interface.h"
#include "../MCAL/GIE/GIE_Interface.h"

void action_OV(void);
int main(void)
{
	GIE_void_GI_Enable(ON);
	TIMER0_voidInit();
	LED_voidInit_Led_Pin(PORTB,PIN0);
	TIMER0_voidSetCallBack_OVF(action_OV,20);
	while(1)
	{

	}
	return 0 ;
}

void action_OV(void)
{
	LED_voidToggle_Led_Pin(PORTB,PIN0);
}
