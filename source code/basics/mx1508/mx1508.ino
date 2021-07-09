uint8_t MOTOR_A1 = 5, MOTOR_A2 = 6, MOTOR_B1 = 9, MOTOR_B2 = 10, SPEED = 50;
uint8_t counter = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(MOTOR_A2, OUTPUT);
  pinMode(MOTOR_B2, OUTPUT);
  analogWrite(MOTOR_A1, 0);
  analogWrite(MOTOR_A2, 0);
  analogWrite(MOTOR_B1, 0);
  analogWrite(MOTOR_B2, 0);
}

void loop() {
  // put your main code here, to run repeatedly:
  uint8_t speed = 128;

  uint8_t selector = counter % 4;

  if (selector == 0) {
    analogWrite(MOTOR_A1, speed);
    analogWrite(MOTOR_A2, 0);
    analogWrite(MOTOR_B1, 0);
    analogWrite(MOTOR_B2, 0);
  }

  if (selector == 1) {
    analogWrite(MOTOR_A1, 0);
    analogWrite(MOTOR_A2, speed);
    analogWrite(MOTOR_B1, 0);
    analogWrite(MOTOR_B2, 0);
  }
  if (selector == 2) {
    analogWrite(MOTOR_A1, 0);
    analogWrite(MOTOR_A2, 0);
    analogWrite(MOTOR_B1, speed);
    analogWrite(MOTOR_B2, 0);
  }
  if (selector == 3) {
    analogWrite(MOTOR_A1, 0);
    analogWrite(MOTOR_A2, 0);
    analogWrite(MOTOR_B1, 0);
    analogWrite(MOTOR_B2, speed);
  }


  delay(3000);
  counter++;
}
