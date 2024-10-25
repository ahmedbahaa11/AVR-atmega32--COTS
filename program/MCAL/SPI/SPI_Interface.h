/*===================================================================================================*/
/*  File        : SPI_Interface.h                                                                    */
/*  Description : This interface file includes SPI Driver prototypes and declarations for Atmega32   */
/*  Author      : Ahmed Bahaa Taha Nasr. Embedded SW Engineer                                        */
/*  Date        : 12/4/2023                                                                          */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-bahaa1/                                          */
/*  Git account : https://github.com/ahmedbahaa11                                                    */
/*  mail        : abahaa14842@gmail.com                                                              */
/*===================================================================================================*/

/* File Gaurd by ifndef & endif */
#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

/*============================================================================================================*/
/*===============================       A.BAHAA SPI Functions Prototypes        ==============================*/
/*============================================================================================================*/
/***************************        [1]  SPI_voidMasterInit                         ***************************/
/***************************        [2]  SPI_voidSlaveInit                          ***************************/
/***************************        [3]  SPI_u8TranceiveData                        ***************************/
/***************************        [4]  SPI_voidTransmitData                       ***************************/
/***************************        [5]  SPI_voidRecieveData                        ***************************/
/***************************        [6]  SPI_voidTranceiveString                    ***************************/
/***************************        [7]  SPI_u8AsynTranceiveData                    ***************************/
/***************************        [8]  SPI_voidSetCallBack                        ***************************/
/*============================================================================================================*/

/************************************************************************************************/
/* Function Name : SPI_voidMasterInit                                                           */
/* Description : Initilization of Master Mode                                                   */                                         
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void SPI_voidMasterInit (void);

/************************************************************************************************/
/* Function Name : SPI_voidSlaveInit                                                            */
/* Description : Initilization of Slave Mode                                                    */                                         
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void SPI_voidSlaveInit (void);

/************************************************************************************************/
/* Function Name : SPI_u8TranceiveData                                                          */
/* Description : Function can Transmit and Recieve Char                                         */                                         
/* Fun. Argument1: Copy_u8Data { Transsmited Data }                                             */
/* Fun. Return : unsigned Char u8  { Recieved Data }                                            */
/************************************************************************************************/
u8 SPI_u8TranceiveData (u8 Copy_u8Data);

/************************************************************************************************/
/* Function Name : SPI_voidTransmitData                                                         */
/* Description : Function can Transmit Char                                                     */                                         
/* Fun. Argument1: Copy_u8Data { Transsmited Data }                                             */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void SPI_voidTransmitData (u8 Copy_u8Data);

/************************************************************************************************/
/* Function Name : SPI_voidRecieveData                                                          */
/* Description : Function can Recieve Char                                                      */                                         
/* Fun. Return : void                                                                           */
/************************************************************************************************/
u8 SPI_voidRecieveData (void);

/************************************************************************************************/
/* Function Name : SPI_voidTranceiveString                                                      */
/* Description : Function can Transmit and Recieve String as Array of Char passing by reference */                                         
/* Fun. Argument1: *Copy_Au8TransmitString { Address of array of Char we need Transmit it }     */
/* Fun. Argument2: *Copy_u8RecieveString   { Address of array of Char we need Recieve it }      */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void SPI_voidTranceiveString (u8 *Copy_Au8TransmitString , u8 *Copy_u8RecieveString );

/*****************************************************************************/
/* Function Name : SPI_voidSetCallBack                                       */
/* Description : Function Call Back that assign Pointer of application       */
/*               Function to our global pointer to use it at ISR Fun.        */
/* Fun. Argument1:{ void (*LocalPointerToFunction) (u8 *Copy_u8RecivedData) }*/
/*                Pointer to function that = Address of application function */
/* Fun. Return : void                                                        */
/*****************************************************************************/
void SPI_voidSetCallBack (  void (*Local_PointerToFunction) (u8 *Copy_u8RecivedData) );

/************************************************************************************************/
/* Function Name : SPI_u8AsynTranceiveData                                                      */
/* Description : Function can Transmit and Recieve Data by Interrupt                            */                                         
/* Fun. Argument1: Copy_u8Data { Transsmited Data }                                             */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void SPI_u8AsynTranceiveData (u8 Copy_u8Data);


#endif