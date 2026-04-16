const int ruptPin = 3; //3:ConnectorA 4:ConnectorB
const int vibPin = 4; //3:ConnectorA 4:ConnectorB

int count = 0;

void setup() {
  pinMode(ruptPin, INPUT);
  Serial.begin(115200);
  pinMode(vibPin, OUTPUT);
}

void loop() {
  if (digitalRead(ruptPin)==LOW) {
    Serial.println("Interrupt!");
    delay(500);
  }
  if (count < 5){
  digitalWrite(vibPin, HIGH);
  delay(3000);
  digitalWrite(vibPin, LOW);
  delay(2000);
  
}
}