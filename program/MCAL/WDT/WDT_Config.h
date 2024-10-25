/*=================================================================================*/
/*  File        : WDT_Config.h                                                     */
/*  Description : This file includes WDT Driver Configrations for Atmega32         */
/*  Author      : Ahmed Bahaa Taha Nasr. Embedded SW Engineer                      */
/*  Date        : 27/3/2023                                                        */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-bahaa1/                        */
/*  Git account : https://github.com/ahmedbahaa11                                  */
/*  mail        : abahaa14842@gmail.com                                            */
/*=================================================================================*/

#ifndef WDT_CONFIG_H_
#define WDT_CONFIG_H_

#define WDT_16K_CYCLES   0
#define WDT_32K_CYCLES   1
#define WDT_64K_CYCLES   2
#define WDT_128K_CYCLES  3
#define WDT_256K_CYCLES  4
#define WDT_512K_CYCLES  5
#define WDT_1024K_CYCLES 6
#define WDT_2048K_CYCLES 7

#define WDT_PRESCALE WDT_2048K_CYCLES

#endif /* WDT_CONFIG_H_ */
