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
#include "../MCAL/ICU/ICU_Interface.h"
#include "../HAL/SERVO_MOTOR/SERVO_Interface.h"
#include "../HAL/LCD/LCD_Interface.h"
u32 Global_u16PeriodTime = 0;
u32 Global_ONTime = 0;
void action1(void);
int main(void)
{
	DIO_voidSetPinDirection(PORTB,PIN3,OUTPUT);		// 0C0
	DIO_voidSetPinDirection(PORTD,PIN6,INPUT);		// ICP1
	DIO_voidSetPinDirection(PORTA,PIN0,OUTPUT);
	TIMER0_voidInit();
	TIMER0_voidsetDutyCycle_PWM ( 50 );
	// TIMER0_voidBahaaPWM ( 100 );
	ICU_voidInit ();
	ICU_SetOutputMembers(&Global_u16PeriodTime, &Global_ONTime);
	LCD_voidInit();
	GIE_void_GI_Enable(ON);

	while(1)
	{
		while( Global_ONTime != 0 || Global_u16PeriodTime != 0  );
		LCD_voidGoTo_XY(0,0);
		LCD_voidWriteString("ON T = ");
		LCD_voidWrite_u32Number(Global_ONTime);
		LCD_voidGoTo_XY(1,0);
		LCD_voidWriteString("P T =  ");
		LCD_voidWrite_u32Number(Global_u16PeriodTime);
	}
	
	// SERVO_voidRotateSpecificAngle_OC1A(90);
	// while(1)
	// {
	// 	for(u8 i = 0; i < 180 ; i++)
	// 	{
	// 		SERVO_voidRotateSpecificAngle_OC1A(i);
	// 		_delay_ms(50);
	// 	}
	// }
	return 0 ;
}

void action1(void)
{
	LED_voidToggle_Led_Pin(PORTC,PIN1);
}
