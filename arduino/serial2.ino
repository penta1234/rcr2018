#define PSD1 0
#define PSD2 1
#define PSD3 2
#define PSD4 3
#define PSD5 4
#define PHOT 5
#define NUM 6

int val[6] = {0};
int i;

void setup() {
  Serial.begin(9600);
}

void loop() {
  for(i = 0; i < 2; i++){
    val[i] = analogRead(i);
  }
  //Serial.print("val1:");
  Serial.print(val[0]);
  Serial.write('\a');
  //Serial.write('\n');
  
  //Serial.print("val2:");
  Serial.print(val[1]);
  Serial.write('\b');
  //Serial.write('\n');
  /*
  Serial.print("val3:");
  Serial.print(val[2]);
  Serial.write('\c');
  
  Serial.print("val4:");
  Serial.print(val[3]);
  Serial.write('\d');

  Serial.print("val5:");
  Serial.print(val[4]);
  Serial.write('\e');
  */
  delay(500);
}

