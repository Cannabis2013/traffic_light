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


/*
 * Use for WAIT_IMP_1
 * These funtions is not defined for WAIT_IMP_2
 *
 */
void wait_ms(int ms);
void wait_sec(int s);

#ifdef WAIT_IMP_2
/*
 * These functions are only available when WAIT_IMP_2 is defined
 */

void init_wait();
void wait_1s();

#endif


#endif // WAIT_H
