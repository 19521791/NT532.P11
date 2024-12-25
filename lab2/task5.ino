int PIR_PIN = 8;

void setup() {
  pinMode(PIR_PIN, INPUT);
  Serial.begin(9600);
}

void loop() {
  int pirValue = digitalRead(PIR_PIN);
  if (pirValue == HIGH) {
    Serial.println("Motion detected!");
  } else {
    Serial.println("No motion detected.");
  }
  delay(1000);
}
