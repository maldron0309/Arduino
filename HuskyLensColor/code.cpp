#include "HUSKYLENS.h"

HUSKYLENS huskylens; // 허스키렌즈 객체 생성

void printResult(HUSKYLENSResult result); 

int red = 5, yellow = 6, green = 7; 

void setup() {
  Serial.begin(9600);
  pinMode(red, OUTPUT); 
  pinMode(yellow, OUTPUT); 
  pinMode(green, OUTPUT); 
  Wire.begin(); 
  delay(100); 
}

void loop() {
  if (!huskylens.request()) {} // 허스키렌즈 데이터 요청
  else if (!huskylens.available()) { 
    // 데이터가 없을 경우 모든 LED 끄기
    digitalWrite(red, LOW);
    digitalWrite(yellow, LOW);
    digitalWrite(green, LOW);
  }
  else {
    Serial.println(F("###########")); 
    while (huskylens.available()) {
      HUSKYLENSResult result = huskylens.read(); // 허스키렌즈 데이터 읽기
      printResult(result); 
    }
  }
}

void printResult(HUSKYLENSResult result) {
  if (result.command == COMMAND_RETURN_BLOCK) { 
    // 감지된 객체 ID에 따라 LED 제어
    switch (result.ID) {
      case 1:  // RED
        digitalWrite(red, HIGH); 
        digitalWrite(yellow, LOW); 
        digitalWrite(green, LOW); 
        break;
      case 2:  // YELLOW
        digitalWrite(red, LOW); 
        digitalWrite(yellow, HIGH);
        digitalWrite(green, LOW); 
        break;
      case 3:  // GREEN
        digitalWrite(red, LOW); 
        digitalWrite(yellow, LOW); 
        digitalWrite(green, HIGH); 
        break;
      default:
        digitalWrite(red, LOW);
        digitalWrite(yellow, LOW);
        digitalWrite(green, LOW);
        break;
    }
  }
}
