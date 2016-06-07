#include <IRremote.h>
#include <Servo.h>
int RECV_PIN = 11; //вход ИК приемника
IRrecv irrecv(RECV_PIN);
decode_results results;
int LED = 8;
Servo myservo;
void setup()

{
  irrecv.enableIRIn(); // включить приемник
  pinMode(LED, OUTPUT);
  myservo.attach(9);
}

void loop() {

  if (irrecv.decode(&results))
  {
    if (results.value == 0x2FD48B7) //код моей кнопки "2FD807F". У Вас он будет дугой
    {
      myservo.write(30);
    }
    if (results.value == 0x2FD08F7)//код моей кнопки "2FD40BF". У Вас он будет дугой
    {
      myservo.write(40);
    }
    irrecv.resume();
  }
}

