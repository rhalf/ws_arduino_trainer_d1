const uint8_t RGB[] = { 9, 10, 11 };

void setup() {
  pinMode(RGB[0], OUTPUT);
  pinMode(RGB[1], OUTPUT);
  pinMode(RGB[2], OUTPUT);
}
void rgb(bool r, bool g, bool b) {
  digitalWrite(RGB[0], r);
  digitalWrite(RGB[1], g);
  digitalWrite(RGB[2], b);
}
void loop() {
  rgb(LOW, LOW, LOW);
  delay(1000);
  rgb(HIGH, LOW, LOW);
  delay(1000);
  rgb(LOW, HIGH, LOW);
  delay(1000);
  rgb(LOW, LOW, HIGH);
  delay(1000);
  rgb(HIGH, HIGH, HIGH);
  delay(1000);
}
