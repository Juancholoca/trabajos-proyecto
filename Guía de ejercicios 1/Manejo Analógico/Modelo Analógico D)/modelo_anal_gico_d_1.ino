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
  
  Serial.begin(9600);
}

void loop() {
  int potValue = analogRead(POTENTIOMETER_PIN); // Lee el valor del potenciómetro
  int delayTime = map(potValue, 0, 1023, 50, 1000); // Mapea el valor del potenciómetro a un rango de velocidad de parpadeo

  // Parpadeo del LED magenta
  setColor(255, 0, 255); // Establece el color magenta
  delay(delayTime); // Espera
  setColor(0, 0, 0); // Apaga el LED
  delay(delayTime); // Espera

  // Parpadeo del LED amarillo
  setColor(255, 255, 0); // Establece el color amarillo
  delay(delayTime); // Espera
  setColor(0, 0, 0); // Apaga el LED
  delay(delayTime); // Espera
}

void setColor(int red, int green, int blue) {
  analogWrite(RED_PIN, red);
  analogWrite(GREEN_PIN, green);
  analogWrite(BLUE_PIN, blue);
  analogWrite(RED1_PIN, red);
  analogWrite(GREEN1_PIN, green);
  analogWrite(BLUE1_PIN, blue);
}