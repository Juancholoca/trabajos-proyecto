#define LED_PIN 5
#define POTENTIOMETER_PIN A0

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(POTENTIOMETER_PIN, INPUT);
}

void loop() {
  int potValue = analogRead(POTENTIOMETER_PIN); // Lee el valor del potenciómetro
  int delayTime = map(potValue, 0, 1023, 0, 10000); // Mapea el valor del potenciómetro a un rango de tiempo de retardo de 0 a 10000 milisegundos (0 a 10 segundos)

  digitalWrite(LED_PIN, HIGH); // Enciende el LED
  delay(delayTime); // Espera
  digitalWrite(LED_PIN, LOW); // Apaga el LED
  delay(delayTime); // Espera
}