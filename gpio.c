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
int closeio(void);

int gpiofd; /* File descriptor for /dev/gpiomem (mmap'd pinout) */
unsigned int *gpio; /* Pointer to mmap'd pinout */

/* Bloated Linux wrappers */
struct gpiochip_info info;

int setupio(){

	gpiofd = open("/dev/gpiochip0", O_RDONLY);
	if (gpiofd < 0) { return -1; }; /* Fail if unable to open */
	
	return 0;

};

int closeio(){

	close(gpiofd);

};

void writepin(int pin, int value){

	if(setupio() != 0){ return; };
	
	struct gpiohandle_request request;
	
	/* Setup request */
	request.lineoffsets[0] = pin;
	request.lines = 1;
	request.flags = GPIOHANDLE_REQUEST_OUTPUT;

	ioctl(gpiofd, GPIO_GET_LINEHANDLE_IOCTL, &request); /* Output value to pin */

	closeio();
	
	struct gpiohandle_data data;

	/* Setup data */
	data.values[0] = value;
	ioctl(request.fd, GPIOHANDLE_SET_LINE_VALUES_IOCTL, &data);

	close(request.fd);

};

int getpin(int pin){

	if(setupio() != 0){ return -1; };
	
	struct gpiohandle_request request;
	
	/* Setup request */
	request.lineoffsets[0] = pin;
	request.lines = 1;
	request.flags = GPIOHANDLE_REQUEST_INPUT;

	ioctl(gpiofd, GPIO_GET_LINEHANDLE_IOCTL, &request); /* Output value to pin */

	closeio();
	
	struct gpiohandle_data data;

	ioctl(request.fd, GPIOHANDLE_GET_LINE_VALUES_IOCTL, &data);

	close(request.fd);

	return data.values[0];

};
