bool boton = false;
//
void setup()
{
  pinMode(2, OUTPUT);
   pinMode(3, OUTPUT);
   pinMode(4, OUTPUT);
   pinMode(5, OUTPUT);
   pinMode(6, OUTPUT);
   pinMode(7, OUTPUT);
   pinMode(8, OUTPUT);
   pinMode(9, OUTPUT);
   pinMode(10, OUTPUT);
   pinMode(11, OUTPUT);
   pinMode(12, INPUT_PULLUP);
   pinMode(A0, INPUT);
}

void loop()
{
  if( digitalRead(12) == LOW)
  {
    boton = !boton;
    
    int tiempo = analogRead(A0);
    
    int x = map ( tiempo , 0 , 1023, 200, 1500);
    
    digitalWrite(2, HIGH);
    delay(x); 
    digitalWrite(3, HIGH);
    digitalWrite(2, LOW);
    delay(x);
    digitalWrite(4, HIGH);
    digitalWrite(3, LOW);
    delay(x);
    digitalWrite(5, HIGH);
    digitalWrite(4, LOW);
    delay(x);
    digitalWrite(6, HIGH);
    digitalWrite(5, LOW);
    delay(x);
    digitalWrite(7, HIGH);
    digitalWrite(6, LOW);
    delay(x);
    digitalWrite(8, HIGH);
    digitalWrite(7, LOW);
    delay(x);
    digitalWrite(9, HIGH);
    digitalWrite(8, LOW);
    delay(x);
    digitalWrite(10, HIGH);
    digitalWrite(9, LOW);
    delay(x);
    digitalWrite(11, HIGH);
    digitalWrite(10, LOW);
    delay(x);
    digitalWrite(11, LOW);
    delay(x);
    
    }else{
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
  }
}
