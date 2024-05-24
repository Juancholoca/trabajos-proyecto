#define RED_PIN 6
#define GREEN_PIN 5
#define BLUE_PIN 3

void setup() {
  pinMode(A0, INPUT);
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  int pikachu = analogRead(A0);
  
  int raichu = map(pikachu, 0, 1023, 0, 255);
  
  // Mostrar cian
  analogWrite(RED_PIN, 0);    // Sin rojo
  analogWrite(GREEN_PIN, raichu);  // Verde
  analogWrite(BLUE_PIN, raichu);   // Azul
  
  delay(500);
  
  // Mostrar rojo
  analogWrite(RED_PIN, raichu);    // Rojo
  analogWrite(GREEN_PIN, 0);    // Sin verde
  analogWrite(BLUE_PIN, 0);     // Sin azul
  
  delay(500);
  
  // Mostrar amarillo
  analogWrite(RED_PIN, raichu);    // Rojo
  analogWrite(GREEN_PIN, raichu);  // Verde
  analogWrite(BLUE_PIN, 0);     // Sin azul
  
  delay(500);
}