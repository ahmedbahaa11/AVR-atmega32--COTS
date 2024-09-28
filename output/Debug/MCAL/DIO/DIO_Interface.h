/*===================================================================================================*/
/*  File        : DIO_Interface.h                                                                    */
/*  Description : This interface file includes DIO Driver prototypes and declarations for Atmega32   */
/*  Author      : Ahmed Bahaa Taha Nasr. Embedded SW Engineer                                        */
/*  Date        : 27/3/2023                                                                          */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-bahaa1/                                          */
/*  Git account : https://github.com/ahmedbahaa11                                                    */
/*  mail        : ahmedbahaataha7@gmil.com                                                           */
/*===================================================================================================*/

/* File Gaurd by ifndef & endif */
#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

/** Macros as Direction options */
#define INPUT                    0
#define OUTPUT                   1

/**** Macros as Value options ***/
#define LOW                      0
#define HIGH                     1

/*** Macros as Status options ***/
#define OFF                      0
#define ON                       1

/* Macros as PortNumber options */
#define PORTA                    0    
#define PORTB                    1     
#define PORTC                    2    
#define PORTD                    3

/** Macros as PinNumber options */
#define PIN0                     0    
#define PIN1                     1     
#define PIN2                     2    
#define PIN3                     3
#define PIN4                     4    
#define PIN5                     5     
#define PIN6                     6    
#define PIN7                     7



/*======================================================================================================================*/
/*======================================     A.BAHAA DIO Functions Prototypes      =====================================*/
/*======================================================================================================================*/
/********************************************    DIO_voidSetPinDirection       ******************************************/
/********************************************    DIO_voidSetPortDirection      ******************************************/ 
/********************************************    DIO_voidSetPinValue           ******************************************/ 
/********************************************    DIO_voidSetPortValue          ******************************************/ 
/********************************************    DIO_u8GetPinValue             ******************************************/ 
/********************************************    DIO_u8GetPortValue            ******************************************/ 
/********************************************    DIO_voidTogglePinValue        ******************************************/ 
/********************************************    DIO_voidTogglePortValue       ******************************************/ 
/********************************************    DIO_voidConfig_Pull_Up_Pin    ******************************************/ 
/* ******************************************    DIO_voidConfig_Pull_Up_Port   ******************************************/
/*======================================================================================================================*/




/*==============================================================================================*/
/* ==============================       Direction Modules        ===============================*/
/*==============================================================================================*/
/************************************************************************************************/
/* Function Name : DIO_voidSetPinDirection                                                      */
/* Description : Set direction of one bit of the Port register                                  */
/* Fun. Argument1: Copy_u8PortNumber { PORTA,PORTB,PORTC,PORTD }                                */
/* Fun. Argument2: Copy_u8PinNumber { PIN0,PIN1,PIN3,PIN4,PIN5,PIN6,PIN7 }                      */
/* Fun. Argument3: Copy_u8Direction { INPUT,OUTPUT }                                            */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void DIO_voidSetPinDirection (u8 Copy_u8PortNumber, u8 Copy_u8PinNumber, u8 Copy_u8Direction );
/************************************************************************************************/
/* Function Name : DIO_voidSetPortDirection                                                     */
/* Description : Set direction of the whole Port register                                       */
/* Fun. Argument1: Copy_u8PortNumber { PORTA,PORTB,PORTC,PORTD }                                */
/* Fun. Argument2: Copy_u8Direction { INPUT,OUTPUT }                                            */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void DIO_voidSetPortDirection (u8 Copy_u8PortNumber, u8 Copy_u8Direction );                 
/*==============================================================================================*/
/*==============================================================================================*/



/*========================================================================================*/
/* ===========================         Write Modules          ============================*/
/*========================================================================================*/
/******************************************************************************************/
/* Function Name : DIO_voidSetPinValue                                                    */
/* Description : Write value of one bit of the Port register                              */
/* Fun. Argument1: Copy_u8PortNumber { PORTA,PORTB,PORTC,PORTD }                          */
/* Fun. Argument2: Copy_u8PinNumber { PIN0,PIN1,PIN3,PIN4,PIN5,PIN6,PIN7 }                */
/* Fun. Argument3: Copy_u8Value { HIGH , LOW }                                            */
/* Fun. Return : void                                                                     */
/******************************************************************************************/
void DIO_voidSetPinValue (u8 Copy_u8PortNumber, u8 Copy_u8PinNumber, u8 Copy_u8Value );
/******************************************************************************************/
/* Function Name : DIO_voidSetPortValue                                                   */
/* Description : write o/p to  the whole Port register                                    */
/* Fun. Argument1: Copy_u8PortNumber { PORTA,PORTB,PORTC,PORTD }                          */
/* Fun. Argument2: Copy_u8Value { HIGH , LOW }                                            */
/* Fun. Return : void                                                                     */
/******************************************************************************************/
void DIO_voidSetPortValue (u8 Copy_u8PortNumber, u8 Copy_u8Value );
/*========================================================================================*/
/*========================================================================================*/



/*==========================================================================*/
/* =====================         Read Modules          =====================*/
/*==========================================================================*/
/****************************************************************************/
/* Function Name : DIO_u8GetPinValue                                        */
/* Description : Read pin value of one bit of the Port register             */
/* Fun. Argument1: Copy_u8PortNumber { PORTA,PORTB,PORTC,PORTD }            */
/* Fun. Argument2: Copy_u8PinNumber { PIN0,PIN1,PIN3,PIN4,PIN5,PIN6,PIN7 }  */
/* Fun. Return :  unsigned char   { HIGH , LOW }                            */
/****************************************************************************/
u8 DIO_u8GetPinValue (u8 Copy_u8PortNumber, u8 Copy_u8PinNumber );
/****************************************************************************/
/* Function Name : DIO_u8GetPortValue                                       */
/* Description : Read i/p of the whole Port register                        */
/* Fun. Argument1: Copy_u8PortNumber { PORTA,PORTB,PORTC,PORTD }            */
/* Fun. Return : u8 {0bxxxxxxxx} (x) is a value in an one Pin on the Port   */
/****************************************************************************/
u8 DIO_u8GetPortValue (u8 Copy_u8PortNumber );
/*==========================================================================*/
/*==========================================================================*/



/*==========================================================================*/
/* ====================     Toggle Write Modules       =====================*/
/*==========================================================================*/
/****************************************************************************/
/* Function Name : DIO_voidTogglePinValue                                   */
/* Description : Toggle pin value of one bit of the Port register           */
/* Fun. Argument1: Copy_u8PortNumber { PORTA,PORTB,PORTC,PORTD }            */
/* Fun. Argument2: Copy_u8PinNumber { PIN0,PIN1,PIN3,PIN4,PIN5,PIN6,PIN7 }  */
/* Fun. Return : void                                                       */
/****************************************************************************/
void DIO_voidTogglePinValue (u8 Copy_u8PortNumber, u8 Copy_u8PinNumber );
/****************************************************************************/
/* Function Name : DIO_voidTogglePortValue                                  */
/* Description : Toggles pin values of the whole Port register              */
/* Fun. Argument1: Copy_u8PortNumber { PORTA,PORTB,PORTC,PORTD }            */
/* Fun. Return : void                                                       */
/****************************************************************************/
void DIO_voidTogglePortValue (u8 Copy_u8PortNumber );
/*==========================================================================*/
/*==========================================================================*/



/*=================================================================================================*/
/*==============================     Enable Pull-Up Res Modules       =============================*/
/*=================================================================================================*/
/***************************************************************************************************/
/* Function Name : DIO_voidConfig_Pull_Up_Pin                                                      */
/* Description : Configure pullup Res status for on a given Pin and port                           */ 
/* Fun. Argument1: Copy_u8PortNumber { PORTA,PORTB,PORTC,PORTD }                                   */
/* Fun. Argument2: Copy_u8PinNumber { PIN0,PIN1,PIN3,PIN4,PIN5,PIN6,PIN7 }                         */
/* Fun. Argument3: Copy_u8PullUpStatus { ON , OFF }                                                */
/* Fun. Return : void                                                                              */
/***************************************************************************************************/
void DIO_voidConfig_Pull_Up_Pin (u8 Copy_u8PortNumber,u8 Copy_u8PinNumber,u8 Copy_u8PullUpStatus);
/***************************************************************************************************/
/* Function Name : DIO_voidConfig_Pull_Up_Port                                                     */
/* Description : Configure Pull-Up Res status for the whole Port register                          */ 
/* Fun. Argument1: Copy_u8PortNumber { PORTA,PORTB,PORTC,PORTD }                                   */
/* Fun. Argument2: Copy_u8PullUpStatus { ON , OFF }                                                */
/* Fun. Return : void                                                                              */
/***************************************************************************************************/
void DIO_voidConfig_Pull_Up_Port (u8 Copy_u8PortNumber, u8 Copy_u8PullUpStatus );
/*=================================================================================================*/
/*=================================================================================================*/




#endif