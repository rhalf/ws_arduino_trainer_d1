uint8_t const BUTTON0 = 2, BUTTON1 = 3, BUTTON2 = 4;


void setup() {
  // put your setup code here, to run once:
  pinMode(BUTTON0, INPUT_PULLUP);
  pinMode(BUTTON1, INPUT_PULLUP);
  pinMode(BUTTON2, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  buttonCallback(BUTTON0, 100);
  buttonCallback(BUTTON1, 100);
  buttonCallback(BUTTON2, 100);
}


void buttonCallback(uint8_t button, uint32_t duration) {
  if (digitalRead(button) == HIGH) return;

  while (digitalRead(button) == LOW) {
    delay(duration);
  }

  switch (button) {
    case BUTTON0:
      Serial.println("Button0 is pressed");
      break;
    case BUTTON1:
      Serial.println("Button1 is pressed");
      break;
    case BUTTON2:
      Serial.println("Button2 is pressed");
      break;
  }

}
