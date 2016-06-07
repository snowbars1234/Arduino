#include <SPI.h>
#include <Ethernet.h>

#include <NinjaBlockEthernet.h>


#include <DHT.h>



#define DHTPIN 4     
#define DHTTYPE DHT11   
DHT dht1(DHTPIN, DHTTYPE);

#define DHTPIN 2     
#define DHTTYPE DHT22   
DHT dht(DHTPIN, DHTTYPE);
#define ENABLE_SERIAL true    


int soil=0;
void setup(){
  pinMode(5,OUTPUT);
  dht.begin();

#if ENABLE_SERIAL
  Serial.begin(9600);
  //   Serial.println("Starting..");
#endif
  delay(1000);   // This delay is to wait for

  NinjaBlock.host = "api.ninja.is";
  NinjaBlock.port = 80;
  NinjaBlock.nodeID = "ARDUINOBLOCK";  
  NinjaBlock.token = "b21fd4522558c44003ae2be1b7a327e444d53194"; 
  NinjaBlock.guid = "0";
  if (NinjaBlock.begin()==0)
    //  Serial.println("Init failed");




  }

  void loop() {

    float h1 = dht1.readHumidity();
    float t1 = dht1.readTemperature();
    float h = dht.readHumidity();
    float t = dht.readTemperature();

    NinjaBlock.guid = "0";
    NinjaBlock.deviceID=(9);
    NinjaBlock.send(t);
    delay(300);

    NinjaBlock.guid = "0";
    NinjaBlock.deviceID=(8);
    NinjaBlock.send(h);
    delay(300);

    NinjaBlock.guid = "1";
    NinjaBlock.deviceID=(9);
    NinjaBlock.send(t1);
    delay(300);

    NinjaBlock.guid = "1";
    NinjaBlock.deviceID=(8);
    NinjaBlock.send(h1);
    delay(300);

    int sensorValue = analogRead(A0);
    sensorValue = constrain(sensorValue, 485, 1023);
    soil = map(sensorValue, 485, 1023, 100, 0);
    Serial.print(soil);
    Serial.println("%"); 

    if (soil<=65){
      digitalWrite(5,HIGH);
      delay(6000);
      digitalWrite(5,LOW);
    }   
  }



