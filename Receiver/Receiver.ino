//// Adding Libraries 
#include <SPI.h>             /* to handle the communication interface with the modem*/
#include <RF24.h>            /* the library which helps us to control the radio modem*/

RF24 radio(7,8);             /* Creating instance 'radio'  ( CE , CSN )   CE -> D7 | CSN -> D8 */                               
const byte Address[6] = "00009"; /* Address from which data to be received */

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);            /*Setting baudrate of Serial Port to 9600*/
  radio.begin();                   /* Activate the modem*/
  radio.openReadingPipe(1, Address);
  pinMode(LED_BUILTIN, OUTPUT);
  /* Sets the address of receiver from which program will receive the data*/
}

void loop() {
  // put your main code here, to run repeatedly:
  radio.startListening();          /*Setting modem in Receiver mode*/
  if (radio.available())
  {
  while (radio.available()){
  int rx_data = 0 ;                    /* Variable to store received data */
  radio.read(&rx_data, sizeof(rx_data));/* Read the received data and store in ' rx_data ' */
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);  
  Serial.print("Received Data : ");
  Serial.println(rx_data);           /* Print received value on Serial Monitor */
    }
  }
    
  else
  {
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
    delay(1000); 
    Serial.println("Not Receiving !!!"); /* If not receiving valid data print " Not Receiving !!! " on Serial Monitor  */
   }
    ///// END OF LOOP //////
}
