#include <SoftwareSerial.h>
#include <SerialCommand.h>
int IN3 = 9; /// шим 
int IN4 = 8; //направление 
int IN5 = 5; //шим
int IN6 = 12; //направление
int IN1 = 6; //ШИМ
int IN2 = 7; 
int val;
int i;
SerialCommand sCmd; 
void setup()
{
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (IN4, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN5, OUTPUT);
  pinMode (IN6, OUTPUT);
  
  Serial.begin(9600);
 

  sCmd.addCommand("W", forward   );      
  sCmd.addCommand("A", right_t   ); 
  sCmd.addCommand("D",  left_t  );     
  sCmd.addCommand("S", back  );       
  sCmd.addCommand("L",left_b );     
  sCmd.addCommand("R", right_t    ); 
  //sCmd.addCommand(" ", stops    );   
  sCmd.addDefaultHandler(unrecognized);    

}



void loop()
{
   sCmd.readSerial(); 
 //if (Serial.available()==0){
  
 /// stops();
  
///  }   
}



 void forward()
 {
  Serial.println("UP");
        digitalWrite (IN4, HIGH);
        digitalWrite (IN3, LOW);
        digitalWrite (IN5, LOW);
        digitalWrite (IN6, HIGH); 

 }
 void back()
 {
   Serial.println("DOWN");
      digitalWrite (IN4, LOW);
      digitalWrite (IN3, HIGH);
      digitalWrite (IN5, HIGH);
      digitalWrite (IN6, LOW); 
 }
 void left_t()
 {
   Serial.println("left_t");
       digitalWrite (IN4, LOW);
       digitalWrite (IN3, HIGH);
       digitalWrite (IN5,LOW);
       digitalWrite (IN6, HIGH);
 }
 void right_t()
 {
  Serial.println("right_t");
      digitalWrite (IN4, HIGH);
      digitalWrite (IN3, LOW);
      digitalWrite (IN5, HIGH);
      digitalWrite (IN6, LOW); 
 }
 void left_b()
 {
  Serial.println("left_b");
 digitalWrite (IN1, HIGH);
 digitalWrite (IN2, LOW);
 }
 void right_b()
 {
  Serial.println("right_b");
 digitalWrite (IN1, HIGH);
 digitalWrite (IN2, LOW);
 }

  void stops()
  {
     Serial.println("stop");
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, LOW);
  digitalWrite (IN4, LOW);
  digitalWrite (IN3, LOW);
  digitalWrite (IN5, LOW);
  digitalWrite (IN6, LOW); 
 }
 void unrecognized()
 {
  Serial.println("alredy");
 
 }
 

