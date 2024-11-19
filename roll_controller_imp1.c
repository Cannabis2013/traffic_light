#include "roll_controller.h"

#ifdef ROLL_CONTROLLER_IMP_1
#include "wait.h"
#include "ard_m328p_defines.h"

#define PAUSE 100

void roll_init(){
    B_DIRS = 0b00001111;
}

void roll_run(){
    for (int i = 0; i < 6; ++i) {
        B_PORTS_OUT = 0b00000001;
        D_PORTS_OUT = 0b00000100;
        wait_ms(PAUSE);
        B_PORTS_OUT = 0b00000010;
        D_PORTS_OUT = 0b00001000;
        wait_ms(PAUSE);
        B_PORTS_OUT = 0b00000100;
        D_PORTS_OUT = 0b00010000;
        wait_ms(PAUSE);
        B_PORTS_OUT = 0b00001000;
        D_PORTS_OUT = 0b00100000;
        wait_ms(PAUSE);
        B_PORTS_OUT = 0b00000001;
        D_PORTS_OUT = 0b01000000;
        wait_ms(PAUSE);
        B_PORTS_OUT = 0b00000010;
        D_PORTS_OUT = 0b10000000;
        wait_ms(PAUSE);
    }
}

#endif
