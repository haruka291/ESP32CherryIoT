const int trigPin = 3; //3:ConnectorA 4:ConnectorB
const int echoPin = 1; //1:ConnectorA 5:ConnectorB

float Duration = 0; //Received Interval Time
float Distance = 0; //Calculation results from Duration

#include <ESP32Servo.h> //ESP32Servo by Kevin Harrington

const int motorPin = 4; //3:ConnectorA 4:ConnectorB

Servo myservo;
int angle = 0; // 現在のサーボの角度を保存する
  
void setup() {
  Serial.begin(115200);
  pinMode(echoPin,INPUT);
  pinMode(trigPin,OUTPUT);

  myservo.attach(motorPin);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); //Ultrasonic output
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  Duration = pulseIn(echoPin, HIGH); //Input from sensor
  Duration = Duration/2; //Half the round trip time
  Distance = Duration*340*100/1000000; //Set sonic speed to 340 m/s

  //Look at the serial monitor
  Serial.print(Distance);
  Serial.print("cm");
  Serial.println(":Distance");
  delay(500);
if (Distance < 20) {
  // 0-180 right
  for(angle ; angle <= 180; angle++) {                        
    myservo.write(angle);
    delay(15);
  }
  } 
  else {
  // 180-0  left 
  for(angle ; angle >= 0; angle--) {                 
    myservo.write(angle);  
    delay(15);      
  }
}
// 4. 最後に少しだけ待機（反応を良くするため短めにするのがコツ）
  delay(100); 
}

