/*
 * IRremote: IRrecvDump - dump details of IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 * JVC and Panasonic protocol added by Kristian Lauszus (Thanks to zenwheel and other people at the original blog post)
 */

#include <IRremote.h>

int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);
IRsend irsend;
decode_results results;

void setup()
{

  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}
unsigned int powerOn[68]={
  6212,8950,4400,600,500,650,450,650,500,550,550,600,500,650,450,600,550,600,500,650,1550,650,1600,600,1600,650,1600,650,1550,650,600,650,1600,600,450,700,450,600,1600,700,450,600,1600,650,450,650,500,650,450,650,450,600,1600,650,500,600,1600,700,450,550,1650,650,1600,600,1600,600,1650,600};


void loop() {  
  irsend.sendNEC(0xFE50AF,32);
  // irsend.sendRaw(powerOn,68,38);

  delay(10000);


}

