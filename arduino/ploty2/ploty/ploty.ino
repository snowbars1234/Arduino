#include <UIPEthernet.h>
#include "plotly_streaming_ethernet.h"
#include "DHT.h"


#define nTraces 2
int i, soil=0;
char *tokens[nTraces] = {
  "xqc81zsuvy", "gv6n8bxgsj"};

plotly graph("pavel97", "xupdjycahy", tokens, "graph", nTraces);


#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE); 

byte mac[] = { 
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
byte my_ip[] = { 
  192, 168, 1, 18 }; 


void setup() {

  Ethernet.begin(mac, my_ip);
  graph.maxpoints = 20000;
  graph.timezone = "Europe/Kiev";
  graph.fileopt = "extend";
  Serial.begin(9600);
  bool success;
  success = graph.init();
  if(!success){
    while(true){
    }
  }

}

float h, t;

void loop() {
  graph.openStream();
  dht.begin();
  delay(500);
  h = dht.readHumidity();
  t = dht.readTemperature();
  graph.plot(millis(), t, tokens[0]);
  graph.plot(millis(), h, tokens[1]);
  delay(1000);
  delay(30000);
}


