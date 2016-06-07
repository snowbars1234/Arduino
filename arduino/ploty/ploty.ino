#include <UIPEthernet.h>
#include "plotly_streaming_ethernet.h"
#include "DHT.h"


#define nTraces 2
int i, soil=0;
char *tokens[nTraces] = {
  "xqc81zsuvy", "gv6n8bxgsj"};

plotly graph("pavel97", "xupdjycahy", tokens, "graph", nTraces);


#define DHTPIN 2
#define DHTTYPE DHT22 
DHT dht(DHTPIN, DHTTYPE); 

byte mac[] = { 
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
byte my_ip[] = { 
  192, 168, 1, 18 }; 


void setup() {
  pinMode(3,OUTPUT);
  Ethernet.begin(mac, my_ip);
  graph.maxpoints = 48384;
  graph.timezone = "Europe/Kiev";
  Serial.begin(9600);
  bool success;
  success = graph.init();
  if(!success){
    while(true){
    }
  }
  graph.openStream();
  dht.begin();
}

float h, t;

void loop() {
  h = dht.readHumidity();
  t = dht.readTemperature();
  graph.plot(millis(), t, tokens[0]);
  graph.plot(millis(), h, tokens[1]);
  for (i = 1 ; i < 600 ; i++) {
    int sensorValue = analogRead(A0);
    sensorValue = constrain(sensorValue, 485, 1023);


    soil = map(sensorValue, 485, 1023, 100, 0);


    Serial.print(soil);
    Serial.println("%");

    if (soil<=60){
      digitalWrite(3,HIGH);
      delay(6000);
      digitalWrite(3,LOW);

    }
    delay(100);
  }
}

