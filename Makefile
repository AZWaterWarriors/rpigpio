all: librpigpio.a

.PHONY: clean

rpigpio.o: gpio.c
	gcc -c gpio.c

librpigpio.a: rpigpio.o
	ar -rc librpigpio.a rpigpio.o

clean:
	rm -rf *.o

spotless:
	rm -rf *.o *.a
