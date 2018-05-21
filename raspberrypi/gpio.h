#ifndef _GPIO_H_INCLUDED_
#define _GPIO_H_INCLUDED_

#include <stdio.h>
#include <pigpiod_if.h>

#define SERVO 18 	//Servo 右　6pin
#define DC 22 		//DC 左　8pin
#define DIR 23 		//右 8pin
#define RANGE 255
#define SPEED 40
#define RIGHT 1200
#define LEFT  1800

int Setup_gpio(void);
void Close_gpio(void);
int Foward(void);
int Stop(void);
int Back(void);
int Esc(void);

#endif
