/*=================================================================================*/
/*  File        : TIMER0_Private.h                                                 */
/*  Description : This Private file includes TIMER0 Driver macros for Atmega32     */
/*  Author      : Ahmed Bahaa Taha Nasr. Embedded SW Engineer                      */
/*  Date        : 7/4/2023                                                         */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-bahaa1/                        */
/*  Git account : https://github.com/ahmedbahaa11                                  */
/*  mail        : ahmedbahaataha7@gmil.com                                         */
/*=================================================================================*/
/* File Gaurd by ifndef & endif */
#ifndef TIMER0_PRIVATE_H
#define TIMER0_PRIVATE_H

/*================================================================================================================*/
/*******************************************       Private Macros       *******************************************/
/*================================================================================================================*/
/********      [TIMER0] Registers       *********/
#define     TCCR0_REG        *((volatile u8*)0x53)     // Timer/Counter Control Register
#define     TCNT0_REG        *((volatile u8*)0x52)     // Timer/Counter Register
#define     OCR0_REG         *((volatile u8*)0x5C)     // Output Compare Register 
#define     TIMSK_REG        *((volatile u8*)0x59)     // Timer/Counter Interrupt Mask Register
#define     TIFR_REG         *((volatile u8*)0x58)     // Timer/Counter Interrupt Flag Register
// #define     SFIOR_REG        *((volatile u8*)0x50)     // Special Function IO Register
/*================================================================================================================*/
/********   TIMER0 [TCCR0] BITS   *******/
#define     TIMER0_TCCR0_CS00          0              // TIMER0 Prescaller Clock Select BIT 0           
#define     TIMER0_TCCR0_CS01          1              // TIMER0 Prescaller Clock Select BIT 1
#define     TIMER0_TCCR0_CS02          2              // TIMER0 Prescaller Clock Select BIT 2
#define     TIMER0_TCCR0_WGM01         3              // Waveform Generation Mode (Normal,PWM-Phase Correct,CTC0,Fast PWM).
#define     TIMER0_TCCR0_COM00         4              // Compare Match Output Mode BIT 0 (OC0) behavior
#define     TIMER0_TCCR0_COM01         5              // Compare Match Output Mode BIT 1 (OC0) behavior
#define     TIMER0_TCCR0_WGM00         6              // Waveform Generation Mode (Normal,PWM-Phase Correct,CTC0,Fast PWM).
#define     TIMER0_TCCR0_FOC0          7              // Force Output Compare
/*================================================================================================================*/
/********   TIMER0 [TIMSK] BITS   *******/
#define     TIMER0_TIMSK_TOIE0         0              // Timer/Counter0 OVF Interrupt Enable BIT 0
#define     TIMER0_TIMSK_OCIE0         1              // Timer/Counter0 CTC Interrupt Enable BIT 1
/*================================================================================================================*/  
/********   TIMER0 [TIFR] BITS    *******/                
#define      TIMER0_TIFR_TOV0          0              // Timer/Counter0 OVF Flag
#define      TIMER0_TIFR_OCF0          1              // Timer/Counter0 CTC Flag
/*================================================================================================================*/
/********   TIMER0 [SFIOR] BITS   *******/                
#define      TIMER0_SFIOR_PSR10        0              // Prescaler Reset TIMER0 and TIMER1
/*================================================================================================================*/
#define     NULL                   (void*)(0)


#endif