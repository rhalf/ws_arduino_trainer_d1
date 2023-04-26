uint8_t BUTTON0 = 2, BUTTON1 = 3, BUTTON2 = 4;

void setup() {
  pinMode(BUTTON0, INPUT_PULLUP);
  pinMode(BUTTON1, INPUT_PULLUP);
  pinMode(BUTTON2, INPUT_PULLUP);
  Serial.begin(9600);
}

void read(uint8_t button, uint16_t time) {
  if (digitalRead(button) == LOW) {
    while (digitalRead(button) == LOW)
      delay(time);
    Serial.println("Button pin " + String(button) + " is pressed");
  }
}

void loop() {
  read(BUTTON0, 100);
  read(BUTTON1, 100);
  read(BUTTON2, 100);
}
