const int BTN_PINS[] = {5, 6, 7};
const int NUM_BTNS = 3;
int btnState[NUM_BTNS];
int lastBtnState[NUM_BTNS];


void checkButtonState() {
  for (int i = 0; i < NUM_BTNS; i++) {
    int reading = digitalRead(BTN_PINS[i]);
    if (reading != lastBtnState[i]) {
      if (reading == HIGH) {
        Serial.println(i); 
      }
      lastBtnState[i] = reading;
    }
  }
}

void setup() {
  Serial.begin(9600); 
  

  for (int i = 0; i < NUM_BTNS; i++) {
    pinMode(BTN_PINS[i], INPUT);
    lastBtnState[i] = LOW;
  }
}

void loop() {
  
  checkButtonState();
 
  delay(50);
}
