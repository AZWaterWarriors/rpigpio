/*
 *
 * Small GPIO Library for Raspberry Pi 4 Model B
 *
 * Electronics control routines
 *
 */

#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

#include "gpio.h"

int setupio(void);
void writepin(int pin, int value);
int getpin(int pin);

int gpiofd;
unsigned int *gpio;

int setupio(){

	gpiofd = open("/dev/gpiomem", O_RDWR);
	if (gpiofd < 0) { return -1; };

	gpio = (unsigned int *)mmap(0, 4096, PROT_READ+PROT_WRITE, MAP_SHARED, gpiofd, 0);
	
	return 0;

};

void writepin(int pin, int value){

	gpio[(pin > 9)] = 1;
	
	gpio[(10 - (value * 3))] = (1<<(pin));

};

void getpin(int pin){

	gpio[(pin > 9)] = 0;
	
	return (gpio[13] & (1<<(pin)));

};
