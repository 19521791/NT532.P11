#define LED1_R 13
#define LED1_Y 12
#define LED1_G 11
#define LED2_R 10
#define LED2_Y A0
#define LED2_G A1

#define pinA 8
#define pinB 9
#define pinC 3
#define pinD 4
#define pinE 5
#define pinF 7
#define pinG 6

#define common 2

int timeLED1[] = {6, 3, 9};
int timeLED2[] = {9, 6, 3};

void setup() {
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  pinMode(pinE, OUTPUT);
  pinMode(pinF, OUTPUT);
  pinMode(pinG, OUTPUT);
  
  pinMode(common, OUTPUT);

  pinMode(LED1_R, OUTPUT);
  pinMode(LED1_Y, OUTPUT);
  pinMode(LED1_G, OUTPUT);
  pinMode(LED2_R, OUTPUT);
  pinMode(LED2_Y, OUTPUT);
  pinMode(LED2_G, OUTPUT);
}

void loop() {
  trafficControl();
}

void trafficControl() {

  setLED(LED1_R, LED1_Y, LED1_G, 0); 
  setLED(LED2_R, LED2_Y, LED2_G, 2);
  countdownSynchronized(timeLED1[0], 0);

  setLED(LED1_R, LED1_Y, LED1_G, 1);
  setLED(LED2_R, LED2_Y, LED2_G, 2);
  countdownSynchronized(timeLED1[1], 0);

  setLED(LED1_R, LED1_Y, LED1_G, 2);
  for (int i = 0; i < 1; i++) {
    setLED(LED2_R, LED2_Y, LED2_G, i);
    countdownSynchronized(timeLED2[i], 1);
  }
}

void setLED(int redPin, int yellowPin, int greenPin, int state) {
  digitalWrite(redPin, state == 2 ? HIGH : LOW);
  digitalWrite(yellowPin, state == 1 ? HIGH : LOW);
  digitalWrite(greenPin, state == 0 ? HIGH : LOW);
}

void countdownSynchronized(int seconds, int mode) {
  for (int i = seconds; i >= 0; i--) {
    displayNumber(i);

    if (mode == 1) {
      if (i == 3) { 
        setLED(LED2_R, LED2_Y, LED2_G, 1);
      }
    }

    delay(1000);
  }
}

void displayNumber(int number) {
  int segmentPinAn[10][7] = {
    {0, 0, 0, 0, 0, 0, 1}, // Số 0
    {1, 0, 0, 1, 1, 1, 1}, // Số 1
    {0, 0, 1, 0, 0, 1, 0}, // Số 2
    {0, 0, 0, 0, 1, 1, 0}, // Số 3
    {1, 0, 0, 1, 1, 0, 0}, // Số 4
    {0, 1, 0, 0, 1, 0, 0}, // Số 5
    {0, 1, 0, 0, 0, 0, 0}, // Số 6
    {0, 0, 0, 1, 1, 1, 1}, // Số 7
    {0, 0, 0, 0, 0, 0, 0}, // Số 8
    {0, 0, 0, 0, 1, 0, 0}  // Số 9
  };

  int arduinoPins[7] = {pinA, pinB, pinC, pinD, pinE, pinF, pinG};
  for (int j = 0; j < 7; j++) {
    digitalWrite(arduinoPins[j], segmentPinAn[number][j]);
  }

  digitalWrite(common, HIGH);
}
