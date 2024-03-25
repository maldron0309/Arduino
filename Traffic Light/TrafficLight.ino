int red = 5, yellow = 6, green = 7;

void setup() {
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
}

void loop() {
  // red 10 sc 
  digitalWrite(red, HIGH);
  delay(10000);

  // yellow red 5sc
  digitalWrite(yellow, HIGH);
  delay(5000);

  // yellow off green on 10sc
  digitalWrite(yellow, LOW);
  digitalWrite(green, HIGH);
  delay(10000);

  // green 0.5sc 10
  for (int i = 0; i < 10; i++) {
    digitalWrite(green, HIGH);
    delay(500);
    digitalWrite(green, LOW);
    delay(500);
  }

  // green off 
  digitalWrite(green, LOW);
  digitalWrite(red, HIGH);
  delay(10000);
}
