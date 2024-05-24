int ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9}; // Array para almacenar los pines de los LEDs

void setup() {
  for (int i = 0; i < 8; i++) {
    pinMode(ledPins[i], OUTPUT); // Configura todos los pines como salidas
  }
}

void loop() {
  // Enciende gradualmente los LEDs
  for (int i = 0; i < 8; i++) {
    digitalWrite(ledPins[i], HIGH); // Enciende el LED actual
    delay(100); // Espera un tiempo para el efecto de encendido gradual
  }
  
  // Apaga gradualmente los LEDs
  for (int i = 7; i >= 0; i--) {
    digitalWrite(ledPins[i], LOW); // Apaga el LED actual
    delay(100); // Espera un tiempo para el efecto de apagado gradual
  }
}