#include "traffic_controller.h"
#ifdef CONTROLLER_IMP_1
#include "ard_m328p_ports.h"
#include "wait.h"

#define S0      0b10000100
#define S1      0b01000100
#define S2      0b00100100
#define S3      0b00101100
#define S4      0b00110000
#define S5      0b00101000
#define S6      0b00100100
#define S7      0b01100100
#define S8      0b11111100  // Testing purposes

#define W0      0b00001001
#define W1      0b00000101
#define W2      0b00000110

void _t_init(){
    D_DIRS = 0b11111100;
}

void _t_cyclus(){
    B_PORTS_OUT = W0;
    D_PORTS_OUT = S0;
    wait_sec(4);
    B_PORTS_OUT = W1;
    wait_ms(750);
    D_PORTS_OUT = S1;
    wait_sec(2);
    D_PORTS_OUT = S2;
    wait_sec(2);
    B_PORTS_OUT = W2;
    wait_ms(750);
    D_PORTS_OUT = S3;
    wait_sec(2);
    D_PORTS_OUT = S4;
    wait_sec(4);
    B_PORTS_OUT = W1;
    wait_ms(750);
    D_PORTS_OUT = S5;
    wait_sec(2);
    D_PORTS_OUT = S6;
    wait_sec(2);
    B_PORTS_OUT = W0;
    wait_ms(750);
    D_PORTS_OUT = S7;
    wait_sec(2);
}

void traffic_light(){
    _t_init();
    while (1) _run_cyclus();
}
#endif
