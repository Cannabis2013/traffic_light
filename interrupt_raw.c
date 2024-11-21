#include "ard_m328p_defines.h"

void _init_interrupt(){
    EICRA = ISC00;
    EIMSK = INT0;
    __asm ("sei");
}

void _halt(){
    volatile long index = 350000;
    while (index > 0) index -= 1;
}

void __vector_1(void) __attribute__((interrupt));

void __vector_1(void)
{
    PORTD = 32;
}

void interrupt_raw()
{
    DDRD = 32;
    _init_interrupt();
    _halt();
    PINB = 1;
}
