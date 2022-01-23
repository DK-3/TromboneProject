#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile

const int buttonPin = 7;
//tx pin is 12
RH_ASK driver;
int led = 13;
void setup()
{
    Serial.begin(9600);    // Debugging only
    if (!driver.init())
         Serial.println("init failed");
    pinMode(buttonPin, INPUT);
    pinMode(led, OUTPUT);     
}

void loop()
{
    digitalWrite(led, HIGH);   // LED Heartbeat
    delay(1000);               
    digitalWrite(led, LOW);    
    delay(1000);               
    
    if(digitalRead(buttonPin)== HIGH)
      {
          const char *msg = "BP";
          driver.send((uint8_t *)msg, strlen(msg));
          driver.waitPacketSent();
          delay(10);
      }
      if(digitalRead(buttonPin)== LOW)
      {
        const char *msg = "BO";
        driver.send((uint8_t *)msg, strlen(msg));
        driver.waitPacketSent();
        delay(10);
      }

}
