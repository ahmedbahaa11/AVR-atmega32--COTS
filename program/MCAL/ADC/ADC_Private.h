/*=================================================================================*/
/*  File        : ADC_Private.h                                                    */
/*  Description : This Private file includes ADC Driver macros for Atmega32        */
/*  Author      : Ahmed Bahaa Taha Nasr. Embedded SW Engineer                      */
/*  Date        : 3/4/2023                                                         */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-bahaa1/                        */
/*  Git account : https://github.com/ahmedbahaa11                                  */
/*  mail        : ahmedbahaataha7@gmil.com                                         */
/*=================================================================================*/

/* File Gaurd by ifndef & endif */
#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

/* Private Macros */
#define      ADMUX_REG             *((volatile u8*)0x27)
#define     ADCSRA_REG             *((volatile u8*)0x26)
#define       ADCH_REG             *((volatile u8*)0x25)   // Pointer to 8 bit ADCH to read Data From 8 BIT of ADC Data by Right Adjust.
#define       ADCL_REG             *((volatile u8*)0x24)
#define        ADC_REG             *((volatile u16*)0x24)  // Pointer to 16 bit ADCH and ADCL to read Data From 10 BIT of ADC Data. 
#define      SFIOR_REG             *((volatile u8*)0x50)

#define     BUSY                    0
#define     NOT_BUSY                1

#define     NULL                (void*)(0)

#endif