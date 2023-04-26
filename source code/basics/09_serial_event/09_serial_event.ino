uint8_t const RGB[] = { 10, 11, 9 };

void rgb(uint8_t r, uint8_t g, uint8_t b) {
  analogWrite(RGB[0], r);
  analogWrite(RGB[1], g);
  analogWrite(RGB[2], b);
}

void setup() {
  Serial.begin(9600);
}

void loop() {}

void serialEvent() {
  char c = (char)Serial.read();
  if (c == 'r')
    rgb(255, 0, 0);
  if (c == 'g')
    rgb(0, 255, 0);
  if (c == 'b')
    rgb(0, 0, 255);
  if (c == 'w')
    rgb(255, 255, 255);
  if (c == 'c')
    rgb(0, 0, 0);
}
