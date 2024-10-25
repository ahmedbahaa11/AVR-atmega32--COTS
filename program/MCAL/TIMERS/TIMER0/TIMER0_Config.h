/*=================================================================================*/
/*  File        : TIMER0_Config.h                                                  */
/*  Description : This file includes TIMER0 Driver Configrations for Atmega32      */
/*  Author      : Ahmed Bahaa Taha Nasr. Embedded SW Engineer                      */
/*  Date        : 7/4/2023                                                         */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-bahaa1/                        */
/*  Git account : https://github.com/ahmedbahaa11                                  */
/*  mail        : abahaa14842@gmail.com                                            */
/*=================================================================================*/
/* File Gaurd by ifndef & endif */
#ifndef TIMER0_CONFIG_H
#define TIMER0_CONFIG_H

/*===============================================*/
/*              TIMER0 Mode Selection            */
/*-----------------------------------------------*/
#define     NORMAL_OVF                   0
#define     PWM_PHASECORRECT             1
#define     CTC                          2
#define     FAST_PWM                     3
/*===============================================*/
#define     MODE                     CTC
/*===============================================*/
/*==========================================================*/
/*               OC0 Mode Selection                         */
/*----------------------------------------------------------*/
#define     DISCONNECTED                                    0
#define     SETonTOP_CLEARonCOMPARE                         1
#define     SETonCOMPARE_CLEARonTOP                         2
#define     SETonCOMPdownCounting_CLEARonCOMPupCounting     3    
#define     SETonCOMPupCounting_CLEARonCOMPdownCounting     4
/*===========================================================*/
#define     OC0_MODE      SETonTOP_CLEARonCOMPARE
/*===========================================================*/
/*===============================================*/
/*          TIMER0 Prescaller Selection          */
/*-----------------------------------------------*/
#define     NO_CLK_SOURCE_TIMER_STOPED       0x00
#define     NOT_USE_PRESCALER                0x01
#define     PRESCALER_DIVISION_BY_8          0x02
#define     PRESCALER_DIVISION_BY_64         0x03
#define     PRESCALER_DIVISION_BY_256        0x04
#define     PRESCALER_DIVISION_BY_1024       0x05
#define     EXTERNAL_CLK_SOURCE_FALLING_EDGE 0x06  
#define     EXTERNAL_CLK_SOURCE_RAISING_EDGE 0x07   
/*===========================================================*/
#define     PRESCALER           PRESCALER_DIVISION_BY_1024
/*===========================================================*/
#define     CPU_CLK       8  // MHz

#endif