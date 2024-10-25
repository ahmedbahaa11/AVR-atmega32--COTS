/*===================================================================================================*/
/*  File        : LED_Interface.h                                                                    */
/*  Description : This interface file includes LED Driver prototypes and declarations for Atmega32   */
/*  Author      : Ahmed Bahaa Taha Nasr. Embedded SW Engineer                                        */
/*  Date        : 28/3/2023                                                                          */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-bahaa1/                                          */
/*  Git account : https://github.com/ahmedbahaa11                                                    */
/*  mail        : abahaa14842@gmail.com                                                              */
/*===================================================================================================*/

/* File Gaurd by ifndef & endif */
#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H


/*==============================================================================================*/
/****************************    A.BAHAA LED Functions Prototypes     ***************************/
/*==============================================================================================*/
/**********************************  LED_voidInit_Led_Pin        ********************************/
/**********************************  LED_voidInit_8Leds_Port     ********************************/
/**********************************  LED_voidStatus_Led_Pin      ********************************/
/**********************************  LED_voidStatus_8Leds_Port   ********************************/
/**********************************  LED_voidToggle_Led_Pin      ********************************/
/**********************************  LED_voidToggle_8Leds_Port   ********************************/
/*==============================================================================================*/


/*================================================================================*/
/* =======================       Initilization Modules        ====================*/
/*================================================================================*/
/**********************************************************************************/
/* Function Name : LED_voidInit_Led_Pin                                           */
/* Description : Initialize one LED on specific port and bit                      */
/* Fun. Argument1: Copy_u8PortNumber { PORTA,PORTB,PORTC,PORTD }                  */
/* Fun. Argument2: Copy_u8PinNumber { PIN0,PIN1,PIN3,PIN4,PIN5,PIN6,PIN7 }        */
/* Fun. Return : void                                                             */
/**********************************************************************************/
void LED_voidInit_Led_Pin ( u8 Copy_u8PortNumber, u8 Copy_u8PinNumber );
/**********************************************************************************/
/* Function Name : LED_voidInit_8Leds_Port                                        */
/* Description : Initialize string of 8 LEDs on specific Port                     */
/* Fun. Argument1: Copy_u8PortNumber { PORTA,PORTB,PORTC,PORTD }                  */
/* Fun. Return : void                                                             */
/**********************************************************************************/
void LED_voidInit_8Leds_Port ( u8 Copy_u8PortNumber);
/*================================================================================*/
/*================================================================================*/




/*===================================================================================================*/
/* ================================       Write Status Modules        ===============================*/
/*===================================================================================================*/
/*****************************************************************************************************/
/* Function Name : LED_voidStatus_Led_Pin                                                            */
/* Description : Status of one led Turn on and off                                                   */
/* Fun. Argument1: Copy_u8PortNumber { PORTA,PORTB,PORTC,PORTD }                                     */
/* Fun. Argument2: Copy_u8PinNumber { PIN0,PIN1,PIN3,PIN4,PIN5,PIN6,PIN7 }                           */
/* Fun. Argument3: Copy_u8Status { ON ,OFF }                                                         */
/* Fun. Return : void                                                                                */
/*****************************************************************************************************/
void LED_voidStatus_Led_Pin ( u8 Copy_u8PortNumber, u8 Copy_u8PinNumber, u8 Copy_u8Status );
/*****************************************************************************************************/
/* Function Name : LED_voidStatus_8Leds_Port                                                         */
/* Description : Status of string of 8 Leds Turn on and off                                          */
/* Fun. Argument1: Copy_u8PortNumber { PORTA,PORTB,PORTC,PORTD }                                     */
/* Fun. Argument3: Copy_u8Status { ON ,OFF }                                                         */
/* Fun. Return : void                                                                                */
/*****************************************************************************************************/
void LED_voidStatus_8Leds_Port ( u8 Copy_u8PortNumber, u8 Copy_u8Status );
/*===================================================================================================*/
/*===================================================================================================*/




/*====================================================================================*/
/* =========================       Toggle Status Modules        ======================*/
/*====================================================================================*/
/**************************************************************************************/
/* Function Name : LED_voidToggle_Led_Pin                                             */
/* Description : Toggle the Status of one led from Turn ON to OFF & from OFF to ON    */
/* Fun. Argument1: Copy_u8PortNumber { PORTA,PORTB,PORTC,PORTD }                      */
/* Fun. Argument2: Copy_u8PinNumber { PIN0,PIN1,PIN3,PIN4,PIN5,PIN6,PIN7 }            */
/* Fun. Return : void                                                                 */
/**************************************************************************************/
void LED_voidToggle_Led_Pin ( u8 Copy_u8PortNumber, u8 Copy_u8PinNumber );
/**************************************************************************************/
/* Function Name : LED_voidToggle_8Leds_Port                                          */
/* Description : Toggle Status of String 8 leds from Turn ON to OFF & from OFF to ON  */
/* Fun. Argument1: Copy_u8PortNumber { PORTA,PORTB,PORTC,PORTD }                      */
/* Fun. Return : void                                                                 */
/**************************************************************************************/
void LED_voidToggle_8Leds_Port ( u8 Copy_u8PortNumber );
/*====================================================================================*/
/*====================================================================================*/




#endif