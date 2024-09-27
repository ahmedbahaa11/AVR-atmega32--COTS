/*=================================================================================*/
/*  File        : 7_SEGMENT_Program.c                                              */
/*  Description : This file includes 7_SEGMENT Driver implementations for Atmega32 */
/*  Author      : Ahmed Bahaa Taha Nasr. Embedded SW Engineer                      */
/*  Date        : 28/3/2023                                                        */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-bahaa1/                        */
/*  Git account : https://github.com/ahmedbahaa11                                  */
/*  mail        : ahmedbahaataha7@gmil.com                                         */
/*=================================================================================*/

/* Include Header Files From LIB */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

/* Include Header Files From MCAL Layer */
#include "../../MCAL/DIO/DIO_Interface.h"

/* Include My own Header Files*/
#include "SEVEN_SEGMENT_Interface.h"
#include "SEVEN_SEGMENT_Private.h"
#include "SEVEN_SEGMENT_Config.h"

u8 Common_Anode_Arr[10]= {ZERO,ONE,TWO,THREE,FOUR,FIVE,SEX,SEVEN,EIGHT,NINE} ;


/*======================================================================================================================*/
/***********************************     A.BAHAA 7_SEGMENT Functions Implementation     *********************************/
/*======================================================================================================================*/
/********************************************    SEGMENT_voidInitSegmentPort       **************************************/
/********************************************    SEGMENT_voidPrintNumber           **************************************/
/*======================================================================================================================*/




/*****************************************************************************************************/
/* Function Name : SEGMENT_voidInitSegmentPort                                                       */
/* Description : Initialize one 7-Segment on specific Port ant make it direction as OUTPUT           */
/* Fun. Argument1: Copy_u8PortNumber { PORTA,PORTB,PORTC,PORTD }                                     */
/* Fun. Return : void                                                                                */
/*****************************************************************************************************/
void SEGMENT_voidInitSegmentPort ( u8 Copy_u8PortNumber )
{
    switch(Copy_u8PortNumber)
    {
        case PORTA :   DIO_voidSetPortDirection (PORTA,OUTPUT);    break;
        case PORTB :   DIO_voidSetPortDirection (PORTB,OUTPUT);    break;
        case PORTC :   DIO_voidSetPortDirection (PORTC,OUTPUT);    break;
        case PORTD :   DIO_voidSetPortDirection (PORTD,OUTPUT);    break;
        default    :                                               break;
    }
}
/*****************************************************************************************************/
/* Function Name : SEGMENT_voidPrintNumber                                                           */
/* Description : Print Number from 0 to 9 at the 7-Segment                                           */
/* Fun. Argument1: Copy_u8PortNumber { PORTA,PORTB,PORTC,PORTD }                                     */
/* Fun. Argument2: Copy_SegmentPolarity { COMMON_ANODE , COMMON_CATHODE }                            */
/* Fun. Argument3: Copy_u8Number { 0,1,2,3,4,5,6,7,8,9 }                                             */
/* Fun. Return : void                                                                                */
/*****************************************************************************************************/
void SEGMENT_voidPrintNumber ( u8 Copy_u8PortNumber , u8 Copy_SegmentPolarity , u8 Copy_u8Number )
{
    switch ( Copy_SegmentPolarity )
    {
        case COMMON_ANODE   :   switch(Copy_u8PortNumber)
                                {
                                    case PORTA :   DIO_voidSetPortValue (PORTA,Common_Anode_Arr[Copy_u8Number]);    break;
                                    case PORTB :   DIO_voidSetPortValue (PORTB,Common_Anode_Arr[Copy_u8Number]);    break;
                                    case PORTC :   DIO_voidSetPortValue (PORTC,Common_Anode_Arr[Copy_u8Number]);    break;
                                    case PORTD :   DIO_voidSetPortValue (PORTD,Common_Anode_Arr[Copy_u8Number]);    break;
                                    default    :                                                                    break;
                                }
                                break;
        case COMMON_CATHODE :   switch(Copy_u8PortNumber)
                                {
                                    case PORTA :   DIO_voidSetPortValue (PORTA,~Common_Anode_Arr[Copy_u8Number]);    break;
                                    case PORTB :   DIO_voidSetPortValue (PORTB,~Common_Anode_Arr[Copy_u8Number]);    break;
                                    case PORTC :   DIO_voidSetPortValue (PORTC,~Common_Anode_Arr[Copy_u8Number]);    break;
                                    case PORTD :   DIO_voidSetPortValue (PORTD,~Common_Anode_Arr[Copy_u8Number]);    break;
                                    default    :                                                                    break;
                                }   
                                break;
        default             :   break;
    }
    
}





