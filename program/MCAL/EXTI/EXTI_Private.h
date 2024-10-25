/*=================================================================================*/
/*  File        : EXTI_Private.h                                                   */
/*  Description : This Private file includes EXTI Driver macros for Atmega32       */
/*  Author      : Ahmed Bahaa Taha Nasr. Embedded SW Engineer                      */
/*  Date        : 2/4/2023                                                         */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-bahaa1/                        */
/*  Git account : https://github.com/ahmedbahaa11                                  */
/*  mail        : abahaa14842@gmail.com                                            */
/*=================================================================================*/

/* File Gaurd by ifndef & endif */
#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

/* Private Macros */

#define  GICR_REG            *((volatile u8*)0x5B)
#define  MCUCR_REG           *((volatile u8*)0x55)
#define  MCUCSR_REG          *((volatile u8*)0x54)

/* Private Macros to BIT Numbers */
#define  PIN0                    0
#define  PIN1                    1
#define  PIN2                    2
#define  PIN3                    3
#define  PIN4                    4
#define  PIN5                    5
#define  PIN6                    6
#define  PIN7                    7

#define  NULL                     (void*)(0)

#endif