#include <Servo.h> // getting the required library
Servo servo1;    
int echopin = 2;
int trigpin = 3;
const int buzzer = 5;
int ledPin =6;



void setup () {
  Serial.begin(9600);
  servo1.attach(4);
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  long duration, distance; //Initializing the two variable
  
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  
  digitalWrite(trigpin, LOW);
  
  
  duration = pulseIn(echopin, HIGH);
  distance = (duration/2)/29.1;
  
  Serial.print(distance);
  Serial.println(" cm");
  
  if(distance>50){
    servo1.write(0);
    noTone(buzzer);
    digitalWrite(ledPin, LOW);
    
  }
  
  if(distance<=50){
    digitalWrite(ledPin, HIGH);
    tone(buzzer, 2000);
    servo1.write(0);  //making the servo to turn 90 cegree
    delay(1000);       // Making it wait for 1000ms just after the turn
    servo1.write(90);   // Making it turn to its initial positon
    delay(1000);       // Making it wait there for another 1000ms 
    
    /*this will keep on repeating unless the the distance is above 50 */
  }
} 