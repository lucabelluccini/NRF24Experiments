// Requires https://github.com/maniacbug/RF24
#include <nRF24L01.h>
#include <RF24.h>
#include <RF24_config.h>
#include <SPI.h>
int msg[1];
RF24 radio(9,10);
const uint64_t pipe = 0xE8E8F0F0E1LL;
/*
this is the most basic sketch I can think of to transmit data from an nrf24l01.
It loops over the numbers 0-255 continuously and sends each number to the receiving 
unit.  I have used this pattern as a test to check for drops in the signal by 
checking the receiving end for gaps between numbers.  It's not sophisticated,
but it seems to work.
*/
 
void setup(void){
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(pipe);}
 
void loop(void){
  
  for (int x=0;x<255;x++){
  msg[0] = x;
  radio.write(msg, 1);
  }
}
