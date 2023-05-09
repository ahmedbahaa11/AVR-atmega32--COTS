/*=================================================================================*/
/*  File        : RTOS_Program.c                                                   */
/*  Description : This file includes RTOS Driver implementations for Atmega32      */
/*  Author      : Ahmed Bahaa Taha Nasr. Embedded SW Engineer                      */
/*  Date        : 19/4/2023                                                        */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-bahaa1/                        */
/*  Git account : https://github.com/ahmedbahaa11                                  */
/*  mail        : ahmedbahaataha7@gmil.com                                         */
/*=================================================================================*/

/* Include Header Files From LIB */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

/* Include My own Header Files*/
#include "RTOS_Interface.h"
#include "RTOS_Private.h"
#include "RTOS_Config.h"

/* Include Files From MCAL */
#include "../../MCAL/TIMERS/TIMER0/TIMER0_Interface.h"

RTOS_TCB RTOS_ArrTasks[RTOS_u8_MAX_NUMBER_TASKS] ;

/*********************************************************************************************/
/* Function Name : RTOS_voidInit                                                             */
/* Description :  Initilization of Scheduler OS Operating System                             */ 
/* Fun. Return : void                                                                        */
/*********************************************************************************************/
void RTOS_voidInit (void)
{
    // Set Call Back Function & Compare Required Time
    TIMER0_voidSetCallBack_CTC_andRequiredTime_ms( &RTOS_voidScheduler , 1 ); // 1 msec
    // Start Timer ( CTC Mode + Enable CTC Interrupt + Put Prescaller 8 )
    TIMER0_voidInit();
}

/*********************************************************************************************/
/* Function Name : RTOS_u8CreateTask                                                         */
/* Description :  Create Task in this OS                                                     */ 
/* Fun. Argument1: Copy_u8Priority   { Periority of Function }                               */
/* Fun. Argument2: Copy_u16Periodicity  { Time ms }                                          */
/* Fun. Argument3: Copy_u16FirstDelay   { Time os Start  (ms) }                              */
/* Fun. Argument4: void (*Copy_PF)(void)   { Address of Function of Task }                   */
/* Fun. Return : u8 ( Error State { OK , NOT_OK } )                                          */
/*********************************************************************************************/
u8 RTOS_u8CreateTask ( u8 Copy_u8Priority , u16 Copy_u16Periodicity , u16 Copy_u16FirstDelay ,void (*Copy_PF)(void) )
{
    u8 Local_ErrorState = OK ;      // For Erros State
    if ( Copy_u8Priority < RTOS_u8_MAX_NUMBER_TASKS )
    {
        RTOS_ArrTasks[Copy_u8Priority].FirstDelay  = Copy_u16FirstDelay  ;
        RTOS_ArrTasks[Copy_u8Priority].Periodicity = Copy_u16Periodicity ;
        RTOS_ArrTasks[Copy_u8Priority].PF          = Copy_PF             ;
        RTOS_ArrTasks[Copy_u8Priority].State       = TASK_RESUMED        ;
    }
    else
    {
        Local_ErrorState = NOT_OK ;
    }
    return Local_ErrorState ;
}

/*********************************************************************************************/
/* Function Name : RTOS_voidScheduler                                                        */
/* Description   : Scheduler Function ( Come at Fixed Time )                                 */ 
/* Fun. Return   : void                                                                      */
/*********************************************************************************************/
static void RTOS_voidScheduler (void)
{
    // This Function Run Every each Interrupt
    u8 Local_u8TaskCounter ;
    // Loop on the ready Tasks
    for ( Local_u8TaskCounter = 0 ; Local_u8TaskCounter < RTOS_u8_MAX_NUMBER_TASKS ; Local_u8TaskCounter++ )
    {   
        /* Check The Task is Suspended or Not */
        if( RTOS_ArrTasks[Local_u8TaskCounter].State == TASK_RESUMED )
        {
            if ( RTOS_ArrTasks[Local_u8TaskCounter].FirstDelay == 0 )
            {
                // Call Task
                RTOS_ArrTasks[Local_u8TaskCounter].PF () ;
                // Update Fisrt Delay Value by Periodicity
                RTOS_ArrTasks[Local_u8TaskCounter].FirstDelay = RTOS_ArrTasks[Local_u8TaskCounter].Periodicity - 1 ;
            }
            else
            {
                RTOS_ArrTasks[Local_u8TaskCounter].FirstDelay -- ;
            }  
        }
        else
        {
            /* Task is Suspended, Do Nothing */
        }
        
    }
    
}

void RTOS_voidSuspendTask ( u8 Copy_u8Priority )
{
    RTOS_ArrTasks[Copy_u8Priority].State = TASK_SUSPENDED ;
}

void RTOS_voidResumeTask ( u8 Copy_u8Priority )
{
    RTOS_ArrTasks[Copy_u8Priority].State = TASK_RESUMED ;
}
