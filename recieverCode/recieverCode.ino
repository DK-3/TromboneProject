#include <RH_ASK.h>
#include <SPI.h> // Not actualy used but needed to compile

//const int servoPin = 7;

RH_ASK driver;

void setup()
{
    Serial.begin(9600);  // Debugging only
    if (!driver.init())
         Serial.println("init failed");
//    pinMode(servoPin, OUTPUT);     
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
      Serial.println(strcmp((char*)buf, "BO"));
      //Serial.println((char*)buf);
      if(strcmp((char*)buf, "BP") == 0)
        {
          Serial.println("TX knows button is pressed");
         //digitalWrite(servoPin, HIGH);
        }
     }
    
}
