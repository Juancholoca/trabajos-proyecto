// C++ code
//
void setup()
{
  pinMode(2, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  Serial.begin( 9600 );
}

void loop()
{
  int rojo = map( analogRead( A0 ) , 0 , 1023 , 0 , 255 );
  int verde = map( analogRead( A1 ) , 0 , 1023 , 0 , 255 );
  int azul = map( analogRead( A2 ) , 0 , 1023 , 0 , 255 );
  analogWrite(3 ,rojo  );
  analogWrite( 6,verde );
  analogWrite(5 ,azul );
  
  Serial.print("(R:");
  	Serial.print(rojo);
  	Serial.print(" G:");
  	Serial.print(verde);
  	Serial.print(" B:");
  	Serial.print(azul);
  	Serial.println(")");
  
  analogRead( A0 );
  analogRead( A1 );
  analogRead( A2 );
  
  
}