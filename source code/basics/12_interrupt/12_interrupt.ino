// BOARD DIGITAL PINS USABLE FOR INTERRUPTS
// Uno, Nano, Mini, other 328-based
// INT0 = 2, INT1 = 3
// Mega, Mega2560, MegaADK
// INT0 = 2, INT1 = 3, INT2 = 21, INT3 = 20,
// INT4 = 19, INT5 = 18
const uint8_t INTERRUPT0 = 0, INTERRUPT1 = 1;
const uint8_t LED1 = 10, LED2 = 11;
void toggle1() {
  digitalWrite(LED1, !digitalRead(LED1));
  delay(250);
}
void toggle2() {
  digitalWrite(LED2, !digitalRead(LED2));
  delay(250);
}
void setup() {              
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  attachInterrupt(INTERRUPT0, toggle1, RISING);
  attachInterrupt(INTERRUPT1, toggle2, FALLING);
}
void loop() {}
