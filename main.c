#include "ard_m328p_ports.h"
#include "ard_m328p_states.h"
#include "wait.h"

int main(){
    D_DIRS  = ACT;
    while (1) {
        D_PORTS = S0;
        wait_sec(4);
        D_PORTS = S1;
        wait_sec(2);
        D_PORTS = S2;
        wait_sec(2);
        D_PORTS = S3;
        wait_sec(2);
        D_PORTS = S4;
        wait_sec(4);
        D_PORTS = S5;
        wait_sec(2);
        D_PORTS = S6;
        wait_sec(2);
        D_PORTS = S7;
        wait_sec(2);
    }
}
