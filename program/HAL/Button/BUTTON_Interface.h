/*=====================================================================================================*/
/*  File        : BUTTON_Interface.h                                                                   */
/*  Description : This interface file includes BUTTON Driver prototypes and declarations for Atmega32  */
/*  Author      : Ahmed Bahaa Taha Nasr. Embedded SW Engineer                                          */
/*  Date        : 28/3/2023                                                                            */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-bahaa1/                                            */
/*  Git account : https://github.com/ahmedbahaa11                                                      */
/*  mail        : ahmedbahaataha7@gmil.com                                                             */
/*=====================================================================================================*/

/* File Gaurd by ifndef & endif */
#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H


/*======================================================================================================================*/
/**************************************     A.BAHAA BUTTON Functions Prototypes     *************************************/
/*======================================================================================================================*/
/********************************************    BUTTON_voidInit_Button_Pin        **************************************/
/********************************************    BUTTON_voidInit_8Buttons_Port     **************************************/
/********************************************    BUTTON_u8Get_Button_Pin           **************************************/
/********************************************    BUTTON_u8Get_8Buttons_Port        **************************************/
/*======================================================================================================================*/



/*===================================================================================================*/
/* ===============================       Initilization Modules        ===============================*/
/*===================================================================================================*/
/*****************************************************************************************************/
/* Function Name : BUTTON_voidInit_Button_Pin                                                        */
/* Description : Initialize one push button on specific Port and Pin with optional Pull Up Resistor  */
/* Fun. Argument1: Copy_u8PortNumber { PORTA,PORTB,PORTC,PORTD }                                     */
/* Fun. Argument2: Copy_u8PinNumber { PIN0,PIN1,PIN3,PIN4,PIN5,PIN6,PIN7 }                           */
/* Fun. Argument3: Copy_u8PullUpStatus { ON , OFF }                                                  */
/* Fun. Return : void                                                                                */
/*****************************************************************************************************/
void BUTTON_voidInit_Button_Pin ( u8 Copy_u8PortNumber, u8 Copy_u8PinNumber , u8 Copy_u8PullUpStatus );
/*****************************************************************************************************/
/* Function Name : BUTTON_voidInit_8Buttons_Port                                                     */
/* Description : Initialize string of 8 push buttons on specific port with optional Pull Up Resistor */
/* Fun. Argument1: Copy_u8PortNumber { PORTA,PORTB,PORTC,PORTD }                                     */
/* Fun. Argument3: Copy_u8PullUpStatus { ON , OFF }                                                  */
/* Fun. Return : void                                                                                */
/*****************************************************************************************************/
void BUTTON_voidInit_8Buttons_Port ( u8 Copy_u8PortNumber, u8 Copy_u8PullUpStatus );
/*===================================================================================================*/
/*===================================================================================================*/




/*===================================================================================================*/
/* ====================================       Read Modules        ===================================*/
/*===================================================================================================*/
/*****************************************************************************************************/
/* Function Name : BUTTON_u8Get_Button_Pin                                                           */
/* Description : Read one push button value in a specific Port and Pin                               */
/* Fun. Argument1: Copy_u8PortNumber { PORTA,PORTB,PORTC,PORTD }                                     */
/* Fun. Argument2: Copy_u8PinNumber { PIN0,PIN1,PIN3,PIN4,PIN5,PIN6,PIN7 }                           */
/* Fun. Return : unsigned character { LOW (Button is Pressed) , HIGH (Button is Not Pressed) }       */
/*****************************************************************************************************/
u8 BUTTON_u8Get_Button_Pin (u8 Copy_u8PortNumber, u8 Copy_u8PinNumber );
/*****************************************************************************************************/
/* Function Name : BUTTON_u8Get_8Buttons_Port                                                        */
/* Description : Read String of 8 push buttons value in a given Port                                 */
/* Fun. Argument1: Copy_u8PortNumber { PORTA,PORTB,PORTC,PORTD }                                     */
/* Fun. Return : unsigned character { 0bxxxxxxxx } (x) is a value in an one Pin on the Port          */
/*****************************************************************************************************/
u8 BUTTON_u8Get_8Buttons_Port (u8 Copy_u8PortNumber);
/*===================================================================================================*/
/*===================================================================================================*/


#endif