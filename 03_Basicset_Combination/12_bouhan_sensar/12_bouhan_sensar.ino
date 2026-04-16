const int touchPin = 3; //3:ConnectorA 4:ConnectorB
const int vibPin = 4; //3:ConnectorA 4:ConnectorB

bool isAlarmActive = false; // 状態を記録する変数

void setup() {
  Serial.begin(115200);
  pinMode(touchPin, INPUT);
  pinMode(vibPin, OUTPUT); // バイブレーションはOUTPUT
}

void loop() {
  // センサーが反応した、または既にアラーム状態の場合
  if (digitalRead(touchPin) == HIGH || isAlarmActive) {
    
    // 初めて検知した瞬間の処理
    if (!isAlarmActive) {
      Serial.println("【警告】侵入者を検知！バイブレーションを開始します。");
      isAlarmActive = true; 
    }
    
    // --- バイブレーションの動作 ---
    // 激しく震わせる（0.3秒おきにオンオフして目立たせる例）
    digitalWrite(vibPin, HIGH);
    delay(300);
    digitalWrite(vibPin, LOW);
    delay(100);
    
    // 確認用：シリアル表示も継続
    Serial.println("！！！警告継続中！！！");

    // 【リセット機能】
    // 警告中に再度センサーを3秒間「長押し（長遮断）」したら解除
    if (digitalRead(touchPin) == HIGH) {
      delay(3000); 
      if (digitalRead(touchPin) == HIGH) { // 3秒後もまだ遮られていたら
        isAlarmActive = false;
        digitalWrite(vibPin, LOW);
        Serial.println("--- 安全を確認。監視に戻ります ---");
        delay(2000); // 復帰直後の誤作動防止
      }
    }
  } 
  else {
    // 平常時
    digitalWrite(vibPin, LOW);
    Serial.println("異常なし");
    delay(500);
  }
}

