#define RED_PIN 6
#define GREEN_PIN 9
#define BLUE_PIN 10
#define BUZZER_PIN 11

void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  // Prende el 1° LED en color rojo fuerte (análogamente)
  analogWrite(RED_PIN, 255);
  analogWrite(GREEN_PIN, 0);
  analogWrite(BLUE_PIN, 0);
  buzz();

  // Se apaga el 1° LED y se prende el 2° LED en color magenta (digitalmente)
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, HIGH);
  buzz();

  // Se apaga el 2° LED y se prende el 3° LED en color cian (análogamente y clarito)
  analogWrite(RED_PIN, 0);
  analogWrite(GREEN_PIN, 255);
  analogWrite(BLUE_PIN, 255);
  buzz();

  // Se apaga el 3° LED y se prende el 1° LED devuelta
  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, LOW);
  buzz();
}

void buzz() {
  digitalWrite(BUZZER_PIN, HIGH); // Enciende el zumbador
  delay(100); // Espera 50 milisegundos
  digitalWrite(BUZZER_PIN, LOW); // Apaga el zumbador
  delay(100); // Espera 50 milisegundos
}