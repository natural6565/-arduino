#include <Servo.h>;
 
Servo servo; 
int trigPin = 12;
int echoPin = 11;
bool st1, st2, st3;
int st3_cnt;

int servoPin = 6;
int angle = 0;

void setup() {
  servo.attach(servoPin);
  
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  st1 = true;
  st2 = false;
  st3 = false;
  st3_cnt = 0;
  servo.write(30);
}

void loop() {
  String result;
  if(st1) {
    long duration, distance;
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = 17 * duration / 1000;
    
    //Serial.println(distance);
    if((distance <= 20) == true) {
      //Serial.println("1");
      Serial.println("버림");
      st2 = true;
      st1 = false;
    }
    else {
      Serial.println("0");
    }
  }
  if(st2) {
    if(Serial.available()) {
      Serial.println(Serial.read());
      Serial.read();
      Serial.println("결과 받음");
      st3 = true;
      st2 = false;
    }
  }
  
  if(st3) {
    //result에 맞게 모터 움직여서 처리
    st3_cnt++;
    if(st3_cnt<=5) {
      for(angle=30 * st3_cnt; angle < 30 * (st3_cnt + 1); angle++) {
        servo.write(angle);
        break;
        delay(3);
      }
    }
    
    Serial.println("st3");
    if (st3_cnt == 5) {
      for(angle = 180; angle > 30; angle--) {
        servo.write(angle);
        delay(3);
      }
      st1 = true;
    }
    if (st3_cnt > 9) {
      st3 = false;
      st3_cnt = 0;
    }
    delay(100);
  }
  
}
