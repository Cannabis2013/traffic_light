CC=avr-gcc
CFLAGS=-Os -mmcu=atmega328p -lm
NOLINK=-c
HEXER=objcopy
HFLAGS=-O ihex
DEV=m328p
MAN=arduino
PORT=/dev/ttyUSB0
RATE=115200
DUDE=avrdude -p ${DEV} -c ${MAN} -P ${PORT} -b ${RATE} -D -U

deploy: main.hex
	${DUDE} flash:w:$^:i
	rm *.o *.hex
hex: main.hex
main.hex: install
install: program.o
	${HEXER} ${HFLAGS} program.o main.hex
program.o: build
build: bundle
	${CC} ${CFLAGS} *.o -o program.o
bundle:
	${CC} ${CFLAGS} ${NOLINK} *.c
clean:
	rm *.o *.hex