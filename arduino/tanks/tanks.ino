#include <Servo.h>
#include <PWMFrequency.h>
//const int Trig = 2; 
//const int Echo = 3; 
int IN3 = 9; /// шим 
int IN4 = 8; //направление 
int IN5 = 10; //шим
int IN6 = 12; //направление
int ENB = 3;
int ENA = 11;
int val;
long duration,distance;
Servo myservo;
void setup()
{
  myservo.attach(10);
  //pinMode(Trig, OUTPUT);
  //pinMode(Echo, INPUT);
  pinMode (ENA, OUTPUT);
  pinMode (ENB, OUTPUT);
  pinMode (IN4, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN5, OUTPUT);
  pinMode (IN6, OUTPUT);
  setPwmFrequency(IN3, 1);
  setPwmFrequency(IN5, 1);
  setPwmFrequency(ENB, 1);
  setPwmFrequency(ENA, 1);
  Serial.begin(9600);

}

/*void echo()
 {
 digitalWrite(Trig,HIGH); //подаем импульс
 delay(10);; //ждем две миллисекунды
 digitalWrite(Trig,LOW); //отключаем подачу импульса
 duration=pulseIn(Echo,HIGH); //включаем прием импульса
 distance=duration/58;
 delay(10);
 
 }
 */
void loop()
{
  /*long right=0,left=0;
   myservo.write(84);
   delay(500);
   
   int i;
   echo();
   Serial.print("distance="); //выводим на COM порт расстояние
   Serial.println(distance); //выводим на COM порт расстояние
   
   
   digitalWrite (IN4, HIGH);
   digitalWrite (IN3, LOW);
   digitalWrite (IN5, LOW);
   digitalWrite (IN6, HIGH);
   //for (i=0 ; i<=50; i++){
   //analogWrite (ENA, i);
   //analogWrite (ENB , i);
   //delay (4);
   
   if(distance<30)
   {
   digitalWrite (IN4, LOW);
   digitalWrite (IN3, LOW);
   digitalWrite (IN5,LOW);
   digitalWrite (IN6, LOW);
   int pos = 0;
   for(pos = 84; pos>=0; pos-=1)     
   {                                
   myservo.write(pos);              
   delay(15);  
   }
   delay(500);
   echo();
   right=distance;
   Serial.print("right=");
   Serial.println(right);
   
   for(pos = 0; pos <= 175; pos += 1) 
   {                                 
   myservo.write(pos);              
   delay(15);                      
   }
   delay(500);
   echo(); 
   left=distance;
   Serial.print("left=");
   Serial.println(left);
   
   for(pos = 175; pos>=84; pos-=1)     
   {                                
   myservo.write(pos);              
   delay(15);   }
   
   if (left>right){
   digitalWrite (IN4, LOW);
   digitalWrite (IN3, LOW);
   //analogWrite (ENA, 10);
   //analogWrite (ENB, 10);
   digitalWrite (IN5, LOW);
   digitalWrite (IN6, HIGH);
   
   }
   
   if (right>left){
   digitalWrite (IN4, HIGH);
   //analogWrite (ENA, 10);
   //analogWrite (ENB, 10);
   digitalWrite (IN3, LOW);
   digitalWrite (IN5, LOW);
   digitalWrite (IN6, LOW);
   
   
   }
   
   }
   
   //}
   */
  int i;
  if (Serial.available())
  {
    val = Serial.read();


    if (val == 'W') // вперед
    {
      digitalWrite (IN4, HIGH);
      digitalWrite (IN3, LOW);
      digitalWrite (IN5, LOW);
      digitalWrite (IN6, HIGH); 
      for (i=0 ; i<=180; i++){
        analogWrite (ENA, i);
        analogWrite (ENB , i);
        delay (30);
      }

      // Задаём движение назад
      if ( val == 'D')
      {
        digitalWrite (IN4, LOW);
        digitalWrite (IN3, HIGH);
        digitalWrite (IN5, HIGH);
        digitalWrite (IN6, LOW); 
      }

      // Задаём движение вправо
      if ( val == 'A')
      {
        digitalWrite (IN4, HIGH);
        digitalWrite (IN3, LOW);
        digitalWrite (IN5, LOW);
        digitalWrite (IN6, LOW); 
      }

      // Задаём движение влево
      if ( val == 'S')
      {
        digitalWrite (IN4, LOW);
        digitalWrite (IN3, LOW);
        digitalWrite (IN5,LOW);
        digitalWrite (IN6, HIGH);
      }

      // Стоп режим
      // При отпускании клавиш в программе в порт шлется «T»
      if ( val == 'T') // При нажатии клавиши «T»
      {
        digitalWrite (IN4, LOW);
        digitalWrite (IN3, LOW);
        digitalWrite (IN5, LOW);
        digitalWrite (IN6, LOW); 
      }
    } 
  }
}

