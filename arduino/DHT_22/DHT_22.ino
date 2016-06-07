#include <UIPEthernet.h>
#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);
byte mac[] = { 
  0x54, 0x34, 0x41, 0x30, 0x30, 0x31 };
char server[] = "api.pushingbox.com"; 
IPAddress ip(192,168,1,18);
EthernetClient client; 
String data; 
float b; 
boolean flag = false;

void setup() {
  Serial.begin(9600);
  Ethernet.begin(mac, ip);

  delay(1000);
}

void loop(){

  b = dht.readTemperature();
  Serial.println("connecting...");
  DataForm(); 

  if (client.connect(server, 80)) {
    sendData();  
    flag = true; 
  }
  else{
    Serial.println("connection failed");
  }

  while(flag){
    if (client.available()) {
      char c = client.read(); 
      Serial.print(c);
    }
    if (!client.connected()) {
      Serial.println();
      Serial.println("disconnecting.");
      Serial.print("Temperature Sent :");
      client.stop(); 
      flag = false; 
      data = ""; 
    }
  }
  delay(5000); 
}

void DataForm(){
  data+="";
  data+="GET /pushingbox?devid=v45A030E9B94B39B&tempData="; 
  data+=b;
  data+=" HTTP/1.1";
}
void sendData(){
  Serial.println("connected");
  client.println(data);
  client.println("Host: api.pushingbox.com");
  client.println("Connection: close");
  client.println();
}


