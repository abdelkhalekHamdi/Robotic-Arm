#include<Servo.h>


Servo srv[4];

int i=0,j=0;
int pot[4]={A0,A1,A2,A3}; // Pot Pins
int val[4]; // Values from Pot
int pin[4]={3,5,6,9};  // Servos pins
int but1=11,but2=12; // buttons

// Arrays to save servo's positions 
byte save1[375];
byte save2[375];
byte save3[375];
byte save4[375];




void setup() {

for(i=0 ; i<4 ; i++ )
{ srv[i].attach(pin[i]);}

Serial.begin(9600);
}





void loop() {
 
for ( i=0 ; i<4 ; i++ )
{val[i] = readpot(pot[i]);
srv[i].write(val[i]);
Serial.println(val[3]); 
delay(5);}

if ( digitalRead(but1) == HIGH )
{ 

for ( i=0 ; i<375 ; i++)

 { 
  save1[i]=readpot(pot[0]);
  save2[i]=readpot(pot[1]);
  save3[i]=readpot(pot[2]);
  save4[i]=readpot(pot[3]);
  
   srv[0].write( readpot(pot[0]));
   srv[1].write( readpot(pot[1]));
   srv[2].write( readpot(pot[2]));
   srv[3].write( readpot(pot[3]));
Serial.println("Save Mode");
  delay(25);
}}

if ( digitalRead(but2) == HIGH )
{
for ( i=0 ; i<375 ; i++)
 { 
 srv[0].write( save1[i] );
 srv[1].write( save2[i] );
 srv[2].write( save3[i] );
 srv[3].write( save4[i] );
    
  delay(25);
  Serial.println("Read Mode");
}}
}

int readpot( int pot )
{ int val = analogRead(pot);
 return map(val,0,1023,0,180); }
 


