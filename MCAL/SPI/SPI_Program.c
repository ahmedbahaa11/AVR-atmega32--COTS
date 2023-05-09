/*=================================================================================*/
/*  File        : SPI_Program.c                                                    */
/*  Description : This file includes SPI Driver implementations for Atmega32       */
/*  Author      : Ahmed Bahaa Taha Nasr. Embedded SW Engineer                      */
/*  Date        : 12/4/2023                                                        */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-bahaa1/                        */
/*  Git account : https://github.com/ahmedbahaa11                                  */
/*  mail        : ahmedbahaataha7@gmil.com                                         */
/*=================================================================================*/

/* Include Header Files From LIB */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

/* Include My own Header Files*/
#include "SPI_Interface.h"
#include "SPI_Private.h"
#include "SPI_Config.h"

/* Include Header Files From MCAL */
#include"../DIO/DIO_Interface.h"

/* Global Pointer to Function */
void (*Global_PF_Vector_12)(u8 *Copy_u8RecivedData) = NULL ;

/*============================================================================================================*/
/*=============================       A.BAHAA SPI Functions Implementation        ============================*/
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
void SPI_voidMasterInit (void)
{
/*======================================*/
/*        Master I/O PIN Mode           */
/*--------------------------------------*/
    DIO_voidSetPinDirection(PORTB,PIN5,OUTPUT);         // MOSI OUTPUT in Master Mode
    DIO_voidSetPinDirection(PORTB,PIN6,INPUT);          // MISO INPUT  in Master Mode
    DIO_voidSetPinDirection(PORTB,PIN7,OUTPUT);         // CLOK OUTPUT in Master Mode
    DIO_voidSetPinDirection(PORTB,PIN4,INPUT);          // SS Slave Select INPUT in Master Mode if we have one Slave only
    DIO_voidConfig_Pull_Up_Pin(PORTB,PIN4,ON);          // For Protection From Noise and Set 0 at SS in Slave to Activate this one Slave
/*======================================*/
/*          Select Master  Mode         */
/*--------------------------------------*/    
        SET_BIT(SPCR_REG,SPCR_MSTR);
/*======================================*/
/*    Select MSB or LSB Send at First   */
/*--------------------------------------*/   
    #if ( DATA_ORDER == MSB_FIRST )
        CLEAR_BIT(SPCR_REG,SPCR_DORD);                  // select MSB to be send first
    #elif ( DATA_ORDER == LSB_FIRST )
        SET_BIT(SPCR_REG,SPCR_DORD);                    // select LSB to be send first
    #endif
/*===========================================*/
/*  Select Clock Polarity Raisinr or Falling */
/*-------------------------------------------*/     
    #if ( CLK_POLARITY == RAISING_Leading_Edge )    
        CLEAR_BIT(SPCR_REG,SPCR_CPOL);                  // Select Raising at Leading edge & Falling at Tralling Edge
    #elif ( CLK_POLARITY == FALLING_Leading_Edge )     
        SET_BIT(SPCR_REG,SPCR_CPOL);                    // Select Falling at Leading edge & Raising at Tralling Edge
    #endif
/*================================================*/
/*  Select Clock Phase Sample or setup on Leading */
/*------------------------------------------------*/  
    #if ( CLK_PHASE == SAMPLE_Leading_Edge )     
        CLEAR_BIT(SPCR_REG,SPCR_CPHA);                  // Select Sampling at leadding edge & Setup at Trailling Edge
    #elif ( CLK_PHASE == SETUP_Leading_Edge )    
        SET_BIT(SPCR_REG,SPCR_CPHA);                    // Select Setup at leadding edge & Sampling at Trailling Edge
    #endif
/*===============================================*/
/*            SPI Prescaler Selection            */
/*-----------------------------------------------*/
    #if(PRESCALER == PRESCALER_DIVISION_BY_4)
        CLEAR_BIT(SPCR_REG,SPCR_SPR0);
        CLEAR_BIT(SPCR_REG,SPCR_SPR1);
        CLEAR_BIT(SPSR_REG,SPSR_SPI2X);
    #elif(PRESCALER == PRESCALER_DIVISION_BY_16)
          SET_BIT(SPCR_REG,SPCR_SPR0);
        CLEAR_BIT(SPCR_REG,SPCR_SPR1);
        CLEAR_BIT(SPSR_REG,SPSR_SPI2X);
    #elif(PRESCALER == PRESCALER_DIVISION_BY_64)
        CLEAR_BIT(SPCR_REG,SPCR_SPR0);
          SET_BIT(SPCR_REG,SPCR_SPR1);
        CLEAR_BIT(SPSR_REG,SPSR_SPI2X);
    #elif(PRESCALER == PRESCALER_DIVISION_BY_128)
          SET_BIT(SPCR_REG,SPCR_SPR0);
          SET_BIT(SPCR_REG,SPCR_SPR1);
        CLEAR_BIT(SPSR_REG,SPSR_SPI2X);
    #elif(PRESCALER == PRESCALER_DIVISION_BY_2)
        CLEAR_BIT(SPCR_REG,SPCR_SPR0);
        CLEAR_BIT(SPCR_REG,SPCR_SPR1);
          SET_BIT(SPSR_REG,SPSR_SPI2X);
    #elif(PRESCALER == PRESCALER_DIVISION_BY_8)
          SET_BIT(SPCR_REG,SPCR_SPR0);
        CLEAR_BIT(SPCR_REG,SPCR_SPR1);
          SET_BIT(SPSR_REG,SPSR_SPI2X);
    #elif(PRESCALER == PRESCALER_DIVISION_BY_32)
        CLEAR_BIT(SPCR_REG,SPCR_SPR0);
          SET_BIT(SPCR_REG,SPCR_SPR1);
          SET_BIT(SPSR_REG,SPSR_SPI2X);
    #endif
/*======================================*/
/*              Enable SPI              */
/*--------------------------------------*/        
    SET_BIT(SPCR_REG,SPCR_SPE);                     // Enable SPI

}

/************************************************************************************************/
/* Function Name : SPI_voidSlaveInit                                                            */
/* Description : Initilization of Slave Mode                                                    */                                         
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void SPI_voidSlaveInit (void)
{
/*======================================*/
/*          Slave I/O PIN Mode          */
/*--------------------------------------*/
    DIO_voidSetPinDirection (PORTB,PIN5,INPUT);         // MOSI  INPUT in Slave Mode
    DIO_voidSetPinDirection(PORTB,PIN6,OUTPUT);         // MISO OUTPUT in Slave Mode
    DIO_voidSetPinDirection (PORTB,PIN7,INPUT);         // CLOK  INPUT in Slave Mode
    DIO_voidSetPinDirection (PORTB,PIN4,INPUT);         // SS Slave Select INPUT in Slave Mode 
    DIO_voidSetPinValue (PORTB,PIN4,LOW);               // Set LOW on SS Always if we have one Slave
/*======================================*/
/*          Select Slave  Mode          */
/*--------------------------------------*/    
    CLEAR_BIT(SPCR_REG,SPCR_MSTR);
/*======================================*/
/*    Select MSB or LSB Send at First   */              // Same With Master Configration.
/*--------------------------------------*/   
    #if ( DATA_ORDER == MSB_FIRST )
        CLEAR_BIT(SPCR_REG,SPCR_DORD);                  // select MSB to be send first
    #elif ( DATA_ORDER == LSB_FIRST )
        SET_BIT(SPCR_REG,SPCR_DORD);                    // select LSB to be send first
    #endif
/*===========================================*/
/*  Select Clock Polarity Raisinr or Falling */         // Same With Master Configration.
/*-------------------------------------------*/     
    #if ( CLK_POLARITY == RAISING_Leading_Edge )    
        CLEAR_BIT(SPCR_REG,SPCR_CPOL);                  // Select Raising at Leading edge & Falling at Tralling Edge
    #elif ( CLK_POLARITY == FALLING_Leading_Edge )     
        SET_BIT(SPCR_REG,SPCR_CPOL);                    // Select Falling at Leading edge & Raising at Tralling Edge
    #endif
/*================================================*/
/*  Select Clock Phase Sample or setup on Leading */    // Same With Master Configration.
/*------------------------------------------------*/  
    #if ( CLK_PHASE == SAMPLE_Leading_Edge )     
        CLEAR_BIT(SPCR_REG,SPCR_CPHA);                  // Select Sampling at leadding edge & Setup at Trailling Edge
    #elif ( CLK_PHASE == SETUP_Leading_Edge )    
        SET_BIT(SPCR_REG,SPCR_CPHA);                    // Select Setup at leadding edge & Sampling at Trailling Edge
    #endif
/*======================================*/
/*              Enable SPI              */
/*--------------------------------------*/        
    SET_BIT(SPCR_REG,SPCR_SPE);                     // Enable SPI
     
}

/************************************************************************************************/
/* Function Name : SPI_u8TranceiveData                                                          */
/* Description : Function can Transmit and Recieve Char                                         */                                         
/* Fun. Argument1: Copy_u8Data { Transsmited Data }                                             */
/* Fun. Return : unsigned Char u8  { Recieved Data }                                            */
/************************************************************************************************/
u8 SPI_u8TranceiveData (u8 Copy_u8Data)
{
    /* Transmit */
    // set the data to REG
    SPDR_REG = Copy_u8Data ;
    // polling
    while( (GET_BIT(SPSR_REG,SPSR_SPIF)) == 0 );
    // clear the flag
    SET_BIT(SPSR_REG,SPSR_SPIF);

    /* Recieve */
    return SPDR_REG ;

}

/************************************************************************************************/
/* Function Name : SPI_voidTransmitData                                                         */
/* Description : Function can Transmit Char                                                     */                                         
/* Fun. Argument1: Copy_u8Data { Transsmited Data }                                             */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void SPI_voidTransmitData (u8 Copy_u8Data)
{
    // set the data to REG
    SPDR_REG = Copy_u8Data ;
    // polling
    while( (GET_BIT(SPSR_REG,SPSR_SPIF)) == 0 );
    // clear the flag
    SET_BIT(SPSR_REG,SPSR_SPIF);
}

/************************************************************************************************/
/* Function Name : SPI_voidRecieveData                                                          */
/* Description : Function can Recieve Char                                                      */                                         
/* Fun. Return : unsigned character ( Data Recived )                                            */
/************************************************************************************************/
u8 SPI_voidRecieveData (void)
{
    return SPDR_REG ;
}

/************************************************************************************************/
/* Function Name : SPI_voidTranceiveString                                                      */
/* Description : Function can Transmit and Recieve String as Array of Char passing by reference */                                         
/* Fun. Argument1: *Copy_Au8TransmitString { Address of array of Char we need Transmit it }     */
/* Fun. Argument2: *Copy_u8RecieveString   { Address of array of Char we need Recieve it }      */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void SPI_voidTranceiveString (u8 *Copy_Au8TransmitString , u8 *Copy_u8RecieveString )
{
    for ( u8 iter=0 ; Copy_Au8TransmitString[iter] != '\0' ; iter++ )
    {
        /* Send Data */
        // set the data to REG
        SPDR_REG = Copy_Au8TransmitString[iter] ;
        // polling
        while( (GET_BIT(SPSR_REG,SPSR_SPIF)) == 0 );
        // clear the flag
        SET_BIT(SPSR_REG,SPSR_SPIF);

        /* Recieve Data */
        Copy_u8RecieveString[iter] = SPDR_REG ;
    }
}

/************************************************************************************************/
/* Function Name : SPI_u8AsynTranceiveData                                                      */
/* Description : Function can Transmit and Recieve Data by Interrupt                            */                                         
/* Fun. Argument1: Copy_u8Data { Transsmited Data }                                             */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void SPI_u8AsynTranceiveData (u8 Copy_u8Data)
{
 
    SET_BIT(SPCR_REG,SPCR_SPIE);            // Enable SPI Interrupt
    /* Transmit */
    SPDR_REG = Copy_u8Data ;                // set the data to REG
}

/*****************************************************************************/
/* Function Name : SPI_voidSetCallBack                                       */
/* Description : Function Call Back that assign Pointer of application       */
/*               Function to our global pointer to use it at ISR Fun.        */
/* Fun. Argument1:{ void (*LocalPointerToFunction) (u8 *Copy_u8RecivedData) }*/
/*                Pointer to function that = Address of application function */
/* Fun. Return : void                                                        */
/*****************************************************************************/
void SPI_voidSetCallBack (  void (*Local_PointerToFunction) (u8 *Copy_u8RecivedData) )
{
    Global_PF_Vector_12 = Local_PointerToFunction ;
}


/*===========================================================================*/
/* =====================         TSR Functions          =====================*/
/*===========================================================================*/
/*****************************************************************************/
/* Function Name : void __vector_12 (void) [ISR Function]                    */
/* Description : ISR Prototype (position 12 on vector table SPI )            */ 
/* Fun. Return : void                                                        */
/*****************************************************************************/
void __vector_12 (void)    __attribute__((signal));
void __vector_12 (void)
{
    u8 Local_u8Data ;
    // Recieve Data
    Local_u8Data = SPDR_REG ;
    u8 *Local_Pu8Data = &Local_u8Data ;
    Global_PF_Vector_12 ( Local_Pu8Data );      // Call Back Application Function
    CLEAR_BIT(SPCR_REG,SPCR_SPIE);              // Disable SPI Interrupt
}