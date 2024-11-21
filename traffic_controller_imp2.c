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
    DDRB = 0b00001111;
    DDRD = 0b11111100;
}

void _init_state(){
    PORTB |= WE_WLK_GRE;
    PORTB |= NS_WLK_RED;
    PORTD  |= WE_CAR_GRE;
    PORTD |= NS_CAR_RED;
}

void _change_to_ns(){
    PORTB &= ~WE_WLK_GRE;
    PORTB |= WE_WLK_RED;
    wait_500ms();
    PORTD &= ~WE_CAR_GRE;
    PORTD |= WE_CAR_YEL;
    wait_2s();
    PORTD &= ~WE_CAR_YEL;
    PORTD |= WE_CAR_RED;
    wait_500ms();
    PORTB &= ~NS_WLK_RED;
    PORTB |= NS_WLK_GRE;
    wait_500ms();
    PORTD |= NS_CAR_YEL;
    wait_2s();
    PORTD &= ~(NS_CAR_RED | NS_CAR_YEL);
    PORTD |= NS_CAR_GRE;
}

void _change_to_we(){
    PORTB &= ~NS_WLK_GRE;
    PORTB |= NS_WLK_RED;
    wait_500ms();
    PORTD &= ~NS_CAR_GRE;
    PORTD |= NS_CAR_YEL;
    wait_2s();
    PORTD &= ~NS_CAR_YEL;
    PORTD |= NS_CAR_RED;
    wait_500ms();
    PORTB &= ~WE_WLK_RED;
    PORTB |= WE_WLK_GRE;
    wait_500ms();
    PORTD |= WE_CAR_YEL;
    wait_2s();
    PORTD &= ~(WE_CAR_RED | WE_CAR_YEL);
    PORTD |= WE_CAR_GRE;
}

void _run_cyclus(){
    _init_state();
    for (int i = 0; i < 2; ++i) {
        wait_4s();
        _change_to_ns();
        wait_4s();
        _change_to_we();
    }
    wait_4s();
}

void traffic_light(){
    _t_init();
    while (1) _run_cyclus();
}
#endif
