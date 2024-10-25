/*========================================================================================================*/
/*  File        : RTOS_Interface.h                                                                        */
/*  Description : This interface file includes RTOS Driver prototypes and declarations for Atmega32       */
/*  Author      : Ahmed Bahaa Taha Nasr. Embedded SW Engineer                                             */
/*  Date        : 19/4/2023                                                                               */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-bahaa1/                                               */
/*  Git account : https://github.com/ahmedbahaa11                                                         */
/*  mail        : abahaa14842@gmail.com                                                                   */
/*========================================================================================================*/

/* File Gaurd by ifndef & endif */
#ifndef RTOS_INTERFACE_H
#define RTOS_INTERFACE_H

/*********************************************************************************************/
/* Function Name : RTOS_voidInit                                                             */
/* Description :  Initilization of Scheduler OS Operating System                             */ 
/* Fun. Return : void                                                                        */
/*********************************************************************************************/
void RTOS_voidInit (void);

/*********************************************************************************************/
/* Function Name : RTOS_u8CreateTask                                                         */
/* Description :  Create Task in this OS                                                     */ 
/* Fun. Argument1: Copy_u8Priority   { Periority of Function }                               */
/* Fun. Argument2: Copy_u16Periodicity  { Time ms }                                          */
/* Fun. Argument3: Copy_u16FirstDelay   { Time os Start  (ms) }                              */
/* Fun. Argument4: void (*Copy_PF)(void)   { Address of Function of Task }                   */
/* Fun. Return : u8 ( Error State { OK , NOT_OK } )                                          */
/*********************************************************************************************/
u8 RTOS_u8CreateTask ( u8 Copy_u8Priority , u16 Copy_u16Periodicity , u16 Copy_u16FirstDelay ,void (*Copy_PF)(void) );

void RTOS_voidSuspendTask ( u8 Copy_u8Priority );
void RTOS_voidResumeTask ( u8 Copy_u8Priority );

#endif