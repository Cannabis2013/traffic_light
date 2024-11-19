#include "ard_m328p_defines.h"
#include "wait.h"

void run_test()
{
    init_wait();
    D_DIRS = 0b11111100;
    while (1) {
        D_PORTS_OUT = 0b10101000;
        wait_1s();
        D_PORTS_OUT = 0b11111100;
    }
}
