uint8_t LM35 = A7;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  float value = (float) analogRead(LM35);
  float milliVolts = (float) value * (5000.0 / 1024.0);
  float temperature =  (float) milliVolts / 10;

  Serial.println(temperature + String("°c"));
  delay(1000);
}
