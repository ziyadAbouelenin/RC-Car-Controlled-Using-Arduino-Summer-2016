#define CMD_DIGITALWRITE 10
#include <SoftwareSerial.h>
#define START_CMD_CHAR '*'
#define END_CMD_CHAR '#'
#define DIV_CMD_CHAR '|'
int state = 0;
int pin10=10;
int pin11=11;
int pin12=12;
int pin13=13;

void setup() {
pinMode(pin10, OUTPUT);
pinMode(pin11, OUTPUT);
pinMode(pin12, OUTPUT);
pinMode(pin13, OUTPUT);

digitalWrite(pin10, LOW);
digitalWrite(pin11, LOW);
digitalWrite(pin12, LOW);
digitalWrite(pin13, LOW);
Serial.begin(9600);
Serial.flush();
 
}
void loop() {
if (Serial.available() < 1) return; // if serial empty, return to loop().

if(Serial.available() > 0){ // Checks whether data is comming from the serial port
state = Serial.read(); // Reads the data from the serial port
}
if (state == '1') { //UP

digitalWrite(pin10, HIGH);
digitalWrite(pin11, LOW);
digitalWrite(pin12, HIGH);

return; 
}

else if (state == '2') { //DOWN

digitalWrite(pin10, LOW);
digitalWrite(pin11, HIGH);
digitalWrite(pin13, HIGH);
digitalWrite(pin12, LOW);
return;

} 

else if (state == '3') {  //LEFT
digitalWrite(pin10, LOW);
digitalWrite(pin11, LOW);
digitalWrite(pin13, LOW);
digitalWrite(pin12, HIGH);
return; 
} 
else if (state == '4') {  //RIGHT
digitalWrite(pin10, HIGH);
digitalWrite(pin13, LOW);
digitalWrite(pin11, LOW);
digitalWrite(pin12, LOW);
return;

} 
else if (state == '0') {
digitalWrite(pin10, LOW);
digitalWrite(pin11, LOW);
digitalWrite(pin12, LOW);
digitalWrite(pin13, LOW);
state='0';
return;


} 
}
