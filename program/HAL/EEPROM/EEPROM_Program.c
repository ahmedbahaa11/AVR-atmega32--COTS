/*=================================================================================*/
/*  File        : EEPROM_Program.c                                                 */
/*  Description : This file includes EEPROM Driver implementations for Atmega32    */
/*  Author      : Ahmed Bahaa Taha Nasr. Embedded SW Engineer                      */
/*  Date        : 17/4/2023                                                        */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-bahaa1/                        */
/*  Git account : https://github.com/ahmedbahaa11                                  */
/*  mail        : abahaa14842@gmail.com                                            */
/*=================================================================================*/

#include <util/delay.h>
/* Include Header Files From LIB */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

/* Include My own Header Files*/
#include "EEPROM_Interface.h"
#include "EEPROM_Private.h"
#include "EEPROM_Config.h"

/* Include Header Files From MCAL Layer */
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/I2C/I2C_Interface.h"



void EEPROM_voidSendDataByte ( u16 Copy_u16LocationAddress , u8 Copy_u8DataByte )
{
    u8 Local_Address ;                                                              
    Local_Address = EEPROM_FIXED_ADDRESS | (EEPROM_A2<<2) | ((u8)(Copy_u16LocationAddress>>8)) ;   
    // Send Start Condition                                                                        
    I2C_Master_u8StartCondition ();                                                      
    // Send the address packet                                                          
    I2C_Master_u8SendSLA_Write_ACK (Local_Address); // 0b1010xxx0 
    // send the rest 8 BITS of the location Adress
    I2C_Master_u8WriteDataByte_ACK ( (u8)(Copy_u16LocationAddress));
    // Send The Data Byte to the Memory Location
    I2C_Master_u8WriteDataByte_ACK (Copy_u8DataByte);
    // Send Stop Condition
    I2C_Master_voidStopCondition ();
    // Delay Until the Write cycle is finished
    _delay_ms(10);

}

u8 EEPROM_voidReadDataByte ( u16 Copy_u16LocationAddress )
{
    u8 Data ;
    u8 Local_Address ;
    Local_Address = EEPROM_FIXED_ADDRESS | (EEPROM_A2<<2) | ((u8)(Copy_u16LocationAddress>>8)) ;
    // Send Start Condition 
    I2C_Master_u8StartCondition ();
    // Send the address packet with Write operation
    I2C_Master_u8SendSLA_Write_ACK (Local_Address);
    // send the rest 8 BITS of the location Adress
    I2C_Master_u8WriteDataByte_ACK ( (u8)(Copy_u16LocationAddress) );
    // Send Repeated Start to chang write request to Read request
    I2C_Master_u8ReStartCondition ();
    // Send the address packet with Read operation
    I2C_Master_u8SendSLA_Read_ACK (Local_Address);
    // Get The Data From Memory
    I2C_Master_u8ReadDataByte_NOTACK (&Data);
    // Send Stop Condition
    I2C_Master_voidStopCondition();
    // Delay Until the Read cycle is finished
    _delay_ms(10);
    // Return Data
    return Data ;
}