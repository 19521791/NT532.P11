int LEDs[] = {8, 9, 10, 11, 12, 13};
int buttonPin = 7;

bool buttonState = false;
bool lastButtonState = false;

void setup() {
  for (int i = 0; i < 6; i++) {
  	pinMode(LEDs[i], OUTPUT);
  }
  
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  buttonState = !digitalRead(buttonPin);
  
  if (buttonState && !lastButtonState) {
   playDiceGame();
  }
}

void playDiceGame() {
  for (int i = 0; i < 6; i++) {
  	digitalWrite(LEDs[i], HIGH);
    delay(1000);
    digitalWrite(LEDs[i], LOW);
  }
  
  int result = random(1, 7);
    
  for (int i = 0; i < result; i++) {
	digitalWrite(LEDs[i], HIGH);
  }
  
  delay(1000);
  
  for (int i = 0; i < 6; i++) {
  	digitalWrite(LEDs[i], LOW);
  }
  
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 6; j++) {
      digitalWrite(LEDs[j], HIGH);
    }
    
    delay(200);
    
    for (int j = 0; j < 6; j++) {
      digitalWrite(LEDs[j], LOW);
    }
    
    delay(200);
  }
}