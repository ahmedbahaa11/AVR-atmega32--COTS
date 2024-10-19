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
		
int main(void)
{
	LCD_voidInit();
	
	LCD_voidGoTo_XY(LINE_1,5);
	LCD_voidWriteString(" Eng / Mostafa");
	_delay_ms(2000);
	LCD_voidClearDisplay();
	
	
	LCD_voidDrawPattern (PATTERN_0,shape0);
	LCD_voidDrawPattern (PATTERN_1,shape1);
	
	LCD_voidDrawPattern (PATTERN_0,shape0);
	LCD_voidWritePattern(0,LINE_2,7);
	
	LCD_voidDrawPattern (PATTERN_1,shape1);
	LCD_voidWritePattern(1,LINE_1,0);
	_delay_ms(200);
	LCD_voidClearGrid(LINE_1,0);
    
	while (1) 
    {	
			
			LCD_voidWritePattern(0,LINE_2,7);
			
		for (u8 i = 0; i <= 14; i++)
		{
			
			LCD_voidWritePattern(1,LINE_2,i);
			_delay_ms(100);
			LCD_voidClearGrid(LINE_2,i-1);
			
			if (i == 6){
				LCD_voidClearGrid(LINE_2,7);
				LCD_voidWritePattern(0,LINE_1,7);
			}
			else if (i == 9){
				LCD_voidClearGrid(LINE_1,7);
				LCD_voidWritePattern(0,LINE_2,7);
			}
			
			if(i == 14){
				for (u8 i = 15; i >0; --i)
				{
					LCD_voidWritePattern(1,LINE_2,i);
					_delay_ms(100);
					LCD_voidClearGrid(LINE_2,i+1);
					
					if (i == 9){
						LCD_voidClearGrid(LINE_2,7);
						LCD_voidWritePattern(0,LINE_1,7);
					}
					else if (i == 6){
						LCD_voidClearGrid(LINE_1,7);
						LCD_voidWritePattern(0,LINE_2,7);
					}
				}
			
			}
		
		}
	}
}

