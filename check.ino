#include <SoftwareSerial.h>
SoftwareSerial SIM900A(10,11); // RX | TX
char c = ' ';
void setup() 
{
    Serial.begin(9600);
    while(!Serial)
    {
        delay(1000)
    }
    Serial.println("Connection with SIM900A established.");
    SIM900A.begin(9600); 
    delay(1000);
    Serial.println("SIM900A initialized.");
}
void loop()
{
    if (SIM900A.available())
    { 
        c = SIM900A.read();
        Serial.write(c);
    }
    if (Serial.available())
    {
        c = Serial.read();
        SIM900A.write(c); 
    }
}
