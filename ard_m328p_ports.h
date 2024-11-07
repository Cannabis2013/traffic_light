#ifndef ARD_M328P_PORTS_H
#define ARD_M328P_PORTS_H

typedef unsigned char byte;

#define D_PORTS *((volatile byte*) 0x2b)
#define D_DIRS *((volatile byte*) 0x2a)

#endif // ARD_M328P_PORTS_H
