/*=================================================================================*/
/*  File        : LCD_Config.h                                                     */
/*  Description : This file includes LCD Driver Configrations for Atmega32         */
/*  Author      : Ahmed Bahaa Taha Nasr. Embedded SW Engineer                      */
/*  Date        : 28/3/2023                                                        */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-bahaa1/                        */
/*  Git account : https://github.com/ahmedbahaa11                                  */
/*  mail        : ahmedbahaataha7@gmil.com                                         */
/*=================================================================================*/

/* File Gaurd by ifndef & endif */
#ifndef LCD_CONFIG_H
#define LCD_CONFIG_H
/* LCD Hardware Configration with atmega PORTS & PINS */

#define LCD_DATA_PORT            PORTA

#define LCD_CONTROL_PORT         PORTB

#define RS_PIN                   PIN2
#define RW_PIN                   PIN1
#define E_PIN                    PIN0


#endif