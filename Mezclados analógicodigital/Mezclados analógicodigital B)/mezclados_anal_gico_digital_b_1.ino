const int buttonPin = 2;   
const int potPin = A0;      
const int redPin = 9;       
const int greenPin = 10;    
const int bluePin = 11;     

bool ledState = false;      
bool lastButtonState = HIGH; 
int colorState = 0;         

void setup() {
  pinMode(buttonPin, INPUT_PULLUP); 
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  // Leer el estado del botón
  bool buttonState = digitalRead(buttonPin);

  // Si el botón se presiona (cambio de HIGH a LOW)
  if (buttonState == LOW && lastButtonState == HIGH) {
    ledState = !ledState;  // Alterna el estado del LED
    delay(50);             // Anti-rebote
  }

  // Actualizar el último estado del botón
  lastButtonState = buttonState;

  // Si el LED está encendido, ajustar los colores con el potenciómetro
  if (ledState) {
    int potValue = analogRead(potPin);
    
    // Mapear el valor del potenciómetro a diferentes rangos para RGB
    int redValue = 0, greenValue = 0, blueValue = 0;

    if (colorState == 0) { // Rojo
      redValue = map(potValue, 0, 1023, 0, 255);
    } else if (colorState == 1) { // Verde
      greenValue = map(potValue, 0, 1023, 0, 255);
    } else if (colorState == 2) { // Azul
      blueValue = map(potValue, 0, 1023, 0, 255);
    }

    analogWrite(redPin, redValue);
    analogWrite(greenPin, greenValue);
    analogWrite(bluePin, blueValue);

    // Cambio de color cada vez que se presiona el botón
    if (buttonState == LOW && lastButtonState == HIGH) {
      colorState = (colorState + 1) % 3; // Cambia entre 0, 1, 2
      delay(50); // Anti-rebote
    }
  } else {
  
    analogWrite(redPin, 0);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);
  }
}