uint32_t c1 = 0;
uint8_t timeDelay = 100;
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  if (millis() - c1 > timeDelay) {
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
    c1 = millis();
  }
}
