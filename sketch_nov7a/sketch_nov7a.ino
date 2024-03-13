int eingang= A0; //Das Wort „eingang“ steht jetzt für den Wert „A0“ (Bezeichnung vom Analogport 0)
int LED = 33; //Das Wort „LED“ steht jetzt für den Wert D5
int sensorwert = 0; //Variable für den Sensorwert mit 0 als Startwert

void setup() //Hier beginnt das Setup.
{
pinMode (LED, OUTPUT); //Der Pin mit der LED (Pin D5) ist jetzt ein Ausgang.
}

void loop()
{
sensorwert =analogRead(eingang); //Die Spannung am Drehregler wird auslesen und wie im vorherigen Sketch als Zahl zwischen 0 und 1023 unter der Variable „sensorwert“ gespeichert.
digitalWrite (LED, HIGH); //Die LED wird eingeschaltet
delay (sensorwert); //Die LED bleibt für so viele Millisekunden eingeschaltet, wie der Wert von „sensorwert“ es gespeichert hat
digitalWrite (LED, LOW); //Die LED wird ausgeschaltet
delay (sensorwert); //Die LED bleibt für so viele Millisekunden ausgeschaltet, wie der Wert von „sensorwert“ es gespeichert hat.
}
//Der Loop-Teil wird nun erneut gestartet. Wenn sich der Wert des ausgelesenen Drehreglers ändert, dann ändert sich auch die Zeit zwischen den Ein- und Aus-Phasen der LED. Das Blinken wird dadurch schneller und langsamer. Das längst
