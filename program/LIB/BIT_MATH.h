/*=================================================================================*/
/*  File        : BIT_MATH.h                                                       */
/*  Description : This file includes BIT_MATH macros for Atmega32                  */
/*  Author      : Ahmed Bahaa Taha Nasr. Embedded SW Engineer                      */
/*  Date        : 10/3/2023                                                        */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-bahaa1/                        */
/*  Git account : https://github.com/ahmedbahaa11                                  */
/*  mail        : abahaa14842@gmail.com                                            */
/*=================================================================================*/

/* File Gaurd by ifndef & endif */
#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(REG,BIT_POSITION)     REG |= (1<<BIT_POSITION)
#define CLEAR_BIT(REG,BIT_POSITION)   REG &= ~(1<<BIT_POSITION)
#define GET_BIT(REG,BIT_POSITION)     REG & (1<<BIT_POSITION)
#define TOGGLE_BIT(REG,BIT_POSITION)  REG ^= (1<<BIT_POSITION)

#endif