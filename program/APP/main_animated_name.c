/*
 * lcd_animation.c
 *
 * Created: 10/19/2024 12:20:12 AM
 * Author : Mostafa Samir
 */ 


#define F_CPU 8000000UL
#include <util/delay.h>
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO/DIO_Interface.h"
#include "../HAL/LCD/LCD_Interface.h"

u8 shape0[8] = {0b00100,0b00100,0b01010,0b10101,0b10101,0b01110,0b10001,0b10001};
u8 shape1[8] = {0b00100,0b01110,0b11111,0b11111,0b10101,0b00100,0b01110,0b01010};
u8 name_arr[12] = {' ','E','n','g','/','M','o','s','t','a','f','a'};
int main(void)
{
	LCD_voidInit();
	
	
	u8 position = 0;
	u8 max_position = 16; // 16x2 LCD

	while (1)
	{
		// move text from left to right
		for (position = 0; position <= max_position; position++) 
		{	
			// Set cursor position and move
			LCD_voidGoTo_XY(0, position);

			// write "Eng / Mostafa"
			for (u8 i = 0; i <= 12; i++)
			{
				
				LCD_voidWriteChar(name_arr[i]);
			}
			
			_delay_ms(300);
		}
	}
}


