/*=================================================================================*/
/*  File        : TIMER1_Private.h                                                 */
/*  Description : This Private file includes TIMER1 Driver macros for Atmega32     */
/*  Author      : Ahmed Bahaa Taha Nasr. Embedded SW Engineer                      */
/*  Date        : 9/4/2023                                                         */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-bahaa1/                        */
/*  Git account : https://github.com/ahmedbahaa11                                  */
/*  mail        : abahaa14842@gmail.com                                            */
/*=================================================================================*/
/* File Gaurd by ifndef & endif */
#ifndef TIMER1_PRIVATE_H
#define TIMER1_PRIVATE_H

/*================================================================================================================*/
/*******************************************       Private Macros       *******************************************/
/*================================================================================================================*/
/********      [TIMER1] Registers       *********/
#define     TCCR1A_REG       *((volatile u8*)0x4F)      // Timer/Counter 1A Control Register
#define     TCCR1B_REG       *((volatile u8*)0x4E)      // Timer/Counter 1B Control Register
#define     TCNT1H_REG       *((volatile u8*)0x4D)      // Timer/Counter 1H Register
#define     TCNT1L_REG       *((volatile u8*)0x4C)      // Timer/Counter 1L Register
#define     TCNT1_REG        *((volatile u16*)0x4C)     // Timer/Counter 16-BIT Register
#define     OCR1AH_REG       *((volatile u8*)0x4B)      // Output Compare 1AH Register 
#define     OCR1AL_REG       *((volatile u8*)0x4A)      // Output Compare 1AL Register 
#define     OCR1A_REG        *((volatile u16*)0x4A)     // Output Compare 1A 16-BIT Register 
#define     OCR1BH_REG       *((volatile u8*)0x49)      // Output Compare 1BH Register 
#define     OCR1BL_REG       *((volatile u8*)0x48)      // Output Compare 1BL Register 
#define     OCR1B_REG        *((volatile u16*)0x48)     // Output Compare 1B 16-BIT Register 
#define     ICR1H_REG        *((volatile u8*)0x47)      // Input Capture 1H Register
#define     ICR1L_REG        *((volatile u8*)0x46)      // Input Capture 1L Register
#define     ICR1_REG         *((volatile u16*)0x46)     // Input Capture 16-BIT Register
#define     TIMSK_REG        *((volatile u8*)0x59)      // Timer/Counter Interrupt Mask Register
#define     TIFR_REG         *((volatile u8*)0x58)      // Timer/Counter Interrupt Flag Register
/*================================================================================================================*/
/********   TIMER1 [TCCR1A] BITS   *******/
#define     TCCR1A_WGM10                 0              // Waveform Generation Mode.           
#define     TCCR1A_WGM11                 1              // Waveform Generation Mode.
#define     TCCR1A_FOC1B                 2              // Force Output Compare for Compare unit B
#define     TCCR1A_FOC1A                 3              // Force Output Compare for Compare unit A
#define     TCCR1A_COM1B0                4              // Compare Output Mode for Compare unit B
#define     TCCR1A_COM1B1                5              // Compare Output Mode for Compare unit B
#define     TCCR1A_COM1A0                6              // Compare Output Mode for Compare unit A
#define     TCCR1A_COM1A1                7              // Compare Output Mode for Compare unit A
/*================================================================================================================*/
/********   TIMER1 [TCCR1B] BITS   *******/
#define     TCCR1B_CS10                  0              // TIMER1 Prescaller Clock Select BIT 0           
#define     TCCR1B_CS11                  1              // TIMER1 Prescaller Clock Select BIT 1
#define     TCCR1B_CS12                  2              // TIMER1 Prescaller Clock Select BIT 2
#define     TCCR1B_WGM12                 3              // Waveform Generation Mode.
#define     TCCR1B_WGM13                 4              // Waveform Generation Mode.
#define     TCCR1B_ICES1                 6              // Input Capture Edge Select.
#define     TCCR1B_ICNC1                 7              // Input Capture Noise Canceler.
/*================================================================================================================*/
/********    TIMER [TIMSK] BITS   *******/
#define     TIMER_TIMSK_TOIE1            2              //  Timer/Counter1 Overflow Interrupt Enable
#define     TIMER_TIMSK_OCIE1B           3              //  Timer/Counter1 Output Compare B Match Interrupt Enable
#define     TIMER_TIMSK_OCIE1A           4              //  Timer/Counter1 Output Compare A Match Interrupt Enable
#define     TIMER_TIMSK_TICIE            5              //  Timer/Counter1 Input Capture Interrupt Enable
/*================================================================================================================*/  
/********    TIMER [TIFR] BITS    *******/                
#define     TIMER_TIFR_TOV1              2              // Timer/Counter1 Overflow Flag
#define     TIMER_TIFR_OCF1B             3              // Timer/Counter1 Output Compare B Match Flag
#define     TIMER_TIFR_OCF1A             4              // Timer/Counter1 Output Compare A Match Flag
#define     TIMER_TIFR_ICF1              5              // Timer/Counter1 Input Capture Flag
/*================================================================================================================*/

#define     NULL                   (void*)(0)


#endif