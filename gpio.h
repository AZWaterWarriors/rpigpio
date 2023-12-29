/*
 *
 * Small GPIO Library for Raspberry Pi 4 Model B
 *
 * Electronics control routines
 *
 */

#ifndef _ELECTRONICS_H
#define _ELECTRONICS_H

int setupio(void);
void writepin(int pin, int value);
int getpin(int pin);

int gpiofd;
unsigned int *gpio;

#endif
