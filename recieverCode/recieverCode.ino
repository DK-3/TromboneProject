#include <Servo.h>
#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile


Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards
int led = 13;
int pos = 0;    // variable to store the servo position
const int servoPin = 7;
int lastVal = 0;
int Val = 0;
//rx pin is 11
RH_ASK driver;

void setup()
{
    myservo.attach(7);  // attaches the servo on pin 7 to the servo object
    Serial.begin(9600);  // Debugging only
    if (!driver.init())
         Serial.println("init failed");
    //pinMode(servoPin, OUTPUT);     
}

void loop()
{
    digitalWrite(led, HIGH);   // LED Heartbeat
    delay(500);               
    digitalWrite(led, LOW);    
    delay(500); 
    
    uint8_t buf[2];
    uint8_t buflen = sizeof(buf);
    if (driver.recv(buf, &buflen)) // Non-blocking
    {
      //int i;
      // Message with a good checksum received, dump it.
      //Serial.print("Message: ");
      Serial.println(strcmp((char*)buf, "BP"));
      Serial.println((char*)buf);
      if(strcmp((char*)buf, "BP") == 2)
        {
          Serial.println("TX knows button is pressed");
          myservo.write(110);      
        }
      else myservo.write(90);
     }
}
