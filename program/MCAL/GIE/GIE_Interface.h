/*===================================================================================================*/
/*  File        : GIE_Interface.h                                                                    */
/*  Description : This interface file includes GIE Driver prototypes and declarations for Atmega32   */
/*  Author      : Ahmed Bahaa Taha Nasr. Embedded SW Engineer                                        */
/*  Date        : 2/4/2023                                                                           */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-bahaa1/                                          */
/*  Git account : https://github.com/ahmedbahaa11                                                    */
/*  mail        : abahaa14842@gmail.com                                                              */
/*===================================================================================================*/

/* File Gaurd by ifndef & endif */
#ifndef GIE_INTERFACE_H
#define GIE_INTERFACE_H

/*** Macros as Status options ***/
#define ON               1
#define OFF              0


/*================================================================================================================*/
/*====================================       A.BAHAA GIE Functions Prototype        ==============================*/
/*================================================================================================================*/
/********************************************    GIE_void_GI_Enable       *****************************************/
/*================================================================================================================*/


/*****************************************************************************/
/* Function Name : GIE_void_GI_Enable                                        */
/* Description : Enable or Disable GIE General Interrupt                     */ 
/* Fun. Argument1: Copy_u8Status { ON , OFF }                                */
/* Fun. Return : void                                                        */
/*****************************************************************************/
void GIE_void_GI_Enable ( u8 Copy_u8Status );


#endif