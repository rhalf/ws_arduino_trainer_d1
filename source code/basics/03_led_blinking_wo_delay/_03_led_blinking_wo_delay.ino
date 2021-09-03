uint32_t c1 = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (millis() - c1 == 100) {
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
    c1 = millis();
  }
}
