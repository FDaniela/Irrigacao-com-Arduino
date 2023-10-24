//Declaracao do pino conectado ao sensor
const int PINO_SENSOR = A0;

//Declaracao da variavel que armazena as leituras do sensor
int leitura_sensor = 0;

// Declaração da variavel que armazena a quantidade de amostras que deeja coletar para o calculo da media
const int NUMERO_AMOSTRAS = 100;

//declaração de variaveis que armazena a soma das leituras
long somatorio=0;

void setup() {
  
  Serial.begin(9600);
  Serial.println("                 ----*****----               ");
  Serial.println("Sensor de Umidade de Solo Capacitivo - Primeiros Passos");
  Serial.println("Coletando media de leituras do sensor...");
  Serial.println("");


  //Define o Pino conectado ao sensor como uma Entrada de Dados.
  pinMode(PINO_SENSOR, INPUT);
  
  //Inicialização da Porta Serial (Monitor Serial).

  for(int i=1; i<=NUMERO_AMOSTRAS;i++){
    leitura_sensor=analogRead(PINO_SENSOR);
    somatorio=somatorio+leitura_sensor;
//    somatorio += leitura_sensor;
     float tensao = leitura_sensor*(5.0/1023);
     Serial.print("Amostra ");
     Serial.print(i);
     Serial.print(" | ");
     Serial.print("Leitura: ");
     Serial.print(leitura_sensor);
     Serial.print(" | ");
     Serial.print("Tensao ");
     Serial.println(tensao);
     delay(1000);
  }

  int media=  somatorio/NUMERO_AMOSTRAS;
  Serial.println("");
  Serial.print("Media Obtida: ");
  Serial.println(media);
}

//*******************************************************************************

void loop() {


}
