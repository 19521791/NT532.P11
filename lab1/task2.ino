const int potPin = A0;  
const int ledPins[] = {2, 3, 4};
const int totalLeds = 3;
int potValue = 0;
int delayTime = 0;
String speedLevel = "";

void setup() {
  for (int i = 0; i < totalLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }

  Serial.begin(115200);
}

void loop() {
  potValue = analogRead(potPin);

  if (potValue < 341) { 
    delayTime = 500; 
    speedLevel = "Slow";
  } else if (potValue < 682) {
    delayTime = 250;
    speedLevel = "Average";
  } else {
    delayTime = 100;
    speedLevel = "Fast";
  }

  Serial.print("Resistor: ");
  Serial.print(potValue);
  Serial.print(" - Speed: ");
  Serial.println(speedLevel);

  for (int i = 0; i < totalLeds; i++) {
    digitalWrite(ledPins[i], HIGH); 
    delay(delayTime);               
    digitalWrite(ledPins[i], LOW);  
  }
}
