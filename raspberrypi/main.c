#include "gpio.h"
#include "myserial.h"
#include "function.h"

//しきい値
#define LT 500
#define RT 500

int main(void)
{
	int sensor[6] = {0};
	int fd;
	struct termios tio;
	unsigned char buf[255];
	unsigned char line_buf[255] = "";

	Setup_Arduino(&fd, &tio);
	Setup_gpio();

	while(1){
		Sensor_Read(sensor, &fd, buf, line_buf);
		
	}

	Close_gpio();
	Close_Arduino(&fd);

	return 0;
}
