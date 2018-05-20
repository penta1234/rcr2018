#include "gpio.h"

int Setup_gpio(void)
{
	int status;
	//pwm setup
	status = pigpio_start(0, 0);
	if(status < 0){
		printf("error\n");
		return 1;
	}
	//set_PWM_range(SERVO, RANGE);
	set_PWM_range(DC, RANGE);
	set_mode(DIR, PI_OUTPUT);
	printf("set pigpio\n");
	//set_PWM_dutycycle(SERVO, 0);
	set_PWM_dutycycle(DC, 0);

	return 0;
}

void Close_gpio(void)
{
	set_PWM_dutycycle(SERVO, 0);
	set_PWM_dutycycle(DC, 0);
	gpio_write(DIR, 0);
}

