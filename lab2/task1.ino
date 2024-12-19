#define trigPin 13
#define echoPin 12
#define ledPin 2

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  long duration, distance;
  int blinkDelay = 0;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = (duration / 2) / 29.1;

  if (distance > 200 || distance <= 0) {
    blinkDelay = -1;
  } else if (distance > 150) {
    blinkDelay = 1000;
  } else if (distance > 100) {
    blinkDelay = 500;
  } else if (distance > 50) {
    blinkDelay = 250;
  } else if (distance > 20) {
    blinkDelay = 100;
  } else {
    blinkDelay = 50;
  }

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm - ");
  if (blinkDelay == -1) {
    Serial.println("Out of range, light off.");
    digitalWrite(ledPin, LOW);
  } else {
    Serial.print("Blink speed: ");
    Serial.print(blinkDelay);
    Serial.println(" ms");
    digitalWrite(ledPin, HIGH);
    delay(blinkDelay);
    digitalWrite(ledPin, LOW);
    delay(blinkDelay);
  }
}
