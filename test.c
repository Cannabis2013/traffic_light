#include "ard_m328p_defines.h"
#include "wait.h"

void test()
{
    DDRD = 0b11111100;
    while (1) {
        PORTD = 0b00100000;
        wait_1s();
        PORTD = 0b10000000;
        wait_1s();
    }
}
