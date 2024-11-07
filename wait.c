#ifndef WAIT
#define WAIT

#define CLOCK_SPEED 500000

void wait_ms(int ms){
    int m = ms < 100 ? 100 : ms;
    long limit = (m * CLOCK_SPEED) / 1000;
    while (limit) limit -= 1;
}

void wait_sec(int s)
{
    volatile long limit = s * CLOCK_SPEED;
    while (limit)limit -= 1;
}

#endif
