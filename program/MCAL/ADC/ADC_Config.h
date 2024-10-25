/*=================================================================================*/
/*  File        : ADC_Config.h                                                     */
/*  Description : This file includes ADC Driver Configrations for Atmega32         */
/*  Author      : Ahmed Bahaa Taha Nasr. Embedded SW Engineer                      */
/*  Date        : 3/4/2023                                                         */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-bahaa1/                        */
/*  Git account : https://github.com/ahmedbahaa11                                  */
/*  mail        : abahaa14842@gmail.com                                            */
/*=================================================================================*/

/* File Gaurd by ifndef & endif */
#ifndef ADC_CONFIG_H
#define ADC_CONFIG_H

/*===============================================*/
/*       Select Reference Voltage       */
/*--------------------------------------*/
#define     AREF                         0
#define     AVCC                         1
#define     RESERVED                     2
#define     INTERNAL                     3
/*===============================================*/
#define     REFERENCE_VOLTAGE           AVCC
/*===============================================*/
/*     Select RIGHT or LEFT Adjust      */
/*--------------------------------------*/
#define     RIGHT                        0
#define     LEFT                         1
/*===============================================*/
#define     ADJUST                     RIGHT
/*===============================================*/
/*        ADC ENABLE or DISABLE         */
/*--------------------------------------*/
#define     DISABLE                      0
#define     ENABLE                       1
/*===============================================*/
#define     ADEN                       ENABLE
/*===============================================*/
/*    AUTO Trigger Enable or Disable    */
/*--------------------------------------*/
#define     DISABLE                      0
#define     ENABLE                       1
/*===============================================*/
#define     ADATE                      DISABLE
/*===============================================*/
/*       ADC Auto Trigger Source        */
/*--------------------------------------*/
#define  Free_Running_Mode               0
#define  Analog_Comparator               1
#define  External_Interrupt_Request_0    2
#define  Timer_Counter0_Compare_Match    3
#define  Timer_Counter0_Overflow         4
#define  Timer_Counter1_Compare_MatchB   5
#define  Timer_Counter1_Overflow         6
#define  Timer_Counter1_Capture_Event    7
/*===============================================*/
#define  AUTO_TRIGGER_SOURCE     Free_Running_Mode
/*===============================================*/
/*    ADC Interrupt Enable or Disable   */
/*--------------------------------------*/
#define     DISABLE                      0
#define     ENABLE                       1
/*===============================================*/
#define     ADIE                       DISABLE
/*===============================================*/
/*        ADC Prescaler Selection        */
/*---------------------------------------*/
#define     NOT_USE_PRESCALER             0
#define     PRESCALER_DIVISION_BY_2       2
#define     PRESCALER_DIVISION_BY_4       4
#define     PRESCALER_DIVISION_BY_8       8
#define     PRESCALER_DIVISION_BY_16      16
#define     PRESCALER_DIVISION_BY_32      32
#define     PRESCALER_DIVISION_BY_64      64
#define     PRESCALER_DIVISION_BY_128     128
/*===============================================*/
#define     PRESCALER           NOT_USE_PRESCALER
/*===============================================*/




#endif