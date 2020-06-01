#define CMD_DIGITALWRITE 10
#include <SoftwareSerial.h>
#define START_CMD_CHAR '*'
#define END_CMD_CHAR '#'
#define DIV_CMD_CHAR '|'
int state = 0;
int pin7=7;
int pin4=4;
int pin5=5;
int pin6=6;

void setup() {
pinMode(pin7, OUTPUT);
pinMode(pin4, OUTPUT);
pinMode(pin5, OUTPUT);
pinMode(pin6, OUTPUT);

digitalWrite(pin7, LOW);
digitalWrite(pin4, LOW);
digitalWrite(pin5, LOW);
digitalWrite(pin6, LOW);


Serial.begin(9600);
Serial.flush();
 
}
void loop() {
if (Serial.available() < 1) return; // if serial empty, return to loop().

if(Serial.available() > 0){ // Checks whether data is comming from the serial port
state = Serial.read(); // Reads the data from the serial port
}
/// FORWORD
if (state == '1') { //UP
digitalWrite(pin7, LOW);
digitalWrite(pin4, HIGH);
digitalWrite(pin6, HIGH);
digitalWrite(pin5, LOW);


}

else if (state == '3') {  //LEFT
digitalWrite(pin7, HIGH);
digitalWrite(pin6, LOW);
digitalWrite(pin4, LOW);
digitalWrite(pin5, LOW);
  


} 
else if (state == '4') {  //RIGHT

digitalWrite(pin7, LOW);
digitalWrite(pin4, LOW);
digitalWrite(pin6, LOW);
digitalWrite(pin5, HIGH);

}

/// BACKWORD
else if (state == '2') { //DOWN
digitalWrite(pin7, HIGH);
digitalWrite(pin4, LOW);
digitalWrite(pin6, LOW);
digitalWrite(pin5, HIGH);
} 

else if (state == '6') {  //LEFT
digitalWrite(pin7, LOW);
digitalWrite(pin4, LOW);
digitalWrite(pin6, HIGH);
digitalWrite(pin5, LOW);

} 
else if (state == '5') {  //RIGHT
digitalWrite(pin7, LOW);
digitalWrite(pin6, LOW);
digitalWrite(pin4, HIGH);
digitalWrite(pin5, LOW);


}

 /// tos top the car
else if (state == '0') {
digitalWrite(pin7, LOW);
digitalWrite(pin4, LOW);
digitalWrite(pin5, LOW);
digitalWrite(pin6, LOW);
state='0';
return;


} 
}
