#include <Servo.h>
#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile


Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
const int servoPin = 7;

RH_ASK driver;

void setup()
{
    myservo.attach(7);  // attaches the servo on pin 9 to the servo object
    Serial.begin(9600);  // Debugging only
    if (!driver.init())
         Serial.println("init failed");
    pinMode(servoPin, OUTPUT);     
}

void loop()
{
    uint8_t buf[2];
    uint8_t buflen = sizeof(buf);
    if (driver.recv(buf, &buflen)) // Non-blocking
    {
      //int i;
      // Message with a good checksum received, dump it.
      //Serial.print("Message: ");
      Serial.println(strcmp((char*)buf, "BP"));
      Serial.println((char*)buf);
      if(strcmp((char*)buf, "BP") == 0)
        {
          Serial.println("TX knows button is pressed");
          for (pos = 0; pos <= 25; pos += 1) { // goes from 0 degrees to 25 degrees
          // in steps of 1 degree
          myservo.write(pos);              // tell servo to go to position in variable 'pos'
          delay(5);                       // waits 5ms for the servo to reach the position
        }
        }
    }
}
