#define PIN_LED_R 3
#define PIN_LED_B 5
#define PIN_LED_G 6
#define PIN_TMP A1
#define PIN_LDR A0
#define MSG_LUZ "El nivel de luz actual es: "
#define MSG_TEMP " y la temperatura actual: "

#define LUZ_MIN 0
#define LUZ_MAX 100
#define TEMP_MIN 18
#define TEMP_MAX 90
#define TEMP_RED 90
#define TEMP_BLUE 18
#define TEMP_GREEN_LOWER 18
#define TEMP_GREEN_UPPER 90

int valorLUZ;
int valorTEMP;

void setup() {
  pinMode(PIN_LED_R, OUTPUT);
  pinMode(PIN_LED_B, OUTPUT);
  pinMode(PIN_LED_G, OUTPUT);
  pinMode(PIN_LDR, INPUT);
  pinMode(PIN_TMP, INPUT);
  Serial.begin(9600);
}

void loop() {
  
  int luzRaw = analogRead(PIN_LDR);
  int luz = map(luzRaw, 1, 310, LUZ_MAX, LUZ_MIN); 
  valorLUZ = luz;
  
  Serial.print(MSG_LUZ);
  Serial.println(valorLUZ);

  int tempRaw = analogRead(PIN_TMP);
  float voltage = tempRaw * 5.0 / 1024;
  float temperatura = (voltage - 0.5) * 100;
  valorTEMP = int(temperatura); 

  Serial.print(MSG_TEMP);
  Serial.print(valorTEMP);
  Serial.println("ºC");

  
  if (luz < 30 || luz > 70) {
    digitalWrite(PIN_LED_R, LOW);
    digitalWrite(PIN_LED_G, LOW);
    digitalWrite(PIN_LED_B, LOW);
  } else {
    
    digitalWrite(PIN_LED_R, valorTEMP > TEMP_RED ? HIGH : LOW);
    digitalWrite(PIN_LED_G, (valorTEMP >= TEMP_GREEN_LOWER && valorTEMP <= TEMP_GREEN_UPPER) ? HIGH : LOW);
    digitalWrite(PIN_LED_B, valorTEMP < TEMP_BLUE ? HIGH : LOW);
  }

  delay(1000); 
}
