/*=================================================================================*/
/*  File        : KPAD_Config.h                                                     */
/*  Description : This file includes KPAD Driver Configrations for Atmega32         */
/*  Author      : Ahmed Bahaa Taha Nasr. Embedded SW Engineer                      */
/*  Date        : 30/3/2023                                                        */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-bahaa1/                        */
/*  Git account : https://github.com/ahmedbahaa11                                  */
/*  mail        : abahaa14842@gmail.com                                            */
/*=================================================================================*/

/* File Gaurd by ifndef & endif */
#ifndef KPAD_CONFIG_H
#define KPAD_CONFIG_H

#define  KPAD_PORT             PORTB
 
#define  KPAD_C0_PIN           PIN4
#define  KPAD_C1_PIN           PIN5
#define  KPAD_C2_PIN           PIN6
#define  KPAD_C3_PIN           PIN7

#define  KPAD_R0_PIN           PIN0
#define  KPAD_R1_PIN           PIN1
#define  KPAD_R2_PIN           PIN2
#define  KPAD_R3_PIN           PIN3

#define  KPAD_COLUMNS_NUM         4
#define  KPAD_ROWS_NUM            4

// arr[1][3] = '*'  C0   C1  C2  C3
#define KPAD_KEYS {{'7','8','9','/'}, {'4','5','6','*'}, {'1','2','3','-'}, {'#','0','=','+'}}
// arr[2][2] = '3'

#endif 