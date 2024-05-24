bool boton = false;
int contar = 0;
int tiempo = 200;

void setup()
{
    pinMode(3, INPUT_PULLUP);
    for (int i = 4; i <= 13; i++) {
        pinMode(i, OUTPUT);
    }

    Serial.begin(9600);
}

void loop()
{

    if (digitalRead(3) == LOW)
    {
        boton = !boton;
        delay(tiempo);
    }

    if (boton == true)
    {
        contar = contar + 1;
        boton = false;
    }

    Serial.print(contar);
    Serial.print(" - resto:");
    Serial.println(contar % 10);

    for (int i = 4; i <= 13; i++) {
        digitalWrite(i, LOW);
    }

    if (contar != 0)
    {
        digitalWrite(contar + 3, HIGH);
    }

    if (contar == 10)
    {
        contar = 0;
    }
}