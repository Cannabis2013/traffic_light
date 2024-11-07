CC=avr-gcc
CFLAGS=-Os -mmcu=atmega328p -lm
NOLINK=-C
OC=objcopy
HFLAGS=-O ihex
DEV=m328p
MAN=arduino
PORT=/dev/ttyUSB0
RATE=115200
DUDE=avrdude -p ${DEV} -c ${arduino} -P ${PORT} -b ${RATE} -D -U

deploy: main.hex
	${DUDE} flash:w:$^:i
main.hex: main.o
	${OC} ${HFLAGS} $^ main.hex
build: wait.o
	${CC} ${CFLAGS} main.c $^ -o main.o
*.c,*.h:
	${CC} ${CFLAGS} ${NOLINK} $@ -o wait.o
clean:
	rm *.o *.hex