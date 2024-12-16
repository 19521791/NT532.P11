#include <LiquidCrystal.h>
#include <stdlib.h>

LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);

const int ledPins[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
const int buttonPins[] = {11, 12, 13};

int level = 1;
int score = 0;
int currentLedCount = 0; 
unsigned long previousMillis = 0;
const int baseTime = 4000;

void setup() {
  for (int i = 0; i < 10; i++) {
    pinMode(ledPins[i], OUTPUT);
  }

  for (int i = 0; i < 3; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }

  lcd.begin(16, 2);
  lcd.print("Thu tai doan so!");
  delay(2000);
  lcd.clear();
}

void loop() {
  playRound();
}

void playRound() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Level: ");
  lcd.print(level);
  lcd.setCursor(0, 1);
  lcd.print("Score: ");
  lcd.print(score);

  currentLedCount = random(1, 11);
  lightUpLeds(currentLedCount);

  int result = waitForButton((baseTime / level) - 1000);

  int correctButton = currentLedCount % 3;
  if (result == correctButton) {
    score += 10;
    lcd.clear();
    lcd.print("Dung! +10 diem");
    level = min(level + 1, 3);
  } else {
    score -= 5;
    lcd.clear();
    if (result == -1) {
      lcd.print("Het gio! -5");
    } else {
      lcd.print("Sai! -5 diem");
    }
    level = 1;
  }

  delay(2000);
  turnOffLeds();
}

void lightUpLeds(int count) {
  turnOffLeds();
  for (int i = 0; i < count; i++) {
    digitalWrite(ledPins[i], HIGH);
  }
}
void turnOffLeds() {
  for (int i = 0; i < 10; i++) {
    digitalWrite(ledPins[i], LOW);
  }
}

int waitForButton(int timeout) {
  unsigned long startTime = millis();
  while (millis() - startTime < timeout) {
    for (int i = 0; i < 3; i++) {
      if (digitalRead(buttonPins[i]) == LOW) {
        delay(200);
        return i;
      }
    }
  }
  return -1;
}
