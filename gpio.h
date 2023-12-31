/*
 *
 * Small GPIO Library for Raspberry Pi 4 Model B
 *
 * Electronics control routines
 *
 */

#ifndef _GPIO_H
#define _GPIO_H

#include <linux/gpio.h>

int setupio(void);
void writepin(int pin, int value);
int getpin(int pin);
int closeio(void);

extern int gpiofd;
extern struct gpiochip_info info;

#endif
