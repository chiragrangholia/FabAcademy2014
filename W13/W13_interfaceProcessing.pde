/**
 * Simple Write. 
 * 
 * Check if the mouse is over a rectangle and writes the status to the serial port. 
 * This example works with the Wiring / Arduino program that follows below.
 */


import processing.serial.*;

Serial myPort;  // Create object from Serial class
int val;        // Data received from the serial port

void setup() 
{
  size(250, 100);
  // I know that the first port in the serial list on my mac
  // is always my  FTDI adaptor, so I open Serial.list()[0].
  // On Windows machines, this generally opens COM1.
  // Open whatever port is the one you're using.
  String portName = Serial.list()[2];
  myPort = new Serial(this, portName, 4800);
}

void draw() {
  background(255);
  if (mouseOverRect1() == true) {  // If mouse is over square,
    fill(255, 0, 0);                    // change color and
    myPort.write('H');              // send an H to indicate mouse is over square
  } 
  else {                        // If mouse is not over square,
    fill(0);                      // change color and
    myPort.write('L');              // send an L otherwise
  }
  rect(25, 25, 50, 50);   // Draw a square
  
  if (mouseOverRect2() == true) {  // If mouse is over square,
    fill(0, 255, 0);                    // change color and
    myPort.write('H');              // send an H to indicate mouse is over square
  } 
  else {                        // If mouse is not over square,
    fill(0);                      // change color and
    myPort.write('L');              // send an L otherwise
  }
  rect(100, 25, 50, 50); 
 
 if (mouseOverRect3() == true) {  // If mouse is over square,
    fill(0, 0, 255);                    // change color and
    myPort.write('H');              // send an H to indicate mouse is over square
  } 
  else {                        // If mouse is not over square,
    fill(0);                      // change color and
    myPort.write('L');              // send an L otherwise
  }
  rect(175, 25, 50, 50); 
}

boolean mouseOverRect1() { // Test if mouse is over square
  return ((mouseX >= 25) && (mouseX <= 75) && (mouseY >= 25) && (mouseY <= 75));
}

boolean mouseOverRect2() { // Test if mouse is over square
  return ((mouseX >= 100) && (mouseX <= 150) && (mouseY >= 25) && (mouseY <= 75));
}

boolean mouseOverRect3() { // Test if mouse is over square
  return ((mouseX >= 175) && (mouseX <= 225) && (mouseY >= 25) && (mouseY <= 75));
}
/*
  // Wiring/Arduino code:
 // Read data from the serial and turn ON or OFF a light depending on the value
 
 char val; // Data received from the serial port
 int ledPin = 4; // Set the pin to digital I/O 4
 
 void setup() {
 pinMode(ledPin, OUTPUT); // Set pin as OUTPUT
 Serial.begin(9600); // Start serial communication at 9600 bps
 }
 
 void loop() {
 if (Serial.available()) { // If data is available to read,
 val = Serial.read(); // read it and store it in val
 }
 if (val == 'H') { // If H was received
 digitalWrite(ledPin, HIGH); // turn the LED on
 } else {
 digitalWrite(ledPin, LOW); // Otherwise turn it OFF
 }
 delay(100); // Wait 100 milliseconds for next reading
 }
 
 */
