const int swPin = 3; //3:ConnectorA 4:ConnectorB
const int vibPin = 4; //3:ConnectorA 4:ConnectorB

unsigned long pressStartTime = 0; //押し始めた時刻を記録する
const int longPressThreshold = 2000;//　1秒以上で長押しと判定

int mode = 0;// (0:平常時、1.警戒中、2非常事態)の3つのモードを覚えておく

void setup() {
  Serial.begin(115200);
  pinMode(swPin, INPUT);
  pinMode(vibPin, OUTPUT);
  Serial.println("システム起動：平常時");
}

void loop() {
//スイッチの判定
  //もしスイッチが押されて（HIGH）、かつ、まだ押し始めた時刻をメモされていない
  if (digitalRead(swPin) == HIGH && pressStartTime == 0) {
    pressStartTime = millis(); //この瞬間の時刻をメモする
  }
  
  //もしスイッチが離されていて(LOW)、 かつ、押し始めた時刻がメモされていたら 
  if(digitalRead(swPin) == LOW && pressStartTime != 0){//!=0は0ではないという意味
  //引き算する　今の時間ー押し始めた時間　= 押し続けていた合計時間
    unsigned long duration = millis() - pressStartTime;

    if(duration >= longPressThreshold){//合計時間が1秒以上だった場合:長押し
      if (mode == 2) mode = 0;//すでに非常事態なら平常時へ移行
      else mode = 2; //それ以外なら非常事態モードへ 
      }
    else if(duration > 50){//合計時間が0.05秒から1秒未満だった場合:短押し
      if(mode == 1) mode = 0;//すでに警戒中なら平常時へ
      else mode = 1;//それ以外なら警戒中モードへ
    }
    pressStartTime = 0;//離されたので、メモをリセットして次の押しはじめを待つ
  }
//2.モードに応じた動作
  if(mode == 1){//モード1:警戒中:短押し
    digitalWrite(vibPin, HIGH);
    Serial.println("警戒中");
    delay(300);
  } 
  else if(mode == 2){//モード2:非常事態:長押し
    Serial.println("非常事態");
    digitalWrite(vibPin, HIGH);
    delay(100);
    digitalWrite(vibPin, LOW);
    delay(100);
  }
  else{//モード0:平常時
    digitalWrite(vibPin, LOW);
    Serial.println("平常時");
    delay(500);
  }
  
}

