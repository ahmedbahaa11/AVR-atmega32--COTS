/*===================================================================================================*/
/*  File        : ICU_Interface.h                                                                    */
/*  Description : This interface file includes ICU Driver prototypes and declarations for Atmega32   */
/*  Author      : Ahmed Bahaa Taha Nasr. Embedded SW Engineer                                        */
/*  Date        : 29/4/2023                                                                          */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-bahaa1/                                          */
/*  Git account : https://github.com/ahmedbahaa11                                                    */
/*  mail        : ahmedbahaataha7@gmil.com                                                           */
/*===================================================================================================*/

/* File Gaurd by ifndef & endif */
#ifndef ICU_INTERFACE_H
#define ICU_INTERFACE_H

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
void ICU_voidInit (void);

/************************************************************************************************/
/* Function Name : ICU_u16GetReadICR1                                                           */
/* Description   : Get Reading From ICR1 Register                                               */                                          
/* Fun. Return   : u16 ( Reading of TIMER1 REG from 0 To 65536 )                                */
/************************************************************************************************/
u16 ICU_u16GetReadICR1 (void);

/************************************************************************************************/
/* Function Name : ICU_voidDisableInterrupt                                                     */
/* Description   : Disable Input Capture Interrupt                                              */                                          
/* Fun. Return   : void                                                                         */
/************************************************************************************************/
void ICU_voidDisableInterrupt(void);

/************************************************************************************************/
/* Function Name : ICU_voidEdgeSelect                                                           */
/* Description : Select Edge Sensing of ICP1 Input Capture Unit PIN                             */                                          
/* Fun. Argument1: Copy_u8EdgeSelect { FALLING_EDGE , RAISING_EDGE }                            */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void ICU_voidEdgeSelect ( u8 Copy_u8EdgeSelect );

/************************************************************************************************/
/* Function Name : ICU_SetCallBackFun                                                           */
/* Description  : Call Back Function                                                            */                                          
/* Fun. Argument1: void (*LocalPF_vector_6) (void) { address of App CallBack Fun ICU_HW }       */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void ICU_SetCallBackFun ( void (*LocalPF_vector_6) (void));


/*=====================================================================*/
/*  (ICES1) Input Capture Edge Select { Falling Edge , Raising Edge }  */
/*---------------------------------------------------------------------*/
#define     FALLING_EDGE                        0
#define     RAISING_EDGE                        1

#endif