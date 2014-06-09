// Description: This program is designed to blink each color of a RGB LED
// When the reading on the input pin is low. You can switch the delay to your
// convienience :)

#define red 6
#define blue 7
#define green 8
//Pin outputs for RGB LED

#define input 2
//Input pin for buttom

void setup()
{
  pinMode(red,OUTPUT);
  pinMode(blue,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(input,INPUT);
  return;
}

long unsigned delayCurrent=0, delayPrev=0;
const int Delay=100;
int count=0;

void loop()
{
  delayCurrent=millis();
  
  if( (delayCurrent-delayPrev>Delay) && digitalRead(input)==LOW )
  {
    if(count==0 || count==1 || count==2)
      digitalWrite(red,HIGH);
     else
      digitalWrite(red,LOW);
    //RED if
    if( count==1 || count==2 || count==3 || count==5)
      digitalWrite(green,HIGH);
    else
      digitalWrite(green,LOW);
    //GREEN if
    if(count==2 || count==3 || count==4)
      digitalWrite(blue,HIGH);
    else
      digitalWrite(blue,LOW);
    //BLUE if
    count++;
    if(count>5)
      count=0;  
    delayPrev=delayCurrent;
  }

}
