#define trigPin 12
#define echoPin 13

int a=7; 
int b=6; 
int c=5; 
int d=11; 
int e=10; 
int f=8; 
int g=9; 
int dp=4; 

long duration;
int distance;

void clearDisplay(void) 
{ 
    digitalWrite(a,LOW);
    digitalWrite(b,LOW);
    digitalWrite(g,LOW);
    digitalWrite(c,LOW);
    digitalWrite(d,LOW);  
    digitalWrite(e,LOW);  
    digitalWrite(f,LOW);  
} 

void displayNumber(int n) 
{
  switch(n) 
  {
    case 1:
      digitalWrite(b,HIGH);
      digitalWrite(c,HIGH);
      break;
    case 2:
      digitalWrite(a,HIGH);
      digitalWrite(b,HIGH);
      digitalWrite(g,HIGH);
      digitalWrite(e,HIGH);
      digitalWrite(d,HIGH);
      break;
    case 3:
      digitalWrite(a,HIGH);
      digitalWrite(b,HIGH);
      digitalWrite(c,HIGH);
      digitalWrite(d,HIGH);
      digitalWrite(g,HIGH);
      break;
    case 4:
      digitalWrite(f,HIGH);
      digitalWrite(b,HIGH);
      digitalWrite(g,HIGH);
      digitalWrite(c,HIGH);
      break;
    case 5:
      digitalWrite(a,HIGH);
      digitalWrite(f,HIGH);
      digitalWrite(g,HIGH);
      digitalWrite(c,HIGH);
      digitalWrite(d,HIGH);
      break;
    case 6:
      digitalWrite(a,HIGH);
      digitalWrite(f,HIGH);
      digitalWrite(g,HIGH);
      digitalWrite(c,HIGH);
      digitalWrite(d,HIGH);
      digitalWrite(e,HIGH);
      break;
    case 7:
      digitalWrite(a,HIGH);
      digitalWrite(b,HIGH);
      digitalWrite(c,HIGH);
      break;
    case 8:
      digitalWrite(a,HIGH);
      digitalWrite(b,HIGH);
      digitalWrite(g,HIGH);
      digitalWrite(c,HIGH);
      digitalWrite(d,HIGH);  
      digitalWrite(e,HIGH);  
      digitalWrite(f,HIGH);
      break;
    case 9:
      digitalWrite(a,HIGH);
      digitalWrite(b,HIGH);
      digitalWrite(g,HIGH);
      digitalWrite(c,HIGH);
      digitalWrite(d,HIGH);  
      digitalWrite(f,HIGH);
      break;
    default:
    // 0
      digitalWrite(a,HIGH);
      digitalWrite(b,HIGH);
      digitalWrite(c,HIGH);
      digitalWrite(d,HIGH);  
      digitalWrite(e,HIGH);
      digitalWrite(f,HIGH); 
  }
}

void setup() 
{ 
  int i;
  for(i=4;i<=11;i++) {
    pinMode(i,OUTPUT);
  }

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  Serial.begin(9600);
} 

void loop() {
  // Trigger the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  clearDisplay();

  duration = pulseIn(echoPin, HIGH);

  // Calculate distance in cm
  distance = (duration / 2) / 29.1;

  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance > 330 || distance <= 0) {
    displayNumber(0);
  } else if (distance > 280 ) {
    displayNumber(1);
  } else if (distance > 240) {
    displayNumber(2);
  } else if (distance > 200) {
    displayNumber(3);
  } else if (distance > 160) {
    displayNumber(4);
  } else if (distance > 120) {
    displayNumber(5);
  } else if (distance > 80) {
    displayNumber(6);
  } else if (distance > 40) {
    displayNumber(7);
  } else displayNumber(8);

  delay(500);
}