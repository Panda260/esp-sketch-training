void setup() {

Serial.begin(9600);
}

void loop() {

int sensorValue = analogRead(A0);

Serial.println(sensorValue);

delay(100); // delay in between reads for stability
}