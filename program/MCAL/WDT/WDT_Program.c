/*=================================================================================*/
/*  File        : WDT_Program.c                                                    */
/*  Description : This file includes WDT Driver implementations for Atmega32       */
/*  Author      : Ahmed Bahaa Taha Nasr. Embedded SW Engineer                      */
/*  Date        : 27/3/2023                                                        */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-bahaa1/                        */
/*  Git account : https://github.com/ahmedbahaa11                                  */
/*  mail        : abahaa14842@gmail.com                                            */
/*=================================================================================*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "WDT_Interface.h"
#include "WDT_Private.h"
#include "WDT_Config.h"

void WDT_voidEnable(void)
{
    SET_BIT(WDT_WDTCR, WDTCR_WDE);

    #if WDT_PRESCALE == WDT_16K_CYCLES
    CLEAR_BIT(WDT_WDTCR, WDTCR_WDP0);
    CLEAR_BIT(WDT_WDTCR, WDTCR_WDP1);
    CLEAR_BIT(WDT_WDTCR, WDTCR_WDP2);
    #elif WDT_PRESCALE == WDT_32K_CYCLES
    SET_BIT(WDT_WDTCR, WDTCR_WDP0);
    CLEAR_BIT(WDT_WDTCR, WDTCR_WDP1);
    CLEAR_BIT(WDT_WDTCR, WDTCR_WDP2);
	#elif WDT_PRESCALE == WDT_64K_CYCLES
	CLEAR_BIT(WDT_WDTCR, WDTCR_WDP0);
	SET_BIT(WDT_WDTCR, WDTCR_WDP1);
	CLEAR_BIT(WDT_WDTCR, WDTCR_WDP2);
	#elif WDT_PRESCALE == WDT_128K_CYCLES
	SET_BIT(WDT_WDTCR, WDTCR_WDP0);
	SET_BIT(WDT_WDTCR, WDTCR_WDP1);
	CLEAR_BIT(WDT_WDTCR, WDTCR_WDP2);
	#elif WDT_PRESCALE == WDT_256K_CYCLES
	CLEAR_BIT(WDT_WDTCR, WDTCR_WDP0);
	CLEAR_BIT(WDT_WDTCR, WDTCR_WDP1);
	SET_BIT(WDT_WDTCR, WDTCR_WDP2);
	#elif WDT_PRESCALE == WDT_512K_CYCLES
	SET_BIT(WDT_WDTCR, WDTCR_WDP0);
	CLEAR_BIT(WDT_WDTCR, WDTCR_WDP1);
	SET_BIT(WDT_WDTCR, WDTCR_WDP2);
	#elif WDT_PRESCALE == WDT_1024K_CYCLES
	CLEAR_BIT(WDT_WDTCR, WDTCR_WDP0);
	SET_BIT(WDT_WDTCR, WDTCR_WDP1);
	SET_BIT(WDT_WDTCR, WDTCR_WDP2);
    #elif WDT_PRESCALE == WDT_2048K_CYCLES
    SET_BIT(WDT_WDTCR, WDTCR_WDP0);
    SET_BIT(WDT_WDTCR, WDTCR_WDP1);
    SET_BIT(WDT_WDTCR, WDTCR_WDP2);
    #endif
}

void WDT_voidReset(void)
{
    __asm__ __volatile__ ("wdr");
}

void WDT_voidDisable(void)
{
	WDT_WDTCR = (1 << WDTCR_WDPTOE) | (1 << WDTCR_WDE);
    WDT_WDTCR = CLEAR_BIT(WDT_WDTCR, WDTCR_WDE);
}
