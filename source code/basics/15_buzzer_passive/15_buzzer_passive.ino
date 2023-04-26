uint8_t const BUZZER = A0;

void setup() {}

void loop() {
  tone(BUZZER, 2048, 100);
  delay(100);
  noTone(BUZZER);
  delay(3000);
}
