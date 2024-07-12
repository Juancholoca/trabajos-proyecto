#define PIR_PIN 2
#define TRIG_PIN 3
#define ECHO_PIN 4
#define LED_R_PIN 5
#define LED_G_PIN 6
#define LED_B_PIN 7
#define BUZZER_PIN 8
#define DISTANCE_THRESHOLD 100

long duration;
int distance;
bool motionDetected = false;

void setup() {
  pinMode(PIR_PIN, INPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_R_PIN, OUTPUT);
  pinMode(LED_G_PIN, OUTPUT);
  pinMode(LED_B_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  motionDetected = digitalRead(PIR_PIN);
  
  if (motionDetected) {
    setLEDColor(255, 255, 0);
    distance = measureDistance();
    
    if (distance > 0 && distance < DISTANCE_THRESHOLD) {
      setLEDColor(255, 0, 0);
      activateAlarm();
    } else {
      setLEDColor(255, 255, 0);
      deactivateAlarm();
    }
  } else {
    setLEDColor(0, 255, 0);
    deactivateAlarm();
  }
  
  delay(100);
}

int measureDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration * 0.034 / 2;
  return distance;
}

void setLEDColor(int red, int green, int blue) {
  analogWrite(LED_R_PIN, red);
  analogWrite(LED_G_PIN, green);
  analogWrite(LED_B_PIN, blue);
}

void activateAlarm() {
  digitalWrite(BUZZER_PIN, HIGH);
  delay(100);
  digitalWrite(BUZZER_PIN, LOW);
  delay(100);
}

void deactivateAlarm() {
  digitalWrite(BUZZER_PIN, LOW);
}
