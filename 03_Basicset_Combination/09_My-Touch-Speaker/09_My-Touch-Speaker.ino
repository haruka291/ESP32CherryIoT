const int touchPin = 3; //3:ConnectorA 4:ConnectorB
const int spkrPin  = 4; //3:ConnectorA 4:ConnectorB

#define DO 261.6
#define _DO 277.18
#define RE 293.665
#define _RE 311.127
#define MI 329.63
#define FA 349.228
#define _FA 369.994
#define SO 391.995
#define _SO 415.305
#define RA 440
#define _RA 466.164
#define SI 493.9
#define octDO 523.251


void playmusic(){
  ledcWriteTone(spkrPin, MI); 
  delay(350);
  ledcWriteTone(spkrPin, 0);  delay(50);
  ledcWriteTone(spkrPin, MI); delay(350);
  ledcWriteTone(spkrPin, 0);  delay(50);
  ledcWriteTone(spkrPin, FA); delay(350);
  ledcWriteTone(spkrPin, 0);  delay(50);
  ledcWriteTone(spkrPin, SO); delay(350);
  ledcWriteTone(spkrPin, 0);  delay(50);
}


void setup() {
  Serial.begin(115200);
  pinMode(touchPin, INPUT);
  pinMode(spkrPin, OUTPUT);
  ledcAttach(spkrPin, 12000, 8); //Pin setting(Pin num, Max frequency, Resolution)
}

void loop() {
  if (digitalRead(touchPin) == HIGH) {
    Serial.println("Touch!");
    playmusic();
  } else {
    Serial.println("...");
  }
  delay(500);

}