int IN3 = 9; // Input3 подключен к выводу 5 
int IN4 = 8;
int IN5 = 11; //
int IN6 = 12;

void setup()
{
  pinMode (IN4, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN5, OUTPUT);
  pinMode (IN6, OUTPUT);
}
void loop()
{
  // На пару выводов "IN" поданы разноименные сигналы, мотор вращается   
  digitalWrite (IN4, HIGH);
  digitalWrite (IN3, LOW);
  digitalWrite (IN5, LOW);
  digitalWrite (IN6, HIGH);
  delay(4000);
  /*  // На пару выводов "IN" поданы одноименные сигналы, мотор не вращается 
   digitalWrite (IN4, LOW); 
   delay(500);
   // На пару выводов "IN" поданы разноименные (и уже противоположные относительно первого случая) сигналы, мотор вращается  
   // относительно первого случая) сигналы, мотор вращается в другую сторону
   digitalWrite (IN3, HIGH);
   delay(4000);
   // Снова на выводах "IN" появились одноименные сигналы, мотор не вращается 
   digitalWrite (IN3, LOW); 
   delay(5000);
   */}

