const int LED_PINS[] = {5, 6, 7};
const int NUM_LEDS = 3;
const int BLINK_DELAY = 500; 


void toggleLED(int pin) {
  digitalWrite(pin, HIGH);
  delay(BLINK_DELAY);
  digitalWrite(pin, LOW);
}


void setup() {
  Serial.begin(9600);
  

  for (int i = 0; i < NUM_LEDS; i++) {
    pinMode(LED_PINS[i], OUTPUT);
  }
}


void loop() {
  if (Serial.available() > 0) {
    int btnNum = Serial.read() - '0';
    if (btnNum >= 0 && btnNum < NUM_LEDS) {
      toggleLED(LED_PINS[btnNum]);
    }
  }
}
