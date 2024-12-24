int tempSensorPin = A0;
int humiditySensorPin = A1;
int led1 = 2, led2 = 3, led3 = 4;

void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
  int tempRaw = analogRead(tempSensorPin);
  double voltage = (tempRaw / 1023.0) * 5000;
  double tempC = (voltage - 500) * 0.1;

  int humidityRaw = analogRead(humiditySensorPin);
  int humidity = map(humidityRaw, 0, 1023, 10, 70);

  Serial.print("Temperature: ");
  Serial.print(tempC, 1);
  Serial.print(" C, Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  // LED
  if (tempC > 80) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
  } else if (humidity > 60 && tempC < 80) {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  } else if (tempC > 60) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
  } else if (tempC > 40) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  } else {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  }

  delay(2000);
}
