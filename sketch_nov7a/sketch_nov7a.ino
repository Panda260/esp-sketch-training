void setup() {
  pinMode(32, OUTPUT);
  pinMode(33, OUTPUT);
}
void loop() {
  digitalWrite(32, HIGH);
  digitalWrite(33, HIGH);
  delay(500);
  digitalWrite(32, LOW);
  digitalWrite(33, LOW);
  delay(500);
}