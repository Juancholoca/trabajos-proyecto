int piezo = 2;

void setup()
{
  pinMode(2, OUTPUT );
  
}

void loop()
{
  piezo = digitalRead( 3 );
delay(30);

  	if( digitalRead( 3 ) == HIGH )
    {
      
	digitalWrite(2 , LOW);
      
    }else{
     
    digitalWrite(2 , HIGH);	
     
    }
}
