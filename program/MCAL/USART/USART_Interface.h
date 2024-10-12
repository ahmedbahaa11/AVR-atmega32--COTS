/*===================================================================================================*/
/*  File        : USART_Interface.h                                                                  */
/*  Description : This interface file includes USART Driver prototypes and declarations for Atmega32 */
/*  Author      : Ahmed Bahaa Taha Nasr. Embedded SW Engineer                                        */
/*  Date        : 11/4/2023                                                                          */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-bahaa1/                                          */
/*  Git account : https://github.com/ahmedbahaa11                                                    */
/*  mail        : ahmedbahaataha7@gmil.com                                                           */
/*===================================================================================================*/

/* File Gaurd by ifndef & endif */
#ifndef USART_INTERFACE_H
#define USART_INTERFACE_H


/*============================================================================================================*/
/*=============================         A.BAHAA USART Functions Prototype          ===========================*/
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
void USART_voidInit (void);

/************************************************************************************************/
/* Function Name : USART_voidSendData                                                           */
/* Description : Function can Transmit Char                                                     */                                         
/* Fun. Argument1: Copy_u8Data { Transsmited Data }                                             */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void USART_voidSendData (u8 Copy_u8Data);

/************************************************************************************************/
/* Function Name : USART_voidRecieveData                                                        */
/* Description : Function can Recieve Data                                                      */ 
/* Fun. Argument1: *Copy_Pu8Data Pointer to { Recived Data }                                    */                                        
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void USART_voidRecieveData (u8 *Copy_Pu8Data);

/**************************************************************************************************/
/* Function Name : USART_voidAsyncSendData                                                        */
/* Description : Function can Transmit Data by Asyncrouns Function (ISR)                          */                                         
/* Fun. Argument1: Copy_u8Data { Transsmited Data }                                               */
/* Fun. Argument2: *Copy_Pu8CallBackFunIndication_TXC {address of Call Back Application Function} */
/* Fun. Return : void                                                                             */
/**************************************************************************************************/
void USART_voidAsyncSendData ( u8 Copy_u8Data , void (*Copy_Pu8CallBackFunIndication_TXC)(void));

/**************************************************************************************************/
/* Function Name : USART_voidAsyncRecieveData                                                     */
/* Description : Function can Transmit Data by Asyncrouns Function (ISR)                          */                                         
/* Fun. Argument1: *Copy_Pu8Data Pointer to { Recived Data }                                      */ 
/* Fun. Return : void                                                                             */
/**************************************************************************************************/
void USART_voidAsyncRecieveData (u8 *Copy_Pu8Data);

#endif