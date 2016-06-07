
int IN3 = 9; /// шим 
int IN4 = 8; //направление 

int IN5 = 5; //шим
int IN6 = 12; //направление

int IN1 = 6; //ШИМ
int IN2 = 7; 
int val;


void setup()
{
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (IN4, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN5, OUTPUT);
  pinMode (IN6, OUTPUT);
  
  Serial.begin(9600);
 

  

}



void loop()
{
  if (Serial.available()){
  
    val = Serial.read();


 
    if (val == 'W') // вперед
    {
   forward();
    }
    if ( val == 'A')
    {
     right_t();
    }

    // Задаём движение влево
    if ( val == 'D')
    {
      left_t();
      
    }

    // Задаём движение назад
    if ( val == 'S')
    {
     back();
    }
 if ( val == 'R')
    {
   right_b();
    }
     if ( val == 'L')
    {
   left_b();
    }
  
    if ( val == 'B')
    {
    stop_b();
    }
    
     if ( val == 'T')
    {
   stop_tank();
}
  }
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
 digitalWrite (IN1, LOW);
 digitalWrite (IN2, HIGH);
 }

  void stop_tank()
  {
     Serial.println("T");
 digitalWrite (IN4, LOW);
  digitalWrite (IN3, LOW);
  digitalWrite (IN5, LOW);
  digitalWrite (IN6, LOW); 
 }
 

  void stop_b()
  { 
     Serial.println("B");
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, LOW);
 
  }
