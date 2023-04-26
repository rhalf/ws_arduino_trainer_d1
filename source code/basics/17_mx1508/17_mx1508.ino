uint8_t MOTOR[] = { 5, 6, 9, 10 };
uint8_t SPEED = 128;
uint8_t counter = 0;

void drive(uint8_t a1, uint8_t a2, uint8_t b1, uint8_t b2) {
  analogWrite(MOTOR[0], a1);
  analogWrite(MOTOR[1], a2);
  analogWrite(MOTOR[2], b1);
  analogWrite(MOTOR[3], b2);
}
void setup() {
}
void loop() {
  drive(SPEED, 0, 0, 0);
  delay(3000);
  drive(0, SPEED, 0, 0);
  delay(3000);
  drive(0, 0, SPEED, 0);
  delay(3000);
  drive(0, 0, 0, SPEED);
  delay(3000);
  drive(0, 0, 0, 0);
  delay(3000);
}