void setup()
{
  pinMode( A0 ,  INPUT  );
  	pinMode( 5  , OUTPUT );
  	
  	Serial.begin(9600);
}

void loop()
{
  
  int poten = analogRead( A0 );
  
  	int piezo = map( poten , 0 , 1023 , 0 , 255 );
  	
analogWrite( 3 , piezo );
  	
  
}