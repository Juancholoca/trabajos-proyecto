bool boton = false;
int contar = 0;
int tiempo = 200;
void setup()
{
    pinMode(2, INPUT_PULLUP);
    pinMode(3, OUTPUT); // Pin rojo del primer LED RGB
    pinMode(4, OUTPUT); // Pin verde del primer LED RGB
    pinMode(5, OUTPUT); // Pin azul del primer LED RGB
    pinMode(6, OUTPUT); // Pin rojo del segundo LED RGB
    pinMode(7, OUTPUT); // Pin verde del segundo LED RGB
    pinMode(8, OUTPUT); // Pin azul del segundo LED RGB
    pinMode(9, OUTPUT); // Pin rojo del tercer LED RGB
    pinMode(10, OUTPUT); // Pin verde del tercer LED RGB
    pinMode(11, OUTPUT); // Pin azul del tercer LED RGB
 
    Serial.begin(9600);

}

void loop()
{
  	
	if(  digitalRead(2) == LOW )
    {
      	boton = !boton;
      	delay(tiempo);
    }

  	if( boton == true)
    {
      	contar = contar + 1;
      	boton = false;
    }


  	
  	Serial.print(contar);
  	Serial.print(" - resto:");
  	Serial.println( contar % 3 ) ;
  
  	
  	if( contar == 1 )
    {
        digitalWrite( 9 , LOW );
      	digitalWrite( 11 ,LOW );
      	digitalWrite( 3 , HIGH );
      	digitalWrite( 4 , HIGH ); //MAGENTA
      	digitalWrite( 5 , LOW );
    }


  	else if( contar == 2 ){
        digitalWrite( 3 , LOW );
      	digitalWrite( 4 , LOW  );
    	digitalWrite( 6 , LOW ); //CIAN
      	digitalWrite( 7 , HIGH );
      	digitalWrite( 8 , HIGH );
    }
  
  	else{
        digitalWrite( 7 , LOW );
      	digitalWrite( 8 ,LOW );
      	digitalWrite( 9 , HIGH );
      	digitalWrite( 10 , LOW );//AMARILLO
      	digitalWrite( 11 , HIGH );
      	contar = 0;
    }
  
  
  
}