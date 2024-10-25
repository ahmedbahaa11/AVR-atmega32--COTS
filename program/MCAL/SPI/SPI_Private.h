/*=================================================================================*/
/*  File        : SPI_Private.h                                                    */
/*  Description : This Private file includes SPI Driver macros for Atmega32        */
/*  Author      : Ahmed Bahaa Taha Nasr. Embedded SW Engineer                      */
/*  Date        : 12/4/2023                                                        */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-bahaa1/                        */
/*  Git account : https://github.com/ahmedbahaa11                                  */
/*  mail        : abahaa14842@gmail.com                                            */
/*=================================================================================*/

/* File Gaurd by ifndef & endif */
#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

/*================================================================================================================*/
/*******************************************       Private Macros       *******************************************/
/*================================================================================================================*/
/*============     [SPI] Registers     ============*/
#define     SPCR_REG       (*(volatile u8 *)(0x2D))        // SPI Control Register – SPCR
#define     SPSR_REG       (*(volatile u8 *)(0x2E))        // SPI Status Register – SPSR
#define     SPDR_REG       (*(volatile u8 *)(0x2F))        // SPI Data Register – SPDR 
/*================================================================================================================*/
/*=======   SPI [SPCR] BITS  ========*/
#define     SPCR_SPR0                0             // Bits 0 – SPR0: SPI Clock Rate Select 1 and 0
#define     SPCR_SPR1                1             // Bits 1 – SPR1: SPI Clock Rate Select 1 and 0
#define     SPCR_CPHA                2             // Bit 2 – CPHA: Clock Phase
#define     SPCR_CPOL                3             // Bit 3 – CPOL: Clock Polarity
#define     SPCR_MSTR                4             // Bit 4 – MSTR: Master/Slave Select
#define     SPCR_DORD                5             // Bit 5 – DORD: Data Order
#define     SPCR_SPE                 6             // Bit 6 – SPE: SPI Enable
#define     SPCR_SPIE                7             // Bit 7 – SPIE: SPI Interrupt Enable
/*================================================================================================================*/
/*=======   SPI [SPSR] BITS  ========*/
#define     SPSR_SPI2X               0             // Bit 0 – SPI2X: Double SPI Speed Bit
#define     SPSR_WCOL                6             // Bit 6 – WCOL: Write COLlision Flag
#define     SPSR_SPIF                7             // Bit 7 – SPIF: SPI Interrupt Flag
/*================================================================================================================*/
#define     NULL                (void*)(0)

#endif