/*=================================================================================*/
/*  File        : SERVO_Program.c                                                  */
/*  Description : This file includes SERVO Driver implementations for Atmega32     */
/*  Author      : Ahmed Bahaa Taha Nasr. Embedded SW Engineer                      */
/*  Date        : 10/4/2023                                                        */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-bahaa1/                        */
/*  Git account : https://github.com/ahmedbahaa11                                  */
/*  mail        : abahaa14842@gmail.com                                            */
/*=================================================================================*/

/* Include Header Files From LIB */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

/* Include My own Header Files*/
#include "SERVO_Interface.h"
#include "SERVO_Private.h"
#include "SERVO_Config.h"

/* Include Header Files From MCAL Layer */
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/TIMERS/TIMER1/TIMER1_Interface.h"

/*==============================================================================================*/
/************************    A.BAHAA SERVO MOTOR Functions Implementation     *******************/
/*==============================================================================================*/
/****************************     SERVO_voidRotateSpecificAngle_OC1A    *************************/
/****************************     SERVO_voidRotateSpecificAngle_OC1B    *************************/
/*==============================================================================================*/


/************************************************************************************************/
/* Function Name : SERVO_voidRotateSpecificAngle_OC1A                                           */
/* Description : Rotate Servo Motor with Specific Angle by PWM TIMER1 at PIN  OCA1   (PD5)      */                                         
/* Fun. Argument1:  Copy_u16Angle      Angle From [ 0  To  180 ] Degree                         */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void SERVO_voidRotateSpecificAngle_OC1A ( u16 Copy_u16Angle )
{
    DIO_voidSetPinDirection(PORTD,PIN5,OUTPUT);
    u32 Local_u32Variable ;
    Local_u32Variable = ((Copy_u16Angle*1000UL)+179820) / (180) ;
    TIMER1_voidBahaa_u16PWM_T1A ( Local_u32Variable ,19999);
}

/************************************************************************************************/
/* Function Name : SERVO_voidRotateSpecificAngle_OC1B                                           */
/* Description : Rotate Servo Motor with Specific Angle by PWM TIMER1 at PIN  OCB1 (PD4)        */                                         
/* Fun. Argument1:  Copy_u16Angle      Angle From [ 0  To  180 ] Degree                         */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void SERVO_voidRotateSpecificAngle_OC1B ( u16 Copy_u16Angle )
{
    DIO_voidSetPinDirection(PORTD,PIN4,OUTPUT);
    u32 Local_u32Variable ;
    Local_u32Variable = ((Copy_u16Angle*1000UL)+179820) / (180) ;
    TIMER1_voidBahaa_u16PWM_T1B ( Local_u32Variable ,19999);
}