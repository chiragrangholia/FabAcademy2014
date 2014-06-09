#include <SoftwareSerial.h>

SoftwareSerial mySerial(0, 1); // RX, TX

void setup()  
{
  mySerial.begin(4800);
  mySerial.println("Hello, world?");
  pinMode(2, INPUT);
  pinMode(7, OUTPUT); 

}

void loop() // run over and over
{
  int buttonState = digitalRead(2);
  mySerial.print(buttonState);
  if (buttonState == HIGH) {     
    // turn LED on:    
    digitalWrite(7, HIGH);  
  } 
  else {
    // turn LED off:
    digitalWrite(7, LOW); 
  }
  delay(100);
}


