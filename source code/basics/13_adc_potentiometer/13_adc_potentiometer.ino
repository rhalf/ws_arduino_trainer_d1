uint8_t POT = A6;

void setup() {
  Serial.begin(9600);
}

void loop() {
  float value = analogRead(POT);
  float volts = value * (5.0 / 1024.0);
  
  Serial.println("value:" + String(value) + ", voltage:" + String(volts));
  
  delay(500);
}
