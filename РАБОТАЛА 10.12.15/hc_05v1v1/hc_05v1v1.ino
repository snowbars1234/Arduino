#include <Servo.h> 

int IN3 = 9; /// шим 
int IN4 = 8; //направление 
int IN5 = 5; //шим
int IN6 = 12; //направление
int IN1 = 6; //ШИМ
int IN2 = 7; 
int lamp = A0;
int pos = 150;
int val;
boolean flag=false;
int g=0;
Servo gunservo;
void setup()
{

  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (IN4, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN5, OUTPUT);
  pinMode (IN6, OUTPUT);
  pinMode(lamp, OUTPUT);  
  Serial.begin(9600);
  gunservo.attach(13);
  gunservo.write(150);
  //  delay(400);
 // gunservo.detach();

}



void loop()
{
  if (Serial.available()){
  
    val = Serial.read();


 
    if (val == 'W') // вперед
      {
       forward();
    }
    if ( val == 'A')  // Задаём движение влево
      {
       right_t();
      }
    if ( val == 'D')   // Задаём движение вправо
     {
      left_t();
      }
    if ( val == 'S')       // Задаём движение назад
      {
       back();
      }
    if ( val == 'R')      //башня вправо
      {
       right_b();
      }
    if ( val == 'L')    //башня влево
      {
       left_b();
      }
  
    if ( val == 'B')     //стоп башня (отпускаем клавишу поворота)
      {
        stop_b();
      }
    
     if ( val == 'T')  //стоп танк (отпускаем клавишу движения)
      {
       stop_tank();
      }

     if (( val == 'H')&&(flag==false))   // вкл лампочки
      {
        digitalWrite(lamp,HIGH);
       Serial.println("GORIT");
       Serial.println(flag);
      }

    if ((val == 'H')&&(flag==true))   // выкл лампочки
      {
       digitalWrite(lamp,LOW);
       Serial.println("neGORIT");
       Serial.println(flag);
      }

   while ( val == 'Q')     //Пушка вверх
      { 
        if(pos>35){
        up_gun();
        }
        else {
          gunservo.write(pos);
        Serial.println("lol");
        break;
      }
      }
      
   while ( val == 'E')     //Пушка вниз
      {
        if(pos<150){
        down_gun();
        }
        
       else {
         gunservo.write(pos);
     Serial.println("lol");
     break;
   }
      } 
    
    
    if ( val == 'G')     //Пушка стапе
      {
        gunservo.write(pos);
        
    }     
flag=!flag;
  }
}





 void forward()
 {
  //Serial.println("UP");
        digitalWrite (IN4, HIGH);
        digitalWrite (IN3, LOW);
        digitalWrite (IN5, LOW);
        digitalWrite (IN6, HIGH); 

 }
 void back()
 {
   //Serial.println("DOWN");
      digitalWrite (IN4, LOW);
      digitalWrite (IN3, HIGH);
      digitalWrite (IN5, HIGH);
      digitalWrite (IN6, LOW); 
 }
 void left_t()
 {
   //Serial.println("left_t");
       digitalWrite (IN4, LOW);
       digitalWrite (IN3, HIGH);
       digitalWrite (IN5,LOW);
       digitalWrite (IN6, HIGH);
 }
 void right_t()
 {
 //Serial.println("right_t");
      digitalWrite (IN4, HIGH);
      digitalWrite (IN3, LOW);
      digitalWrite (IN5, HIGH);
      digitalWrite (IN6, LOW); 
 }
 void left_b()
 {
 //Serial.println("left_b");
      digitalWrite (IN1, HIGH);
      digitalWrite (IN2, LOW);
 }
 void right_b()
 {
 //Serial.println("right_b");
       digitalWrite (IN1, LOW);
       digitalWrite (IN2, HIGH);
 }

  void stop_tank()
  {
  // Serial.println("T");
        digitalWrite (IN4, LOW);
        digitalWrite (IN3, LOW);
        digitalWrite (IN5, LOW);
      digitalWrite (IN6, LOW); 
 }
 

  void up_gun ()
  {
    
   for(pos=pos ; pos>35; pos--)     // goes from 180 degrees to 0 degrees 
    {    
    
   gunservo.write(pos);              // tell servo to go to position in variable 'pos' 
   delay(15);
   refresh ();
  
   if (val!='Q')
     {
   return;
     }
    } 
  }
  
  
  void down_gun ()
  {
   for(pos=pos ; pos<150; pos++)  // goes from 0 degrees to 180 degrees 
    {   
    
    gunservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15); 
    refresh ();
    if (val!= 'E')
      {
   return;
      }
    } 
   }
  
  void stop_b()
  { 
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, LOW);
 
  }
  
  void refresh (){
    
   if( Serial.available()){
   val = Serial.read();
   }
  }
