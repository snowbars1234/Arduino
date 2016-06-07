
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(2,OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);


  Serial.print(sensorValue);


  if (sensorValue<=600){
    digitalWrite(2,HIGH);
    delay(10000);

    digitalWrite(2,LOW);
  }
  delay(1000);        // delay in between reads for stability
}

