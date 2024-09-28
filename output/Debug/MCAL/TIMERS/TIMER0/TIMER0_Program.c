/*=================================================================================*/
/*  File        : TIMER0_Program.c                                                 */
/*  Description : This file includes TIMER0 Driver implementations for Atmega32    */
/*  Author      : Ahmed Bahaa Taha Nasr. Embedded SW Engineer                      */
/*  Date        : 7/4/2023                                                         */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-bahaa1/                        */
/*  Git account : https://github.com/ahmedbahaa11                                  */
/*  mail        : ahmedbahaataha7@gmil.com                                         */
/*=================================================================================*/

/* Include Header Files From LIB */
#include "../../../LIB/STD_TYPES.h"
#include "../../../LIB/BIT_MATH.h"

/* Include My own Header Files*/
#include "TIMER0_Interface.h"
#include "TIMER0_Private.h"
#include "TIMER0_Config.h"

void (*Global_PointerToFunction_OVF_T0) (void) = NULL ; 
void (*Global_PointerToFunction_CTC_T0) (void) = NULL ; 
u16 Global_u8PreloadValue = 0 ;
u16 Global_u8CompareMatchValue = 0 ;
u32 Global_u32Time_ms = 0 ;
u32 Global_counterOVF = 0 ;

/*============================================================================================================*/
/*==============================     A.BAHAA TIMER0 Functions Implementation      ============================*/
/*============================================================================================================*/
/***************************  [1]  TIMER0_voidInit                                     ************************/
/***************************  [2]  TIMER0_voidSetCallBack_OVF                          ************************/
/***************************  [3]  TIMER0_voidSetCallBack_CTC                          ************************/
/***************************  [4]  TIMER0_voidSetPreloadValue                          ************************/
/***************************  [5]  TIMER0_voidSetCompareMatchValue                     ************************/
/***************************  [6]  TIMER0_voidSetBusyWait_ms                           ************************/
/***************************  [7]  TIMER0_voidBahaaPWM                                 ************************/
/***************************  [8]  TIMER0_voidSetCallBack_CTC_andRequiredTime_ms       ************************/
/***************************  [9]  void __vector_11 (void)   __attribute__((signal));  ************************/
/***************************  [10]  void __vector_10 (void)   __attribute__((signal)); ************************/
/*============================================================================================================*/

/************************************************************************************************/
/* Function Name : TIMER0_voidInit                                                              */
/* Description : Initilization of TIMER0 with Specific Specks accordig to Gonfigration File.h   */                                          
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void TIMER0_voidInit (void)
{
/*======================================*/
/*         TIMER0 Mode Selection        */
/*--------------------------------------*/
    #if (MODE == NORMAL_OVF)                             // OVF Normal Mode of Timer/Counter0
        CLEAR_BIT(TCCR0_REG,TIMER0_TCCR0_WGM00);
        CLEAR_BIT(TCCR0_REG,TIMER0_TCCR0_WGM01);
		SET_BIT(TIMSK_REG,TIMER0_TIMSK_TOIE0);          // Enable T0 OVF Interrupt [PIE].        

    #elif (MODE == PWM_PHASECORRECT)                     // PWM_Phase Correct Mode of Timer/Counter0
        SET_BIT(TCCR0_REG,TIMER0_TCCR0_WGM00);
        CLEAR_BIT(TCCR0_REG,TIMER0_TCCR0_WGM01);
        /*======================================*/
        /*          OC0 Mode Selection          */
        /*--------------------------------------*/
        #if ( OC0_MODE == DISCONNECTED )
            CLEAR_BIT(TCCR0_REG,TIMER0_TCCR0_COM00);
            CLEAR_BIT(TCCR0_REG,TIMER0_TCCR0_COM01);
        #elif ( OC0_MODE == SETonCOMPdownCounting_CLEARonCOMPupCounting )
            CLEAR_BIT(TCCR0_REG,TIMER0_TCCR0_COM00);
            SET_BIT(TCCR0_REG,TIMER0_TCCR0_COM01);
        #elif ( OC0_MODE == SETonCOMPupCounting_CLEARonCOMPdownCounting )
            SET_BIT(TCCR0_REG,TIMER0_TCCR0_COM00);
            SET_BIT(TCCR0_REG,TIMER0_TCCR0_COM01);
        #else 
            #error  Wrong selection of OC0 mode
        #endif

    #elif (MODE == CTC)                                  // CTC Mode of Timer/Counter0
        CLEAR_BIT(TCCR0_REG,TIMER0_TCCR0_WGM00);
        SET_BIT(TCCR0_REG,TIMER0_TCCR0_WGM01);
		SET_BIT(TIMSK_REG,TIMER0_TIMSK_OCIE0);          // Enable T0 CTC Interrupt [PIE]. 

    #elif (MODE == FAST_PWM)                             // Fast-PWM Mode of Timer/Counter0
        SET_BIT(TCCR0_REG,TIMER0_TCCR0_WGM00);
        SET_BIT(TCCR0_REG,TIMER0_TCCR0_WGM01);
        /*======================================*/
        /*          OC0 Mode Selection          */
        /*--------------------------------------*/
        #if ( OC0_MODE == DISCONNECTED )
            CLEAR_BIT(TCCR0_REG,TIMER0_TCCR0_COM00);
            CLEAR_BIT(TCCR0_REG,TIMER0_TCCR0_COM01);
        #elif ( OC0_MODE == SETonTOP_CLEARonCOMPARE )
            CLEAR_BIT(TCCR0_REG,TIMER0_TCCR0_COM00);
            SET_BIT(TCCR0_REG,TIMER0_TCCR0_COM01);
        #elif ( OC0_MODE == SETonCOMPARE_CLEARonTOP )
            SET_BIT(TCCR0_REG,TIMER0_TCCR0_COM00);
            SET_BIT(TCCR0_REG,TIMER0_TCCR0_COM01);
        #else 
            #error  Wrong selection of OC0 mode
        #endif

    #else 
        #error  Wrong selection of operation mode
    #endif 
/*======================================*/
/*======================================*/
/*     TIMER0 Prescaller Selection      */
/*--------------------------------------*/
    TCCR0_REG = ( TCCR0_REG & 0b11111000 );              // Clear Prescaller 

    #if( PRESCALER == NO_CLK_SOURCE_TIMER_STOPED )          
        CLEAR_BIT(TCCR0_REG,TIMER0_TCCR0_CS00);
        CLEAR_BIT(TCCR0_REG,TIMER0_TCCR0_CS01);
        CLEAR_BIT(TCCR0_REG,TIMER0_TCCR0_CS02);
    #elif ( PRESCALER == NOT_USE_PRESCALER )
        SET_BIT(TCCR0_REG,TIMER0_TCCR0_CS00);
        CLEAR_BIT(TCCR0_REG,TIMER0_TCCR0_CS01);
        CLEAR_BIT(TCCR0_REG,TIMER0_TCCR0_CS02);
    #elif ( PRESCALER == PRESCALER_DIVISION_BY_8 )
        CLEAR_BIT(TCCR0_REG,TIMER0_TCCR0_CS00);
        SET_BIT(TCCR0_REG,TIMER0_TCCR0_CS01);
        CLEAR_BIT(TCCR0_REG,TIMER0_TCCR0_CS02);
    #elif ( PRESCALER == PRESCALER_DIVISION_BY_64 )
        SET_BIT(TCCR0_REG,TIMER0_TCCR0_CS00);
        SET_BIT(TCCR0_REG,TIMER0_TCCR0_CS01);
        CLEAR_BIT(TCCR0_REG,TIMER0_TCCR0_CS02);
    #elif ( PRESCALER == PRESCALER_DIVISION_BY_256 )
        CLEAR_BIT(TCCR0_REG,TIMER0_TCCR0_CS00);
        CLEAR_BIT(TCCR0_REG,TIMER0_TCCR0_CS01);
        SET_BIT(TCCR0_REG,TIMER0_TCCR0_CS02);
    #elif ( PRESCALER == PRESCALER_DIVISION_BY_1024 )
        SET_BIT(TCCR0_REG,TIMER0_TCCR0_CS00);
        CLEAR_BIT(TCCR0_REG,TIMER0_TCCR0_CS01);
        SET_BIT(TCCR0_REG,TIMER0_TCCR0_CS02);
    #elif ( PRESCALER == EXTERNAL_CLK_SOURCE_FALLING_EDGE )
        CLEAR_BIT(TCCR0_REG,TIMER0_TCCR0_CS00);
        SET_BIT(TCCR0_REG,TIMER0_TCCR0_CS01);
        SET_BIT(TCCR0_REG,TIMER0_TCCR0_CS02);
    #elif ( PRESCALER == EXTERNAL_CLK_SOURCE_RAISING_EDGE )
        SET_BIT(TCCR0_REG,TIMER0_TCCR0_CS00);
        SET_BIT(TCCR0_REG,TIMER0_TCCR0_CS01);
        SET_BIT(TCCR0_REG,TIMER0_TCCR0_CS02);
    #else
        #error  Wrong selection of Prescaller mode
    #endif
/*======================================*/
}

/************************************************************************************************/
/* Function Name : TIMER0_voidSetCallBack_OVF                                                   */
/* Description : Call Back Function To Assign the address of OVF APP. Fun. at Global Pointer    */                                          
/* Fun. Argument1: (*Local_PointerToFunction_OVF) { Address of OVF Application Function }       */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void TIMER0_voidSetCallBack_OVF (void (*Local_PointerToFunction_OVF) (void), f32 const requiredTime_ms)
{
    u32 TimerCLK = 8UL / PRESCALER;
    u32 OVF_Tome = 256UL * TimerCLK; // 256 MircoSeconed
    f32 counterOVF = (requiredTime_ms * 1000UL) / (f32)256; // 3906.25
    Global_counterOVF = (u32)counterOVF; // 3906      // 3906.25 - 3906.00 = 0.25
    u8 preLoadValue = 256U - (256U * ((f32)(counterOVF - ((f32)Global_counterOVF)))); // 256 - 64 = 192
    if((preLoadValue > 0U) && (preLoadValue < 255U)) {
        TIMER0_voidSetPreloadValue(preLoadValue);
        Global_counterOVF++;
    }
    Global_PointerToFunction_OVF_T0 = Local_PointerToFunction_OVF ;
}

/************************************************************************************************/
/* Function Name : TIMER0_voidSetCallBack_CTC                                                   */
/* Description : Call Back Function To Assign the address of CTC APP. Fun. at Global Pointer    */                                          
/* Fun. Argument1: (*Local_PointerToFunction_CTC) { Address of CTC Application Function }       */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void TIMER0_voidSetCallBack_CTC (void (*Local_PointerToFunction_CTC) (void))
{
    Global_PointerToFunction_CTC_T0 = Local_PointerToFunction_CTC ;
}

/************************************************************************************************/
/* Function Name : TIMER0_voidSetPreloadValue                                                   */
/* Description : Set Preload Value in a Timer Register to Start Count From this Preload Value   */                                          
/* Fun. Argument1: Copy_u8PreloadValue  { from  0  To  255 }                                    */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void TIMER0_voidSetPreloadValue ( u8 Local_u8PreloadValue )
{
    #if (MODE == NORMAL_OVF)
        TCNT0_REG = Local_u8PreloadValue ;
        Global_u8PreloadValue = Local_u8PreloadValue ;
    #else
        // No Action
    #endif
}

/************************************************************************************************/
/* Function Name : TIMER0_voidSetCompareMatchValue                                              */
/* Description : Set Compare Match Value in OCR0 Register To make Timer Over Flow at This Value */                                          
/* Fun. Argument1: Copy_u8CompareMatchValue  { from  0  To  255 }                               */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void TIMER0_voidSetCompareMatchValue ( u8 Local_u8CompareMatchValue )
{
    #if (MODE == CTC)
        OCR0_REG = Local_u8CompareMatchValue ;
        Global_u8CompareMatchValue = Local_u8CompareMatchValue ;
    #elif ( MODE == FAST_PWM )
        OCR0_REG = Local_u8CompareMatchValue ;
    #elif (MODE == PWM_PHASECORRECT)
        OCR0_REG = Local_u8CompareMatchValue ;
    #endif
}

/************************************************************************************************/
/* Function Name : TIMER0_voidSetCallBack_CTC_andRequiredTime_ms                                */
/* Description : Call Back Function To Assign the address of CTC APP. Fun. at Global Pointer    */                                         
/* Fun. Argument1: (*Local_PointerToFunction_CTC) { Address of CTC Application Function }       */
/* Fun. Argument2: Copy_u32Time_ms { Required Time }                                            */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void TIMER0_voidSetCallBack_CTC_andRequiredTime_ms (void (*Local_PointerToFunction_CTC) (void),u32 Copy_u32Time_ms)
{
    TIMER0_voidSetCompareMatchValue (200);
    TIMER0_voidSetCallBack_CTC (Local_PointerToFunction_CTC);
    Global_u32Time_ms = Copy_u32Time_ms ;
}

/**************************************************************************************************/
/* Function Name : TIMER0_voidSetBusyWait_ms                                                      */
/* Description : Set Busy Wait Function work as Delay by make Processor Stuck in Fun. during Time */                                          
/* Fun. Argument1: Copy_u32Time_ms  { any Time in Milliseconds }                                  */
/* Fun. Return : void                                                                             */
/**************************************************************************************************/
void TIMER0_voidSetBusyWait_ms ( u32 Copy_u32Time_ms )
{
    CLEAR_BIT(TIMSK_REG,TIMER0_TIMSK_OCIE0);              // Disable T0 CTC Interrupt [PIE].
    u32 Counter_CTC = 0 ;
    TIMER0_voidSetCompareMatchValue (200);
    Counter_CTC = ( Copy_u32Time_ms * 1000UL ) /200 ;     // Counter_CTC = (Required Time(ms) * 1000) / (Compare Match Value)
    u32 iter = 0 ;
    for ( iter =0 ; iter < Counter_CTC ; iter++)
    {
    	u8 Local_u8Flag ;
    	Local_u8Flag = GET_BIT(TIFR_REG,TIMER0_TIFR_OCF0);
    	while ( Local_u8Flag == 0 )
    	{
    		Local_u8Flag = GET_BIT(TIFR_REG,TIMER0_TIFR_OCF0);      // Polling in the CTC Flag
    	}
		SET_BIT(TIFR_REG,TIMER0_TIFR_OCF0);						    // Clear Flag
    }
    SET_BIT(TIMSK_REG,TIMER0_TIMSK_OCIE0);          // Enable T0 CTC Interrupt [PIE]. 
}

/************************************************************************************************/
/* Function Name : TIMER0_voidBahaaPWM                                                          */
/* Description : Set Compare Match Value in OCR0 Register To make PWM at PIN OC0                */                                          
/* Fun. Argument1: Local_u8CompareMatchValue  { from  0  To  255 }                              */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void TIMER0_voidBahaaPWM ( u8 Local_u8CompareMatchValue )
{
    TIMER0_voidSetCompareMatchValue ( Local_u8CompareMatchValue );
}
/*  // For Loop to Increase PWM and Decrease PWM used in APPLICATION.
    for ( u16 Counter=0 ; Counter <= 255 ; Counter++ )
    {
        TIMER0_voidBahaaPWM (Counter);
        _delay_ms(10);
    }
    for ( u16 Counter=0 ; Counter <= 255 ; Counter++ )
    {
        TIMER0_voidBahaaPWM (255-Counter);
        _delay_ms(10);
    }
*/


/*=============================================================================================================*/
/* ==========================================         TSR Functions          ==================================*/
/*=============================================================================================================*/

/*****************************************************************************/
/* Function Name : void __vector_11 (void) [ISR Function]                    */
/* Description : ISR Prototype (position 11 on vector table OVF TIMER0 )     */ 
/* Fun. Return : void                                                        */
/*****************************************************************************/
/**************     [ISR] to OVF     *************/
void __vector_11 (void)   __attribute__((signal));
void __vector_11 (void)
{
    static u32 counter = 0 ;
    counter ++ ;
    if ( counter == Global_counterOVF )
    {
        if(Global_PointerToFunction_OVF_T0 != NULL)
		{
    		Global_PointerToFunction_OVF_T0();                 // Action of OVF Application Function
		}
        counter = 0 ; 
        TCNT0_REG = Global_u8PreloadValue ;                 // For Next Period Preload Value.
    }
}

/*****************************************************************************/
/* Function Name : void __vector_10 (void) [ISR Function]                    */
/* Description : ISR Prototype (position 10 on vector table CTC TIMER0 )     */ 
/* Fun. Return : void                                                        */
/*****************************************************************************/
/**************     [ISR] to CTC     *************/
void __vector_10 (void)   __attribute__((signal));
void __vector_10 (void)
{
    u32 Counter_CTC = 0 ;
    Counter_CTC = ( Global_u32Time_ms * 1000UL ) / (200) ;        // Counter_CTC = (Required Time(ms) * 1000) / (Compare Match Value)
    static u16 counter = 0 ;
    counter ++ ;
    if(Global_u32Time_ms == 0)
    {
        if ( counter == 5000 )
        {
            if(Global_PointerToFunction_CTC_T0 != NULL)
		    {
                Global_PointerToFunction_CTC_T0();                  // Action of CTC Application Function 
		    }                
            counter = 0 ;                                        // For Next Period.
            OCR0_REG = Global_u8CompareMatchValue ;              // For Next Period Compare Match Value.
        }
    }
    else
    {
        if ( counter == Counter_CTC )
        {
            if(Global_PointerToFunction_CTC_T0 != NULL)
		    {
                Global_PointerToFunction_CTC_T0();                  // Action of CTC Application Function 
		    }                
            counter = 0 ;                                        // For Next Period.
            OCR0_REG = Global_u8CompareMatchValue ;              // For Next Period Compare Match Value.
        }
    }
    
}
