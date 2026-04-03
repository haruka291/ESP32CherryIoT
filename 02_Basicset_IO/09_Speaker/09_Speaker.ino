const int spkrPin = 3; //3:ConnectorA 4:ConnectorB

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
#define TI 493.883
#define octDO 523.251


void playmusic(){
  // き(ド)
  ledcWriteTone(spkrPin, DO);
  delay(350);
  ledcWriteTone(spkrPin, 0); delay(50); // 音の切れ目

  // ら(ド)
  ledcWriteTone(spkrPin, DO);
  delay(350);
  ledcWriteTone(spkrPin, 0); delay(50);

  // き(ソ)
  ledcWriteTone(spkrPin, SO);
  delay(350);
  ledcWriteTone(spkrPin, 0); delay(50);

  // ら(ソ)
  ledcWriteTone(spkrPin, SO);
  delay(350);
  ledcWriteTone(spkrPin, 0); delay(50);

  // ひ(ラ)
  ledcWriteTone(spkrPin, RA);
  delay(350);
  ledcWriteTone(spkrPin, 0); delay(50);

  // か(ラ)
  ledcWriteTone(spkrPin, RA);
  delay(350);
  ledcWriteTone(spkrPin, 0); delay(50);

  // る(ソ〜)
  ledcWriteTone(spkrPin, SO);
  delay(750); // 最後の音は2倍の長さで伸ばす
  
  // 次のフレーズへの間（無音）
  ledcWriteTone(spkrPin, 0); 
  delay(400);
  }

void setup() {
  pinMode(spkrPin, OUTPUT);
  ledcAttach(spkrPin, 12000, 8); //Pin setting(Pin num, Max frequency, Resolution)
}

void loop() {
  playmusic();
  delay(3000);
}
