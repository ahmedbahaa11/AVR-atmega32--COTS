/*===================================================================================================*/
/*  File        : ADC_Interface.h                                                                    */
/*  Description : This interface file includes ADC Driver prototypes and declarations for Atmega32   */
/*  Author      : Ahmed Bahaa Taha Nasr. Embedded SW Engineer                                        */
/*  Date        : 3/4/2023                                                                           */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-bahaa1/                                          */
/*  Git account : https://github.com/ahmedbahaa11                                                    */
/*  mail        : ahmedbahaataha7@gmil.com                                                           */
/*===================================================================================================*/

/* File Gaurd by ifndef & endif */
#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

/*     Macros of Channel Number    */
#define     ADC0                    0
#define     ADC1                    1
#define     ADC2                    2
#define     ADC3                    3
#define     ADC4                    4
#define     ADC5                    5
#define     ADC6                    6
#define     ADC7                    7

typedef struct temp_ADC {
    u16 digitalValue;
    u16 analogValue;
    u16 tempValue;
}Temperature;



/************************************************************************************************/
/* Function Name : ADC_voidInit                                                                 */
/* Description : Initilization of ADC with Specific Specs accordig to Gonfigration File.h       */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void ADC_voidInit (void);
/************************************************************************************************/
/* Function Name : ADC_u16ReadSynchronus                                                        */
/* Description : Get Analog Reading From ADC                                                    */
/* Fun. Argument1: Copy_u8ChannelNumber { ADC0,ADC1,ADC2,ADC3,ADC4,ADC5,ADC6,ADC7 }             */
/* Fun. Return : u16                                                                            */
/************************************************************************************************/
u16 ADC_u16ReadSynchronus ( u8 Copy_u8ChannelNumber ) ;

u16 ADC_u16ReadASynchronus ( u8 Copy_u8ChannelNumber ,  void (*Local_PointerToFunction) (void) ) ;

void ADC_getTemperature ( u8 Copy_u8ChannelNumber , Temperature * Outdata );

#endif