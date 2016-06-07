/*
 * created by Rui Santos, http://randomnerdtutorials.com
 * Bluetooth App - Turn On and Off LED
 */

// Pin 13 - LED
int led = 13;
int state;

void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);     
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

void loop() {
  if(Serial.available() > 0){     
    state = Serial.read();
  }

  if (state == '1') {
    digitalWrite(led, HIGH);
  }   // turn the LED on (HIGH is the voltage level)

  else if (state == '2') {
    digitalWrite(led, LOW);
  }    // turn the LED off by making the voltage LOW

    delay(100);               // wait for 100ms

  //For debugging purpose
  //Serial.println(state);
}

