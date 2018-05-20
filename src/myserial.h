
#ifndef _MYSERIAL_H_INCLUDED_
#define _MYSERIAL_H_INCLUDED_

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#include <string.h>

#define SERIAL_PORT "/dev/ttyACM0"

int Setup_Arduino(int*, struct termios*);
void Sensor_Read(int *, int*, unsigned char*, unsigned char*);
void Close_Arduino(int*);

#endif