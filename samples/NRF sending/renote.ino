
#include  <SPI.h> 
#include "nRF24L01.h" 
#include "RF24.h" 

int  msg[1];
RF24 radio(9,10); 
const uint64_t pipe = 0xE8E8F0F0E1LL; 

void setup(void){
  //Serial.begin(9600);

 radio.begin();
 
 radio.openWritingPipe(pipe);}

void loop(void){

//Serial.println(analogRead(A0));
 msg[0] = 112; 
 radio.write(msg,1);
 

 }


 

