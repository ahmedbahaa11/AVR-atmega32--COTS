/*========================================================================================================*/
/*  File        : SEVEN_SEGMENT_Interface.h                                                               */
/*  Description : This interface file includes 7_SEGMENT Driver prototypes and declarations for Atmega32  */
/*  Author      : Ahmed Bahaa Taha Nasr. Embedded SW Engineer                                             */
/*  Date        : 28/3/2023                                                                               */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-bahaa1/                                               */
/*  Git account : https://github.com/ahmedbahaa11                                                         */
/*  mail        : abahaa14842@gmail.com                                                                   */
/*========================================================================================================*/

/* File Gaurd by ifndef & endif */
#ifndef SEVEN_SEGMENT_INTERFACE_H
#define SEVEN_SEGMENT_INTERFACE_H

/* Segment Polarity */
#define COMMON_ANODE               0
#define COMMON_CATHODE             1





/*======================================================================================================================*/
/***********************************       A.BAHAA 7_SEGMENT Functions Prototype       **********************************/
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
void SEGMENT_voidInitSegmentPort ( u8 Copy_u8PortNumber );
/*****************************************************************************************************/
/* Function Name : SEGMENT_voidPrintNumber                                                           */
/* Description : Print Number from 0 to 9 at the 7-Segment                                           */
/* Fun. Argument1: Copy_u8PortNumber { PORTA,PORTB,PORTC,PORTD }                                     */
/* Fun. Argument2: Copy_SegmentPolarity { COMMON_ANODE , COMMON_CATHODE }                            */
/* Fun. Argument3: Copy_u8Number { 0,1,2,3,4,5,6,7,8,9 }                                             */
/* Fun. Return : void                                                                                */
/*****************************************************************************************************/
void SEGMENT_voidPrintNumber ( u8 Copy_u8PortNumber , u8 Copy_SegmentPolarity , u8 Copy_u8Number );


#endif