void setup()
{
  pinMode( A0 ,  INPUT  );
  	pinMode( 5  , OUTPUT );
  	
  	Serial.begin(9600);
}

void loop()
{
  
  int led = analogRead( A0 );
  

  	int led1 = map( led , 0 , 1023 , 0 , 255 );
  	
analogWrite( 3 , led1 );
  
}