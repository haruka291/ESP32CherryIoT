const int swPin = 3;
const int vibPin = 4;

int count = 0;

void setup() {
  Serial.begin(115200);
  pinMode(swPin, INPUT);
  pinMode(vibPin, OUTPUT);
}

void loop() {
  if (digitalRead(swPin) == HIGH) {
    count++;
    Serial.println(count);

    if (count > 1000) {
      Serial.println("非常事態");
      digitalWrite(vibPin, HIGH);
      delay(50);
      digitalWrite(vibPin, LOW);
      delay(50);
    } 
    else if (count > 500) {
      Serial.println("警告中");
      digitalWrite(vibPin, HIGH);
    }
    delay(1);
  } 
  
  else {
    if (count > 0) {
      Serial.println("平常時");
      digitalWrite(vibPin, LOW);

    }
    
    count = 0;

  
  }
}