#include <ESP8266WiFi.h>

const char* ssid = "TP-LINK_F5A0";
const char* password = "mynet777@@";

void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);
  WiFi.begin(ssid,password);
  Serial.print("Connecting to wifi");

  while(WiFi.status()!= WL_CONNECTED){
    Serial.print(".");
    delay(500);
  }

  Serial.println("Connected to Wifi");
  Serial.print("IP addresss " );
  Serial.println(WiFi.localIP());
 
}

void loop() {
  // put your main code here, to run repeatedly:

  if((WiFi.status() == WL_CONNECTED)){
    Serial.println(" you can try to ping me");
    delay(5000);
  }
  
  
}
