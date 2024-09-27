/*===================================================================================================*/
/*  File        : EXTI_Interface.h                                                                   */
/*  Description : This interface file includes EXTI Driver prototypes and declarations for Atmega32  */
/*  Author      : Ahmed Bahaa Taha Nasr. Embedded SW Engineer                                        */
/*  Date        : 2/4/2023                                                                           */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-bahaa1/                                          */
/*  Git account : https://github.com/ahmedbahaa11                                                    */
/*  mail        : ahmedbahaataha7@gmil.com                                                           */
/*===================================================================================================*/

/* File Gaurd by ifndef & endif */
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

/* Macros as INT options */
#define  INT0             0
#define  INT1             1
#define  INT2             2

/* Macros as Sense Control options */
#define  FALLING_EDGE                 0
#define  RAISING_EDGE                 1
#define  LOW_LEVEL                    2
#define  ON_CHANGE                    3


/*=================================================================================================================*/
/*====================================       A.BAHAA EXTI Functions Prototype        ==============================*/
/*=================================================================================================================*/
/**********************************************  [1]  EXTI_voidEnable          *************************************/
/**********************************************  [2]  EXTI_voidDisable         *************************************/
/**********************************************  [3]  EXTI_voidSetCallBack     *************************************/
/*=================================================================================================================*/


/*********************************************************************************************/
/* Function Name : EXTI_voidEnable                                                           */
/* Description :  Enable (PIE) Peripheral Interrupt Enable and Put Sesnse Control            */ 
/* Fun. Argument1: Copy_u8INTnumber { INT0 , INT1 , INT2 }                                   */
/* Fun. Argument1: Copy_u8SenseControl {FALLING_EDGE, RAISING_EDGE, LOW_LEVEL, ON_CHANGE}    */
/* Fun. Return : void                                                                        */
/*********************************************************************************************/
void EXTI_voidEnable ( u8 Copy_u8INTnumber , u8 Copy_u8SenseControl );

/*****************************************************************************/
/* Function Name : EXTI_voidDisable                                          */
/* Description :  Disable (PIE) Peripheral Interrupt Enable                  */ 
/* Fun. Argument1: Copy_u8INTnumber { INT0 , INT1 , INT2 }                   */
/* Fun. Return : void                                                        */
/*****************************************************************************/
void EXTI_voidDisable ( u8 Copy_u8INTnumber );

/*****************************************************************************/
/* Function Name : EXTI_voidSetCallBack                                      */
/* Description : Function Call Back that assign Pointer of application       */
/*               Function to our global pointer to use it at ISR Fun.        */ 
/* Fun. Argument1:{ void (*Local_PointerToFunction) (void) }                 */
/*                Pointer to function that = Address of application function */
/* Fun. Return : void                                                        */
/*****************************************************************************/
void EXTI_voidSetCallBack ( u8 Copy_u8INTnumber , void (*Local_PointerToFunction) (void) );





#endif