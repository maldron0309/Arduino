#include <LiquidCrystal.h>

const int rs = 4, en = 6, d4 = 10, d5 = 11, d6 = 12, d7 = 13;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


const int buzzerPin = 3;


void displayCountdown() {
  for (int i = 9; i >= 0; i--) {
    lcd.setCursor(3, 0);
    lcd.print("COUNTDOWN");
    lcd.setCursor(3, 1);
    lcd.print("Number = ");
    lcd.print(i);
    delay(1000);
    lcd.clear();
  }
}


void displayEndMessage() {
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("BOOM! Fire!");
  delay(2000);
  lcd.clear();
  lcd.setCursor(5, 0);
  lcd.print("The End");
  delay(2000);
}


void emergencyAlert() {
  for (int i = 0; i < 4; i++) {
    tone(buzzerPin, 1000);
    lcd.setCursor(3, 0);
    lcd.print("Emergency!");
    lcd.setCursor(2, 1);
    lcd.print("Program Class");
    delay(500);
    noTone(buzzerPin);
    lcd.clear();
    delay(500);
  }
}

void setup() {
  // Initialize the LCD and buzzer pin
  lcd.begin(16, 2);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  displayCountdown();
  displayEndMessage();
  emergencyAlert();
}
