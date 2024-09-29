#define PIR_PIN 4
#define LED_PIN 2

void setup() 
{
    Serial.begin(9600);
    pinMode(LED_PIN, OUTPUT);
    pinMode(PIR_PIN, INPUT);
}

void loop()
{
    verificarMovimiento();
    delay(500);
}

void verificarMovimiento() 
{
    int movimiento = digitalRead(PIR_PIN);

    if (movimiento == HIGH) {
        encenderLuz();
    } else {
        apagarLuz();
    }
}

void encenderLuz() 
{
    Serial.println("Movimiento detectado! Luz encendida.");
    digitalWrite(LED_PIN, HIGH);
}

void apagarLuz() 
{
    Serial.println("No hay movimiento. Luz apagada.");
    digitalWrite(LED_PIN, LOW);
}
