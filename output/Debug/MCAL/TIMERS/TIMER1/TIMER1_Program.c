/*=================================================================================*/
/*  File        : TIMER1_Program.c                                                 */
/*  Description : This file includes TIMER1 Driver implementations for Atmega32    */
/*  Author      : Ahmed Bahaa Taha Nasr. Embedded SW Engineer                      */
/*  Date        : 9/4/2023                                                         */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-bahaa1/                        */
/*  Git account : https://github.com/ahmedbahaa11                                  */
/*  mail        : ahmedbahaataha7@gmil.com                                         */
/*=================================================================================*/

/* Include Header Files From LIB */
#include "../../../LIB/STD_TYPES.h"
#include "../../../LIB/BIT_MATH.h"

/* Include My own Header Files*/
#include "TIMER1_Interface.h"
#include "TIMER1_Private.h"
#include "TIMER1_Config.h"

void (*Global_PointerToFunction_OVF_T1) (void) = NULL ; 
void (*Global_PointerToFunction_CTC_T1) (void) = NULL ; 
u16 Global_u16PreloadValue = 0 ;
u16 Global_u16CompareMatchValue_1A = 0 ;
u16 Global_u16CompareMatchValue_1B = 0 ;

/*============================================================================================================*/
/*=============================     A.BAHAA TIMER1 Functions Implementation       ============================*/
/*============================================================================================================*/
/***************************     [1]  TIMER1_voidInit                              ****************************/
/***************************     [2]  TIMER1_voidSetCallBack_OVF                   ****************************/
/***************************     [3]  TIMER1_voidSetCallBack_CTC                   ****************************/
/***************************     [4]  TIMER1_voidSetPreloadValue                   ****************************/
/***************************     [5]  TIMER1_voidSetCompareMatchValue_T1A          ****************************/
/***************************     [6]  TIMER1_voidSetCompareMatchValue_T1B          ****************************/
/***************************     [7]  TIMER1_voidBahaa_u16PWM_T1A                  ****************************/
/***************************     [8]  TIMER1_voidBahaa_u16PWM_T1B                  ****************************/
/*============================================================================================================*/

/************************************************************************************************/
/* Function Name : TIMER1_voidInit                                                              */
/* Description : Initilization of TIMER1 with Specific Specks accordig to Gonfigration File.h   */                                          
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void TIMER1_voidInit (void)
{
/*======================================*/
/*         TIMER1 Mode Selection        */
/*--------------------------------------*/
    #if (MODE == NORMAL_OVF)                             
        CLEAR_BIT(TCCR1A_REG,TCCR1A_WGM10);
        CLEAR_BIT(TCCR1A_REG,TCCR1A_WGM11);
		CLEAR_BIT(TCCR1B_REG,TCCR1B_WGM12);                 
        CLEAR_BIT(TCCR1B_REG,TCCR1B_WGM13);
        SET_BIT(TIMSK_REG,TIMER_TIMSK_TOIE1);         // Enable T1 OVF Interrupt [PIE]. 
    #elif (MODE == PWM_PHASECORRECT_8_BIT)                     
          SET_BIT(TCCR1A_REG,TCCR1A_WGM10);
        CLEAR_BIT(TCCR1A_REG,TCCR1A_WGM11);
		CLEAR_BIT(TCCR1B_REG,TCCR1B_WGM12);                 
        CLEAR_BIT(TCCR1B_REG,TCCR1B_WGM13);
    #elif (MODE == PWM_PHASECORRECT_9_BIT)                                 
        CLEAR_BIT(TCCR1A_REG,TCCR1A_WGM10);
          SET_BIT(TCCR1A_REG,TCCR1A_WGM11);
		CLEAR_BIT(TCCR1B_REG,TCCR1B_WGM12);                 
        CLEAR_BIT(TCCR1B_REG,TCCR1B_WGM13);           
    #elif (MODE == PWM_PHASECORRECT_10_BIT)                             
          SET_BIT(TCCR1A_REG,TCCR1A_WGM10);
          SET_BIT(TCCR1A_REG,TCCR1A_WGM11);
		CLEAR_BIT(TCCR1B_REG,TCCR1B_WGM12);                 
        CLEAR_BIT(TCCR1B_REG,TCCR1B_WGM13);
    #elif (MODE == CTC)
        CLEAR_BIT(TCCR1A_REG,TCCR1A_WGM10);
        CLEAR_BIT(TCCR1A_REG,TCCR1A_WGM11);
		  SET_BIT(TCCR1B_REG,TCCR1B_WGM12);                 
        CLEAR_BIT(TCCR1B_REG,TCCR1B_WGM13);
        SET_BIT(TIMSK_REG,TIMER_TIMSK_OCIE1A);         // Enable T1 A CTC Interrupt [PIE].
        SET_BIT(TIMSK_REG,TIMER_TIMSK_OCIE1B);         // Enable T1 B CTC Interrupt [PIE].
    #elif (MODE == FAST_PWM_8_BIT)
          SET_BIT(TCCR1A_REG,TCCR1A_WGM10);
        CLEAR_BIT(TCCR1A_REG,TCCR1A_WGM11);
		  SET_BIT(TCCR1B_REG,TCCR1B_WGM12);                 
        CLEAR_BIT(TCCR1B_REG,TCCR1B_WGM13);
    #elif (MODE == FAST_PWM_9_BIT)
        CLEAR_BIT(TCCR1A_REG,TCCR1A_WGM10);
          SET_BIT(TCCR1A_REG,TCCR1A_WGM11);
		  SET_BIT(TCCR1B_REG,TCCR1B_WGM12);                 
        CLEAR_BIT(TCCR1B_REG,TCCR1B_WGM13);
    #elif (MODE == FAST_PWM_10_BIT)
          SET_BIT(TCCR1A_REG,TCCR1A_WGM10);
          SET_BIT(TCCR1A_REG,TCCR1A_WGM11);
		  SET_BIT(TCCR1B_REG,TCCR1B_WGM12);                 
        CLEAR_BIT(TCCR1B_REG,TCCR1B_WGM13);
    #elif (MODE == PWM_Phase_FrequencyCorrect_ICR1)
        CLEAR_BIT(TCCR1A_REG,TCCR1A_WGM10);
        CLEAR_BIT(TCCR1A_REG,TCCR1A_WGM11);
		CLEAR_BIT(TCCR1B_REG,TCCR1B_WGM12);                 
          SET_BIT(TCCR1B_REG,TCCR1B_WGM13);
    #elif (MODE == PWM_Phase_FrequencyCorrect)
          SET_BIT(TCCR1A_REG,TCCR1A_WGM10);
        CLEAR_BIT(TCCR1A_REG,TCCR1A_WGM11);
		CLEAR_BIT(TCCR1B_REG,TCCR1B_WGM12);                 
          SET_BIT(TCCR1B_REG,TCCR1B_WGM13);
    #elif (MODE == PWM_PhaseCorrect_ICR1)
        CLEAR_BIT(TCCR1A_REG,TCCR1A_WGM10);
          SET_BIT(TCCR1A_REG,TCCR1A_WGM11);
		CLEAR_BIT(TCCR1B_REG,TCCR1B_WGM12);                 
          SET_BIT(TCCR1B_REG,TCCR1B_WGM13);
    #elif (MODE == PWM_PhaseCorrect)
          SET_BIT(TCCR1A_REG,TCCR1A_WGM10);
          SET_BIT(TCCR1A_REG,TCCR1A_WGM11);
		CLEAR_BIT(TCCR1B_REG,TCCR1B_WGM12);                 
          SET_BIT(TCCR1B_REG,TCCR1B_WGM13);
    #elif (MODE == CTC_ICR1)
        CLEAR_BIT(TCCR1A_REG,TCCR1A_WGM10);
        CLEAR_BIT(TCCR1A_REG,TCCR1A_WGM11);
		  SET_BIT(TCCR1B_REG,TCCR1B_WGM12);                 
          SET_BIT(TCCR1B_REG,TCCR1B_WGM13);
          SET_BIT(TIMSK_REG,TIMER_TIMSK_TICIE);         // Enable T1 CTC ICR1 Interrupt [PIE].
    #elif (MODE == Reversed)
          SET_BIT(TCCR1A_REG,TCCR1A_WGM10);
        CLEAR_BIT(TCCR1A_REG,TCCR1A_WGM11);
		  SET_BIT(TCCR1B_REG,TCCR1B_WGM12);                 
          SET_BIT(TCCR1B_REG,TCCR1B_WGM13);
    #elif (MODE == FAST_PWM_ICR1)
        CLEAR_BIT(TCCR1A_REG,TCCR1A_WGM10);
          SET_BIT(TCCR1A_REG,TCCR1A_WGM11);
		  SET_BIT(TCCR1B_REG,TCCR1B_WGM12);                 
          SET_BIT(TCCR1B_REG,TCCR1B_WGM13);
    #elif (MODE == FAST_PWM)
          SET_BIT(TCCR1A_REG,TCCR1A_WGM10);
          SET_BIT(TCCR1A_REG,TCCR1A_WGM11);
		  SET_BIT(TCCR1B_REG,TCCR1B_WGM12);                 
          SET_BIT(TCCR1B_REG,TCCR1B_WGM13);
    #else 
        #error  Wrong selection of operation mode
    #endif 
/*==============================================*/
/*          OC1A Mode Selection                 */
/*----------------------------------------------*/
    #if (OC1A_MODE == DISCONNECTED)
        CLEAR_BIT(TCCR1A_REG,TCCR1A_COM1A0);
        CLEAR_BIT(TCCR1A_REG,TCCR1A_COM1A1);
    #elif ((OC1A_MODE == SETonTOP_CLEARonCOMPARE) || (OC1A_MODE == SETonCOMPdownCounting_CLEARonCOMPupCounting))
        CLEAR_BIT(TCCR1A_REG,TCCR1A_COM1A0);
          SET_BIT(TCCR1A_REG,TCCR1A_COM1A1);
    #elif ((OC1A_MODE == SETonCOMPARE_CLEARonTOP) || (OC1A_MODE == SETonCOMPupCounting_CLEARonCOMPdownCounting))
        SET_BIT(TCCR1A_REG,TCCR1A_COM1A0);
        SET_BIT(TCCR1A_REG,TCCR1A_COM1A1);
    #else 
        #error  Wrong selection of OC1A mode
    #endif
    #if ( MODE == NORMAL_OVF || MODE == CTC || MODE == CTC_ICR1 )       // Compare Output Mode, non-PWM
        CLEAR_BIT(TCCR1A_REG,TCCR1A_COM1A0);                            // Disable OC1A
        CLEAR_BIT(TCCR1A_REG,TCCR1A_COM1A1);                            // Disable OC1A

    #endif
/*==============================================*/
/*          OC1B Mode Selection                 */
/*----------------------------------------------*/
    #if (OC1B_MODE == DISCONNECTED)
        CLEAR_BIT(TCCR1A_REG,TCCR1A_COM1B0);
        CLEAR_BIT(TCCR1A_REG,TCCR1A_COM1B1);
    #elif ((OC1B_MODE == SETonTOP_CLEARonCOMPARE) || (OC1B_MODE == SETonCOMPdownCounting_CLEARonCOMPupCounting))
        CLEAR_BIT(TCCR1A_REG,TCCR1A_COM1B0);
          SET_BIT(TCCR1A_REG,TCCR1A_COM1B1);
    #elif ((OC1B_MODE == SETonCOMPARE_CLEARonTOP) || (OC1B_MODE == SETonCOMPupCounting_CLEARonCOMPdownCounting))
        SET_BIT(TCCR1A_REG,TCCR1A_COM1B0);
        SET_BIT(TCCR1A_REG,TCCR1A_COM1B1);
    #else 
        #error  Wrong selection of OC1B mode
    #endif
    #if ( MODE == NORMAL_OVF || MODE == CTC || MODE == CTC_ICR1 )       // Compare Output Mode, non-PWM
        CLEAR_BIT(TCCR1A_REG,TCCR1A_COM1B0);                            // Disable OC1B
        CLEAR_BIT(TCCR1A_REG,TCCR1A_COM1B1);                            // Disable OC1B

    #endif
/*======================================*/
/*     TIMER1 Prescaller Selection      */
/*--------------------------------------*/
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
/*======================================*/
}

/************************************************************************************************/
/* Function Name : TIMER1_voidSetCallBack_OVF                                                   */
/* Description : Call Back Function To Assign the address of OVF APP. Fun. at Global Pointer    */                                          
/* Fun. Argument1: (*Local_PointerToFunction_OVF) { Address of OVF Application Function }       */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void TIMER1_voidSetCallBack_OVF (void (*Local_PointerToFunction_OVF) (void))
{
    Global_PointerToFunction_OVF_T1 = Local_PointerToFunction_OVF ;
}

/************************************************************************************************/
/* Function Name : TIMER1_voidSetCallBack_CTC                                                   */
/* Description : Call Back Function To Assign the address of CTC APP. Fun. at Global Pointer    */                                          
/* Fun. Argument1: (*Local_PointerToFunction_CTC) { Address of CTC Application Function }       */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void TIMER1_voidSetCallBack_CTC (void (*Local_PointerToFunction_CTC) (void))
{
    Global_PointerToFunction_CTC_T1 = Local_PointerToFunction_CTC ;
}

/************************************************************************************************/
/* Function Name : TIMER1_voidSetPreloadValue                                                   */
/* Description : Set Preload Value in a Timer Register to Start Count From this Preload Value   */                                          
/* Fun. Argument1: Copy_u8PreloadValue  { from  0  To  255 }                                    */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void TIMER1_voidSetPreloadValue ( u16 Local_u16PreloadValue )
{
    #if (MODE == NORMAL_OVF)
        TCNT1_REG = Local_u16PreloadValue ;
        Global_u16PreloadValue = Local_u16PreloadValue ;
    #else
        // No Action
    #endif
}

/*************************************************************************************************/
/* Function Name : TIMER1_voidSetCompareMatchValue_T1A                                           */
/* Description : Set Compare Match Value in OCR1A Register To make Timer Over Flow at This Value */                                          
/* Fun. Argument1: Copy_u8CompareMatchValue  { from  0  To  65,535 }  [16 BIT]                   */
/* Fun. Return : void                                                                            */
/*************************************************************************************************/
void TIMER1_voidSetCompareMatchValue_T1A ( u16 Local_u16CompareMatchValue )
{
    #if (MODE != NORMAL_OVF)
        OCR1A_REG = Local_u16CompareMatchValue ;
        Global_u16CompareMatchValue_1A = Local_u16CompareMatchValue ;
    #endif
}

/*************************************************************************************************/
/* Function Name : TIMER1_voidSetCompareMatchValue_T1B                                           */
/* Description : Set Compare Match Value in OCR1B Register To make Timer Over Flow at This Value */                                          
/* Fun. Argument1: Copy_u8CompareMatchValue  { from  0  To  65,535 }  [16 BIT]                   */
/* Fun. Return : void                                                                            */
/*************************************************************************************************/
void TIMER1_voidSetCompareMatchValue_T1B ( u16 Local_u16CompareMatchValue )
{
    #if (MODE != NORMAL_OVF)
        OCR1B_REG = Local_u16CompareMatchValue ;
        Global_u16CompareMatchValue_1B = Local_u16CompareMatchValue ;
    #endif
}

/************************************************************************************************/
/* Function Name : TIMER1_voidBahaa_u16PWM_T1A                                                  */
/* Description : Configrable TOP Value and Compare match Value To Make Special PWM              */
/*               Set TOP Value in ICR1A Register to OVF at This Value.                          */ 
/*               and Set Compare Match Value in OCR1A Register To make PWM at PIN OC1A          */                                          
/* Fun. Argument1: Local_u8CompareMatchValue  { from  0  To  65,535 }  [16 BIT]                 */
/* Fun. Argument2: Copy_u16TopValue           { from  0  To  65,535 }  [16 BIT]                 */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void TIMER1_voidBahaa_u16PWM_T1A ( u16 Copy_u16CompareMatchValue , u16 Copy_u16TopValue )
{
    TIMER1_voidSetCompareMatchValue_T1A ( Copy_u16CompareMatchValue );
    ICR1_REG = Copy_u16TopValue ;
}

/************************************************************************************************/
/* Function Name : TIMER1_voidBahaa_u16PWM_T1B                                                  */
/* Description : Configrable TOP Value and Compare match Value To Make Special PWM              */
/*               Set TOP Value in ICR1B Register to OVF at This Value.                           */ 
/*               and Set Compare Match Value in OCR1B Register To make PWM at PIN OC1B          */                                          
/* Fun. Argument1: Local_u8CompareMatchValue  { from  0  To  65,535 }  [16 BIT]                 */
/* Fun. Argument2: Copy_u16TopValue           { from  0  To  65,535 }  [16 BIT]                 */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void TIMER1_voidBahaa_u16PWM_T1B ( u16 Copy_u16CompareMatchValue , u16 Copy_u16TopValue )
{
    TIMER1_voidSetCompareMatchValue_T1B ( Copy_u16CompareMatchValue );
    ICR1_REG = Copy_u16TopValue ;
}







