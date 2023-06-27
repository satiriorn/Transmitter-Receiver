#include <WiFi.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
 


RF24 radio(4, 5); 
const byte Address[6] = "00009";

void setup() 
{
  Serial.begin(115200);
  radio.begin();
  
 
  Serial.println("Transmitter starting....");
 
  radio.openReadingPipe(0, Address);   //Setting the address at which we will receive the data
  radio.setPALevel(RF24_PA_MIN);       //You can set this as minimum or maximum depending on the distance between the transmitter and receiver.
  radio.stopListening();         //Set module as transmitter
}

 
void loop()
{
  const char text[] = "Hello World";
  radio.write(&text, sizeof(text));
  
  delay(1000);
}
