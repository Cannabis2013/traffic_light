#include "wait.h"

#ifdef WAIT_IMP_1

#define CLOCK_SPEED 500000

void _wait(int s)
{
    volatile long limit = s * CLOCK_SPEED;
    while (limit)limit -= 1;
}

void wait_ms(int ms){
    int m = ms < 100 ? 100 : ms;
    volatile long limit = (m * CLOCK_SPEED) / 1000;
    while (limit) limit -= 1;
}

void wait_4s(){
    _wait(4);
}

void wait_2s(){
    _wait(2);
}

void wait_1s(){
    _wait(1);
}

void wait_500ms(){
    wait_ms(500);
}
#endif
