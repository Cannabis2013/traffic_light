#include "wait.h"

#ifdef WAIT_IMP_2

#include "ard_m328p_defines.h"

void wait_ms(int ms){}
void wait_sec(int s){}
void _disable();

// AVR status register
#define I_BIT               (1 << 7)
// MCU status register
#define WDRF                (1 << 3)
// Watchdog timer control register
#define WDIF                (1 << 7)
#define WDIE                (1 << 6)
#define WDP3                (1 << 5)
#define WDCE                (1 << 4)
#define WDE                 (1 << 3)
#define WDP2                (1 << 2)
#define WDP1                (1 << 1)
#define WDP0                (1 << 0)

volatile int _time_out = 0;

void _set_time_out(){
    D_PORTS_OUT = 0b11111100;
    volatile long index = 350000;
    while (index >= 0) index -= 1;
}

void _poll();

void init_wait(){
    M_STA &= ~WDRF; // Reset
    W_TIMER = WDIE | WDCE | (W_TIMER & ~WDE);
}

void _set_prescale_units(){
    W_TIMER |= WDCE | WDE;
    W_TIMER = WDE | WDP2 | WDP1;
}

void _disable(){
    A_STA &= ~I_BIT;
    M_STA &= ~WDRF; // Reset
    W_TIMER |= WDCE | WDE;
    W_TIMER = 0x00;
    A_STA |= I_BIT;
}

void _poll(){
    volatile byte b = 0;
    while (!b) b = W_TIMER & WDIF;
}

void wait_1s(){
    A_STA &= ~I_BIT;
    M_STA &= ~WDRF; // Reset
    _set_prescale_units();
    A_STA |= I_BIT;
    _poll();
    _disable();
}

#endif
