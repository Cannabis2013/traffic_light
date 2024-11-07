#include "wait.h"
#include "bit_states.h"

typedef unsigned char byte;

#define D_PORTS *((volatile byte*) 0x2b)
#define D_DIRS *((volatile byte*) 0x2a)

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
