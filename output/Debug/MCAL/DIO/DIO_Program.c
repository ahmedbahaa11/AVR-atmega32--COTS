/*=================================================================================*/
/*  File        : DIO_Program.c                                                    */
/*  Description : This file includes DIO Driver implementations for Atmega32       */
/*  Author      : Ahmed Bahaa Taha Nasr. Embedded SW Engineer                      */
/*  Date        : 27/3/2023                                                        */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-bahaa1/                        */
/*  Git account : https://github.com/ahmedbahaa11                                  */
/*  mail        : ahmedbahaataha7@gmil.com                                         */
/*=================================================================================*/

/* Include Header Files From LIB */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

/* Include My own Header Files*/
#include "DIO_Interface.h"
#include "DIO_Private.h"
#include "DIO_Config.h"


/*======================================================================================================================*/
/*====================================     A.BAHAA DIO Functions Implementation      ===================================*/
/*======================================================================================================================*/
/********************************************    DIO_voidSetPinDirection       ******************************************/
/********************************************    DIO_voidSetPortDirection      ******************************************/ 
/********************************************    DIO_voidSetPinValue           ******************************************/ 
/********************************************    DIO_voidSetPortValue          ******************************************/ 
/********************************************    DIO_u8GetPinValue             ******************************************/ 
/********************************************    DIO_u8GetPortValue            ******************************************/ 
/********************************************    DIO_voidTogglePinValue        ******************************************/ 
/********************************************    DIO_voidTogglePortValue       ******************************************/ 
/********************************************    DIO_voidConfig_Pull_Up_Pin    ******************************************/ 
/* ******************************************    DIO_voidConfig_Pull_Up_Port   ******************************************/
/*======================================================================================================================*/




/*==============================================================================================*/
/* ==============================       Direction Modules        ===============================*/
/*==============================================================================================*/
/************************************************************************************************/
/* Function Name : DIO_voidSetPinDirection                                                      */
/* Description : Set direction of one bit of the Port register                                  */
/* Fun. Argument1: Copy_u8PortNumber { PORTA,PORTB,PORTC,PORTD }                                */
/* Fun. Argument2: Copy_u8PinNumber { PIN0,PIN1,PIN3,PIN4,PIN5,PIN6,PIN7 }                      */
/* Fun. Argument3: Copy_u8Direction { INPUT,OUTPUT }                                            */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void DIO_voidSetPinDirection (u8 Copy_u8PortNumber, u8 Copy_u8PinNumber, u8 Copy_u8Direction )
{
    /* i/p validation */
    if ( Copy_u8PortNumber > PORTD || Copy_u8PinNumber > PIN7 )
    {
        // Do Nothing
    }
    else
    {
        switch(Copy_u8Direction)
        {
            case INPUT :    switch(Copy_u8PortNumber)
                            {
                                case PORTA :    CLEAR_BIT( DDRA_REG ,Copy_u8PinNumber );    break;       
                                case PORTB :    CLEAR_BIT( DDRB_REG ,Copy_u8PinNumber );    break;
                                case PORTC :    CLEAR_BIT( DDRC_REG ,Copy_u8PinNumber );    break;
                                case PORTD :    CLEAR_BIT( DDRD_REG ,Copy_u8PinNumber );    break;
                                default    :                                                break;
                            }
                            break;
            case OUTPUT :   switch(Copy_u8PortNumber)
                            {
                                case PORTA :    SET_BIT( DDRA_REG ,Copy_u8PinNumber );      break;
                                case PORTB :    SET_BIT( DDRB_REG ,Copy_u8PinNumber );      break;
                                case PORTC :    SET_BIT( DDRC_REG ,Copy_u8PinNumber );      break;
                                case PORTD :    SET_BIT( DDRD_REG ,Copy_u8PinNumber );      break;
                                default    :                                                break; 
                            }
                            break;
            default :       break;
                            
        }
    }
}
/************************************************************************************************/
/* Function Name : DIO_voidSetPortDirection                                                     */
/* Description : Set direction of the whole Port register                                       */
/* Fun. Argument1: Copy_u8PortNumber { PORTA,PORTB,PORTC,PORTD }                                */
/* Fun. Argument2: Copy_u8Direction { INPUT,OUTPUT }                                            */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void DIO_voidSetPortDirection (u8 Copy_u8PortNumber, u8 Copy_u8Direction )
{
    /* i/p validation */
    if ( Copy_u8PortNumber > PORTD )
    {
        // Do Nothing
    }
    else
    {
        switch(Copy_u8Direction)
        {
            case INPUT :    switch(Copy_u8PortNumber)
                            {
                                case PORTA :    DDRA_REG = 0x00 ;   break;
                                case PORTB :    DDRB_REG = 0x00 ;   break;
                                case PORTC :    DDRC_REG = 0x00 ;   break;
                                case PORTD :    DDRD_REG = 0x00 ;   break;
                                default    :                        break;
                            }
                            break;
            case OUTPUT :   switch(Copy_u8PortNumber)
                            {
                                case PORTA :    DDRA_REG = 0xff ;   break;
                                case PORTB :    DDRB_REG = 0xff ;   break;
                                case PORTC :    DDRC_REG = 0xff ;   break;
                                case PORTD :    DDRD_REG = 0xff ;   break;
                                default    :                        break;
                            }
                            break;
            default :       break;
                            
        }
    }
}
/*==============================================================================================*/
/*==============================================================================================*/





/*========================================================================================*/
/* ===========================         Write Modules          ============================*/
/*========================================================================================*/
/******************************************************************************************/
/* Function Name : DIO_voidSetPinValue                                                    */
/* Description : Write value of one bit of the Port register                              */
/* Fun. Argument1: Copy_u8PortNumber { PORTA,PORTB,PORTC,PORTD }                          */
/* Fun. Argument2: Copy_u8PinNumber { PIN0,PIN1,PIN3,PIN4,PIN5,PIN6,PIN7 }                */
/* Fun. Argument3: Copy_u8Value { HIGH , LOW }                                            */
/* Fun. Return : void                                                                     */
/******************************************************************************************/
void DIO_voidSetPinValue (u8 Copy_u8PortNumber, u8 Copy_u8PinNumber, u8 Copy_u8Value )
{
        /* i/p validation */
    if ( Copy_u8PortNumber > PORTD || Copy_u8PinNumber > PIN7 )
    {
        // Do Nothing
    }
    else
    {
        switch(Copy_u8Value)
        {
            case LOW :    switch(Copy_u8PortNumber)
                            {
                                case PORTA :    CLEAR_BIT( PORTA_REG ,Copy_u8PinNumber );   break;
                                case PORTB :    CLEAR_BIT( PORTB_REG ,Copy_u8PinNumber );   break;
                                case PORTC :    CLEAR_BIT( PORTC_REG ,Copy_u8PinNumber );   break;
                                case PORTD :    CLEAR_BIT( PORTD_REG ,Copy_u8PinNumber );   break;
                                default    :                                                break; 
                            }
                            break;
            case HIGH :   switch(Copy_u8PortNumber)
                            {
                                case PORTA :    SET_BIT( PORTA_REG ,Copy_u8PinNumber );     break;
                                case PORTB :    SET_BIT( PORTB_REG ,Copy_u8PinNumber );     break;
                                case PORTC :    SET_BIT( PORTC_REG ,Copy_u8PinNumber );     break;
                                case PORTD :    SET_BIT( PORTD_REG ,Copy_u8PinNumber );     break;
                                default    :                                                break; 
                            }
                            break;
            default :       break;
                            
        }
    }
}
/******************************************************************************************/
/* Function Name : DIO_voidSetPortValue                                                   */
/* Description : write o/p to  the whole Port register                                    */
/* Fun. Argument1: Copy_u8PortNumber { PORTA,PORTB,PORTC,PORTD }                          */
/* Fun. Argument2: Copy_u8Value { HIGH , LOW }                                            */
/* Fun. Return : void                                                                     */
/******************************************************************************************/
void DIO_voidSetPortValue (u8 Copy_u8PortNumber, u8 Copy_u8Value )
{
    /* i/p validation */
    if ( Copy_u8PortNumber > PORTD )
    {
        // Do Nothing
    }
    else
    {
        switch(Copy_u8PortNumber)
        {
            case PORTA: PORTA_REG = Copy_u8Value;
                        break;
    
            case PORTB: PORTB_REG = Copy_u8Value;
                        break;
    
            case PORTC: PORTC_REG = Copy_u8Value;
                        break;
    
            case PORTD: PORTD_REG = Copy_u8Value;
                        break;
            default:
                        break;
        }
    }
}
/*========================================================================================*/
/*========================================================================================*/




/*==========================================================================*/
/* =====================         Read Modules          =====================*/
/*==========================================================================*/
/****************************************************************************/
/* Function Name : DIO_u8GetPinValue                                        */
/* Description : Read pin value of one bit of the Port register             */
/* Fun. Argument1: Copy_u8PortNumber { PORTA,PORTB,PORTC,PORTD }            */
/* Fun. Argument2: Copy_u8PinNumber { PIN0,PIN1,PIN3,PIN4,PIN5,PIN6,PIN7 }  */
/* Fun. Return :  unsigned char   { HIGH , LOW }                            */
/****************************************************************************/
u8 DIO_u8GetPinValue (u8 Copy_u8PortNumber, u8 Copy_u8PinNumber )
{
    u8 Local_u8Variable;
    /* i/p validation */
    if ( Copy_u8PortNumber > PORTD || Copy_u8PinNumber > PIN7 )
    {
        // Do Nothing
    }
    else
    {
        switch(Copy_u8PortNumber)
        {
            case PORTA :    Local_u8Variable = GET_BIT( PINA_REG ,Copy_u8PinNumber );   break;   
            case PORTB :    Local_u8Variable = GET_BIT( PINB_REG ,Copy_u8PinNumber );   break;
            case PORTC :    Local_u8Variable = GET_BIT( PINC_REG ,Copy_u8PinNumber );   break;
            case PORTD :    Local_u8Variable = GET_BIT( PIND_REG ,Copy_u8PinNumber );   break;
            default :                                                                   break;
        }
    }
    return Local_u8Variable ;
}
/****************************************************************************/
/* Function Name : DIO_u8GetPortValue                                       */
/* Description : Read i/p of the whole Port register                        */
/* Fun. Argument1: Copy_u8PortNumber { PORTA,PORTB,PORTC,PORTD }            */
/* Fun. Return : u8 {0bxxxxxxxx} (x) is a value in an one Pin on the Port   */
/****************************************************************************/
u8 DIO_u8GetPortValue (u8 Copy_u8PortNumber )
{
    u8 Local_u8Variable;
    /* i/p validation */
    if ( Copy_u8PortNumber > PORTD )
    {
        // Do Nothing
    }
    else
    {
        switch(Copy_u8PortNumber)
        {
            case PORTA :    Local_u8Variable = PINA_REG ;   break;  
            case PORTB :    Local_u8Variable = PINB_REG ;   break;
            case PORTC :    Local_u8Variable = PINC_REG ;   break;
            case PORTD :    Local_u8Variable = PIND_REG ;   break;
            default    :                                    break;
        }
    }
    return Local_u8Variable ;
}
/*==========================================================================*/
/*==========================================================================*/



/*==========================================================================*/
/* ====================     Toggle Write Modules       =====================*/
/*==========================================================================*/
/****************************************************************************/
/* Function Name : DIO_voidTogglePinValue                                   */
/* Description : Toggle pin value of one bit of the Port register           */
/* Fun. Argument1: Copy_u8PortNumber { PORTA,PORTB,PORTC,PORTD }            */
/* Fun. Argument2: Copy_u8PinNumber { PIN0,PIN1,PIN3,PIN4,PIN5,PIN6,PIN7 }  */
/* Fun. Return : void                                                       */
/****************************************************************************/
void DIO_voidTogglePinValue (u8 Copy_u8PortNumber, u8 Copy_u8PinNumber )
{
    /* i/p validation */
    if ( Copy_u8PortNumber > PORTD || Copy_u8PinNumber > PIN7 )
    {
        // Do Nothing
    }
    else
    {
        switch(Copy_u8PortNumber)
        {
            case PORTA :    TOGGLE_BIT( PORTA_REG, Copy_u8PinNumber );     break;
            case PORTB :    TOGGLE_BIT( PORTB_REG, Copy_u8PinNumber );     break;
            case PORTC :    TOGGLE_BIT( PORTC_REG, Copy_u8PinNumber );     break;
            case PORTD :    TOGGLE_BIT( PORTD_REG, Copy_u8PinNumber );     break;
            default :                                                      break;
        }
    }
}
/****************************************************************************/
/* Function Name : DIO_voidTogglePortValue                                  */
/* Description : Toggles pin values of the whole Port register              */
/* Fun. Argument1: Copy_u8PortNumber { PORTA,PORTB,PORTC,PORTD }            */
/* Fun. Return : void                                                       */
/****************************************************************************/
void DIO_voidTogglePortValue (u8 Copy_u8PortNumber )
{
        /* i/p validation */
    if ( Copy_u8PortNumber > PORTD )
    {
        // Do Nothing
    }
    else 
    {
        switch(Copy_u8PortNumber)
        {
            case PORTA :    PORTA_REG ^= 0xff ;     break;           
            case PORTB :    PORTB_REG ^= 0xff ;     break;          
            case PORTC :    PORTC_REG ^= 0xff ;     break; 
            case PORTD :    PORTD_REG ^= 0xff ;     break; 
            default    :                            break;
        }
    }
}
/*==========================================================================*/
/*==========================================================================*/




/*=================================================================================================*/
/*==============================     Enable Pull-Up Res Modules       =============================*/
/*=================================================================================================*/
/***************************************************************************************************/
/* Function Name : DIO_voidConfig_Pull_Up_Pin                                                      */
/* Description : Configure pullup Res status for on a given Pin and port                           */ 
/* Fun. Argument1: Copy_u8PortNumber { PORTA,PORTB,PORTC,PORTD }                                   */
/* Fun. Argument2: Copy_u8PinNumber { PIN0,PIN1,PIN3,PIN4,PIN5,PIN6,PIN7 }                         */
/* Fun. Argument3: Copy_u8PullUpStatus { ON , OFF }                                                */
/* Fun. Return : void                                                                              */
/***************************************************************************************************/
void DIO_voidConfig_Pull_Up_Pin (u8 Copy_u8PortNumber, u8 Copy_u8PinNumber , u8 Copy_u8PullUpStatus )
{
    /* i/p validation */
    if ( Copy_u8PortNumber > PORTD || Copy_u8PinNumber > PIN7 )
    {
        // Do Nothing
    }
    else
    {
       switch(Copy_u8PullUpStatus)
       {
            case ON  :   DIO_voidSetPinValue (Copy_u8PortNumber,Copy_u8PinNumber, HIGH );   break;
            case OFF :   DIO_voidSetPinValue (Copy_u8PortNumber,Copy_u8PinNumber, LOW  );   break; 
            default  :                                                                      break; 
       }
    }    
}
/***************************************************************************************************/
/* Function Name : DIO_voidConfig_Pull_Up_Port                                                     */
/* Description : Configure Pull-Up Res status for the whole Port register                          */ 
/* Fun. Argument1: Copy_u8PortNumber { PORTA,PORTB,PORTC,PORTD }                                   */
/* Fun. Argument2: Copy_u8PullUpStatus { ON , OFF }                                                */
/* Fun. Return : void                                                                              */
/***************************************************************************************************/
void DIO_voidConfig_Pull_Up_Port (u8 Copy_u8PortNumber, u8 Copy_u8PullUpStatus )
{
    /* i/p validation */
    if ( Copy_u8PortNumber > PORTD )
    {
        // Do Nothing
    }
    else
    {
       switch(Copy_u8PullUpStatus)
       {
            case ON :  DIO_voidSetPortValue (Copy_u8PortNumber, HIGH );  break;
            case OFF:  DIO_voidSetPortValue (Copy_u8PortNumber, LOW );   break;
            default :                                                    break;
       }
    }    
}
/*=================================================================================================*/
/*=================================================================================================*/
