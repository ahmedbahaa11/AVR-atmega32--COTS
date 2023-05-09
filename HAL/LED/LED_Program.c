/*=================================================================================*/
/*  File        : LED_Program.c                                                    */
/*  Description : This file includes LED Driver implementations for Atmega32       */
/*  Author      : Ahmed Bahaa Taha Nasr. Embedded SW Engineer                      */
/*  Date        : 28/3/2023                                                        */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-bahaa1/                        */
/*  Git account : https://github.com/ahmedbahaa11                                  */
/*  mail        : ahmedbahaataha7@gmil.com                                         */
/*=================================================================================*/

/* Include Header Files From LIB */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

/* Include My own Header Files*/
#include "LED_Interface.h"
#include "LED_Private.h"
#include "LED_Config.h"

/* Include Header Files From MCAL Layer */
#include "../../MCAL/DIO/DIO_Interface.h"



/*==============================================================================================*/
/**************************    A.BAHAA LED Functions Implementations     ************************/
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
void LED_voidInit_Led_Pin ( u8 Copy_u8PortNumber, u8 Copy_u8PinNumber )
{
    /* i/p validation */
    if ( Copy_u8PortNumber > PORTD  || Copy_u8PinNumber > PIN7 )
    {
        // Do Nothing
    }
    else
    {
        DIO_voidSetPinDirection (Copy_u8PortNumber,Copy_u8PinNumber,OUTPUT);
    }
}
/**********************************************************************************/
/* Function Name : LED_voidInit_8Leds_Port                                        */
/* Description : Initialize string of 8 LEDs on specific Port                     */
/* Fun. Argument1: Copy_u8PortNumber { PORTA,PORTB,PORTC,PORTD }                  */
/* Fun. Return : void                                                             */
/**********************************************************************************/
void LED_voidInit_8Leds_Port ( u8 Copy_u8PortNumber)
{
    /* i/p validation */
    if ( Copy_u8PortNumber > PORTD )
    {
        // Do Nothing
    }
    else
    {
        DIO_voidSetPortDirection ( Copy_u8PortNumber, OUTPUT );
    }
}
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
void LED_voidStatus_Led_Pin ( u8 Copy_u8PortNumber, u8 Copy_u8PinNumber, u8 Copy_u8Status )
{
    /* i/p validation */
    if ( Copy_u8PortNumber > PORTD  || Copy_u8PinNumber > PIN7 )
    {
        // Do Nothing
    }
    else
    {
        switch(Copy_u8Status)
        {
            case ON  :   DIO_voidSetPinValue ( Copy_u8PortNumber, Copy_u8PinNumber, HIGH );     break;
            case OFF :   DIO_voidSetPinValue ( Copy_u8PortNumber, Copy_u8PinNumber, LOW  );     break;
            default  :                                                                          break;
        }
    }
}
/*****************************************************************************************************/
/* Function Name : LED_voidStatus_8Leds_Port                                                         */
/* Description : Status of string of 8 Leds Turn on and off                                          */
/* Fun. Argument1: Copy_u8PortNumber { PORTA,PORTB,PORTC,PORTD }                                     */
/* Fun. Argument3: Copy_u8Status { ON ,OFF }                                                         */
/* Fun. Return : void                                                                                */
/*****************************************************************************************************/
void LED_voidStatus_8Leds_Port ( u8 Copy_u8PortNumber, u8 Copy_u8Status )
{
    /* i/p validation */
    if ( Copy_u8PortNumber > PORTD  )
    {
        // Do Nothing
    }
    else
    {
        switch(Copy_u8Status)
        {
            case ON  :   DIO_voidSetPortValue ( Copy_u8PortNumber, HIGH );     break;
            case OFF :   DIO_voidSetPortValue ( Copy_u8PortNumber, LOW  );     break;
            default  :                                                         break;
        }
    }
}
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
void LED_voidToggle_Led_Pin ( u8 Copy_u8PortNumber, u8 Copy_u8PinNumber )
{
    /* i/p validation */
    if ( Copy_u8PortNumber > PORTD  || Copy_u8PinNumber > PIN7 )
    {
        // Do Nothing
    }
    else
    {
        DIO_voidTogglePinValue ( Copy_u8PortNumber, Copy_u8PinNumber );
    }
}
/**************************************************************************************/
/* Function Name : LED_voidToggle_8Leds_Port                                          */
/* Description : Toggle Status of String 8 leds from Turn ON to OFF & from OFF to ON  */
/* Fun. Argument1: Copy_u8PortNumber { PORTA,PORTB,PORTC,PORTD }                      */
/* Fun. Return : void                                                                 */
/**************************************************************************************/
void LED_voidToggle_8Leds_Port ( u8 Copy_u8PortNumber )
{
    /* i/p validation */
    if ( Copy_u8PortNumber > PORTD )
    {
        // Do Nothing
    }
    else
    {
        DIO_voidTogglePortValue ( Copy_u8PortNumber );
    }
}
/*====================================================================================*/
/*====================================================================================*/