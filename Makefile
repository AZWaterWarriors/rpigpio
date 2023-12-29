all: librpigpio.a

.PHONY: clean

gpio.o: gpio.c
	gcc -g -c gpio.c

librpigpio.a: gpio.o
	ar -rc librpigpio.a gpio.o

clean:
	rm -rf *.o

spotless:
	rm -rf *.o *.a
