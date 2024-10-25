/*=================================================================================*/
/*  File        : I2C_Program.c                                                    */
/*  Description : This file includes I2C Driver implementations for Atmega32       */
/*  Author      : Ahmed Bahaa Taha Nasr. Embedded SW Engineer                      */
/*  Date        : 14/4/2023                                                        */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-bahaa1/                        */
/*  Git account : https://github.com/ahmedbahaa11                                  */
/*  mail        : abahaa14842@gmail.com                                            */
/*=================================================================================*/

/* Include Header Files From LIB */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

/* Include Header Files From MCAL */
#include"../DIO/DIO_Interface.h"

/* Include My own Header Files*/
#include "I2C_Interface.h"
#include "I2C_Private.h"
#include "I2C_Config.h"

/*===========================================================================================================================*/
/*=================================================  [ Master Functions ]   =================================================*/
/*===========================================================================================================================*/
/* Set Master Address to 0 if master will not be addressed */
void I2C_voidMasterInit (u8 Copy_u8MasterAddress)
{
    Enable_ACK ();           // Enable ACK  
    /*===============================================================================*/
    /*  SCL frequency = ( CPU Clock frequency ) / ( 16 + 2(TWBR) * 4^TWPS )          */
    /*  ( 16 + 2(TWBR) * 4^TWPS ) = ( CPU Clock frequency ) / SCL frequency          */  
    /*  2(TWBR) * 4^TWPS = ( CPU Clock frequency / SCL frequency ) - 16              */ 
    /*  TWBR = (( CPU Clock frequency / SCL frequency ) - 16) / ( 2 * 4^TWPS )       */
    /*  // CPU Clock frequency = 8 MHz = 8000000 Hz                                  */
    /*  // SCL frequency = 400 KHz = 400000 Hz     ( Max Speed of TWI )              */
    /*  // TWPS = Value of the prescaler bits in the TWI Status Register (TWSR_REG)  */
    /*  // Prescaller -> 1   ->   0   0   ->  TWPS = 0  ->    4^(0) = 1              */
    /*  // Prescaller -> 4   ->   0   1   ->  TWPS = 1  ->    4^(1) = 4              */
    /*  // Prescaller -> 16  ->   1   0   ->  TWPS = 2  ->    4^(2) = 16             */
    /*  // Prescaller -> 64  ->   1   1   ->  TWPS = 3  ->    4^(3) = 64             */
    /*  TWBR = (( CPU Clock frequency / SCL frequency ) - 16) / ( 2 * 4^TWPS)        */ 
    /*  TWBR = (( 8000000 / 400000 ) - 16) / ( 2 * 4^(0) )                           */ 
    /*  TWBR = ( 20 - 16 ) / ( 2 * 1 ) = (4) / (2)                                   */
    /*  TWBR = 2                                                                     */
    /*===============================================================================*/
    TWBR_REG = 2 ;                        // Set TWBR with vale => 400 KHz ( TWBR = 2 )
    // Set prescaller == 1 (clr TWSR 0,1)
    CLEAR_BIT(TWSR_REG,TWSR_TWPS0);
    CLEAR_BIT(TWSR_REG,TWSR_TWPS1);
    /*Check if the master node will be addressed or not*/
	if( Copy_u8MasterAddress == 0x00 )
	{
		/*Do Nothing*/
	}
	else
	{
		/*Set The Required Address to The Master*/
		TWAR_REG = (Copy_u8MasterAddress << 1);
	}
    // Enable I2C  ( set TWCR 2 )
    SET_BIT(TWCR_REG,TWCR_TWEN);
}
/*===========================================================================================================================*/
Error_t I2C_Master_u8StartCondition (void)
{
    Error_t Local_Error = I2C_NO_Error ;
    SET_BIT(TWCR_REG,TWCR_TWSTA);                              // Start condition ( Set TWCR 5)
    SET_BIT(TWCR_REG,TWCR_TWINT);                              // Clear flag ( Set TWCR 7 )
    while( ( GET_BIT(TWCR_REG,TWCR_TWINT) ) == 0 );            // Wait for flag ( TWCR 7 == 0 )
    if ( (TWSR_REG & STATUS_BIT_MASK) != MASTER_START_ACK )    // Check status code == start condition ( TWSR & 0xf8 ) == 0x08
    {
        Local_Error = I2C_Error_Master_StartCond_ACK ; 
    }
    return Local_Error ;
}
/*===========================================================================================================================*/
Error_t I2C_Master_u8ReStartCondition (void)
{
    Error_t Local_Error = I2C_NO_Error ;
    SET_BIT(TWCR_REG,TWCR_TWSTA);                                   // Start condition ( Set TWCR 5)
    SET_BIT(TWCR_REG,TWCR_TWINT);                                   // Clear flag ( Set TWCR 7 )
    while( ( GET_BIT(TWCR_REG,TWCR_TWINT) ) == 0 );                 // Wait for flag ( TWCR 7 == 0 )
    if ( (TWSR_REG & STATUS_BIT_MASK) != MASTER_REP_START_ACK )     // Check status code == Repeat condition ( TWSR & 0xf8 ) == 0x10 
    {
        Local_Error = I2C_Error_Master_ReStartCond_ACK ; 
    }
    return Local_Error ;
}
/*===========================================================================================================================*/
Error_t I2C_Master_u8SendSLA_Write_ACK (u8 Copy_u8SlaveAddress)
{
    Error_t Local_Error = I2C_NO_Error ;
    TWDR_REG = (Copy_u8SlaveAddress<<1) ;                           // Write 7 bits slave address ( TWDR == address<<1 )
    CLEAR_BIT(TWDR_REG,TWDR_TWD0);                                  // Write condition ( CLEAR TWDR 0 )
    CLEAR_BIT(TWCR_REG,TWCR_TWSTA);                                 // Clear start condition bit ( TWCR 5 ) - for sure
    SET_BIT(TWCR_REG,TWCR_TWINT);                                   // Clear flag ( Set TWCR 7 )
    while( ( GET_BIT(TWCR_REG,TWCR_TWINT) ) == 0 );                 // Wait for flag ( TWCR 7 == 0 )
    if ( (TWSR_REG & STATUS_BIT_MASK) != MASTER_SLA_Write_ACK )     // Check status code == SLA + Write + ACK == (0x18)
    {
        Local_Error = I2C_Error_Master_SendSLA_Write_ACK ; 
    }
    return Local_Error ;
}
/*===========================================================================================================================*/
Error_t I2C_Master_u8SendSLA_Write_NOTACK (u8 Copy_u8SlaveAddress)
{
    Error_t Local_Error = I2C_NO_Error ;
    Disable_ACK ();                                                    // Disable ACK
    TWDR_REG = (Copy_u8SlaveAddress<<1) ;                              // Write 7 bits slave address ( TWDR == address<<1 )
    CLEAR_BIT(TWDR_REG,TWDR_TWD0);                                     // Write condition ( CLEAR TWDR 0 )
    CLEAR_BIT(TWCR_REG,TWCR_TWSTA);                                    // Clear start condition bit ( TWCR 5 ) - for sure
    SET_BIT(TWCR_REG,TWCR_TWINT);                                      // Clear flag ( Set TWCR 7 )
    while( ( GET_BIT(TWCR_REG,TWCR_TWINT) ) == 0 );                    // Wait for flag ( TWCR 7 == 0 )
    if ( (TWSR_REG & STATUS_BIT_MASK) != MASTER_SLA_Write_NOTACK )     // Check status code == SLA + Write + NOTACK == (0x20)
    {
        Local_Error = I2C_Error_Master_SendSLA_Write_NOTACK ; 
    }
    return Local_Error ;
}
/*===========================================================================================================================*/
Error_t I2C_Master_u8SendSLA_Read_ACK (u8 Copy_u8SlaveAddress)
{
    Error_t Local_Error = I2C_NO_Error ;
    TWDR_REG = (Copy_u8SlaveAddress<<1) ;                              // Write 7 bits slave address ( TWDR == address<<1 )
    SET_BIT(TWDR_REG,TWDR_TWD0);                                       // Read condition ( SET TWDR 0 )
    CLEAR_BIT(TWCR_REG,TWCR_TWSTA);                                    // Clear start condition bit ( TWCR 5 ) - for sure
    SET_BIT(TWCR_REG,TWCR_TWINT);                                      // Clear flag ( Set TWCR 7 )
    while( ( GET_BIT(TWCR_REG,TWCR_TWINT) ) == 0 );                    // Wait for flag ( TWCR 7 == 0 )
    if ( (TWSR_REG & STATUS_BIT_MASK) != MASTER_SLA_Read_ACK )         // Check status code == SLA + Read + ACK == (0x40)
    {
        Local_Error = I2C_Error_Master_SendSLA_Read_ACK ; 
    }
    return Local_Error ;
}
/*===========================================================================================================================*/
Error_t I2C_Master_u8SendSLA_Read_NOTACK (u8 Copy_u8SlaveAddress)
{
    Error_t Local_Error = I2C_NO_Error ;
    Disable_ACK ();                                                    // Disable ACK 
    TWDR_REG = (Copy_u8SlaveAddress<<1) ;                              // Write 7 bits slave address ( TWDR == address<<1 )
    SET_BIT(TWDR_REG,TWDR_TWD0);                                       // Read condition ( SET TWDR 0 )
    CLEAR_BIT(TWCR_REG,TWCR_TWSTA);                                    // Clear start condition bit ( TWCR 5 ) - for sure
    SET_BIT(TWCR_REG,TWCR_TWINT);                                      // Clear flag ( Set TWCR 7 )
    while( ( GET_BIT(TWCR_REG,TWCR_TWINT) ) == 0 );                    // Wait for flag ( TWCR 7 == 0 )
    if ( (TWSR_REG & STATUS_BIT_MASK) != MASTER_SLA_Read_NOTACK )      // Check status code == SLA + Read + NOTACK == (0x48)
    {
        Local_Error = I2C_Error_Master_SendSLA_Read_NOTACK ; 
    }
    return Local_Error ;
}
/*===========================================================================================================================*/
Error_t I2C_Master_u8WriteDataByte_ACK (u8 Copy_u8WriteData)
{
    Error_t Local_Error = I2C_NO_Error ;
    TWDR_REG = Copy_u8WriteData ;                                      // Write data in TWDR
    SET_BIT(TWCR_REG,TWCR_TWINT);                                      // Clear flag ( Set TWCR 7 )
    while( ( GET_BIT(TWCR_REG,TWCR_TWINT) ) == 0 );                    // Wait for flag ( TWCR 7 == 0 )
    if ( (TWSR_REG & STATUS_BIT_MASK) != MASTER_WR_DataByte_ACK )      // Check status code == Master Send Data + ACK == (0x28)
    {
        Local_Error = I2C_Error_Master_WriteDataByte_ACK ; 
    }
    return Local_Error ;
}
/*===========================================================================================================================*/
Error_t I2C_Master_u8WriteDataByte_NOTACK (u8 Copy_u8WriteData)
{
    Error_t Local_Error = I2C_NO_Error ;
    Disable_ACK ();                                                    // Disable ACK 
    TWDR_REG = Copy_u8WriteData ;                                      // Write data in TWDR
    SET_BIT(TWCR_REG,TWCR_TWINT);                                      // Clear flag ( Set TWCR 7 )
    while( ( GET_BIT(TWCR_REG,TWCR_TWINT) ) == 0 );                    // Wait for flag ( TWCR 7 == 0 )
    if ( (TWSR_REG & STATUS_BIT_MASK) != MASTER_WR_DataByte_NOTACK )   // Check status code == Master Send Data + NOTACK == (0x30)
    {
        Local_Error = I2C_Error_Master_WriteDataByte_NOTACK ; 
    }
    return Local_Error ;
}
/*===========================================================================================================================*/
Error_t I2C_Master_u8ReadDataByte_ACK (u8 *Copy_Pu8ReadData)
{
    Error_t Local_Error = I2C_NO_Error ;
    SET_BIT(TWCR_REG,TWCR_TWINT);                                      // Clear flag ( Set TWCR 7 )
    while( ( GET_BIT(TWCR_REG,TWCR_TWINT) ) == 0 );                    // Wait for flag ( TWCR 7 == 0 )
    if ( (TWSR_REG & STATUS_BIT_MASK) != MASTER_RD_DataByte_ACK )      // Check status code == Master Read Data + ACK == (0x50)
    {
        Local_Error = I2C_Error_Master_ReadDataByte_ACK ; 
    }
    *Copy_Pu8ReadData = TWDR_REG ;                                     // Read Data From Reg TWDR
    return Local_Error ;
}
/*===========================================================================================================================*/
Error_t I2C_Master_u8ReadDataByte_NOTACK (u8 *Copy_Pu8ReadData)
{
    Error_t Local_Error = I2C_NO_Error ;
    Disable_ACK ();                                                    // Disable ACK 
    SET_BIT(TWCR_REG,TWCR_TWINT);                                      // Clear flag ( Set TWCR 7 )
    while( ( GET_BIT(TWCR_REG,TWCR_TWINT) ) == 0 );                    // Wait for flag ( TWCR 7 == 0 )
    if ( (TWSR_REG & STATUS_BIT_MASK) != MASTER_RD_DataByte_NOTACK )   // Check status code == Master Read Data + NOTACK == (0x58)
    {
        Local_Error = I2C_Error_Master_ReadDataByte_NOTACK ; 
    }
    *Copy_Pu8ReadData = TWDR_REG ;                                     // Read Data From Reg TWDR
    return Local_Error ;
}
/*===========================================================================================================================*/
void I2C_Master_voidStopCondition (void)
{
    SET_BIT(TWCR_REG,TWCR_TWSTO);               // Stop condition ( Set TWCR 4 )
    SET_BIT(TWCR_REG,TWCR_TWINT);               // Clear flag ( Set TWCR 7 )  
}

/*===========================================================================================================================*/
/*=================================================   [ Slave Functions ]   =================================================*/
/*===========================================================================================================================*/
/*===========================================================================================================================*/
void I2C_voidSlaveInit (u8 Copy_u8SlaveAddress)
{
    TWAR_REG = Copy_u8SlaveAddress << 1 ;       // Set slave address in ( TWAR = address<<1 )
    Enable_ACK();                               // Enable ACK  ( set TWCR 6 )
    SET_BIT(TWCR_REG,TWCR_TWEN);                // Enable I2C  ( set TWCR 2 )
}
/*===========================================================================================================================*/
Error_t I2C_SLAVE_u8OwnSLA_Write_Recieved_ACK (void)
{
    Error_t Local_Error = I2C_NO_Error ;
    SET_BIT(TWCR_REG,TWCR_TWINT);                                            // Clear flag ( Set TWCR 7 )
    while( ( GET_BIT(TWCR_REG,TWCR_TWINT) ) == 0 );                          // Wait for flag ( TWCR 7 == 0 )
    if ( (TWSR_REG & STATUS_BIT_MASK) != SLAVE_OwnSLA_Write_Recieved_ACK )   // Check status code == Own Slave Address + Write + ACK == (0x60)
    {
        Local_Error = I2C_Error_Slave_OwnSLA_Write_ACK ; 
    }
    return Local_Error ;
}
/*===========================================================================================================================*/
Error_t I2C_SLAVE_u8OwnSLA_Read_Recieved_ACK (void)
{
    Error_t Local_Error = I2C_NO_Error ;
    SET_BIT(TWCR_REG,TWCR_TWINT);                                            // Clear flag ( Set TWCR 7 )
    while( ( GET_BIT(TWCR_REG,TWCR_TWINT) ) == 0 );                          // Wait for flag ( TWCR 7 == 0 )
    if ( (TWSR_REG & STATUS_BIT_MASK) != SLAVE_OwnSLA_Read_Recieved_ACK )    // Check status code == Own Slave Address + Read + ACK == (0xA8)
    {
        Local_Error = I2C_Error_Slave_OwnSLA_Read_ACK ; 
    }
    return Local_Error ;
}
/*===========================================================================================================================*/
Error_t I2C_SLAVE_u8DataByteRecieved_ACK (u8 *Copy_Pu8RecievedData)
{
    Error_t Local_Error = I2C_NO_Error ;
    SET_BIT(TWCR_REG,TWCR_TWINT);                                            // Clear flag ( Set TWCR 7 )
    while( ( GET_BIT(TWCR_REG,TWCR_TWINT) ) == 0 );                          // Wait for flag ( TWCR 7 == 0 )
    if ( (TWSR_REG & STATUS_BIT_MASK) != SLAVE_DataByte_Recieved_ACK )       // Check status code == Data Byte Recived + ACK  == (0x80)
    {
        Local_Error = I2C_Error_Slave_DataByteRecieved_ACK ; 
    }
    *Copy_Pu8RecievedData = TWDR_REG ;                                       // Read Data From Reg TWDR 
    return Local_Error ;
}
/*===========================================================================================================================*/
Error_t I2C_SLAVE_u8DataByteRecieved_NOTACK (u8 *Copy_Pu8RecievedData)
{
    Error_t Local_Error = I2C_NO_Error ;    
    Disable_ACK ();                                                             // Disable ACK 
    SET_BIT(TWCR_REG,TWCR_TWINT);                                               // Clear flag ( Set TWCR 7 )
    while( ( GET_BIT(TWCR_REG,TWCR_TWINT) ) == 0 );                             // Wait for flag ( TWCR 7 == 0 )
    if ( (TWSR_REG & STATUS_BIT_MASK) != SLAVE_DataByte_Recieved_NOTACK )       // Check status code == Data Byte Recived + NOTACK  == (0x88)
    {
        Local_Error = I2C_Error_Slave_DataByteRecieved_NOTACK ; 
    }
    *Copy_Pu8RecievedData = TWDR_REG ;                                          // Read Data From Reg TWDR
    return Local_Error ;
}
/*===========================================================================================================================*/
Error_t I2C_SLAVE_u8DataByteTransmit_ACK (u8 Copy_Pu8TransmitData)
{
    Error_t Local_Error = I2C_NO_Error ;
    TWDR_REG =  Copy_Pu8TransmitData ;                                       // Write Data in Reg TWDR 
    SET_BIT(TWCR_REG,TWCR_TWINT);                                            // Clear flag ( Set TWCR 7 )
    while( ( GET_BIT(TWCR_REG,TWCR_TWINT) ) == 0 );                          // Wait for flag ( TWCR 7 == 0 )
    if ( (TWSR_REG & STATUS_BIT_MASK) != SLAVE_DataByte_Transmitted_ACK )    // Check status code == Data Byte Transmit + ACK  == (0xB8)
    {
        Local_Error = I2C_Error_Slave_DataByteTransmit_ACK ; 
    } 
    return Local_Error ;
}
/*===========================================================================================================================*/
Error_t I2C_SLAVE_u8DataByteTransmit_NOTACK (u8 Copy_Pu8TransmitData)
{
    Error_t Local_Error = I2C_NO_Error ;
    Disable_ACK ();                                                             // Disable ACK 
    TWDR_REG =  Copy_Pu8TransmitData ;                                          // Write Data in Reg TWDR 
    SET_BIT(TWCR_REG,TWCR_TWINT);                                               // Clear flag ( Set TWCR 7 )
    while( ( GET_BIT(TWCR_REG,TWCR_TWINT) ) == 0 );                             // Wait for flag ( TWCR 7 == 0 )
    if ( (TWSR_REG & STATUS_BIT_MASK) != SLAVE_DataByte_Transmitted_NOTACK )    // Check status code == Data Byte Transmit + NOTACK  == (0xC0)
    {
        Local_Error = I2C_Error_Slave_DataByteTransmit_NOTACK ; 
    } 
    return Local_Error ;
}
/*===========================================================================================================================*/
void Enable_ACK (void)
{
    // Enable ACK  ( Set TWCR 6 )
    SET_BIT(TWCR_REG,TWCR_TWEA);
}
/*===========================================================================================================================*/
void Disable_ACK (void)
{
    // Disable ACK  ( Clear TWCR 6 )
    CLEAR_BIT(TWCR_REG,TWCR_TWEA);
}
/*===========================================================================================================================*/
