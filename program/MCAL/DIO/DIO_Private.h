/*=================================================================================*/
/*  File        : DIO_Private.h                                                    */
/*  Description : This Private file includes DIO Driver macros for Atmega32        */
/*  Author      : Ahmed Bahaa Taha Nasr. Embedded SW Engineer                      */
/*  Date        : 27/3/2023                                                        */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-bahaa1/                        */
/*  Git account : https://github.com/ahmedbahaa11                                  */
/*  mail        : abahaa14842@gmail.com                                            */
/*=================================================================================*/

/* File Gaurd by ifndef & endif */
#ifndef DIO_PRIVATE_H
#define DIO_PRIVATE_H

/* Private Macros */

#define DDRA_REG         *((volatile u8*)0x3A)
#define DDRB_REG         *((volatile u8*)0x37)
#define DDRC_REG         *((volatile u8*)0x34)
#define DDRD_REG         *((volatile u8*)0x31)
         
#define PORTA_REG        *((volatile u8*)0x3B)
#define PORTB_REG        *((volatile u8*)0x38)
#define PORTC_REG        *((volatile u8*)0x35)
#define PORTD_REG        *((volatile u8*)0x32)
         
#define PINA_REG         *((volatile u8*)0x39)
#define PINB_REG         *((volatile u8*)0x36)
#define PINC_REG         *((volatile u8*)0x33)
#define PIND_REG         *((volatile u8*)0x30)


#endif