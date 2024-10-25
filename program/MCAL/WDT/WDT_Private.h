/*=================================================================================*/
/*  File        : WDT_Private.h                                                    */
/*  Description : This file includes WDT Driver macros for Atmega32                */
/*  Author      : Ahmed Bahaa Taha Nasr. Embedded SW Engineer                      */
/*  Date        : 27/3/2023                                                        */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-bahaa1/                        */
/*  Git account : https://github.com/ahmedbahaa11                                  */
/*  mail        : abahaa14842@gmail.com                                            */
/*=================================================================================*/
#ifndef WDT_PRIVATE_H_
#define WDT_PRIVATE_H_


#define WDT_WDTCR  (*(volatile u8 *)0x41)


#define WDTCR_WDP0   0x00
#define WDTCR_WDP1   0x01
#define WDTCR_WDP2   0x02
#define WDTCR_WDE 	 0x03
#define WDTCR_WDPTOE 0x04

#endif /* WDT_PRIVATE_H_ */
