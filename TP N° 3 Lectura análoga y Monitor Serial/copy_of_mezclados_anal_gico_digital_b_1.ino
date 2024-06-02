#define buttonPin 7 

void setup()
{
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);

  Serial.begin(9600);
}

void loop()
{
  // Verificar si el botón ha sido presionado
  if (digitalRead(buttonPin) == LOW) {
    delay(50);  // Pequeño retardo para evitar rebotes del botón

    if (digitalRead(buttonPin) == LOW) {  // Verificar de nuevo si el botón sigue presionado
      Serial.println("Tiene 5 s para configurar el color del led....");

      delay(5000);  // Pausa de 5 segundos para que el usuario ajuste los potenciómetros

      // Leer los valores de los potenciómetros
      int rojo = map(analogRead(A0), 0, 1023, 0, 255);
      int verde = map(analogRead(A1), 0, 1023, 0, 255);
      int azul = map(analogRead(A2), 0, 1023, 0, 255);
      
      // Establecer el color del LED RGB
      analogWrite(3, rojo);
      analogWrite(6, verde);
      analogWrite(5, azul);

      // Imprimir los valores RGB en el monitor serial
      Serial.print("El led esta usando esta configuración de colores RGB: (");
      Serial.print(rojo);
      Serial.print("; ");
      Serial.print(verde);
      Serial.print("; ");
      Serial.print(azul);
      Serial.println(")");

      delay(5000);  // Mantener el color durante 5 segundos

      // Apagar el LED RGB
      analogWrite(3, 0);
      analogWrite(6, 0);
      analogWrite(5, 0);

      Serial.println("LED apagado. Presiona el boton para cambiar el color nuevamente.");

      // Esperar hasta que el botón sea liberado para evitar múltiples detecciones
      while (digitalRead(buttonPin) == LOW) {
        delay(50);  // Pequeño retardo para evitar el rebote del botón
      }
    }
  }
}