int IN3 = 9; /// шим 
int IN4 = 8; //направление 
int IN5 = 6; //шим
int IN6 = 12; //направление
int ENA = 3;
int ENB = 11;
int val;
int i;
void setup()
{


  pinMode (ENA, OUTPUT);
  pinMode (ENB, OUTPUT);
  pinMode (IN4, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN5, OUTPUT);
  pinMode (IN6, OUTPUT);
  Serial.begin(9600);
}


void loop()
{
  if (Serial.available())
  {
    val = Serial.read();


    if (val == 'W') // вперед
    {

      digitalWrite (IN4, HIGH);
      digitalWrite (IN3, LOW);
      digitalWrite (IN5, LOW);
      digitalWrite (IN6, HIGH); 

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

