//PWM - Pulse Width Modulation
//UNO - pins 3, 5, 6, 9, 10, and 11
//MEGA - pins 2 - 13 and 44 - 46
void setup() {
  // put your main code here, to run repeatedly:  
  pinMode(9, OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:  
  for (uint8_t v = 0; v < 255; v++) {
    analogWrite(9, v);
    delay(5);
  }
}
