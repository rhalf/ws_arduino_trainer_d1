uint8_t BUTTON0 = 2, BUTTON1 = 3, BUTTON2 = 4;

void setup() {
  pinMode(BUTTON0, INPUT_PULLUP);
  pinMode(BUTTON1, INPUT_PULLUP);
  pinMode(BUTTON2, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(BUTTON0) == LOW)
    Serial.println("Button0 is pressed");
  if (digitalRead(BUTTON1) == LOW) 
    Serial.println("Button1 is pressed");
  if (digitalRead(BUTTON2) == LOW) 
    Serial.println("Button2 is pressed");
}
