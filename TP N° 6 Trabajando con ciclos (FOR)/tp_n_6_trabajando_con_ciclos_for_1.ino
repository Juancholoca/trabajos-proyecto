#define LED_R 3
#define LED_G 5
#define LED_B 6

void setup()
{
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
  Serial.begin(9600);
}

void loop()
{	  
  for (int r = 0; r <= 255; r+= 51){
  for (int g = 0; g <= 255; g+= 51){
  for (int b = 0; b <= 255; b+= 51){
  
    analogWrite( LED_R , r);
  	analogWrite( LED_G , g);
    analogWrite( LED_B , b);
  	delay(200);
   } 
  }
 }
}