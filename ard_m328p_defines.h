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
#define A_STA *((volatile byte*) 0x5F)
// MCU status register
#define M_STA *((volatile byte*) 0x34)
// Watchdog timer registers
#define W_TIMER *((volatile byte*) 0x60)
// Data direction registers
#define B_DIRS *((volatile byte*) 0x24)
#define C_DIRS *((volatile byte*) 0x27)
#define D_DIRS *((volatile byte*) 0x2a)
// Input addresses
#define B_PORTS_IN *((volatile byte*) 0x23)
#define C_PORTS_IN *((volatile byte*) 0x26)
#define D_PORTS_IN *((volatile byte*) 0x29)
// Data registers
#define B_PORTS_OUT *((volatile byte*) 0x25)
#define C_PORTS_OUT *((volatile byte*) 0x28)
#define D_PORTS_OUT *((volatile byte*) 0x2b)

#endif // ARD_M328P_DEFINES_H
