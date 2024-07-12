void setup() {
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  
  pinMode(9, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);

  pinMode(10, OUTPUT);
}

void loop() {
  analogWrite(3, 255);
  analogWrite(5, 0);
  analogWrite(6, 0);
  digitalWrite(10, HIGH);
  delay(100);
  digitalWrite(10, LOW);
  delay(100);
  delay(800);
  
  analogWrite(3, 0);
  digitalWrite(9, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(10, HIGH);
  delay(100);
  digitalWrite(10, LOW);
  delay(100);
  delay(800);
  
  digitalWrite(9, LOW);
  digitalWrite(12, LOW);
  analogWrite(A0, 0);
  analogWrite(A1, 128);
  analogWrite(A2, 255);
  digitalWrite(10, HIGH);
  delay(100);
  digitalWrite(10, LOW);
  delay(100);
  delay(800);
  
  analogWrite(A1, 0);
  analogWrite(A2, 0);
  digitalWrite(10, LOW);
  delay(1000);
}
