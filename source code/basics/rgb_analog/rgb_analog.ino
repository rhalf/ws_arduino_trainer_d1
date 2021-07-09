uint8_t const RGB[] = {9, 10, 11};

void setup() {

}

void loop() {

  for (uint8_t index = 0; index < 255; index++) {
    analogWrite(RGB[0], index);
    delay(20);
  }
  analogWrite(RGB[0], 0);

  for (uint8_t index = 0; index < 255; index++) {
    analogWrite(RGB[1], index);
    delay(20);
  }
  analogWrite(RGB[1], 0);

  for (uint8_t index = 0; index < 255; index++) {
    analogWrite(RGB[2], index);
    delay(20);
  }
  analogWrite(RGB[2], 0);

  for (uint8_t index = 0; index < 255; index++) {
    analogWrite(RGB[0], index);
    analogWrite(RGB[1], index);
    analogWrite(RGB[2], index);
    delay(20);
  }
  
  analogWrite(RGB[2], 0);
  analogWrite(RGB[1], 0);
  analogWrite(RGB[2], 0);

}
