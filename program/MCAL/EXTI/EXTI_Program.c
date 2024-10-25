/*=================================================================================*/
/*  File        : EXTI_Program.c                                                    */
/*  Description : This file includes EXTI Driver implementations for Atmega32       */
/*  Author      : Ahmed Bahaa Taha Nasr. Embedded SW Engineer                      */
/*  Date        : 2/4/2023                                                        */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-bahaa1/                        */
/*  Git account : https://github.com/ahmedbahaa11                                  */
/*  mail        : abahaa14842@gmail.com                                            */
/*=================================================================================*/

/* Include Header Files From LIB */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

/* Include My own Header Files*/
#include "EXTI_Interface.h"
#include "EXTI_Private.h"
#include "EXTI_Config.h"

/* Global Pointer to Function */
void (*Global_PF_Vector_1)(void) = NULL ;
void (*Global_PF_Vector_2)(void) = NULL ;
void (*Global_PF_Vector_3)(void) = NULL ;


/*=================================================================================================================*/
/*====================================     A.BAHAA EXTI Functions Implementation      =============================*/
/*=================================================================================================================*/
/**********************************************  [1]  EXTI_voidEnable          *************************************/
/**********************************************  [2]  EXTI_voidDisable         *************************************/
/**********************************************  [3]  EXTI_voidSetCallBack     *************************************/
/*******************************     void __vector_1 (void)   __attribute__((signal));     *************************/
/*******************************     void __vector_2 (void)   __attribute__((signal));     *************************/
/*******************************     void __vector_3 (void)   __attribute__((signal));     *************************/
/*=================================================================================================================*/


/*********************************************************************************************/
/* Function Name : EXTI_voidEnable                                                           */
/* Description :  Enable (PIE) Peripheral Interrupt Enable and Put Sesnse Control            */ 
/* Fun. Argument1: Copy_u8INTnumber { INT0 , INT1 , INT2 }                                   */
/* Fun. Argument1: Copy_u8SenseControl {FALLING_EDGE, RAISING_EDGE, LOW_LEVEL, ON_CHANGE}    */
/* Fun. Return : void                                                                        */
/*********************************************************************************************/
void EXTI_voidEnable ( u8 Copy_u8INTnumber , u8 Copy_u8SenseControl )
{
    switch ( Copy_u8INTnumber )
    {
        case INT0 :     SET_BIT(GICR_REG,PIN6);             // Set 1 On PIN6 At GTCR_REG to [Enable] (PIE) Peripheral Interrupt Enable to INT0 .
                        switch ( Copy_u8SenseControl )
                        {                                                                                                   // BIT1  -  BIT0  on MCUCR_REG
                            case FALLING_EDGE :     SET_BIT(MCUCR_REG,PIN1);      CLEAR_BIT(MCUCR_REG,PIN0);      break;    //   1   -   0   Falling Edge
                            case RAISING_EDGE :     SET_BIT(MCUCR_REG,PIN1);      SET_BIT(MCUCR_REG,PIN0);        break;    //   1   -   1   Raising Edge  
                            case LOW_LEVEL    :     CLEAR_BIT(MCUCR_REG,PIN1);    CLEAR_BIT(MCUCR_REG,PIN0);      break;    //   0   -   0   Low Level  
                            case ON_CHANGE    :     CLEAR_BIT(MCUCR_REG,PIN1);    SET_BIT(MCUCR_REG,PIN0);        break;    //   0   -   1   On Change   
                            default           :                                                                   break;
                        }
                        break;
        case INT1 :     SET_BIT(GICR_REG,PIN7);             // Set 1 On PIN7 At GTCR_REG to [Enable] (PIE) Peripheral Interrupt Enable to INT1 .
                        switch ( Copy_u8SenseControl )
                        {                                                                                                   // BIT3  -  BIT2  on MCUCR_REG
                            case FALLING_EDGE :     SET_BIT(MCUCR_REG,PIN3);      CLEAR_BIT(MCUCR_REG,PIN2);      break;    //   1   -   0   Falling Edge
                            case RAISING_EDGE :     SET_BIT(MCUCR_REG,PIN3);      SET_BIT(MCUCR_REG,PIN2);        break;    //   1   -   1   Raising Edge
                            case LOW_LEVEL    :     CLEAR_BIT(MCUCR_REG,PIN3);    CLEAR_BIT(MCUCR_REG,PIN2);      break;    //   0   -   0   Low Level
                            case ON_CHANGE    :     CLEAR_BIT(MCUCR_REG,PIN3);    SET_BIT(MCUCR_REG,PIN2);        break;    //   0   -   1   On Change 
                            default           :                                                                   break;  
                        }
                        break;
        case INT2 :     SET_BIT(GICR_REG,PIN5);             // Set 1 On PIN5 At GTCR_REG to [Enable] (PIE) Peripheral Interrupt Enable to INT2 .
                        switch ( Copy_u8SenseControl )
                        {                                                                      //  BIT6  on  MCUCSR_REG
                            case FALLING_EDGE :     CLEAR_BIT(MCUCSR_REG,PIN6);      break;    //   0    Falling Edge   
                            case RAISING_EDGE :     SET_BIT(MCUCSR_REG,PIN6);        break;    //   1    Raising Edge
                            default           :                                      break;  
                        } 
                        break;
        default   :     break;
    }
}

/*****************************************************************************/
/* Function Name : EXTI_voidDisable                                          */
/* Description :  Disable (PIE) Peripheral Interrupt Enable                  */ 
/* Fun. Argument1: Copy_u8INTnumber { INT0 , INT1 , INT2 }                   */
/* Fun. Return : void                                                        */
/*****************************************************************************/
void EXTI_voidDisable ( u8 Copy_u8INTnumber )
{
    switch ( Copy_u8INTnumber )
    {
        case INT0 :     CLEAR_BIT(GICR_REG,PIN6);   break;    // Set 0 On PIN6 At GTCR_REG to [Disable] (PIE) Peripheral Interrupt Enable to INT0 .
        case INT1 :     CLEAR_BIT(GICR_REG,PIN7);   break;    // Set 0 On PIN7 At GTCR_REG to [Disable] (PIE) Peripheral Interrupt Enable to INT1 .
        case INT2 :     CLEAR_BIT(GICR_REG,PIN5);   break;    // Set 0 On PIN5 At GTCR_REG to [Disable] (PIE) Peripheral Interrupt Enable to INT2 .
        default   :                                 break;
    }
}

/*****************************************************************************/
/* Function Name : EXTI_voidSetCallBack                                      */
/* Description : Function Call Back that assign Pointer of application       */
/*               Function to our global pointer to use it at ISR Fun.        */
/* Fun. Argument1: Copy_u8INTnumber { INT0 , INT1 , INT2 }                   */ 
/* Fun. Argument2:{ void (*LocalPointerToFunction) (void) }                  */
/*                Pointer to function that = Address of application function */
/* Fun. Return : void                                                        */
/*****************************************************************************/
void EXTI_voidSetCallBack ( u8 Copy_u8INTnumber , void (*Local_PointerToFunction) (void) )
{
    switch( Copy_u8INTnumber )
    {
        case INT0 :     Global_PF_Vector_1 = Local_PointerToFunction ;     break;
        case INT1 :     Global_PF_Vector_2 = Local_PointerToFunction ;     break; 
        case INT2 :     Global_PF_Vector_3 = Local_PointerToFunction ;     break; 
        default   :                                                        break; 
    } 
}


/*===========================================================================*/
/* =====================         TSR Functions          =====================*/
/*===========================================================================*/

/*****************************************************************************/
/* Function Name : void __vector_1 (void) [ISR Function]                     */
/* Description : ISR Prototype (position 1 on vector table INT0 )            */ 
/* Fun. Return : void                                                        */
/*****************************************************************************/
void __vector_1 (void)   __attribute__((signal));
void __vector_1 (void)
{
    if ( Global_PF_Vector_1 != NULL )
    {
        Global_PF_Vector_1 ();  // calling Global pointer to function that contain address of Application Function with INT0. 
    }

}
/*****************************************************************************/
/* Function Name : void __vector_2 (void) [ISR Function]                     */
/* Description : ISR Prototype (position 2 on vector table INT1 )            */ 
/* Fun. Return : void                                                        */
/*****************************************************************************/
void __vector_2 (void)   __attribute__((signal));
void __vector_2 (void) 
{
    if ( Global_PF_Vector_2 != NULL )
    {
        Global_PF_Vector_2 ();  // calling Global pointer to function that contain address of Application Function with INT1. 
    }
    
}
/*****************************************************************************/
/* Function Name : void __vector_3 (void) [ISR Function]                     */
/* Description : ISR Prototype (position 3 on vector table INT2 )            */ 
/* Fun. Return : void                                                        */
/*****************************************************************************/
void __vector_3 (void)   __attribute__((signal));
void __vector_3 (void) 
{
    if ( Global_PF_Vector_3 != NULL )
    {
        Global_PF_Vector_3 ();  // calling Global pointer to function that contain address of Application Function with INT2.
    }
}