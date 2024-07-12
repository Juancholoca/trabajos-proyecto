#define RED_PIN 6
#define GREEN_PIN 5
#define BLUE_PIN 3
#define RED1_PIN 9
#define GREEN1_PIN 10
#define BLUE1_PIN 11
#define POTENTIOMETER_PIN A0

void setup() {
  pinMode(POTENTIOMETER_PIN, INPUT);
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(RED1_PIN, OUTPUT);
  pinMode(GREEN1_PIN, OUTPUT);
  pinMode(BLUE1_PIN, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  int potValue = analogRead(POTENTIOMETER_PIN);
  int delayTime = map(potValue, 0, 1023, 50, 1000);

  analogWrite(RED_PIN, 255);
  analogWrite(GREEN_PIN, 0);
  analogWrite(BLUE_PIN, 255);
  analogWrite(RED1_PIN, 255);
  analogWrite(GREEN1_PIN, 0);
  analogWrite(BLUE1_PIN, 255);
  delay(delayTime);
  analogWrite(RED_PIN, 0);
  analogWrite(GREEN_PIN, 0);
  analogWrite(BLUE_PIN, 0);
  analogWrite(RED1_PIN, 0);
  analogWrite(GREEN1_PIN, 0);
  analogWrite(BLUE1_PIN, 0);
  delay(delayTime);

  analogWrite(RED_PIN, 255);
  analogWrite(GREEN_PIN, 255);
  analogWrite(BLUE_PIN, 0);
  analogWrite(RED1_PIN, 255);
  analogWrite(GREEN1_PIN, 255);
  analogWrite(BLUE1_PIN, 0);
  delay(delayTime);
  analogWrite(RED_PIN, 0);
  analogWrite(GREEN_PIN, 0);
  analogWrite(BLUE_PIN, 0);
  analogWrite(RED1_PIN, 0);
  analogWrite(GREEN1_PIN, 0);
  analogWrite(BLUE1_PIN, 0);
  delay(delayTime);
}
