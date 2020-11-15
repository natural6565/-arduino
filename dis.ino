int trigPin = 12;
int echoPin = 11;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = 17 * duration / 1000;
  
  if(distance <= 20) {
    String result;
    Serial.println("1");
    Serial.println("버림");
    while(!(Serial.available())) {
      delay(50);
    }
      result = Serial.read();
      Serial.println(Serial.read());
    Serial.println("결과 받음");
    //result에 맞게 모터 움직여서 처리
    delay(1000);
  }
  else {
    Serial.println("0");
    delay(10);
  }

//  Serial.print("Duration: ");
//  Serial.print(duration);
  Serial.print("\nDIstance: ");
  Serial.print(distance);
  Serial.print("cm\n");

  delay(100);
}
