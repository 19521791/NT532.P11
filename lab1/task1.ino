int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;
int led5 = 6;
int led6 = 7;
int led7 = 8;
int led8 = 9;
int led9 = 10;
int led10 = 11;
int led11 = 12;
int led12 = 13;

int pushPin = A0;
int pushCurrentState = HIGH;
int pushLastState = HIGH;
int numberPressed = 0;

void setup() {
  pinMode(pushPin, INPUT_PULLUP);
  
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led8, OUTPUT);
  pinMode(led9, OUTPUT);
  pinMode(led10, OUTPUT);
  pinMode(led11, OUTPUT);
  pinMode(led12, OUTPUT);
}

void loop() {
  pushCurrentState = digitalRead(pushPin);
  
  if ( pushCurrentState == HIGH && pushLastState == LOW) 
  {
    numberPressed++;
    if (numberPressed > 12)
    {
      numberPressed = numberPressed - 12;
    }
  }
  pushLastState = pushCurrentState;
  
  digitalWrite(led1, numberPressed >= 1);
  digitalWrite(led2, numberPressed >= 2);
  digitalWrite(led3, numberPressed >= 3);
  digitalWrite(led4, numberPressed >= 4);
  digitalWrite(led5, numberPressed >= 5);
  digitalWrite(led6, numberPressed >= 6);
  digitalWrite(led7, numberPressed >= 7);
  digitalWrite(led8, numberPressed >= 8);
  digitalWrite(led9, numberPressed >= 9);
  digitalWrite(led10, numberPressed >= 10);
  digitalWrite(led11, numberPressed >= 11);
  digitalWrite(led12, numberPressed >= 12);
}