const int swPin = 3; //3:ConnectorA 4:ConnectorB
const int vibPin = 4; //3:ConnectorA 4:ConnectorB

bool swState = 0;

void setup() {
  Serial.begin(115200);
  pinMode(swPin, INPUT);
  pinMode(vibPin, OUTPUT);
}

void loop() {
  
  if (digitalRead(swPin) == HIGH) {
    swState = !swState;
  }

  if(swState == 1){
    //Look at the serial monitor
    digitalWrite(vibPin, HIGH);
    Serial.println("ON");
    delay(300);
  } else {
    digitalWrite(vibPin, LOW);
    Serial.println("OFF");
    delay(300);
  }

}
