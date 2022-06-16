uint32_t c1 = 0;
uint8_t timeDelay = 100;
void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (millis() - c1 > timeDelay) {
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
    c1 = millis();
  }
}
