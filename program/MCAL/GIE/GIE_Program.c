/*=================================================================================*/
/*  File        : GIE_Program.c                                                    */
/*  Description : This file includes GIE Driver implementations for Atmega32       */
/*  Author      : Ahmed Bahaa Taha Nasr. Embedded SW Engineer                      */
/*  Date        : 2/4/2023                                                         */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-bahaa1/                        */
/*  Git account : https://github.com/ahmedbahaa11                                  */
/*  mail        : abahaa14842@gmail.com                                            */
/*=================================================================================*/

/* Include Header Files From LIB */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

/* Include My own Header Files*/
#include "GIE_Interface.h"
#include "GIE_Private.h"
#include "GIE_Config.h"

/*=================================================================================================================*/
/*====================================     A.BAHAA GIE Functions Implementation      ==============================*/
/*=================================================================================================================*/
/********************************************    GIE_void_GI_Enable       ******************************************/
/*=================================================================================================================*/


/*****************************************************************************/
/* Function Name : GIE_void_GI_Enable                                        */
/* Description : Enable or Disable GIE General Interrupt                     */ 
/* Fun. Argument1: Copy_u8Status { ON , OFF }                                */
/* Fun. Return : void                                                        */
/*****************************************************************************/
void GIE_void_GI_Enable ( u8 Copy_u8Status )
{
    switch ( Copy_u8Status )
    {
        case ON  :    SET_BIT(SREG_REG,7);       break;
        case OFF :    CLEAR_BIT(SREG_REG,7);     break;
        default  :                               break;
    }
}
