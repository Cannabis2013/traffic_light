#include "ard_m328p_ports.h"
#include "wait.h"

/* Codes:
 *  gyrgyr--
 *
 * Bit states:
 *  s0:10000100
 *  s1:01000100
 *  s2:00100100
 *  s3:00101100
 *  s4:00110000
 *  s5:00101000
 *  s6:00100100
 *  s7:01100100
 */

#define ACT     0b11111100
#define S0      0b10000100
#define S1      0b01000100
#define S2      0b00100100
#define S3      0b00101100
#define S4      0b00110000
#define S5      0b00101000
#define S6      0b00100100
#define S7      0b01100100
#define S8      0b11111100  // Testing purposes

void run(){
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
