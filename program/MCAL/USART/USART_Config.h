/*=================================================================================*/
/*  File        : USART_Config.h                                                   */
/*  Description : This file includes USART Driver Configrations for Atmega32       */
/*  Author      : Ahmed Bahaa Taha Nasr. Embedded SW Engineer                      */
/*  Date        : 11/4/2023                                                        */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-bahaa1/                        */
/*  Git account : https://github.com/ahmedbahaa11                                  */
/*  mail        : abahaa14842@gmail.com                                            */
/*=================================================================================*/

/* File Gaurd by ifndef & endif */
#ifndef USART_CONFIG_H
#define USART_CONFIG_H
/*===============================================*/
/*          Select BAUD Rate & CPU CLOCK         */
/*-----------------------------------------------*/
#define     CPU_CLK             8000000
#define     BAUD_RATE           9600
/*===============================================*/

/*===============================================*/
/*   Select Normal or Double Speed Transsmition  */
/*-----------------------------------------------*/
#define     DOUBBLE_SPEED           0
#define     NORMAL_SPEED            1
/*===============================================*/
#define     SPEED            DOUBBLE_SPEED
/*===============================================*/

/*===============================================*/
/*    Select Parity Mode EVEN , ODD , DISABLE    */
/*-----------------------------------------------*/
#define     DISABLE                  0
#define     EVEN                     1
#define     ODD                      2
/*===============================================*/
#define     Parity_Mode             DISABLE
/*===============================================*/

/*===============================================*/
/*        Select STOP BIT  { ONE , TWO }         */
/*-----------------------------------------------*/
#define     ONE                      0
#define     TWO                      1
/*===============================================*/
#define     STOP_BIT                ONE
/*===============================================*/

#endif