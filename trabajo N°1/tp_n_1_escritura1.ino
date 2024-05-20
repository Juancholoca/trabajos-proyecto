// Pines de los LEDs RGB
const int led1R = 3;
const int led1G = 5;
const int led1B = 6;

const int led2R = 9;
const int led2G = 11;
const int led2B = 12;

const int led3R = A0;
const int led3G = A1;
const int led3B = A2;

// Pin del buzzer
const int buzzerPin = 10;

// Función para activar el buzzer
void buzz(int duration) {
  digitalWrite(buzzerPin, HIGH);
  delay(duration);
  digitalWrite(buzzerPin, LOW);
  delay(duration);
}

void setup() {
  // Configurar los pines de los LEDs RGB como salida
  pinMode(led1R, OUTPUT);
  pinMode(led1G, OUTPUT);
  pinMode(led1B, OUTPUT);
  
  pinMode(led2R, OUTPUT);
  pinMode(led2G, OUTPUT);
  pinMode(led2B, OUTPUT);
  
  pinMode(led3R, OUTPUT);
  pinMode(led3G, OUTPUT);
  pinMode(led3B, OUTPUT);

  // Configurar el pin del buzzer como salida
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Prender LED 1 en color rojo fuerte (analógico)
  analogWrite(led1R, 255);
  analogWrite(led1G, 0);
  analogWrite(led1B, 0);
  buzz(100);
  delay(1000);  // Esperar 1 segundo
  
  // Apagar LED 1
  analogWrite(led1R, 0);
  analogWrite(led1G, 0);
  analogWrite(led1B, 0);
  
  // Prender LED 2 en color magenta (digital)
  digitalWrite(led2R, HIGH);
  digitalWrite(led2B, HIGH);
  digitalWrite(led2G, LOW);
  buzz(100);
  delay(1000);  // Esperar 1 segundo
  
  // Apagar LED 2
  digitalWrite(led2R, LOW);
  digitalWrite(led2B, LOW);
  
  // Prender LED 3 en color cian clarito (analógico)
  analogWrite(led3R, 0);
  analogWrite(led3G, 128);
  analogWrite(led3B, 255);
  buzz(100);
  delay(1000);  // Esperar 1 segundo
  
  // Apagar LED 3
  analogWrite(led3G, 0);
  analogWrite(led3B, 0);
}