int PIR_PIN = 2;
int LED1_PIN = 8;
int LED2_PIN = 9;

void setup() {
  pinMode(PIR_PIN, INPUT);
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int pirValue = digitalRead(PIR_PIN);

  if (pirValue == HIGH) {
    Serial.println("Motion detected! LEDs blinking.");
    digitalWrite(LED1_PIN, HIGH);
    digitalWrite(LED2_PIN, LOW);
    delay(500);                   
    digitalWrite(LED1_PIN, LOW);  
    digitalWrite(LED2_PIN, HIGH); 
    delay(500);                   
  } else {
    Serial.println("No motion. LEDs off.");
    digitalWrite(LED1_PIN, LOW);
    digitalWrite(LED2_PIN, LOW);
  }
}
