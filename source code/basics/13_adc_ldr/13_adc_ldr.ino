uint8_t LDR = A6;

void setup() {
  Serial.begin(9600);
}

void loop() {
  float value = analogRead(LDR);
  float volts = value * (5.0 / 1024.0);
  
  Serial.print(value);
  Serial.print(", ");
  Serial.print(volts);
  Serial.println(" volts");
  

  if (volts > 0.75){
    Serial.println("Trigger");
  }

  delay(500);
}
