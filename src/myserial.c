#include "myserial.h"

int Setup_Arduino(int* _fd, struct termios* _tio)
{
	unsigned char msg[] = "serial port open...\n";
	int baudRate = B9600;

    *_fd = open(SERIAL_PORT, O_RDWR);     // デバイスをオープンする
    if (*_fd < 0) {
       	printf("open error\n");
        return -1;
    }

    _tio->c_cflag += CREAD;               // 受信有効
    _tio->c_cflag += CLOCAL;              // ローカルライン（モデム制御なし）
    _tio->c_cflag += CS8;                 // データビット:8bit
    _tio->c_cflag += 0;                   // ストップビット:1bit
    _tio->c_cflag += 0;                   // パリティ:None

    cfsetispeed( _tio, baudRate );
    cfsetospeed( _tio, baudRate );

    cfmakeraw(_tio);                    // RAWモード

    tcsetattr(*_fd, TCSANOW, _tio );     // デバイスに設定を行う

    ioctl(*_fd, TCSETS, _tio);            // ポートの設定を有効にする

	return 0;
}

void Sensor_Read(int _sensor[6], int* _fd, unsigned char buf[255], unsigned char line_buf[255])
{
   	int i;
    int len;
    int length = 0;
    int val = 0;

    	// 受信処理
    len = read(*_fd, buf, sizeof(buf));

	for(i = 0; i < len; i++){
		if(buf[i] == '\a' || buf[i] == '\b' || buf[i] == 'c' || buf[i] == 'd' || buf[i] == 'e' || buf[i] == 'f'){
			val = atoi(line_buf);
			if(buf[i] == '\a'){
				printf("psd1:%d\n",val);
				_sensor[0] = val;
			}else if(buf[i] == '\b'){
				printf("psd2:%d\n", val);
				_sensor[1] = val;
			}/*else if(buf[i] == '\c'){
				printf("psd3:%d\n", val);
				_sensor[2] = val;
			}else if(buf[i] == '\d'){
				printf("psd4:%d\n", val);
				_sensor[3] = val;
			}else if(buf[i] == '\e'){
				printf("psd5:%d\n", val);
				_sensor[4] = val;
			}else if(buf[i] == '\f'){
				printf("photo:%d\n", val);
				_sensor[5] = val;
			}*/
			strcpy(line_buf, "");
		}
		else{
			length = strlen(line_buf);
			line_buf[length] = buf[i];
			line_buf[length + 1] = '\0';
			//printf("%s\n",buf);
		}
	}
}

void Close_Arduino(int* _fd)
{
	close(*_fd);
}
