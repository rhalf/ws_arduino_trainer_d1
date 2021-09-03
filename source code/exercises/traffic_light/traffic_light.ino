//Red, Green, Blue
const uint8_t RGB[] = { 9, 10, 11 };
void setup() {
  // put your setup code here, to run once:
  for (uint8_t index = 0; index < sizeof(RGB); index++)
    pinMode(RGB[index], OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(RGB[0], 0);
  analogWrite(RGB[1], 0);
  analogWrite(RGB[2], 255);
  delay(7000);

  analogWrite(RGB[0], 0);
  analogWrite(RGB[1], 192);
  analogWrite(RGB[2], 48);
  delay(3000);

  analogWrite(RGB[0], 0);
  analogWrite(RGB[1], 255);
  analogWrite(RGB[2], 0);
  delay(10000);
}
