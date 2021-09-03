/*
* PWM - Pulse Width Modulation
* UNO - pins 3, 5, 6, 9, 10, and 11
* MEGA - pins pins 2 - 13 and 44 - 46
*/
void setup() {
  // put your setup code here, to run once:  
  pinMode(10, OUTPUT);
}

void loop() {
  for (int value = 255; value > 0; value--) {
    analogWrite(11, value);
    delay(5);
  }
}
