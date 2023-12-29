all: librpigpio.a

rpigpio.o: gpio.c
	gcc -c gpio.c

librpigpio.a: rpigpio.o
	ar -rc librpigpio.a rpigpio.o
