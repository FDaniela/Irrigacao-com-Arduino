/*******************************************************************************
* Projeto Irrigador Automatico/Manual de Solo (v1.0)
* 
* Este codigo monitora a umidade do solo, convertendo a leitura do sensor para 
* um valor entre 0 e 100 %. Verificado a necessidade de irrigação do solo, ocorre
* o acionamento da bomba peristáltica (utilizamos um motor de passo para fins didáticos).
* 
*******************************************************************************/

#include <Stepper.h>
#define botao 12

//Altere este valor para ajustar o número de passos por revolução do seu motor (Equivale a 1 volta completa).
const int passosporgiro = 600;

//Inicialização da Biblioteca Stepper.h e configuração dos pinos 8 ate o 11.
Stepper mp(passosporgiro, 8, 10, 9, 11);

//Declaracao do pino conectado ao sensor
const int PINO_SENSOR = A0;

//Declaracao da variavel que armazena as leituras do sensor
int leitura_sensor = 0;

//Declaracao da variavel auxiliar para o "delay" de 10 segundos
bool pausa = true;

//837
//

//Declaracao das variaveis que armazenam os valores de calibracao
const int VALOR_MAXIMO = 840; //Valor com solo seco
const int VALOR_MINIMO = 700; //Valor com solo umido
//Altere o valor das variaveis acima de acordo com as medias obtidas atraves da leitura padrão do sensor.

//Declaracao das variaveis que armazenam a concentracao maxima e minima desejada em %
const int CONCENTRACAO_MINIMA = 30;
const int CONCENTRACAO_MAXIMA = 90;
//Altere as variaveis acima com os valores ideais para a sua planta

//*******************************************************************************

void setup() {
  
  //Definindo Rotações por minuto do motor de passo (RPM).
  mp.setSpeed(50);
  
  //Define o Pino como Entrada de Dados.
  pinMode(botao, INPUT);

  // Define o pino do Motor como Saida de Dados.
  pinMode(passosporgiro, OUTPUT);

  //Define o Pino conectado ao sensor como uma Entrada de Dados.
  pinMode(PINO_SENSOR, INPUT);
  
  //Inicialização da Porta Serial (Monitor Serial).
  Serial.begin(9600);
}

//*******************************************************************************

void loop() {

  //Realiza a leitura do sensor, mapeando seus valores entre 0 e 100 %.
  leitura_sensor = analogRead(PINO_SENSOR);
  leitura_sensor = map(leitura_sensor, VALOR_MINIMO, VALOR_MAXIMO, 100, 0);
  Serial.println("Valor em: " + String(leitura_sensor) + "%");


  //Condição para identificar o status do Botão - 0 ou 1
  if (digitalRead(botao)== HIGH){ //Se o botão foi pressionado, faça
    Serial.println("Irrigação Manual"); // Imprime a frase no monitor serial
    mp.step(passosporgiro); //Acionamento do motor de passo
    

    //Verificando se a leitura esta abaixo da concetracao minima desejada:
  } else if(leitura_sensor < CONCENTRACAO_MINIMA){ //Se sim
      Serial.println("Irrigando a planta ..."); // Imprime a frase no monitor serial
      mp.step(passosporgiro); //Acionamento do motor de passo
      pausa = false; //Configura a variavel "pausa" como falsa
      } else if (leitura_sensor > CONCENTRACAO_MAXIMA) { //Caso contrario
          pausa = true; //Configura a variavel "pausa" como verdadeira
          }

  //Verifica se a variavel "pausa" e verdadeira
  if(pausa = true && leitura_sensor >= 30){ //Se sim
    //Aguarda 3 segundos para uma nova leitura
    delay(3000);
  }

}
