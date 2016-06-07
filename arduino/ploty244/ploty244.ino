#include <UIPEthernet.h>
#include "plotly_streaming_ethernet.h"
#include "DHT.h"


#define nTraces 2
int i;
char *tokens[nTraces] = {
  "n52pjyuspb", "63ze214eja"};
bool success;
plotly graph("pavel97", "xupdjycahy", tokens, "graph999", nTraces);


#define DHTPIN 2
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE); 

byte mac[] = { 
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
byte my_ip[] = { 
  192, 168, 1, 19 }; 


void setup() {
  Serial.begin(9600);
  graph.maxpoints = 20000 ;
  graph.timezone = "Europe/Kiev";
  Ethernet.begin(mac, my_ip);

  graph.fileopt = "extend";
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
  success = graph.init();
  if(!success){
    while(true){
    }
  }
  graph.openStream();
  dht.begin();
  delay(500);
  h = dht.readHumidity();
  t = dht.readTemperature();
  delay(500);
  graph.plot(millis(), t, tokens[0]);
  delay(500);
  graph.plot(millis(), h, tokens[1]);
  delay(750);
  delay(1200000);

  ///delay(60000);


}

