#include "ard_m328p_ports.h"
#include "wait.h"

#define ACT     0b11111100;

#define NS_RED (1 << 2)
#define NS_YEL (1 << 3)
#define NS_GRE (1 << 4)
#define WE_RED (1 << 5)
#define WE_YEL (1 << 6)
#define WE_GRE (1 << 7)

void init_state(){
    D_PORTS  |= WE_GRE;
    D_PORTS |= NS_RED;
}

void change_to_ns(){
    D_PORTS &= ~WE_GRE;
    D_PORTS |= WE_YEL;
    wait_sec(2);
    D_PORTS &= ~WE_YEL;
    D_PORTS |= WE_RED;
    wait_sec(2);
    D_PORTS |= NS_YEL;
    wait_sec(2);
    D_PORTS &= ~(NS_RED | NS_YEL);
    D_PORTS |= NS_GRE;
}

void change_to_we(){
    D_PORTS &= ~NS_GRE;
    D_PORTS |= NS_YEL;
    wait_sec(2);
    D_PORTS &= ~NS_YEL;
    D_PORTS |= NS_RED;
    wait_sec(2);
    D_PORTS |= WE_YEL;
    wait_sec(2);
    D_PORTS &= ~(WE_RED | WE_YEL);
    D_PORTS |= WE_GRE;
}

int main(){
    D_DIRS  = ACT;
    init_state();
    while (1) {
        wait_sec(4);
        change_to_ns();
        wait_sec(4);
        change_to_we();
    }
}
