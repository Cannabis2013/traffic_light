#include "traffic_controller.h"
#ifdef CONTROLLER_IMP_2
#include "ard_m328p_defines.h"
#include "wait.h"

#define NS_CAR_RED  (1 << 2)
#define NS_CAR_YEL  (1 << 3)
#define NS_CAR_GRE  (1 << 4)
#define WE_CAR_RED  (1 << 5)
#define WE_CAR_YEL  (1 << 6)
#define WE_CAR_GRE  (1 << 7)

#define NS_WLK_RED (1 << 0)
#define NS_WLK_GRE (1 << 1)
#define WE_WLK_RED (1 << 2)
#define WE_WLK_GRE (1 << 3)

void _t_init(){
    B_DIRS = 0b00001111;
    D_DIRS = 0b11111100;
}

void _init_state(){
    B_PORTS_OUT |= WE_WLK_GRE;
    B_PORTS_OUT |= NS_WLK_RED;
    D_PORTS_OUT  |= WE_CAR_GRE;
    D_PORTS_OUT |= NS_CAR_RED;
}

void _change_to_ns(){
    B_PORTS_OUT &= ~WE_WLK_GRE;
    B_PORTS_OUT |= WE_WLK_RED;
    wait_ms(750);
    D_PORTS_OUT &= ~WE_CAR_GRE;
    D_PORTS_OUT |= WE_CAR_YEL;
    wait_sec(2);
    D_PORTS_OUT &= ~WE_CAR_YEL;
    D_PORTS_OUT |= WE_CAR_RED;
    wait_ms(750);
    B_PORTS_OUT &= ~NS_WLK_RED;
    B_PORTS_OUT |= NS_WLK_GRE;
    wait_ms(750);
    D_PORTS_OUT |= NS_CAR_YEL;
    wait_sec(2);
    D_PORTS_OUT &= ~(NS_CAR_RED | NS_CAR_YEL);
    D_PORTS_OUT |= NS_CAR_GRE;
}

void _change_to_we(){
    B_PORTS_OUT &= ~NS_WLK_GRE;
    B_PORTS_OUT |= NS_WLK_RED;
    wait_ms(750);
    D_PORTS_OUT &= ~NS_CAR_GRE;
    D_PORTS_OUT |= NS_CAR_YEL;
    wait_sec(2);
    D_PORTS_OUT &= ~NS_CAR_YEL;
    D_PORTS_OUT |= NS_CAR_RED;
    wait_ms(750);
    B_PORTS_OUT &= ~WE_WLK_RED;
    B_PORTS_OUT |= WE_WLK_GRE;
    wait_ms(750);
    D_PORTS_OUT |= WE_CAR_YEL;
    wait_sec(2);
    D_PORTS_OUT &= ~(WE_CAR_RED | WE_CAR_YEL);
    D_PORTS_OUT |= WE_CAR_GRE;
}

void _run_cyclus(){
    _init_state();
    for (int i = 0; i < 2; ++i) {
        wait_sec(4);
        _change_to_ns();
        wait_sec(4);
        _change_to_we();
    }
    wait_sec(4);
}

void t_run(){
    _t_init();
    while (1) _run_cyclus();
}
#endif
