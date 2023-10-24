int pinLed1 = 9;
int pinLed2 = 10;
int pinLed3 = 11;

void setup()
{
  pinMode(pinLed1, OUTPUT);
  pinMode(pinLed2, OUTPUT);
  pinMode(pinLed3, OUTPUT);
  
  Serial.begin (9600);
  Serial.println ("Arduino Inicializado");
  
}
void loop()
{
  Serial.println ("LED Vermelho Ligado");
  digitalWrite(pinLed1, HIGH);
  
  Serial.println ("LED Amarelo Desligado");
  digitalWrite(pinLed2, LOW);
  
  Serial.println ("LED Verde Desligado");
  digitalWrite(pinLed3, LOW);

//    delay(2000);

    Serial.println ("LED Vermelho Desligado");
  digitalWrite(pinLed1, LOW);
  
  Serial.println ("LED Amarelo Desligado");
  digitalWrite(pinLed2, HIGH);
  
  Serial.println ("LED Verde Desligado");
  digitalWrite(pinLed3, LOW);

//    delay(2000);

  Serial.println ("LED Vermelho Desligado");
  digitalWrite(pinLed1, LOW);
  
  Serial.println ("LED Amarelo Desligado");
  digitalWrite(pinLed2, LOW);
  
  Serial.println ("LED Verde Desligado");
  digitalWrite(pinLed3, HIGH);

//  delay(2000);
  
//  Serial.println ("LED Vermelho Desligado");
//  digitalWrite(pinLed1, LOW);
//  
//  Serial.println ("LED Amarelo Desligado");
//  digitalWrite(pinLed2, LOW);
//  
//  Serial.println ("LED Verde Desligado");
//  digitalWrite(pinLed3, LOW);
//  
//  delay(1000);
    
}
