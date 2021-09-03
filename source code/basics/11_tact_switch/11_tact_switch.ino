uint8_t BUTTON0 = 2, BUTTON1 = 3, BUTTON2 = 4;

void setup() {
  // put your setup code here, to run once:
  pinMode(BUTTON0, INPUT_PULLUP);
  pinMode(BUTTON1, INPUT_PULLUP);
  pinMode(BUTTON2, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(BUTTON0) == LOW)
    Serial.println("Button0 is pressed");
  if (digitalRead(BUTTON1) == LOW) 
    Serial.println("Button1 is pressed");
  if (digitalRead(BUTTON2) == LOW) 
    Serial.println("Button2 is pressed");
}
