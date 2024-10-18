/*
 * calc.c
 *
 * Created: 10/18/2024 6:14:22 PM
 * Author : Mostafa Samir
 */

#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/io.h>
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO/DIO_Interface.h"
#include "../HAL/LCD/LCD_Interface.h"
#include "../HAL/KPAD/KPAD_Interface.h"

// Function Prototypes
u8 performCalculation(u8 num1, u8 num2, char operator);

int main(void) {
    KPAD_voidInit();
    LCD_voidInit();
    LCD_voidWriteString(" Press # to Start");
   

    while (1) {
        char key = KPAD_u8GetPressedKey();
        if (key == '#') {  // Start calculation
            LCD_voidClearDisplay();
            LCD_voidWriteString(" Calculator");
            _delay_ms(1000);
            LCD_voidClearDisplay();

            while (1) {
                // Read first number
                u8 num1 = KPAD_u8GetPressedKey(); 
                LCD_voidWrite_u32Number(num1); // Display first number

                // Read operator
                char operator = KPAD_u8GetPressedKey();
                LCD_voidWriteChar(operator); // Display operator

                // Read second number
                u8 num2 = KPAD_u8GetPressedKey() ; 
                LCD_voidWrite_u32Number(num2); // Display second number

                // Wait for '=' key to calculate and display the result
                char equalKey = KPAD_u8GetPressedKey();
                if (equalKey == '=') {
                    u8 result = performCalculation(num1, num2, operator); // Perform calculation
                    
                    // Display result on LCD
                    LCD_voidClearDisplay();
                    LCD_voidWriteString(" Res: ");
                    LCD_voidWrite_u32Number(result); // Display the result
                    _delay_ms(2000); // Show result for 2 seconds
                    LCD_voidClearDisplay();
                }
            }
        }
    }
}

u8 performCalculation(u8 num1, u8 num2, char operator) {
    switch (operator) {
        case '+': return num1 + num2;
        case '-': return num1 - num2;
        case '*': return num1 * num2;
        case '/': return (num2 != 0) ? (num1 / num2) : 0; // Handle division by zero
        default: return 0; // Invalid operator
    }
}
