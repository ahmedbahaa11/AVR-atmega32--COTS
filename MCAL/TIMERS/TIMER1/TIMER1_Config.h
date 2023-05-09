/*=================================================================================*/
/*  File        : TIMER1_Config.h                                                  */
/*  Description : This file includes TIMER1 Driver Configrations for Atmega32      */
/*  Author      : Ahmed Bahaa Taha Nasr. Embedded SW Engineer                      */
/*  Date        : 9/4/2023                                                         */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-bahaa1/                        */
/*  Git account : https://github.com/ahmedbahaa11                                  */
/*  mail        : ahmedbahaataha7@gmil.com                                         */
/*=================================================================================*/
/* File Gaurd by ifndef & endif */
#ifndef TIMER1_CONFIG_H
#define TIMER1_CONFIG_H

/*===============================================*/
/*              TIMER1 Mode Selection            */
/*-----------------------------------------------*/
#define     NORMAL_OVF                          0       
#define     PWM_PHASECORRECT_8_BIT              1
#define     PWM_PHASECORRECT_9_BIT              2
#define     PWM_PHASECORRECT_10_BIT             3
#define     CTC                                 4
#define     FAST_PWM_8_BIT                      5
#define     FAST_PWM_9_BIT                      6
#define     FAST_PWM_10_BIT                     7
#define     PWM_Phase_FrequencyCorrect_ICR1     8
#define     PWM_Phase_FrequencyCorrect          9
#define     PWM_PhaseCorrect_ICR1               10
#define     PWM_PhaseCorrect                    11
#define     CTC_ICR1                            12
#define     Reversed                            13
#define     FAST_PWM_ICR1                       14
#define     FAST_PWM                            15
/*==========================================================*/
#define     MODE                     FAST_PWM_ICR1
/*==========================================================*/
/*==========================================================*/
/*               OC1A & OC1B Mode Selection                 */
/*----------------------------------------------------------*/
#define     DISCONNECTED                                    0
#define     SETonTOP_CLEARonCOMPARE                         1
#define     SETonCOMPARE_CLEARonTOP                         2
#define     SETonCOMPdownCounting_CLEARonCOMPupCounting     3    
#define     SETonCOMPupCounting_CLEARonCOMPdownCounting     4
/*===========================================================*/
#define     OC1A_MODE      SETonTOP_CLEARonCOMPARE                  // Channel A at PIN OC1A
#define     OC1B_MODE      DISCONNECTED                             // Channel B at PIN OC1B
/*===========================================================*/
/*===============================================*/
/*          TIMER1 Prescaller Selection          */
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