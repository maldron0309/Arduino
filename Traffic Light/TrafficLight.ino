int red = 5, yellow = 6, green = 7;

void setup() {
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
}

void loop() {
  // Red for 10s
  digitalWrite(red, HIGH);
  delay(10000);

  // Yellow with Red for 5s
  digitalWrite(yellow, HIGH);
  delay(5000);

  // Green for 10s Red,Yellow off
  digitalWrite(red, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(green, HIGH);
  delay(10000);

  // Green blinks 10times 0.5s
  for (int i = 0; i < 10; i++) {
    digitalWrite(green, HIGH);
    delay(500);
    digitalWrite(green, LOW);
    delay(500);
  }

  // Red for 10s Green off
  digitalWrite(green, LOW);
  digitalWrite(red, HIGH);
  delay(10000);
}
