/*===================================================================================================*/
/*  File        : I2C_Interface.h                                                                    */
/*  Description : This interface file includes I2C Driver prototypes and declarations for Atmega32   */
/*  Author      : Ahmed Bahaa Taha Nasr. Embedded SW Engineer                                        */
/*  Date        : 14/4/2023                                                                          */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-bahaa1/                                          */
/*  Git account : https://github.com/ahmedbahaa11                                                    */
/*  mail        : abahaa14842@gmail.com                                                              */
/*===================================================================================================*/

/* File Gaurd by ifndef & endif */
#ifndef I2C_INTERFACE_H
#define I2C_INTERFACE_H

typedef enum 
{
    I2C_NO_Error ,
    I2C_Error_Master_StartCond_ACK ,
    I2C_Error_Master_ReStartCond_ACK ,
    I2C_Error_Master_SendSLA_Write_ACK ,
    I2C_Error_Master_SendSLA_Write_NOTACK ,
    I2C_Error_Master_SendSLA_Read_ACK ,
    I2C_Error_Master_SendSLA_Read_NOTACK ,
    I2C_Error_Master_WriteDataByte_ACK ,
    I2C_Error_Master_WriteDataByte_NOTACK ,
    I2C_Error_Master_ReadDataByte_ACK ,
    I2C_Error_Master_ReadDataByte_NOTACK ,
    I2C_Error_Slave_OwnSLA_Write_ACK ,
    I2C_Error_Slave_OwnSLA_Read_ACK ,
    I2C_Error_Slave_DataByteRecieved_ACK ,
    I2C_Error_Slave_DataByteRecieved_NOTACK ,
    I2C_Error_Slave_DataByteTransmit_ACK ,
    I2C_Error_Slave_DataByteTransmit_NOTACK ,
}Error_t ;
/*===================================================================*/
/*======================   Master Functions  ========================*/
/*===================================================================*/
void I2C_voidMasterInit (u8 Copy_u8MasterAddress);
Error_t I2C_Master_u8StartCondition (void); 
Error_t I2C_Master_u8ReStartCondition (void);
Error_t I2C_Master_u8SendSLA_Write_ACK (u8 Copy_u8SlaveAddress);
Error_t I2C_Master_u8SendSLA_Write_NOTACK (u8 Copy_u8SlaveAddress);
Error_t I2C_Master_u8SendSLA_Read_ACK (u8 Copy_u8SlaveAddress);
Error_t I2C_Master_u8SendSLA_Read_NOTACK (u8 Copy_u8SlaveAddress);
Error_t I2C_Master_u8WriteDataByte_ACK (u8 Copy_u8WriteData);
Error_t I2C_Master_u8WriteDataByte_NOTACK (u8 Copy_u8WriteData);
Error_t I2C_Master_u8ReadDataByte_ACK (u8 *Copy_Pu8ReadData);
Error_t I2C_Master_u8ReadDataByte_NOTACK (u8 *Copy_Pu8ReadData);
void I2C_Master_voidStopCondition (void);
/*===================================================================*/
/*=======================   Slave Functions   =======================*/
/*===================================================================*/
void I2C_voidSlaveInit (u8 Copy_u8SlaveAddress);
Error_t I2C_SLAVE_u8OwnSLA_Write_Recieved_ACK (void);
Error_t I2C_SLAVE_u8OwnSLA_Read_Recieved_ACK (void);
Error_t I2C_SLAVE_u8DataByteRecieved_ACK (u8 *Copy_Pu8RecievedData);
Error_t I2C_SLAVE_u8DataByteRecieved_NOTACK (u8 *Copy_Pu8RecievedData);
Error_t I2C_SLAVE_u8DataByteTransmit_ACK (u8 Copy_Pu8TransmitData);
Error_t I2C_SLAVE_u8DataByteTransmit_NOTACK (u8 Copy_Pu8TransmitData);
/*===================================================================*/
void Enable_ACK (void);
void Disable_ACK (void);
/*===================================================================*/



#endif