#include <util/delay.h>
#include <stdbool.h>
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO/DIO_Interface.h"
#include "../HAL/LED/LED_Interface.h"
#include "../HAL/LCD/LCD_Interface.h"
#include "../MCAL/TIMERS/TIMER0/TIMER0_Interface.h"
#include "../MCAL/TIMERS/TIMER1/TIMER1_Interface.h"
#include "../MCAL/GIE/GIE_Interface.h"
#include "../MCAL/WDT/WDT_Interface.h"
#include "../MCAL/ICU/ICU_Interface.h"
#include "../HAL/SERVO_MOTOR/SERVO_Interface.h"
u32 Global_u16PeriodTime = 0;
u32 Global_ONTime = 0;
int main(void)
{
	DIO_voidSetPinDirection(PORTB,PIN3,OUTPUT);		// 0C0
	DIO_voidSetPinDirection(PORTD,PIN6,INPUT);		// ICP1
	DIO_voidSetPinDirection(PORTA,PIN0,OUTPUT);
	DIO_voidSetPinDirection(PORTD,PIN5,OUTPUT);     // OC1A

	LCD_voidInit();
	TIMER1_voidInit();
	ICU_voidInit ();
	ICU_GetOutputs(&Global_u16PeriodTime, &Global_ONTime);
	GIE_void_GI_Enable(ON);
	TIMER0_voidInit();
	TIMER0_voidsetDutyCycle_PWM ( 75 );

	while(1)
	{
		LCD_voidGoTo_XY(0,0);
		LCD_voidWriteString("ON T = ");
		LCD_voidWrite_u32Number(Global_ONTime);
		LCD_voidGoTo_XY(1,0);
		LCD_voidWriteString("P T =  ");
		LCD_voidWrite_u32Number(Global_u16PeriodTime);
	}
	
	return 0 ;
}
