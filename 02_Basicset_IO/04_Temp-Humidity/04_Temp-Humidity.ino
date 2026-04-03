#include <DHT20.h> //DHT20 by RobTillaart
#include <Wire.h>

DHT20 DHT;

void setup() {
  Serial.begin(115200);
  Wire.begin(1, 3); //1,3:ConnectorA 5,4:ConnectorB
}

void loop() {
  DHT.read();
  float Temperature = DHT.getTemperature();//温度
  float Humidity = DHT.getHumidity();      //湿度
  //Look at the serial monitor
  Serial.print(String(Temperature) + "℃");
  Serial.print(" / ");
  Serial.println(String(Humidity) + "％");
  delay(500);
}