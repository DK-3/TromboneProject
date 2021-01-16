#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
const int buttonPin = 8;
int lastVal = 0;
int Val = 0;
void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println(digitalRead(buttonPin));
  Val = digitalRead(buttonPin);
  if(Val != lastVal){
    if(Val == 1){
      myservo.write(110);
    }
    if(Val == 0){
      myservo.write(90);
    }
   
  }
  lastVal = Val;
}
  
//  for (pos = 0; pos <= 25; pos += 1) { // goes from 0 degrees to 25 degrees
//    // in steps of 1 degree
//    myservo.write(pos);              // tell servo to go to position in variable 'pos'
//    delay(5);                       // waits 5ms for the servo to reach the position
//  }
//  for (pos = 25; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
//    myservo.write(pos);              // tell servo to go to position in variable 'pos'
//    delay(5);                       // waits 15ms for the servo to reach the position
//  }
//  delay(2000);
