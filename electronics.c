/*
 *
 * Water Warriors Moisture Harvester Control System
 *
 * Electronics control routines
 *
 */
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

#include "electronics.h"

int setupio(void);
void fans(int onoff);
void peltier(int onoff);
void fans2(int onoff);

void writepin(int pin, int value);
int readpin(int pin);

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

void readpin(int pin){

	gpio[(pin > 9)] = 0;
	
	return (gpio[13] & (1<<(pin)));

};

void fans(int onoff){

	writepin(FAN_PIN, onoff);

};

void peltier(int onoff){

	writepin(PELT_PIN, onoff);

};

void fans2(int onoff){

	writepin(FAN2_PIN, onoff);

};
