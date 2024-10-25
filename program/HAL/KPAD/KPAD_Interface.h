/*===================================================================================================*/
/*  File        : KPAD_Interface.h                                                                    */
/*  Description : This interface file includes KPAD Driver prototypes and declarations for Atmega32   */
/*  Author      : Ahmed Bahaa Taha Nasr. Embedded SW Engineer                                        */
/*  Date        : 30/3/2023                                                                          */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-bahaa1/                                          */
/*  Git account : https://github.com/ahmedbahaa11                                                    */
/*  mail        : abahaa14842@gmail.com                                                              */
/*===================================================================================================*/

/* File Gaurd by ifndef & endif */
#ifndef KPAD_INTERFACE_H
#define KPAD_INTERFACE_H

/*==============================================================================================*/
/**************************      A.BAHAA KPAD Functions Prototype       *************************/
/*==============================================================================================*/
/**********************************  KPAD_voidInit                *******************************/
/**********************************  KPAD_u8GetPressedKey         *******************************/
/*==============================================================================================*/

/******************************************/
/* Function Name : KPAD_voidInit          */
/* Description : Initializing the KPAD    */
/* Fun. Return : void                     */
/******************************************/
void KPAD_voidInit (void);
/*****************************************************************************************/
/* Function Name : KPAD_u8GetPressedKey                                                  */
/* Description : Write a Pattern on the LCD at specific Line & Position                  */
/* Fun. Return : unsigned character ( The Oressed Key / Key = 0xff if not key pressed )  */                                                                 
/*****************************************************************************************/
u8   KPAD_u8GetPressedKey (void);



#endif