const int RED_LED = 5;
const int YELLOW_LED = 6;
const int GREEN_LED = 7;

void setup() {
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    char input = Serial.read();
    controlLED(input);
  }
}

void controlLED(char input) {
  int ledPin = -1;
  switch (input) {
    case 'A': ledPin = RED_LED; break;
    case 'B': ledPin = RED_LED; break;
    case 'C': ledPin = YELLOW_LED; break;
    case 'D': ledPin = YELLOW_LED; break;
    case 'E': ledPin = GREEN_LED; break;
    case 'F': ledPin = GREEN_LED; break;
    default: return;
  }
  setLEDState(ledPin, input % 2 == 0 ? LOW : HIGH);
}

void SetLEDState(int pin, int state) {
  digitalWrite(pin, state);
}
