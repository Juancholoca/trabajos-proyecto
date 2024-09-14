#define NOTE_GS4 415
#define NOTE_F4  349
#define NOTE_AS5 466 
#define NOTE_C5  523
#define NOTE_B4  494
#define NOTE_C4  262
#define NOTE_DS4 311
#define NOTE_D4  294
#define NOTE_CS4 277
#define NOTE_CS5 554
#define NOTE_G4  392

#define MSG(a,b,c,d,e,f) Serial.print("Nota total: ");Serial.print(a);Serial.print(" Figura: ");Serial.print(b);Serial.print(" Duracion: ");Serial.print(c);Serial.print(" Silencio: ");Serial.print(d);Serial.print(" Tone duracion:");Serial.print(e);Serial.print(" Delay: ");Serial.println(f);

#define length(vec,tipo) sizeof(vec)/sizeof(tipo)


 //int notes[] = {415, 349, 349, 466, 523, 494, 466, 415, 349, 262, 311, 349, 415, 294, 294, 466, 523, 494, 466, 415, 349, 262, 311, 349, 415, 277, 277, 466, 523, 494, 466, 415, 349, 262, 311, 349, 415, 349, 415, 466, 523, 554, 523, 466, 415, 392, 349, 262, 311, 349};
int nota[] = {NOTE_GS4, NOTE_F4, NOTE_F4, NOTE_AS5, NOTE_C5, NOTE_B4, NOTE_AS5, NOTE_GS4, NOTE_F4, NOTE_C4, NOTE_DS4, NOTE_F4, NOTE_GS4, NOTE_D4, NOTE_D4, NOTE_AS5, NOTE_C5, NOTE_B4, NOTE_AS5, NOTE_GS4, NOTE_F4, NOTE_C4, NOTE_DS4, NOTE_F4, NOTE_GS4, NOTE_CS4, NOTE_CS4, NOTE_AS5, NOTE_C5, NOTE_B4, NOTE_AS5, NOTE_GS4, NOTE_F4, NOTE_C4, NOTE_DS4, NOTE_F4, NOTE_GS4, NOTE_F4, NOTE_GS4, NOTE_AS5, NOTE_C5, NOTE_CS5, NOTE_C5, NOTE_AS5, NOTE_GS4, NOTE_G4, NOTE_F4, NOTE_C4, NOTE_DS4, NOTE_F4};
int figura[] = {16, 4, 4, 16, 16, 8, 8, 8, 16, 8, 8, 8, 16, 4, 4, 16, 16, 8, 8, 8, 16, 8, 8, 8, 16, 4, 4, 16, 16, 8, 8, 8, 16, 8, 8, 8, 8, 8, 8, 16, 16, 8, 8, 8, 8, 8, 8, 8, 8, 8};


//{16, 32, 32, 16, 16, 32, 32, 32, 16, 32, 32, 32, 16, 32, 32, 16, 16, 32, 32, 32, 16, 32, 32, 32, 16, 32, 32, 16, 16, 32, 32, 32, 16, 32, 32, 32, 32, 32, 32, 16, 16, 32, 32, 32, 32, 32, 32, 32, 32, 32};

  //{273, 102, 102, 273, 273, 136, 136, 136, 273, 136, 136, 136, 273, 102, 102, 273, 273, 136, 136, 136, 273, 136, 136, 136, 273, 102, 102, 273, 273, 136, 136, 136, 273, 136, 136, 136, 136, 136, 136, 273, 273, 136, 136, 136, 136, 136, 136, 136, 136, 136};

/*
 2  redonda
 4  blanca
 8  negra
 16 corchea
 32 semi-corchea
*/

int BPM = 110;
float tiempoSilencio = 1.0;
int duracionTotalNota = (60000 * 4) / BPM;


void setup() {
    pinMode( 6 , OUTPUT);
      Serial.begin(9600);
}


// tone( pin , nota , duracion)  ->  toca una nota durante X tiempo
// delay( duracion  )            -> duracion entre notas
// noTone( pin )                 -> deje de sonar la nota

void loop() {
  //CICLO  FOR
  for( int i = 0 ; i < length(nota,int)-1 ; i++ )
  {
    if( figura[i] >= 0 )
    {
        //figura es POSITIVA
          int duracionNota = ( duracionTotalNota / figura[i] )  ;
          tone( 6 , nota[i] , duracionNota * 0.9 ); //el 0.8  no son obligatorio
          delay( duracionNota );  //el 1.3  no son obligatorio
          noTone(6);
        //MSG( duracionTotalNota, figura[i] , duracionNota,  tiempoSilencio, duracionNota*0.8 , duracionNota*1.3 );
    }else{
        //figura es NEGATIVA
            int duracionNota = ( duracionTotalNota / (figura[i]*(-1)) )  ;
            tone( 6 , nota[i] , duracionNota * 0.9 );
              delay( duracionNota  );
              noTone(6);
          //MSG( duracionTotalNota, figura[i] , duracionNota,  tiempoSilencio, duracionNota*0.8 , duracionNota );
    }
 }
}

