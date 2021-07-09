/*
  on v01:
    -turn On active switch
    -turn Off passive switch
  note:
    -this code would not run on passive buzzer
*/
uint8_t const BUZZER = A0;

void setup() {
  // put your setup code here, to run once:
  pinMode(BUZZER, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(BUZZER, LOW);
  delay(100);
  digitalWrite(BUZZER, HIGH);
  delay(3000);
}
