bool boton = false;
int contar = 0;
int tiempo = 200;

void setup()
{
    pinMode(4, INPUT_PULLUP);
    pinMode(5, OUTPUT); // Pin rojo del LED RGB
    pinMode(6, OUTPUT); // Pin verde del LED RGB
    pinMode(7, OUTPUT); // Pin azul del LED RGB

    Serial.begin(9600);
}

void loop()
{
    if (digitalRead(4) == LOW)
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
    Serial.println(contar % 7);

    // Apagar el LED RGB antes de cambiar de color
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);

    // Cambiar de color según el valor de contar
    if (contar % 7 == 1)
    {
        // Rojo
        digitalWrite(5, HIGH);
    }
    else if (contar % 7 == 2)
    {
        // Cian
        digitalWrite(6, HIGH);
    }
    else if (contar % 7 == 3)
    {
        // Verde
        digitalWrite(5, HIGH);
        digitalWrite(6, HIGH);
    }
    else if (contar % 7 == 4)
    {
        // Magenta
        digitalWrite(5, HIGH);
        digitalWrite(7, HIGH);
    }
    else if (contar % 7 == 5)
    {
        // Azul
        digitalWrite(7, HIGH);
    }
    else if (contar % 7 == 6)
    {
        // Blanco
        digitalWrite(5, HIGH);
        digitalWrite(6, HIGH);
        digitalWrite(7, HIGH);
    }
    else
    {
        // Amarillo
        digitalWrite(5, HIGH);
        digitalWrite(6, HIGH);
    }

    // Reiniciar la secuencia si llega al final
    if (contar == 7)
    {
        contar = 0;
    }

   }

