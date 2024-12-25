#define ldrPin A1       
#define buttonPin A0     

int ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

int lightLevel = 0;      
int mode = 0;            
int buttonState = 0;     
int lastButtonState = 0; 
unsigned long lastDebounceTime = 0; 
const unsigned long debounceDelay = 50; 

void setup() {
  pinMode(ldrPin, INPUT);
  pinMode(buttonPin, INPUT_PULLUP); 

  for (int i = 0; i < 10; i++) {
    pinMode(ledPins[i], OUTPUT);
  }

  Serial.begin(9600);
}

void loop() {

  lightLevel = analogRead(ldrPin);

  int reading = digitalRead(buttonPin);
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;

      if (buttonState == LOW) {
        mode = (mode + 1) % 3;
      }
    }
  }

  lastButtonState = reading;

  if (mode == 0) {
    controlLEDsBasedOnLight(lightLevel);
  } else if (mode == 1) {
    controlLEDs(5);
  } else if (mode == 2) {
    controlLEDs(10);
  }

  Serial.print("Light Level: ");
  Serial.print(lightLevel);
  Serial.print(" | Mode: ");
  Serial.println(mode);

  delay(100);
}

void controlLEDsBasedOnLight(int lightLevel) {
  if (lightLevel < 200) {
    controlLEDs(10);
  } else if (lightLevel < 400) {
    controlLEDs(7);
  } else if (lightLevel < 700) {
    controlLEDs(3);
  } else { // Ánh sáng mạnh
    controlLEDs(0);
  }
}

void controlLEDs(int numLEDs) {
  for (int i = 0; i < 10; i++) {
    if (i < numLEDs) {
      digitalWrite(ledPins[i], HIGH);
    } else {
      digitalWrite(ledPins[i], LOW);
    }
  }
}
