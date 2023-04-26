/*
  on v01:
    -turn On active switch
    -turn Off passive switch
  note:
    -this code would not run on passive buzzer
*/I can 
uint8_t const BUZZER = A0;

void setup() {
  pinMode(BUZZER, OUTPUT);

}

void loop() {
  digitalWrite(BUZZER, LOW);
  delay(100);
  digitalWrite(BUZZER, HIGH);
  delay(3000);
}
