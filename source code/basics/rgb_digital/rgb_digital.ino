uint8_t const RGB[] = {9, 10, 11};

void setup() {
  pinMode(RGB[0], OUTPUT);
  pinMode(RGB[1], OUTPUT);
  pinMode(RGB[2], OUTPUT);
}

void loop() {

  digitalWrite(RGB[0], HIGH);
  delay(1000);
  digitalWrite(RGB[0], LOW);

  digitalWrite(RGB[1], HIGH);
  delay(1000);
  digitalWrite(RGB[1], LOW);

  digitalWrite(RGB[2], HIGH);
  delay(1000);
  digitalWrite(RGB[2], LOW);

  digitalWrite(RGB[0], HIGH);
  digitalWrite(RGB[1], HIGH);
  digitalWrite(RGB[2], HIGH);
  delay(1000);
  digitalWrite(RGB[0], LOW);
  digitalWrite(RGB[1], LOW);
  digitalWrite(RGB[2], LOW);


}
