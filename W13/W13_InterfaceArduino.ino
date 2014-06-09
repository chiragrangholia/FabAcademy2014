#include <SoftwareSerial.h>

SoftwareSerial mySerial(0, 1); // RX, TX

int val = 0;

void setup()  
{
  mySerial.begin(4800);
  mySerial.println("Hello, world?");
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);

}

void loop() // run over and over
{
  if (mySerial.available()) { // If data is available to read,
    val = mySerial.read(); // read it and store it in val
  }
  
  //////////////
  
  if (val == 'H') { // If H was received
    digitalWrite(6, LOW); // turn the LED on
  } 
  else {
    digitalWrite(6, HIGH); // Otherwise turn it OFF
  }
  
  ///////////////
  
  if (val == 'H') { // If H was received
    digitalWrite(7, LOW); // turn the LED on
  } 
  else {
    digitalWrite(7, HIGH); // Otherwise turn it OFF
  }
  
  /////////////////////
  
  if (val == 'H') { // If H was received
    digitalWrite(8, LOW); // turn the LED on
  } 
  else {
    digitalWrite(8, HIGH); // Otherwise turn it OFF
  }
}




