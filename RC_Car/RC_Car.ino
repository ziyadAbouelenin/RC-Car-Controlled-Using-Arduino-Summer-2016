#include <SoftwareSerial.h>

SoftwareSerial BT(10, 11); //TX, RX respetively
String readdata;
int firstMotor1 = 2;
int firstMotor2 = 3;

int secondMotor1 = 4;
int secondMotor2 = 5;

int trigPin = 9;
int echoPin = 8;
int led = 13;
void setup() {
 BT.begin(9600);
 Serial.begin(9600);
pinMode(firstMotor1,OUTPUT);
pinMode(firstMotor2,OUTPUT);
pinMode(secondMotor1,OUTPUT);
pinMode(secondMotor2,OUTPUT);
pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
}
//-----------------------------------------------------------------------// 
void loop() {
  while (BT.available()){  //Check if there is an available byte to read
  delay(10); //Delay added to make thing stable
  char c = BT.read(); //Conduct a serial read
  readdata += c; //build the string- "forward", "reverse", "left" and "right"
  } 
  if (readdata.length() > 0 ) {
    Serial.println(readdata); // print data to serial monitor
// if data received as forward move robot forward
  if(readdata == "b") 
  {
 digitalWrite(firstMotor1, 1);
     digitalWrite(firstMotor2, 0);
      digitalWrite(secondMotor1, 1);
     digitalWrite(secondMotor2, 0);
    delay(100);
  }
  // if data received as reverse move robot reverse

  else if(readdata == "f")
  {
     digitalWrite(firstMotor1, 0);
     digitalWrite(firstMotor2, 1);
     digitalWrite(secondMotor1, 0);
     digitalWrite(secondMotor2, 1);
    delay(100);
  }
// if data received as right turn robot to right direction.
  else if (readdata == "r")
  {
          digitalWrite(firstMotor1, 0);
     digitalWrite(firstMotor2, 1);
      digitalWrite(secondMotor1, 1);
     digitalWrite(secondMotor2, 0);
    delay (100);
   
  }
// if data received as left turn robot to left direction
 else if ( readdata == "l")
 {
      digitalWrite(firstMotor1, 1);
     digitalWrite(firstMotor2, 0);
      digitalWrite(secondMotor1, 0);
     digitalWrite(secondMotor2, 1);
   delay (100);
 }
 // if data received as stop, halt the robot

 else if (readdata == "s")
 {
     digitalWrite(firstMotor1, 0);
     digitalWrite(firstMotor2, 0);
      digitalWrite(secondMotor1, 0);
     digitalWrite(secondMotor2, 0);
   delay (100);
 }

  


readdata="";}

 long duration, distance;
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  duration=pulseIn(echoPin, HIGH);
  distance =(duration/2)/29.1;
  Serial.print(distance);
  Serial.println("CM");
  delay(10);
 
 if((distance<=20)) 
  {
     digitalWrite(firstMotor1, 0);
     digitalWrite(firstMotor2, 0);
      digitalWrite(secondMotor1, 0);
     digitalWrite(secondMotor2, 0);
   delay (100);
   digitalWrite(led, 1);
}
 else {
     digitalWrite(led, 0);

 }
} //Reset the variable=

