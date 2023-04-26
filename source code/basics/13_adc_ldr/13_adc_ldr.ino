const uint8_t LDR = A6;

void setup() {
  Serial.begin(9600);
}

void loop() {
  float value = analogRead(LDR);
  float volts = value * (5.0 / 1024.0);

  Serial.println("value:" + String(value) + ", voltage:" + String(volts));

  if (volts > 0.75)
    Serial.println("Triggerred by light");

  delay(250);
}
