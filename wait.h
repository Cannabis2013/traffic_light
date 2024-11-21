#ifndef WAIT_H
#define WAIT_H

/*
 *  Remember to define what implementation to use
 *
 *  Implementations for this project:
 *  WAIT_IMP_1:
 *      Is based on loops and approximated time out values
 *      Consider this as unreliable
 *  WAIT_IMP_2:
 *      Is based on interupts and timers
 *      Is more reliable as wait operation are implemented on hardware level
 */

#define WAIT_IMP_2

void wait_ms(int ms);
void wait_4s();
void wait_2s();
void wait_1s();
void wait_500ms();
void wait_125ms();

#endif // WAIT_H
