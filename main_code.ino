/*
---------Projeto Integrador II------------
Instituto Federal de Santa Catarina
Engenharia Eletrônica
Aluno: Caio Neves Meira


Tema: Domótica
                   
-------------------------------------------
*/


//-----------------------Bibliotecas
#include <Servo.h>
#include <DHT.h>
//------------------------Atribuição
#define led_quarto1 10
#define led_quarto2 9
#define led_banheiro1 8
#define led_banheiro2 7
#define led_sala 6
#define led_cozinha 5
#define led_garagem 4
#define led_entrada 3
#define MQ2 A15
#define DHTPIN 33
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
//------------------------Variáveis
Servo s;
int c = 0, pos = 25; //variáveis para controle da posição do servo motor
char keyboard = 0; //Usado como Hold para a tecla digitada pelo teclado.
int pinoservo = 31; //atribuição do sinal lógico do servomotor.
const unsigned long duracao_MQ2 = 1000; //duração do processo do sensor MQ2
unsigned long tempo_MQ2 = millis(); //tempo que a função está em execução
int MQ2_input; //Sinal recebido pelo MQ2
int MQ2_Limit = 250; //Limite do sensor MQ2, (caso o valor captado passe 250, ele emite um sinal)

//---------------------------------
void setup() {

  Serial.begin(9600); // inicialização com tempo padrão para checar o recebimento de dados do teclado.
  while (!Serial);
  
  s.attach(pinoservo);    //inicialização do servomotor
  s.write(25); //posição inicial do servo motor

  dht.begin(); //inicialização do sensor de temperatura e umidade
  
  pinMode(led_quarto1, OUTPUT);
  pinMode(led_quarto2, OUTPUT);
  pinMode(led_banheiro1, OUTPUT);
  pinMode(led_banheiro2, OUTPUT);
  pinMode(led_sala, OUTPUT);
  pinMode(led_cozinha, OUTPUT);
  pinMode(led_garagem, OUTPUT);
  pinMode(led_entrada, OUTPUT);
  
  
  pinMode(MQ2, INPUT);

}

void control() {
// ------------------ Funções controladas pelo teclado
  if (Serial.available() > 0){
    keyboard = Serial.read();
    Serial.println(keyboard);
    
    if (keyboard == '1'){
      digitalWrite(led_quarto1, !digitalRead(led_quarto1));  //controle dos LEDS dos cômodos
      Serial.print("Status do LED do Quarto 1 alterado\n");
    }
    if (keyboard == '2'){
      digitalWrite(led_quarto2, !digitalRead(led_quarto2));
      Serial.print("Status do LED do Quarto 2 alterado\n");
    }
    if (keyboard == '3'){
      digitalWrite(led_banheiro1, !digitalRead(led_banheiro1));
      Serial.print("Status do LED do Banheiro 1 alterado\n");
    }
    if (keyboard == '4'){
      digitalWrite(led_banheiro2, !digitalRead(led_banheiro2));
      Serial.print("Status do LED do Banheiro 2 alterado\n");
    }
    if (keyboard == '5'){
      digitalWrite(led_sala, !digitalRead(led_sala));
      Serial.print("Status do LED do Sala alterado\n");
    }
    if (keyboard == '6'){
      digitalWrite(led_cozinha, !digitalRead(led_cozinha));
      Serial.print("Status do LED do Cozinha alterado\n");
    }
    if (keyboard == '7'){
      digitalWrite(led_garagem, !digitalRead(led_garagem));
      Serial.print("Status do LED do Garagem alterado\n");
    }
    if (keyboard == '8'){
       digitalWrite(led_entrada, !digitalRead(led_entrada));
       Serial.print("Status do LED do Entrada alterado\n");
    }
    
    if (keyboard == 'g'){
      for(pos == 25 ; pos < 75; pos++){   //Controle de Abertura do Portão
        c = pos;
        s.write(c);
        //delay(10);
      }
      Serial.print("portão aberto");
    }
    if (keyboard == 'G'){                 //Controle de Fechamento do Portão
      for(pos == 75; pos > 25; pos--){
        c = pos;
        s.write(c);
        //delay(10);
      }
      Serial.print("portão fechado");
    }
    if (keyboard == 'b'){
      int MQ2_input = analogRead(MQ2);         //Printar na tela valor recebido pelo MQ2
      Serial.print("Valor deterctado pelo sensor:   ");
      Serial.println(MQ2_input);
    }
    if (keyboard == 'n'){
      float t = dht.readTemperature();       //Printar valor da Temperatura
      Serial.print("Temperatura:   ");
      Serial.print(t);
      Serial.print("  °C");
    }
    if (keyboard == 'm'){
      float h = dht.readHumidity();        //printar valor da Umidade
      Serial.print("Umidade:   ");
      Serial.print(h);
    }
  }
}

//----------------Sensor de Fumaça / Incêndio
void mq2(unsigned long start_time) {
   
    if(start_time - tempo_MQ2 > duracao_MQ2) {     //executa a tarefa apenas se estiver dentro do tempo definido

      tempo_MQ2 = start_time;
      int MQ2_input = analogRead(MQ2);
      if (MQ2_input > MQ2_Limit){
        Serial.print("    ATENÇÃO!, GÁS DETECTADO \n");
        Serial.print("    ATENÇÃO!, GÁS DETECTADO \n");
        Serial.print("    ATENÇÃO!, GÁS DETECTADO \n");
        Serial.print("    ATENÇÃO!, GÁS DETECTADO \n");
        Serial.print("");
        Serial.print("");
        Serial.print("\n");
        Serial.println(MQ2_input);
      }
    }

}
//------------------LOOP----------
void loop(){

  unsigned long timing = millis();      //atribui a "timing" o valor do tempo atual mantido em millis()
  
  control();  //inicia a função de controle por teclado
  mq2(timing); //inicia a função de leitura do MQ2
  
}
//-------------------------------
