const int buttonPin = 2;      // Pin del botón
const int potPin = A0;        // Pin del potenciómetro
const int numLeds = 11;       // Número de LEDs

// Pines de los LEDs
const int ledPins[numLeds] = {3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

bool sequenceActive = false;   // Estado de la secuencia (activa/inactiva)
bool lastButtonState = HIGH;   // Último estado del botón (para detectar cambios)

void setup() {
  pinMode(buttonPin, INPUT_PULLUP); // Configura el botón con resistencia pull-up interna

  // Configurar los pines de los LEDs como salida
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  // Leer el estado del botón
  bool buttonState = digitalRead(buttonPin);

  // Si el botón se presiona (cambio de HIGH a LOW)
  if (buttonState == LOW && lastButtonState == HIGH) {
    sequenceActive = !sequenceActive;  // Alterna el estado de la secuencia
    delay(50);  // Anti-rebote
  }

  // Actualizar el último estado del botón
  lastButtonState = buttonState;

  // Leer el valor del potenciómetro y mapearlo a un rango de tiempo
  int potValue = analogRead(potPin);
  int delayTime = map(potValue, 0, 1023, 100, 1000);  // Rango de 100 ms a 1000 ms

  // Ejecutar la secuencia si está activa
  if (sequenceActive) {
    for (int i = 0; i < numLeds; i++) {
      digitalWrite(ledPins[i], HIGH);  // Encender el LED
      delay(delayTime);  // Esperar un tiempo según el valor del potenciómetro
      digitalWrite(ledPins[i], LOW);   // Apagar el LED
    }
  } else {
    // Apagar todos los LEDs si la secuencia no está activa
    for (int i = 0; i < numLeds; i++) {
      digitalWrite(ledPins[i], LOW);
    }
  }
}