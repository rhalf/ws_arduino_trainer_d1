uint8_t LM35 = A7;

void setup() {
  Serial.begin(9600);
}

void loop() {
  float value = (float) analogRead(LM35);
  float milliVolts = (float) value * (5000.0 / 1024.0);
  
  float temperature =  (float) milliVolts / 10;

  //alt0176
  Serial.println(String(value)+ "," + String(temperature) + String("°c"));

  if (temperature > 31.0) Serial.println("You are so hot.");

  delay(500);
}
