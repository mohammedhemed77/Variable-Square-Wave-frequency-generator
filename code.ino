/* *************************************************
This code generate variable square wave using knob *
from 100 : 1000 Hz                                 *
by : Mohammed Hemed                                *
Hardware : Arduino Mega + potentiometer = 5k_Ohm   *
****************************************************/
// preprocessors to save memory 
// instead of  const int square_pulse = 22;  // which take 2 bytes  :D  


#define square_pulse 7
#define knob A0



#include <SPI.h>
byte address = 0x11;
int CS= 10;
int i=0;


void setup() {
pinMode(square_pulse,OUTPUT);
Serial.begin(9600);

pinMode (CS, OUTPUT);
  SPI.begin();
  // adjust high and low resistance of potentiometer
  // adjust Highest Resistance .
   digitalPotWrite(0x00);
   delay(1000);
 
      // adjust  wiper in the  Mid point  .
   digitalPotWrite(0x80);
   delay(1000);

   // adjust Lowest Resistance .
   digitalPotWrite(0xFF);
   delay(1000);
}

/*****************************************

if you don't use tone function 
generating square wave of : ton = toff : 


| Freq | Period |   ton    |   toFF       |
| 100  |  0.01  | 5 msec   | 5000 microsec|
| 200  |  0.01  | 5 msec   | 2500 microsec|

and so on .... 

digitalWrite(pinNumber,HIGH);
delayMicroseconds(half_period);  
digitalWrite(pinNumber,LOW);
delay(half_period);  

****************************************/
void loop() {
// read the knob value  
int knob_reading = analogRead(knob);
// make 10 intervals and generate 11 frequencies 

if      (knob_reading > 10  && knob_reading <=100)    { tone(square_pulse,100);  digitalPotWrite(10);}

else if (knob_reading > 100 && knob_reading <=200)    { tone(square_pulse,200);  digitalPotWrite(5); }

else if (knob_reading > 200 && knob_reading <=300)    { tone(square_pulse,300);  digitalPotWrite(3); }

else if (knob_reading > 300 && knob_reading <=400)    { tone(square_pulse,400);  digitalPotWrite(3); }

else if (knob_reading > 400 && knob_reading <=500)    { tone(square_pulse,500);  digitalPotWrite(3); }

else if (knob_reading > 500 && knob_reading <=600)    { tone(square_pulse,600);  digitalPotWrite(2); }

else if (knob_reading > 600 && knob_reading <=700)    { tone(square_pulse,700);  digitalPotWrite(2); }

else if (knob_reading > 700 && knob_reading <=800)    { tone(square_pulse,800);  digitalPotWrite(2); }

else if (knob_reading > 800 && knob_reading <=900)    { tone(square_pulse,900);  digitalPotWrite(1); } 

else if (knob_reading > 900 && knob_reading <=1000)   { tone(square_pulse,1000); digitalPotWrite(1); }

// print knob_reading to test and debug code : 
Serial.println(knob_reading);
}

int digitalPotWrite(int value)
{
  digitalWrite(CS, LOW);
  SPI.transfer(address);
  SPI.transfer(value);
  digitalWrite(CS, HIGH);
}
