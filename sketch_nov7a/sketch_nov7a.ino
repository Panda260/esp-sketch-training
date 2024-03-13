		void setup(){ //Wir starten mit dem Setup 
			pinMode(33, OUTPUT); // Pin 33 ist ein Ausgang. 
			pinMode(32, OUTPUT); // Pin 32 ist ein Ausgang. 
      pinMode(22, OUTPUT);
		}
		
		void loop(){ // Das Hauptprogramm beginnt. 
			digitalWrite(33, HIGH);  
			delay(5000); //grün
			digitalWrite(33, LOW); 
			digitalWrite(32, HIGH);
			delay(1000); //gelb
			digitalWrite(32, LOW);
      digitalWrite(22, HIGH);
			delay(5000); //rot 
			digitalWrite(22, LOW);
      digitalWrite(32, HIGH); //gelb 
			delay(1000); //gelb
			digitalWrite(32, LOW); //gelb
		}