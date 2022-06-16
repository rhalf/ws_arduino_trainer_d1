//Blue, Red, Green
const uint8_t RGB[] = { 9, 10, 11 };
void setup() {}
void loop() {
  // Green - Go 7 seconds
  analogWrite(RGB[0], 0);
  analogWrite(RGB[1], 0);
  analogWrite(RGB[2], 255);
  delay(7000);
  // Amber - Ready 3 seconds
  analogWrite(RGB[0], 0);
  analogWrite(RGB[1], 192);
  analogWrite(RGB[2], 48);
  delay(3000);
  // Red - Stop 10 seconds
  analogWrite(RGB[0], 0);
  analogWrite(RGB[1], 255);
  analogWrite(RGB[2], 0);
  delay(10000);
}
