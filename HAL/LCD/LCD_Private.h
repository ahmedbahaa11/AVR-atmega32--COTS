/*=================================================================================*/
/*  File        : LCD_Private.h                                                    */
/*  Description : This Private file includes LCD Driver macros for Atmega32        */
/*  Author      : Ahmed Bahaa Taha Nasr. Embedded SW Engineer                      */
/*  Date        : 28/3/2023                                                        */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-bahaa1/                        */
/*  Git account : https://github.com/ahmedbahaa11                                  */
/*  mail        : ahmedbahaataha7@gmil.com                                         */
/*=================================================================================*/

/* File Gaurd by ifndef & endif */
#ifndef LCD_PRIVATE_H
#define LCD_PRIVATE_H

/* Private Macros */

#define   FS_8BIT_2LINES_5x10               0b00111100   // Function Set { 8 BIT, 2 LINES, 5x10 }
#define   FS_4BIT_2LINES_5x10               0b00101100   // Function Set { 4 BIT, 2 LINES, 5x10 } 
#define   FS_8BIT_2LINES_5x7                0b00111000   // Function Set { 8 BIT, 2 LINES, 5x7 } 
#define   FS_4BIT_2LINES_5x7                0b00101000   // Function Set { 4 BIT, 2 LINES, 5x7 }
#define   DIS_ON_NO_CURSER                  0b00001100   // Display ON & NO Curser 
#define   DIS_ON_YES_CURSER                 0b00001110   // Display ON & YES Curser & NO Blinking Curser
#define   DIS_ON_Blinking_CURSER            0b00001111   // Display ON & YES Curser & YES Blinking Curser
#define   DIS_CLEAR                         0b00000001   // Clear All Display
#define   ENTRY_MODE_INCREASE_LEFT_SHIFT    0b00000111   // Entry Mode Increase and Left shift
#define   ENTRY_MODE_INCREASE_NO_SHIFT      0b00000110   // Entry Mode Increase and No shifting
#define   ENTRY_MODE_DECREASE_RIGHT_SHIFT   0b00000101   // Entry Mode Decrease and Right shift
#define   ENTRY_MODE_DECREASE_NO_SHIFT      0b00000100   // Entry Mode Decrease and No shifting


#endif