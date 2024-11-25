#include "wait.h"

#ifdef WAIT_IMP_2
#include "ard_m328p_defines.h"

#define HALF_SECOND     1
#define ONE_SECOND      2
#define TWO_SECOND      4
#define FOUR_SECOND     8
#define H_SECOND        16

void wait_ms(int ms){}
void wait_sec(int s){}

void _set_interrupt(){
    WDTCSR = WDIE;
}

void _set_prescale_units(int mode){
    volatile byte scales;
    if(mode == 16)
        scales = WDE | WDP1 | WDP0;
    else if(mode == 1)
        scales = WDE | WDP2 | WDP0;
    else if(mode == 2)
        scales = WDE | WDP2 | WDP1;
    else if(mode == 4)
        scales = WDE | WDP2 | WDP1 | WDP0;
    else if(mode == 8)
        scales = WDE | WDP3;
    else
        scales = WDE | WDP2 | WDP1;
    WDTCSR = WDCE | WDE;
    WDTCSR = scales;
}

void _reset_wdt(){
    MCUSR &= ~WDRF; // Reset
    WDTCSR |= WDCE;
    WDTCSR = 0;
}

void _poll(){
    volatile byte b = 0;
    while (!b) b = WDTCSR & WDIF;
}

void _wdt_wait(int mode){
    _reset_wdt();
    _set_prescale_units(mode);
    _set_interrupt();
    _poll();
}

// Public functions

void wait_4s(){
    _wdt_wait(FOUR_SECOND);
}

void wait_2s(){
    _wdt_wait(TWO_SECOND);
}

void wait_1s(){
    _wdt_wait(ONE_SECOND);
}

void wait_500ms(){
    _wdt_wait(HALF_SECOND);
}

void wait_125ms()
{
    _wdt_wait(H_SECOND);
}

#endif
