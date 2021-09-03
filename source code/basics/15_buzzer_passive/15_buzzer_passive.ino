/*  
  on v01:
    -turn Off active switch
    -turn On passive switch
  note:
    -this code would run on both passive and active buzzer
*/
uint8_t const BUZZER = A0;

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  tone(BUZZER, 2048, 100);
  delay(100);
  noTone(BUZZER);
  delay(3000);
}
