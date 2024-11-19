#include "wait.h"

#ifdef WAIT_IMP_1

#define CLOCK_SPEED 500000

void wait_ms(int ms){
    int m = ms < 100 ? 100 : ms;
    volatile long limit = (m * CLOCK_SPEED) / 1000;
    while (limit) limit -= 1;
}

void wait_sec(int s)
{
    volatile long limit = s * CLOCK_SPEED;
    while (limit)limit -= 1;
}
#endif
