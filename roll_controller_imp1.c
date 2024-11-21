#include "roll_controller.h"

#ifdef ROLL_CONTROLLER_IMP_1
#include "wait.h"
#include "ard_m328p_defines.h"

#define PAUSE 100

void roll_init(){
    DDRB = 0b00001111;
}

void roll_run(){
    for (int i = 0; i < 6; ++i) {
        PORTB = 0b00000001;
        PORTD = 0b00000100;
        wait_ms(PAUSE);
        PORTB = 0b00000010;
        PORTD = 0b00001000;
        wait_ms(PAUSE);
        PORTB = 0b00000100;
        PORTD = 0b00010000;
        wait_ms(PAUSE);
        PORTB = 0b00001000;
        PORTD = 0b00100000;
        wait_ms(PAUSE);
        PORTB = 0b00000001;
        PORTD = 0b01000000;
        wait_ms(PAUSE);
        PORTB = 0b00000010;
        PORTD = 0b10000000;
        wait_ms(PAUSE);
    }
}

#endif
