//PWM - Pulse Width Modulation
//UNO - pins 3, 5, 6, 9, 10, and 11
//MEGA - pins 2 - 13 and 44 - 46
void setup() {}

void loop() {
  for (uint8_t v = 0; v < 255; v++) {
    analogWrite(11, v);
    delay(1);
  }
  for (uint8_t v = 255; v > 0; v--) {
    analogWrite(11, v);
    delay(2);
  }
}
