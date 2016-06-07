#include "etherShield.h"
#include "ETHER_28J60.h"
#include <Servo.h>
#include <IRremote.h>
int RECV_PIN = 6; 
IRrecv irrecv(RECV_PIN);
decode_results results;
Servo myservo1;
Servo myservo;
IRsend irsend;
static uint8_t mac[6] = {
  0xAA, 0xBB, 0xCC, 0xDD, 0xBB, 0xAA}; 
int val, i;  

boolean flag = false , lom =false;                                                              
char* params;
static uint8_t ip[4] = {
  192, 168, 1, 15};                       
static uint16_t port = 80;                                     
ETHER_28J60 e;

void setup()
{
  irrecv.enableIRIn();
  myservo.attach(9);
  myservo1.attach(8);
  e.setup(mac, ip, port);
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(1,OUTPUT);
  pinMode(0,OUTPUT);
}
void pultETHER(){


  if (params = e.serviceRequest()){
    if (strcmp(params, "?cmd=2") == 0)  
    {
      flag = true;



      servo3();
      servoON();
      delay(550);
      while(flag=true){ 


        servoOF();
        pultIR2();
        pultETHER2();
        if ((irrecv.decode(&results))||(params = e.serviceRequest())){
          if ((results.value == 0x2FD58A7)||(strcmp(params, "?cmd=1") == 0)) {
            lom=true;
            flag = false;
            return;
          }
          irrecv.resume();
          e.respond();
        }


      }

    }
    if (strcmp(params, "?cmd=10") == 0)  // ON//OFF computer
    {

      digitalWrite(1,LOW); 

    }
    if (strcmp(params, "?cmd=20") == 0)   // OFF computer
    {
      digitalWrite(1,HIGH);

    }
    if (strcmp(params, "?cmd=9") == 0)  // ON//OFF computer
    {

      digitalWrite(1,LOW); 

    }
    if (strcmp(params, "?cmd=8") == 0)   // OFF computer
    {
      digitalWrite(1,HIGH);

    }
    if (strcmp(params, "?cmd=11") == 0)  // ON//OFF computer
    {
      digitalWrite(5,HIGH);
      delay(100);
      digitalWrite(5,LOW); 

    }
    if (strcmp(params, "?cmd=12") == 0)   // OFF computer
    {
      digitalWrite(5,HIGH);
      delay(5000);
      digitalWrite(5,LOW); 
    }
    if (strcmp(params, "?cmd=3") == 0) // ON/OFF light
    {
      digitalWrite(7,HIGH);
      delay(100);
      digitalWrite(7,LOW);
    }
    if (strcmp(params, "?cmd=6") == 0)  // ON LAMP
    {
      digitalWrite(4,HIGH);
    }
    if (strcmp(params, "?cmd=13") == 0) { //POWER TV
      irsend.sendNEC(0xFE50AF,32);
    }
    if (strcmp(params, "?cmd=14") == 0) { //Vol +
      irsend.sendNEC(0xFE7887,32);  
    }
    if (strcmp(params, "?cmd=15") == 0) { //EXIT
      irsend.sendNEC(0xFEEA15,32);
    }
    if (strcmp(params, "?cmd=16") == 0) { //CH+
      irsend.sendNEC(0xFEF807,32);  
    }
    if (strcmp(params, "?cmd=17") == 0) { //VOL-
      irsend.sendNEC(0xFEFA05,32); 
    }
    if (strcmp(params, "?cmd=18") == 0) { //SOURce
      irsend.sendNEC(0xFECA35,32); 
    }
    if (strcmp(params, "?cmd=19") == 0) { //CH-
      irsend.sendNEC(0xFE3AC5,32);  
    }


    e.respond();
  }
}
void pultETHER2()
{
  if (params = e.serviceRequest()){
    if (strcmp(params, "?cmd=10") == 0)  // ON//OFF computer
    {

      digitalWrite(1,LOW); 

    }
    if (strcmp(params, "?cmd=20") == 0)   // OFF computer
    {
      digitalWrite(1,HIGH);

    }
    if (strcmp(params, "?cmd=9") == 0)  // ON//OFF computer
    {

      digitalWrite(1,LOW); 

    }
    if (strcmp(params, "?cmd=8") == 0)   // OFF computer
    {
      digitalWrite(1,HIGH);

    }
    if (strcmp(params, "?cmd=11") == 0)  // ON//OFF computer
    {
      digitalWrite(5,HIGH);
      delay(100);
      digitalWrite(5,LOW); 

    }
    if (strcmp(params, "?cmd=12") == 0)   // OFF computer
    {
      digitalWrite(5,HIGH);
      delay(5000);
      digitalWrite(5,LOW); 
    }
    if (strcmp(params, "?cmd=3") == 0) // ON/OFF light
    {
      digitalWrite(7,HIGH);
      delay(100);
      digitalWrite(7,LOW);
    }
    if (strcmp(params, "?cmd=6") == 0)  // ON LAMP
    {
      digitalWrite(4,HIGH);
    }
    if (strcmp(params, "?cmd=7") == 0) { //OFF LAMP
      digitalWrite(4,LOW);  
    }
    if (strcmp(params, "?cmd=13") == 0) { //POWER TV
      irsend.sendNEC(0xFE50AF,32);
    }
    if (strcmp(params, "?cmd=14") == 0) { //Vol +
      irsend.sendNEC(0xFE7887,32);  
    }
    if (strcmp(params, "?cmd=15") == 0) { //EXIT
      irsend.sendNEC(0xFEEA15,32);
    }
    if (strcmp(params, "?cmd=16") == 0) { //CH+
      irsend.sendNEC(0xFEF807,32);  
    }
    if (strcmp(params, "?cmd=17") == 0) { //VOL-
      irsend.sendNEC(0xFEFA05,32); 
    }
    if (strcmp(params, "?cmd=18") == 0) { //SOURce
      irsend.sendNEC(0xFECA35,32); 
    }
    if (strcmp(params, "?cmd=19") == 0) { //CH-
      irsend.sendNEC(0xFE3AC5,32);  
    }
    e.respond();
  }
}
void pultIR(){

  if (irrecv.decode(&results))
  {
    if (results.value == 0x2FD7887)
    {
      flag = true;



      servo3();
      servoON();
      delay(550);
      while(flag=true){ 


        servoOF();
        pultIR2();
        pultETHER2();
        if ((irrecv.decode(&results))||(params = e.serviceRequest())){
          if ((results.value == 0x2FD58A7)||(strcmp(params, "?cmd=1") == 0)) {
            flag = false;
            lom=true;
            return;
          }
          irrecv.resume();
          e.respond();
        }



      }
    }
    if (results.value == 0x2FD708F) //ON/OFF LIGHT
    {
      digitalWrite(7,HIGH);
      delay(100);
      digitalWrite(7,LOW);
    }
    if (results.value == 0x2FD08F7) //ON/OFF comp
    {
      digitalWrite(5,HIGH);
      delay(100);
      digitalWrite(5,LOW); 
    }
    if (results.value == 0x2FDD827) //ON/ LAMP
    {
      digitalWrite(4,HIGH);
    }
    if (results.value == 0x2FDF807) //OFF LAMP
    {
      digitalWrite(4,LOW);
    }  
    if (results.value == 0x2FD48B7) { //POWER TV
      irsend.sendNEC(0xFE50AF,32);
    }

    irrecv.resume();
  }


}
void pultIR2(){
  if (irrecv.decode(&results))
  {
    if (results.value == 0x2FD708F) //ON/OFF LIGHT
    {
      digitalWrite(7,HIGH);
      delay(100);
      digitalWrite(7,LOW);
    }
    if (results.value == 0x2FD08F7) //ON/OFF comp
    {
      digitalWrite(5,HIGH);
      delay(100);
      digitalWrite(5,LOW); 
    }
    if (results.value == 0x2FDD827) //ON/ LAMP
    {
      digitalWrite(4,HIGH);
    }
    if (results.value == 0x2FDF807) //OFF LAMP
    {
      digitalWrite(4,LOW);
    }
    if (results.value == 0x2FD48B7) { //POWER TV
      irsend.sendNEC(0xFE50AF,32);
    }

    irrecv.resume();
  }
}


void servo3(){
  myservo.write(3);
  myservo1.write(3);
}
void servoON(){
  myservo.attach(9);
  myservo1.attach(8);
}
void servoOF(){
  myservo.detach();
  myservo1.detach();
}



void loop()
{
  lom =false;
  flag = false;



  val = analogRead(A0);
  Serial.println(val);
  if (val <= 100)  {
    servo3();
    servoON();

  }
  else {
    val = map(val, 100, 1023, 5, 165);   // scale it to use it with the servo (value between 0 and 180)
    myservo.write(val-20);
    myservo1.write(val-20);
    servoON();
  }
  delay(550);
  servoOF();
  for (i = 1 ; i < 3000 ; i++) {

    pultIR();
    pultETHER();
    if (lom){
      return;
    }
    delay(100);
  }



}








