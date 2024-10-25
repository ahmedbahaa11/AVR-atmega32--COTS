/*===================================================================================================*/
/*  File        : SERVO_Interface.h                                                                  */
/*  Description : This interface file includes SERVO Driver prototypes and declarations for Atmega32 */
/*  Author      : Ahmed Bahaa Taha Nasr. Embedded SW Engineer                                        */
/*  Date        : 10/4/2023                                                                          */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-bahaa1/                                          */
/*  Git account : https://github.com/ahmedbahaa11                                                    */
/*  mail        : abahaa14842@gmail.com                                                              */
/*===================================================================================================*/

/* File Gaurd by ifndef & endif */
#ifndef SERVO_INTERFACE_H
#define SERVO_INTERFACE_H


/*==============================================================================================*/
/**************************    A.BAHAA SERVO MOTOR Functions Prototypes     *********************/
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
void SERVO_voidRotateSpecificAngle_OC1A ( u16 Copy_u16Angle );

/************************************************************************************************/
/* Function Name : SERVO_voidRotateSpecificAngle_OC1B                                           */
/* Description : Rotate Servo Motor with Specific Angle by PWM TIMER1 at PIN  OCB1   (PD4)      */                                         
/* Fun. Argument1:  Copy_u16Angle      Angle From [ 0  To  180 ] Degree                         */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void SERVO_voidRotateSpecificAngle_OC1B ( u16 Copy_u16Angle );



#endif