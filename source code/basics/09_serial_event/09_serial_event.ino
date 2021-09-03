boolean flag = false;
String data = "";

void setup() {
  // put your setup code here, to run once:        
  Serial.begin(9600);
  Serial.println("Enter anything :");
}
void loop() {
  // put your setup code here, to run once:        
  if (flag) {
    Serial.print("data : ");
    Serial.println(data);
    data = "";
    flag = false;
  }
}
void serialEvent() {              
  while (Serial.available()) {
    char c = (char)Serial.read();
    if (c == '\n') flag = true;
    else data += c;
  }
}
