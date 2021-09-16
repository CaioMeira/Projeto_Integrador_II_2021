### Implementação

Dividi a implementação em duas etapas: desenvolvimento e prototipagem.

#### Primeira Etapa: Teste 

O foco foi em conferir se todos os componentes estavam funcionando devidamente, 
e também para definir os parâmetros de limite, tanto para o MQ2, quanto para o PIR.
Esses parâmetros foram definidos conforme a necessidade do uso

Para o MQ2, foi utilizado a função

~~~C
MQ2_input = analogRead(MQ2);
Serial.println(MQ2)
if (MQ2_input > MQ2_Limit){
        Serial.print("    ATENÇÃO!, GÁS DETECTADO \n");
        Serial.print("    ATENÇÃO!, GÁS DETECTADO \n");
        Serial.print("    ATENÇÃO!, GÁS DETECTADO \n");
        Serial.print("    ATENÇÃO!, GÁS DETECTADO \n");
        }
  ~~~       

Com isso fui elevando o valor do MQ2_Limit, até o ponto onde as condições normais do ambiente não acionassem o sensor,
também adicionei uma margem um pouco maior, para evitar falsos alarmes.

Parâmetro final ficou como: MQ2_Limit = 750


Para o PIR, havia três coisas para conferir:

-Tempo que ele fica ativo até desligar
-Distância máxima
-componente com defeito.

Sendo os dois primeiros, "configurados" pelos potenciômetros presentes no mesmo.

E na terceira parte foi elaborado um código para acender um LED, caso uma presença fosse detectada, para testar se o componente estava funcionando ou não.

~~~C
PIR_input = digitalRead(PIR);
    if(PIR_input == HIGH && led_entrada == LOW) {
      digitalWrite(led_entrada, HIGH);                      
      z = 1;
      }
    }
    if(PIR_input == LOW && z == 1) {
      digitalWrite(led_entrada, LOW);
      z = 0;
    }
 ~~~
 
A intenção deste código era fazer, a luz não desligar caso tenha sido acendida diretamente pelo comando do usuário, Ou seja,
Só iria desligar caso o LED fosse atendido pelo próprio sensor.

Porém não obtive sucesso.

Os parâmentro foram trocados várias vezes, o código foi testado de maneiras diferentes, mas mesmo assim não obtive sucesso com o componente.
Em nenhum momento ele detectou alguma presença, então foi considerado um mal-funcionamento do componente.

Mas os parâmetros definidos seriam: 
>Desativar após 5 segundos;
>Detectar presença entre aproximadamente 0 e 3 metros.

Obs: Todos os códigos de testes completos ficarão disponíveis na pasta "Testes" na página inicial desse repertório.

### Segunda Etapa: Desenvolvimento

Na segunda etapa foi elaborado o main code, código esse que unia todas as funções, sendo as funções usadas: control, pir e mq2

- control: Função onde o programa vai realizar uma função baseando-se na instrução passada pelo teclado, utilizada para controle dos LEDS e do servo motor.
- mq2: Função onde o programa iria emitir um alerta caso o sensor detecte um "valor" de gás ou fumaçã excedente ao valor limite definido (750) e assim emitir um sinal de alerta para o usuário
- pir: função onde o programa iria receber um sinal de presença do sensor PIR e acender o led da entrada da casa, e apagar o mesmo, se e somente se, o led foi acionado por essa
       função, e não pelo acionamento manual do usuário.
 
para ambas as funções mq2, e pir foram definidos tempos limites para a tarefa.
 
Segue o código:

~~~C
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
//------------------------Atribuição
#define led_quarto1 10
#define led_quarto2 9
#define led_banheiro1 8
#define led_banheiro2 7
#define led_sala 6
#define led_cozinha 5
#define led_garagem 4
#define led_entrada 3
#define PIR 30
#define MQ2 A15
//------------------------Variáveis
Servo s;
int i = 0, c = 0, pos = 10, z = 0;
char keyboard = 0;
int pinoservo = 31;
const unsigned long duracao_MQ2 = 1000, duracao_PIR = 2500;
unsigned long tempo_MQ2 = millis(), tempo_PIR = millis(), timing = 0;
int PIR_input, MQ2_input;
int MQ2_Limit = 750;

//---------------------------------
void setup() {

  Serial.begin(9600);
  while (!Serial);
  
  s.attach(pinoservo);
  s.write(15);

  pinMode(led_quarto1, OUTPUT);
  pinMode(led_quarto2, OUTPUT);
  pinMode(led_banheiro1, OUTPUT);
  pinMode(led_banheiro2, OUTPUT);
  pinMode(led_sala, OUTPUT);
  pinMode(led_cozinha, OUTPUT);
  pinMode(led_garagem, OUTPUT);
  pinMode(led_entrada, OUTPUT);
  
  pinMode(PIR, INPUT);
  pinMode(MQ2, INPUT);

}

void control() {
// ------------------ Funções controladas pelo teclado
  if (Serial.available() > 0){
    keyboard = Serial.read();
    Serial.println(keyboard);
    
    if (keyboard == '1'){
      digitalWrite(led_quarto1, !digitalRead(led_quarto1));
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
      if (PIR_input == LOW){
        digitalWrite(led_entrada, !digitalRead(led_entrada));
        Serial.print("Status do LED do Entrada alterado\n");
      }
      else {
        digitalWrite(led_entrada, HIGH);
        Serial.print("Sensor de presença detectou algo, Led da entrada ativo!\n");
      }
    }
    if (keyboard == 'g'){
      for(pos == 15 ; pos < 105; pos++){
        c = pos;
        s.write(c);
        //delay(15);
      }
      Serial.print("portão aberto");
    }
    if (keyboard == 'G'){
      for(pos == 105; pos > 15; pos--){
        c = pos;
        s.write(c);
        //delay(15);
      }
      Serial.print("portão fechado");
    }
  }
}

//-----------------------Sensor de presença
void pir(unsigned long start_time) {

  if(start_time - tempo_PIR > duracao_PIR) {
    
    tempo_PIR = start_time;
    PIR_input = digitalRead(PIR);
    if(PIR_input == HIGH && led_entrada == LOW) {
      digitalWrite(led_entrada, HIGH);                      
      z = 1;
      }
    }
    if(PIR_input == LOW && z == 1) {
      digitalWrite(led_entrada, LOW);
      z = 0;
    }
  }
}
}

//----------------Sensor de Fumaça / Incêndio
void mq2(unsigned long start_time) {
   
    if(start_time - tempo_MQ2 > duracao_MQ2) {

      tempo_MQ2 = start_time;
      MQ2_input = analogRead(MQ2);
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

  while(i < 1) {
  
    Serial.print("      Sistema de controle Ativado!");
    Serial.print("");
    Serial.print("");
    Serial.print("  \n");
    i = 2;
    }

  timing = millis();
  
  control();
  pir(timing);
  mq2(timing);
  
}
//-------------------------------
~~~

### Etapa 3: Prototipagem


Na etapa prototipagem, o sistema foi montado, para conferir se todas as funções estavam funcionando corretamente em conjunto.
Como já esperávamos pelos testes, a função PIR, não está funcional, devido a um possível mal-funcionamento do componente, mas todas as outras funções funcionaram corretamente.

Segue a lista de instruções para o usuário:

- '1' = Led do Quarto 1
- '2' = Led do Quarto 2
- '3' = Led do Banheiro 1
- '4' = Led do Banheiro 2
- '5' = Led da Sala
- '6' = Led da Cozinha
- '7' = Led da Garagem
- '8' = Led da entrada
- 'g' = Abre o portão
- 'G' = Fecha o portão

