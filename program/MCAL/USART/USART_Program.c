/*=================================================================================*/
/*  File        : USART_Program.c                                                  */
/*  Description : This file includes USART Driver implementations for Atmega32     */
/*  Author      : Ahmed Bahaa Taha Nasr. Embedded SW Engineer                      */
/*  Date        : 11/4/2023                                                        */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-bahaa1/                        */
/*  Git account : https://github.com/ahmedbahaa11                                  */
/*  mail        : abahaa14842@gmail.com                                            */
/*=================================================================================*/

/* Include Header Files From LIB */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
/* Include My own Header Files*/
#include "USART_Interface.h"
#include "USART_Private.h"
#include "USART_Config.h"

/* Global Pointer to Function */
void (*Global_PF_Vector_15)(void)  = NULL ;
/* Global Variables */
u8 Global_u8TXData = 0 ;
u8 *Global_u8RXData = 0 ;

/*============================================================================================================*/
/*=============================       A.BAHAA USART Functions Implementation        ==========================*/
/*============================================================================================================*/
/***************************  [1]  USART_voidInit                                         *********************/
/***************************  [2]  USART_voidSendData                                     *********************/
/***************************  [3]  USART_voidRecieveData                                  *********************/
/***************************  [4]  USART_voidAsyncSendData                                *********************/
/***************************  [5]  USART_voidAsyncRecieveData                             *********************/
/***************************  [6]  void __vector_13 (void)    __attribute__((signal));    *********************/
/***************************  [7]  void __vector_14 (void)    __attribute__((signal));    *********************/
/***************************  [8]  void __vector_15 (void)    __attribute__((signal));    *********************/
/*============================================================================================================*/

/************************************************************************************************/
/* Function Name : USART_voidInit                                                               */
/* Description : Initilization of UART Mode                                                     */                                         
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void USART_voidInit (void)
{
/*======================================*/
/*          BAUD RATE Selection         */
/*--------------------------------------*/
    CLEAR_BIT(UBRRH_REG,UBRRH_URSEL);                    // access UBRRH to Configer the BAUD Rate
    u16 UBRR = 0 ;
    #if( SPEED == NORMAL_SPEED )                         // U2X = 1  Normal Speed Transsmition
        UBRR = ( CPU_CLK / ( BAUD_RATE * 8UL ) ) - 1 ;
    #elif( SPEED == DOUBBLE_SPEED )                      // U2X = 0  Double Speed Transsmition
        UBRR = ( CPU_CLK / ( BAUD_RATE * 16UL ) ) - 1 ;
    #endif                                                      // UBRR = 0b1111000000110011
    UBRRL_REG = (u8)(UBRR);                     // first 8 Bit  // (u8)UBRR = 0b00110011
    UBRRH_REG = (u8)(UBRR >> 8);                // second 8 Bit // (UBRR >> 8 ) = 0b0000000011110000
                                                                // (u8)(UBRR >> 8 ) = 0b11110000

/*======================================*/
/*        USART Initilization           */
/*--------------------------------------*/
    SET_BIT(UCSRC_REG,UCSRC_URSEL);             // Select UCSRC_REG
    CLEAR_BIT(UCSRC_REG,UCSRC_UMSE1);           // select Async Mode
/*======================================*/
/*         Select Parity Mode           */
/*--------------------------------------*/    
    #if ( Parity_Mode == DISABLE )              // Select Parity (Disable)
        CLEAR_BIT(UCSRC_REG,UCSRC_UPM0);
        CLEAR_BIT(UCSRC_REG,UCSRC_UPM1);
    #elif ( Parity_Mode == EVEN )               // Select Parity (EVEN)
        CLEAR_BIT(UCSRC_REG,UCSRC_UPM0);
          SET_BIT(UCSRC_REG,UCSRC_UPM1);
    #elif ( Parity_Mode == ODD )                // Select Parity (ODD)
          SET_BIT(UCSRC_REG,UCSRC_UPM0);
          SET_BIT(UCSRC_REG,UCSRC_UPM1);   
    #endif
/*======================================*/
/*          Select STOP BIT             */
/*--------------------------------------*/
    #if ( STOP_BIT == ONE )
    CLEAR_BIT(UCSRC_REG,UCSRC_USBS);             // select 1 Stop Bit
    #elif ( STOP_BIT == TWO )
      SET_BIT(UCSRC_REG,UCSRC_USBS);             // select 2 Stop Bit
    #endif
/*======================================*/
/*       Select Character Size          */
/*--------------------------------------*/
    // Character size [8] Bit
      SET_BIT(UCSRC_REG,UCSRC_UCSZ0);
      SET_BIT(UCSRC_REG,UCSRC_UCSZ1);
    CLEAR_BIT(UCSRB_REG,UCSRB_UCSZ2);
/*======================================*/
/*          Enable RX & TX              */
/*--------------------------------------*/     
    SET_BIT(UCSRB_REG,UCSRB_TXEN);               // Enable TX 
    SET_BIT(UCSRB_REG,UCSRB_RXEN);               // Enable RX 
/*======================================*/
}

/************************************************************************************************/
/* Function Name : USART_voidSendData                                                           */
/* Description : Function can Transmit Char                                                     */                                         
/* Fun. Argument1: Copy_u8Data { Transsmited Data }                                             */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void USART_voidSendData (u8 Copy_u8Data)
{
    // Polling flag Data Register is Empty.
    while ( (GET_BIT(UCSRA_REG,UCSRA_UDRE)) == 0 );
    // Transsmit Data.
    UDR_REG = Copy_u8Data ;
    /* Data Transsmition is Complete So The Flag of [UCSRA_TXC] is Raised */
    /* Then we Need Clear This Flag by SET ONE , To Next Transsmition     */
    SET_BIT(UCSRA_REG,UCSRA_TXC);
}

/************************************************************************************************/
/* Function Name : USART_voidRecieveData                                                        */
/* Description : Function can Recieve Data                                                      */ 
/* Fun. Argument1: *Copy_Pu8Data Pointer to { Recived Data }                                    */                                        
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void USART_voidRecieveData (u8 *Copy_Pu8Data)
{
    // Polling flag Data Recieve is Complete.
    while ( (GET_BIT(UCSRA_REG,UCSRA_RXC)) == 0 );
    // Recieve Data in Passing Pointer.
    *Copy_Pu8Data = UDR_REG ;
}

/**************************************************************************************************/
/* Function Name : USART_voidAsyncSendData                                                        */
/* Description : Function can Transmit Data by Asyncrouns Function (ISR)                          */                                         
/* Fun. Argument1: Copy_u8Data { Transsmited Data }                                               */
/* Fun. Argument2: *Copy_Pu8CallBackFunIndication_TXC {address of Call Back Application Function} */
/* Fun. Return : void                                                                             */
/**************************************************************************************************/
void USART_voidAsyncSendData ( u8 Copy_u8Data , void (*Copy_Pu8CallBackFunIndication_TXC)(void))
{
    SET_BIT(UCSRB_REG,UCSRB_UDRIE);                              // Enable UDRIE Data Register Empty Interrupt Enable.
    SET_BIT(UCSRB_REG,UCSRB_TXCIE);                              // Enable TXCIE Transmitt Complete Interrupt Enable.( For Indication )
    Global_u8TXData = Copy_u8Data ;                              // Assign Data to Global Variable to use it in ISR Fun.
    Global_PF_Vector_15 = Copy_Pu8CallBackFunIndication_TXC ;    // Assign The pointer that contain adderss of App CallBack Fun to Global pointer to Call it in ISR Fun.
}

/**************************************************************************************************/
/* Function Name : USART_voidAsyncRecieveData                                                     */
/* Description : Function can Transmit Data by Asyncrouns Function (ISR)                          */                                         
/* Fun. Argument1: *Copy_Pu8Data Pointer to { Recived Data }                                      */ 
/* Fun. Return : void                                                                             */
/**************************************************************************************************/
void USART_voidAsyncRecieveData (u8 *Copy_Pu8Data)
{
    SET_BIT(UCSRB_REG,UCSRB_RXCIE);            // Enable RXCIE Recieve Complete Interrupt Enable.
    Global_u8RXData = Copy_Pu8Data ;           // assign Passing Pointer to Global Pointer to Read Revived Data on This Passing Pointer in ISR (RXCIE)
}

/*===========================================================================*/
/*======================         TSR Functions          =====================*/
/*===========================================================================*/

/*****************************************************************************/
/* Function Name : void __vector_13 (void) [ISR Function]                    */
/* Description : ISR Prototype (position 13 on vector table RXCIE )          */
/*          This function for Recieve Data when INT Recieve Complete         */ 
/* Fun. Return : void                                                        */
/*****************************************************************************/
void __vector_13 (void)    __attribute__((signal));
void __vector_13 (void)
{
    *Global_u8RXData = UDR_REG ;        // Recieve Data in Passing Pointer.
}

/*****************************************************************************/
/* Function Name : void __vector_14 (void) [ISR Function]                    */
/* Description : ISR Prototype (position 14 on vector table UDRIE )          */ 
/*          This function for Transmitt Data when INT Data Register is Empty */
/* Fun. Return : void                                                        */
/*****************************************************************************/
void __vector_14 (void)    __attribute__((signal));
void __vector_14 (void)
{ 
    UDR_REG = Global_u8TXData ;         // Transsmit Data.
}

/*****************************************************************************/
/* Function Name : void __vector_15 (void) [ISR Function]                    */
/* Description : ISR Prototype (position 15 on vector table TXCIE )          */
/*              This function for Indication to Tramsmittion Complete        */ 
/* Fun. Return : void                                                        */
/*****************************************************************************/
void __vector_15 (void)    __attribute__((signal));
void __vector_15 (void)
{
   Global_PF_Vector_15 () ; // Call App Function That Indicator to Transmittion Complete.
}