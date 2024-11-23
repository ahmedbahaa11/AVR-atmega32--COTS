/*=================================================================================*/
/*  File        : ICU_Program.c                                                    */
/*  Description : This file includes ICU Driver implementations for Atmega32       */
/*  Author      : Ahmed Bahaa Taha Nasr. Embedded SW Engineer                      */
/*  Date        : 29/4/2023                                                        */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-bahaa1/                        */
/*  Git account : https://github.com/ahmedbahaa11                                  */
/*  mail        : abahaa14842@gmail.com                                            */
/*=================================================================================*/

/* Include Header Files From LIB */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

/* Include My own Header Files*/
#include "ICU_Interface.h"
#include "ICU_Private.h"
#include "ICU_Config.h"

/* Include Header Files From MCAL */
#include"../DIO/DIO_Interface.h"
#include"../TIMERS/TIMER1/TIMER1_Interface.h"
#include"../TIMERS/TIMER1/TIMER1_Private.h"
#include"../TIMERS/TIMER1/TIMER1_Config.h"

u32* global_periodTime = NULL;
u32* global_onTime     = NULL;

/*============================================================================================================*/
/*=============================       A.BAHAA ICU Functions Implementation        ============================*/
/*============================================================================================================*/
/***********************   [1]  ICU_voidInit                                       ****************************/
/***********************   [2]  ICU_voidDisableInterrupt                           ****************************/
/***********************   [3]  ICU_voidEdgeSelect                                 ****************************/
/***********************   [4]  ICU_u16GetReadICR1                                 ****************************/
/***********************   [5]  ICU_SetCallBackFun                                 ****************************/
/***********************   [6]  void __vector_6 (void)   __attribute__((signal));  ****************************/
/*============================================================================================================*/


/************************************************************************************************/
/* Function Name : ICU_voidInit                                                                 */
/* Description   : Initilization of TIMER1 & ICU HW                                             */                                          
/* Fun. Return   : void                                                                         */
/************************************************************************************************/
void ICU_voidInit (void)
{
    TIMER1_voidInit();
/*=====================================================================*/
/*  TIMER1 Normal Mode Selection to use ICU to Calculate PWM Frequency */
/*---------------------------------------------------------------------*/
        /*       TIMER1 Normal Mode      */                             
        CLEAR_BIT(TCCR1A_REG,TCCR1A_WGM10);
        CLEAR_BIT(TCCR1A_REG,TCCR1A_WGM11);
		CLEAR_BIT(TCCR1B_REG,TCCR1B_WGM12);                 
        CLEAR_BIT(TCCR1B_REG,TCCR1B_WGM13);

/*=====================================================================*/
/*                     TIMER1 Prescaller Selection                     */
/*---------------------------------------------------------------------*/
    TCCR1B_REG = ( TCCR1B_REG & 0b11111000 );              // Clear Prescaller 

    #if( PRESCALER == NO_CLK_SOURCE_TIMER_STOPED )          
        CLEAR_BIT(TCCR1B_REG,TCCR1B_CS10);
        CLEAR_BIT(TCCR1B_REG,TCCR1B_CS11);
        CLEAR_BIT(TCCR1B_REG,TCCR1B_CS12);
    #elif ( PRESCALER == NOT_USE_PRESCALER )
          SET_BIT(TCCR1B_REG,TCCR1B_CS10);
        CLEAR_BIT(TCCR1B_REG,TCCR1B_CS11);
        CLEAR_BIT(TCCR1B_REG,TCCR1B_CS12);
    #elif ( PRESCALER == PRESCALER_DIVISION_BY_8 )
        CLEAR_BIT(TCCR1B_REG,TCCR1B_CS10);
          SET_BIT(TCCR1B_REG,TCCR1B_CS11);
        CLEAR_BIT(TCCR1B_REG,TCCR1B_CS12);
    #elif ( PRESCALER == PRESCALER_DIVISION_BY_64 )
          SET_BIT(TCCR1B_REG,TCCR1B_CS10);
          SET_BIT(TCCR1B_REG,TCCR1B_CS11);
        CLEAR_BIT(TCCR1B_REG,TCCR1B_CS12);
    #elif ( PRESCALER == PRESCALER_DIVISION_BY_256 )
        CLEAR_BIT(TCCR1B_REG,TCCR1B_CS10);
        CLEAR_BIT(TCCR1B_REG,TCCR1B_CS11);
          SET_BIT(TCCR1B_REG,TCCR1B_CS12);
    #elif ( PRESCALER == PRESCALER_DIVISION_BY_1024 )
          SET_BIT(TCCR1B_REG,TCCR1B_CS10);
        CLEAR_BIT(TCCR1B_REG,TCCR1B_CS11);
          SET_BIT(TCCR1B_REG,TCCR1B_CS12);
    #elif ( PRESCALER == EXTERNAL_CLK_SOURCE_FALLING_EDGE )
        CLEAR_BIT(TCCR1B_REG,TCCR1B_CS10);
          SET_BIT(TCCR1B_REG,TCCR1B_CS11);
          SET_BIT(TCCR1B_REG,TCCR1B_CS12);
    #elif ( PRESCALER == EXTERNAL_CLK_SOURCE_RAISING_EDGE )
        SET_BIT(TCCR1B_REG,TCCR1B_CS10);
        SET_BIT(TCCR1B_REG,TCCR1B_CS11);
        SET_BIT(TCCR1B_REG,TCCR1B_CS12);
    #else
        #error  Wrong selection of Prescaller mode
    #endif
/*=====================================================================*/
/*  (ICES1) Input Capture Edge Select { Falling Edge , Raising Edge }  */
/*---------------------------------------------------------------------*/
    ICU_voidEdgeSelect ( RAISING_EDGE );        // Sense Raising Edge to start calculate time of Period Time from First Raising Ege to Second Raising Edge.
/*=====================================================*/
/*     (TICIE) Enable Input Capture Unit Interrupt     */
/*-----------------------------------------------------*/
    SET_BIT(TIMSK_REG,TIMER_TIMSK_TICIE);       // Enable PIE of ICU
}

/************************************************************************************************/
/* Function Name : ICU_voidDisableInterrupt                                                     */
/* Description   : Disable Input Capture Interrupt                                              */                                          
/* Fun. Return   : void                                                                         */
/************************************************************************************************/
void ICU_voidDisableInterrupt(void)
{
	CLEAR_BIT(TIMSK_REG,TIMER_TIMSK_TICIE);
}

/************************************************************************************************/
/* Function Name : ICU_voidEdgeSelect                                                           */
/* Description : Select Edge Sensing of ICP1 Input Capture Unit PIN                             */                                          
/* Fun. Argument1: Copy_u8EdgeSelect { FALLING_EDGE , RAISING_EDGE }                            */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void ICU_voidEdgeSelect ( u8 Copy_u8EdgeSelect )
{
    switch ( Copy_u8EdgeSelect )
    {
        case FALLING_EDGE :  CLEAR_BIT(TCCR1B_REG,TCCR1B_ICES1);       break;
        case RAISING_EDGE :    SET_BIT(TCCR1B_REG,TCCR1B_ICES1);       break;
        default           :         break;
    }
}

/************************************************************************************************/
/* Function Name : ICU_u16GetReadICR1                                                           */
/* Description   : Get Reading From ICR1 Register                                               */                                          
/* Fun. Return   : u16 ( Reading of TIMER1 REG from 0 To 65536 )                                */
/************************************************************************************************/
u16 ICU_u16GetReadICR1 (void)
{
	return ICR1_REG ;
}

/************************************************************************************************/
/* Function Name : ICU_SetCallBackFun                                                           */
/* Description  : Call Back Function                                                            */                                          
/* Fun. Argument1: void (*LocalPF_vector_6) (void) { address of App CallBack Fun ICU_HW }       */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void ICU_SetOutputMembers (u32* periodTime, u32* onTime)
{
	global_periodTime = periodTime ;
	global_onTime     = onTime     ;
}

void ICU_ISR (void)
{
    static u16 Global_ICU_Read1 ;
    static u16 Global_ICU_Read2 ;
    static u16 Global_ICU_Read3 ;
    static u8 Counter = 0 ;
    Counter++ ;
    if ( Counter == 1 )
    {
        // First Raising Edege
        Global_ICU_Read1 = ICU_u16GetReadICR1 (); 
    }
    else if ( Counter == 2 )
    {
        // Second Raising Edege
        Global_ICU_Read2 = ICU_u16GetReadICR1 ();

        *global_periodTime = Global_ICU_Read2 - Global_ICU_Read1 ;
        
        // Sense Falling Edge to calculate time of ON Time from Second Raising Ege to First Falling Edge.
        ICU_voidEdgeSelect ( FALLING_EDGE );      
    }
    else if ( Counter == 3 )
    {
        Global_ICU_Read3 = ICU_u16GetReadICR1 ();
        *global_onTime = Global_ICU_Read3 - Global_ICU_Read2 - 1 ;
        Counter = 0 ;
        ICU_voidDisableInterrupt();
    }
}

/*****************************************************************************/
/* Function Name : void __vector_6 (void) [ISR (ICU) Function]               */
/* Description : ISR Prototype (position 6 on vector table ICU TIMER1 )      */ 
/* Fun. Return : void                                                        */
/*****************************************************************************/
/*  ISR (ICU)  */
void __vector_6 (void)    __attribute__((signal));
void __vector_6 (void)
{
    if((global_periodTime != NULL) && (global_onTime != NULL))
    {
        ICU_ISR();
    }
}