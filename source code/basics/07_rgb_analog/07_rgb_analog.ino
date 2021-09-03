uint8_t const RGB[] = {9, 10, 11};

void setup() {}

void loop() {
  for (uint8_t i = 0; i < 255; i++) {
    analogWrite(RGB[0], i);
    delay(20);
  }
  analogWrite(RGB[0], 0);

  for (uint8_t i = 0; i < 255; i++) {
    analogWrite(RGB[1], i);
    delay(20);
  }
  analogWrite(RGB[1], 0);

  for (uint8_t i = 0; i < 255; i++) {
    analogWrite(RGB[2], i);
    delay(20);
  }
  analogWrite(RGB[2], 0);

  for (uint8_t i = 0; i < 255; i++) {
    analogWrite(RGB[0], i);
    analogWrite(RGB[1], i);
    analogWrite(RGB[2], i);
    delay(20);
  }
  
  analogWrite(RGB[2], 0);
  analogWrite(RGB[1], 0);
  analogWrite(RGB[2], 0);
}
