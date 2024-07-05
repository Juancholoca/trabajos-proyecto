#define TRIGGER 4  
#define ECHO     3  
#define BUZZER  5  
#define POT      A0 
#define MAX_DISTANCE 330 
#define MIN_DISTANCE 20  
#define MIN_GOAL_DISTANCE 50  
#define MAX_GOAL_DISTANCE 200 

int Posicion = 100; 

void setup() {
  Serial.begin(9600);

  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(POT, INPUT);
}

void loop() {
  int potValue = analogRead(POT);
  Posicion = map(potValue, 0, 1023, MIN_GOAL_DISTANCE, MAX_GOAL_DISTANCE);

  long duracion, distancia;
  digitalWrite(TRIGGER, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER, LOW);
  duracion = pulseIn(ECHO, HIGH);
  distancia = duracion * 0.034 / 2;

  if (distancia < MIN_DISTANCE || distancia > MAX_DISTANCE) {
    distancia = MAX_DISTANCE;
  }

  int buzzSpeed = map(distancia, MIN_DISTANCE, MAX_DISTANCE, 1000, 100);

  tone(BUZZER, 1000, 100);
  delay(buzzSpeed);
  noTone(BUZZER);
  delay(buzzSpeed);

  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.print(" cm - Posicion del objeto: ");
  Serial.print(Posicion);
  Serial.print(" cm - Velocidad: ");
  Serial.print(buzzSpeed);
  Serial.println(" ms");

  delay(100);
}