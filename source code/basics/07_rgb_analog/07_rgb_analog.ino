uint8_t const RGB[] = { 10, 11, 9 };

void rgb(uint8_t r, uint8_t g, uint8_t b) {
  analogWrite(RGB[0], r);
  analogWrite(RGB[1], g);
  analogWrite(RGB[2], b);
}

void setup() {}

void loop() {
  rgb(0xFF, 0x00, 0x00); //Red
  delay(7000);
  rgb(0x00, 0xFF, 0x00); //Green
  delay(4000);
  rgb(0xD0, 0x20, 0x00); //Amber
  delay(3000);
}
