#ifndef ARD_M328P_DEFINES_H
#define ARD_M328P_DEFINES_H

/*
 * This file contains definitions for the Atmega328 mcu
 *
 * For further info consult the datasheet for Atmega328
 */

typedef unsigned char byte;

#define T_INT *((volatile byte*) 0x000C)
// AVR status register
#define S_REG *((volatile byte*) 0x5F)
#define I_BIT 128
// MCU status register
#define MCUSR *((volatile byte*) 0x34)
#define WDRF 8
// Watchdog Timer (WDT)
#define WDTCSR *((volatile byte*) 0x60)
#define WDIF 128
#define WDIE 64
#define WDP3 32
#define WDCE 16
#define WDE  8
#define WDP2 4
#define WDP1 2
#define WDP0 1
// Data direction registers
#define DDRB *((volatile byte*) 0x24)
#define DDRC *((volatile byte*) 0x27)
#define DDRD *((volatile byte*) 0x2a)
// Input addresses
#define PINB *((volatile byte*) 0x23)
#define PINC *((volatile byte*) 0x26)
#define PIND *((volatile byte*) 0x29)
// Data registers
#define PORTB *((volatile byte*) 0x25)
#define PORTC *((volatile byte*) 0x28)
#define PORTD *((volatile byte*) 0x2b)
// Interrupts
#define EICRA *((volatile byte*) 0x69)
#define ISC11 8
#define ISC10 4
#define ISC01 2
#define ISC00 1
#define EIMSK *((volatile byte*) 0x3D)
#define INT1 2
#define INT0 1
#define EIFR *((volatile byte*) 0x3C)
#define INTF1 2
#define INTF0 1

#endif // ARD_M328P_DEFINES_H
