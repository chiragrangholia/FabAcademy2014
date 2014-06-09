
#include <SoftwareSerial.h>

SoftwareSerial mySerial(0, 1); // RX, TX

//int ledPin = 6;
// int ledPin = 7;
// int ledPin = 8;// the pin that the LED is attached to
char incomingByte;      // a variable to read incoming serial data into

void setup() {
  // initialize serial communication:
  mySerial.begin(9600);
  // initialize the LED pin as an output:
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop() {
  // see if there's incoming serial data:
  if (mySerial.available() > 0) {
    // read the oldest byte in the serial buffer:
    incomingByte = mySerial.read();
    // if it's a capital H (ASCII 72), turn on the LED:
    if (incomingByte == 'R') {

      for(int fadeValue = 0 ; fadeValue <= 255; fadeValue +=5) { 
        // sets the value (range from 0 to 255):
        analogWrite(8, fadeValue);         
        // wait for 30 milliseconds to see the dimming effect    
        delay(50);
      }
      for(int fadeValue = 255 ; fadeValue >= 0; fadeValue -=5) { 
        // sets the value (range from 0 to 255):
        analogWrite(7, fadeValue);         
        // wait for 30 milliseconds to see the dimming effect    
        delay(50);                            
      } 

      for(int fadeValue = 255 ; fadeValue >= 0; fadeValue -=5) { 
        // sets the value (range from 0 to 255):
        analogWrite(6, fadeValue);         
        // wait for 30 milliseconds to see the dimming effect    
        delay(50);   
        digitalWrite(6, LOW);

      }
      //digitalWrite(8, HIGH);

      /*digitalWrite(8, HIGH);   // turn the LED on (HIGH is the voltage level)
       delay(200);               // wait for a second
       digitalWrite(8, LOW);    // turn the LED off by making the voltage LOW
       delay(200); 
       {
       digitalWrite(7, HIGH);
       delay(200);
       digitalWrite(7, LOW);
       delay(200);
       }
       {
       digitalWrite(6, HIGH);
       delay(200);
       digitalWrite(6, LOW);
       delay(200);
       }// wait for a second
       */
    } 
    // if it's an L (ASCII 76) turn off the LED:
    if (incomingByte == 'L') {
      digitalWrite(8, LOW);
    }



    if (incomingByte == 'G') {
      //digitalWrite(7, HIGH);

      digitalWrite(8, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(500);               // wait for a second
      digitalWrite(8, LOW);    // turn the LED off by making the voltage LOW
      delay(500); 
      {
        digitalWrite(7, HIGH);
        delay(500);
        digitalWrite(7, LOW);
        delay(500);
      }
      {
        digitalWrite(6, HIGH);
        delay(500);
        digitalWrite(6, LOW);
        delay(500);
      }// wait for a second

    } 
    // if it's an L (ASCII 76) turn off the LED:
    if (incomingByte == 'L') {
      digitalWrite(7, LOW);
    }


    if (incomingByte == 'B') {

      for (int thisPin = 8; thisPin >= 6; thisPin++) { 
        // turn the pin on:
        digitalWrite(thisPin, HIGH);   
        delay(25);  


        // turn the pin off:
        // digitalWrite(thisPin, LOW);    
      }

      for (int thisPin = 6; thisPin < 8; thisPin++) { 
        // turn the pin on:
        digitalWrite(thisPin, HIGH);   
        delay(25);                  
        // turn the pin off:
        digitalWrite(thisPin, LOW);
      }
      digitalWrite(6, HIGH);
    } 
    // if it's an L (ASCII 76) turn off the LED:
    if (incomingByte == 'L') {
      digitalWrite(6, LOW);
    }
  }
}






