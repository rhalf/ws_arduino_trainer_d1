uint8_t LDR = A6;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  float value = analogRead(LDR);
  float volts = value * (5.0 / 1024.0);
  
  Serial.print(value);
  Serial.print(", ");
  Serial.print(volts);
  Serial.println(" volts");
  
  delay(500);
}
