/*===================================================================================================*/
/*  File        : LCD_Interface.h                                                                    */
/*  Description : This interface file includes LCD Driver prototypes and declarations for Atmega32   */
/*  Author      : Ahmed Bahaa Taha Nasr. Embedded SW Engineer                                        */
/*  Date        : 28/3/2023                                                                          */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-bahaa1/                                          */
/*  Git account : https://github.com/ahmedbahaa11                                                    */
/*  mail        : abahaa14842@gmail.com                                                              */
/*===================================================================================================*/

/* File Gaurd by ifndef & endif */
#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

#define    LINE_1               0
#define    LINE_2               1

#define    PATTERN_0        0b01000000    // address of First Byte at Sequence 0 at CGRAM            
#define    PATTERN_1        0b01001000    // address of First Byte at Sequence 1 at CGRAM            
#define    PATTERN_2        0b01010000    // address of First Byte at Sequence 2 at CGRAM
#define    PATTERN_3        0b01011000    // address of First Byte at Sequence 3 at CGRAM
#define    PATTERN_4        0b01100000    // address of First Byte at Sequence 4 at CGRAM
#define    PATTERN_5        0b01101000    // address of First Byte at Sequence 5 at CGRAM
#define    PATTERN_6        0b01110000    // address of First Byte at Sequence 6 at CGRAM
#define    PATTERN_7        0b01111000    // address of First Byte at Sequence 7 at CGRAM


/*==============================================================================================*/
/**************************    A.BAHAA LCD Functions Implementations     ************************/
/*==============================================================================================*/
/********************************** [1]  LCD_voidInit                  **************************/
/********************************** [2]  LCD_voidWriteCommand          **************************/
/********************************** [3]  LCD_voidWriteChar             **************************/
/********************************** [4]  LCD_voidWriteString           **************************/
/********************************** [5]  LCD_voidWrite_u32Number       **************************/
/********************************** [6]  LCD_voidGoTo_XY               **************************/
/********************************** [7]  LCD_voidDrawPattern           **************************/
/********************************** [8] LCD_voidWritePattern           **************************/ 
/********************************** [9]  LCD_voidClearDisplay          **************************/
/********************************** [10]  LCD_voidClearGrid            **************************/
/********************************** [11] LCD_voidClearLine             **************************/
/********************************** [12] LCD_voidShiftLeft             **************************/
/********************************** [13] LCD_voidShiftRight            **************************/
/*==============================================================================================*/


/*****************************************************************************************/
/* Function Name : [1] LCD_voidInit                                                      */
/* Description : Initialized the LCD                                                     */
/* Fun. Return : void                                                                    */
/*****************************************************************************************/
void LCD_voidInit (void);
/*****************************************************************************************/
/* Function Name : [2]  LCD_voidWriteCommand                                             */
/* Description : Send a Command to the LCD                                               */
/* Fun. Argument1: Copy_u8Command                                                        */
/* Fun. Return : void                                                                    */
/*****************************************************************************************/
void LCD_voidWriteCommand ( u8 Copy_u8Command );
/*****************************************************************************************/
/* Function Name : [3] LCD_voidWriteChar                                                 */
/* Description : Send a Data to the LCD   ( Character Data )                             */
/* Fun. Argument1: Copy_u8Char                                                           */
/* Fun. Return : void                                                                    */
/*****************************************************************************************/
void LCD_voidWriteChar ( u8 Copy_u8Char );
/*****************************************************************************************/
/* Function Name : [4] LCD_voidWriteString                                               */
/* Description : Send a Data of String to the LCD                                        */
/* Fun. Argument1: *Copy_u8Arr      ( String Data | array of character )                 */
/* Fun. Return : void                                                                    */
/*****************************************************************************************/
void LCD_voidWriteString (u8 *Copy_u8Arr );
/*****************************************************************************************/
/* Function Name : [5] LCD_voidWrite_u32Number                                           */
/* Description : Send a Long Number  to the LCD                                          */
/* Fun. Argument1: Copy_u32Number     ( unsigned integer number )                        */
/* Fun. Return : void                                                                    */
/*****************************************************************************************/
void LCD_voidWrite_u32Number ( u32 Copy_u32Number);
/**********************************************************************************************/
/* Function Name : [6] LCD_voidGoTo_XY                                                        */
/* Description : Put the AC of DDRAM of LCD at Specifec position to display at this position  */
/* Fun. Argument1: Copy_u8Line    { LINE_1 , LINE_2 }                                         */
/* Fun. Argument2: Copy_u8Position    {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15}                 */
/* Fun. Return : void                                                                         */
/**********************************************************************************************/
void LCD_voidGoTo_XY ( u8 Copy_u8Line , u8 Copy_u8Position );
/*************************************************************************************************************************/
/* Function Name : [7] LCD_voidDrawPattern                                                                               */
/* Description : Draw a Pattern and save it on PATTERN_NUMBER at CGRAM                                                   */
/* Fun.Argument1: Copy_u8Pattern_Number{PATTERN_0,PATTERN_1,PATTERN_2,PATTERN_3,PATTERN_4,PATTERN_5,PATTERN_6,PATTERN_7} */
/* Fun.Argument2: *Copy_u8Arr_Pattern { Address of array for Details of drawing }                                        */
/* Fun. Return : void                                                                                                    */
/*************************************************************************************************************************/
void LCD_voidDrawPattern ( u8 Copy_u8Pattern_Number , u8 *Copy_u8Arr_Pattern );
/*****************************************************************************************/
/* Function Name : [8] LCD_voidWritePattern                                              */
/* Description : Write a Pattern on the LCD at specific Line & Position                  */
/* Fun. Argument1: Copy_u8Pattern {0,1,2,3,4,5,6,7}                                      */
/* Fun. Argument2: Copy_u8Line { LINE_1 , LINE_2 }                                       */
/* Fun. Argument3: Copy_u8Position { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 }             */
/* Fun. Return : void                                                                    */
/*****************************************************************************************/
void LCD_voidWritePattern ( u8 Copy_u8Pattern , u8 Copy_u8Line , u8 Copy_u8Position );
/*****************************************************************************************/
/* Function Name : [9] LCD_voidClearDisplay                                              */
/* Description : Clear all Display of LCD                                                */
/* Fun. Return : void                                                                    */
/*****************************************************************************************/
void LCD_voidClearDisplay (void);
/*****************************************************************************************/
/* Function Name : [10] LCD_voidShiftLeft                                                */
/* Description : Shift Left all Display of LCD                                           */
/* Fun. Return : void                                                                    */
/*****************************************************************************************/
void LCD_voidShiftLeft (void);
/*****************************************************************************************/
/* Function Name : [11] LCD_voidShiftRight                                               */
/* Description : Shift Right all Display of LCD                                          */
/* Fun. Return : void                                                                    */
/*****************************************************************************************/
void LCD_voidShiftRight (void);
/*****************************************************************************************/
/* Function Name : [12] LCD_voidClearGrid                                                */
/* Description : Clear Specific position on LCD                                          */
/* Fun. Argument1: Copy_u8Line { LINE_1 , LINE_2 }                                       */
/* Fun. Argument2: Copy_u8Position { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 }             */
/* Fun. Return : void                                                                    */
/*****************************************************************************************/
void LCD_voidClearGrid ( u8 Copy_u8Line , u8 Copy_u8Position );
/*****************************************************************************************/
/* Function Name : [13] LCD_voidClearLine                                                */
/* Description : Clear Specific LINE on LCD                                              */
/* Fun. Argument1: Copy_u8Line { LINE_1 , LINE_2 }                                       */
/* Fun. Return : void                                                                    */
/*****************************************************************************************/
void LCD_voidClearLine ( u8 Copy_u8Line );







#endif