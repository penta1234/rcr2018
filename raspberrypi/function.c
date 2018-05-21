#include "gpio.h"

int Foward(void){
	gpio_write(DIR, 1);
    set_PWM_dutycycle(DC, SPEED);
    time_sleep(0.05);
    printf("motor foward\n");
    return 0;
}

int Stop(void){
	gpio_write(DIR, 0);
    set_PWM_dutycycle(DC, 0);
    printf("motor stop\n");
    return 0;
}

int Back(void){
    gpio_write(DIR, 0);
    set_PWM_dutycycle(DC, SPEED);
    time_sleep(0.05);
    return 0;
}

/*int Esc(void){
    set_PWM_dutycycle(SERVO,0);
    set_PWM_dutycycle(DC,0);
    gpio_write(DIR, 0);
    printf("exit\n");
    exit(0);
}*/

int Right(void){
	set_servo_pulsewidth(SERVO, RIGHT);
	Foward();
	return 0;
}

int Left(void){
	set_servo_pulsewidth(SERVO, LEFT);
	Foward();
	return 0;
}

//PSD�̒l��500�ȏ��Ȃ��Ȃ���
int Trace(int *sensor){
	if(sensor[0] >= 500)		//sensor[0] PSD of left
		Right();
	}
	else if(sensor[1] >= 500){  //sensor[1] PSD of right
		Left();
	}
	return 0;
}
