#include "etherShield.h"
#include "ETHER_28J60.h"
#include <Servo.h>
Servo myservo1;
Servo myservo;
static uint8_t mac[6] = {
  0xAA, 0xBB, 0xCC, 0xDD, 0xBB, 0xAA};   // this just needs to be unique for your network,
int val, i;                                                              // so unless you have more than one of these boards
boolean flag = false;                                                               // connected, you should be fine with this value.

static uint8_t ip[4] = {
  192, 168, 1, 15};                       // the IP address for your board. Check your home hub

static uint16_t port = 80;                                      // Use port 80 - the standard for HTTP

ETHER_28J60 e;

void setup()
{
  myservo.attach(9);
  myservo1.attach(8);
  e.setup(mac, ip, port);
  Serial.begin(9600);
  pinMode(2, OUTPUT);

}

void loop()
{

  flag = false;
  char* params;

  digitalWrite(2,HIGH);

  val = analogRead(A0);
  Serial.println(val);
  if ((val >= 1000) || (val <= 100)) {
    myservo.write(3);
    myservo1.write(3);


  }
  else {
    val = map(val, 100, 1023, 5, 165);     // scale it to use it with the servo (value between 0 and 180)
    myservo.write(val);
    myservo1.write(val);



  }

  for (i = 1 ; i < 600 ; i++) {
    params = e.serviceRequest();
    if (strcmp(params, "?cmd=1") == 0)
    {

      flag = true;
      break;

    }
    digitalWrite(2,LOW);
    delay(100);
  }

  while (flag) {
    params = e.serviceRequest();
    if (strcmp(params, "?cmd=1") == 0) {
      flag = !flag;
    }
    myservo.write(0);
    myservo1.write(0);
    if (strcmp(params, "?cmd=2") == 0){
      flag=false;
      break;
    }
  }

}


