int nombre=5;
#define LED_R_PIN 6
#define LED_B_PIN 8
#define LED_G_PIN 7
#define BUZZER_PIN 5
#define PIR_PIN 2
#define ECHO_PIN 3
#define TRIG_PIN 4

const float DISTANCIA_UMBRAL = 100.0;

// Macros para mensajes
#define MSG(TITULO, TEXTO) Serial.print(TITULO); Serial.println(TEXTO);
#define ALERTA "ALERTA: Intruso"
#define DISTANCIA "Dis: "

void setup() {
  pinMode(PIR_PIN, INPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_R_PIN, OUTPUT);
  pinMode(LED_G_PIN, OUTPUT);
  pinMode(LED_B_PIN, OUTPUT);
  
  Serial.begin(9600); // Inicializar comunicación serie
}

void loop() {
  bool movimiento = digitalRead(PIR_PIN);
  
  if (movimiento == HIGH) {
    // Movimiento detectado
    MSG(ALERTA, "Intruso");
    digitalWrite(BUZZER_PIN, HIGH);
    setColor(255, 255, 0); // Amarillo
  } else {
    digitalWrite(BUZZER_PIN, LOW);
    setColor(0, 255, 0); // Verde
  }

  // Medir distancia con sensor ultrasónico
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  float duracion = pulseIn(ECHO_PIN, HIGH);
  float distancia = duracion / 57.6;

  MSG(DISTANCIA, distancia);
  
  if (distancia < DISTANCIA_UMBRAL) {
    // Proximidad detectada
    setColor(255, 0, 0); // Rojo
    if (movimiento == HIGH) {
      tone(BUZZER_PIN, 1000); // Sonido de alarma distinto para proximidad con movimiento
    } else {
      tone(BUZZER_PIN, 500); // Sonido de alarma distinto para proximidad sin movimiento
    }
  } else {
    noTone(BUZZER_PIN); // Apagar buzzer si no hay proximidad
  }
  
  delay(100); // Pequeño retardo para estabilizar lecturas
}

void setColor(int r, int g, int b) {
  analogWrite(LED_R_PIN, r);
  analogWrite(LED_G_PIN, g);
  analogWrite(LED_B_PIN, b);
}