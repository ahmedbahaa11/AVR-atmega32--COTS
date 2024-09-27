/*=================================================================================*/
/*  File        : TIMER0_Config.h                                                  */
/*  Description : This file includes TIMER0 Driver Configrations for Atmega32      */
/*  Author      : Ahmed Bahaa Taha Nasr. Embedded SW Engineer                      */
/*  Date        : 7/4/2023                                                         */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-bahaa1/                        */
/*  Git account : https://github.com/ahmedbahaa11                                  */
/*  mail        : ahmedbahaataha7@gmil.com                                         */
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
#define     MODE                     FAST_PWM
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
#define     NO_CLK_SOURCE_TIMER_STOPED          0
#define     NOT_USE_PRESCALER                   1
#define     PRESCALER_DIVISION_BY_8             8
#define     PRESCALER_DIVISION_BY_64            64
#define     PRESCALER_DIVISION_BY_256           256
#define     PRESCALER_DIVISION_BY_1024          1024
#define     EXTERNAL_CLK_SOURCE_FALLING_EDGE    6
#define     EXTERNAL_CLK_SOURCE_RAISING_EDGE    7
/*===========================================================*/
#define     PRESCALER           PRESCALER_DIVISION_BY_8
/*===========================================================*/


#endif