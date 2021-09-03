void setup() {
  // put your setup code here, to run once:      
  Serial.begin(9600);
  Serial.println("Enter anything :");
}
void loop() {
  // put your main code here, to run repeatedly:      
  char data[20];
  if (Serial.available()) {
    Serial.readBytesUntil('\n', data, sizeof(data));
    Serial.print("data : ");
    Serial.print(data);
    Serial.println();
  }
}