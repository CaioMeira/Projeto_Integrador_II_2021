### Implementação

Dividi a implementação em duas etapas: desenvolvimento e prototipagem.

#### Primeira Etapa: Desenvolvimento 

O foco foi em conferir se todas as partes estavam funcionando devidamente, 
e também para atribuir todas as funções em um único código

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

Para definir o Valor de MQ2_Limit, primeiro ajustei com um valor bem baixo, e fui elevando aos poucos até atingir um valor que evitasse alarmes falsos.

Parâmetro final ficou como: MQ2_Limit = 250


Para o PIR, havia três coisas para conferir:

 - Tempo que ele fica ativo até desligar
 - Distância máxima
 - componente com defeito.

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
 
A intenção deste código era fazer, a luz não desligar caso tenha sido acendida diretamente pelo comando do usuário, ou seja,
só iria desligar caso o LED fosse atendido pelo próprio sensor.

Porém não obtive sucesso.

Os parâmentros foram trocados várias vezes, o código foi testado de maneiras diferentes, mas mesmo assim não obtive sucesso com o componente.
Em nenhum momento ele detectou alguma presença, então foi considerado um mal-funcionamento do componente, e o mesmo foi removido do projeto.

Mas os parâmetros definidos seriam: 
- Desativar após 5 segundos;
- Detectar presença entre aproximadamente 0 e 3 metros.

Durante a elaboração do main code, código esse que unia todas as funções, sendo as funções usadas: control, e mq2

- control: Função onde o programa vai realizar uma função baseando-se na instrução passada pelo teclado, utilizada para controle dos LEDS, do servo motor e também para receber os valores atuais dos sensores MQ2 e DTH11.
- mq2: Função onde o programa iria emitir um alerta caso o sensor detecte um "valor" de gás ou fumaça excedente ao valor limite definido (250) e assim emitir um sinal de alerta na tela para o usuário
 
Para a função MQ2 foi definido um tempo limite para a execução da tarefa, utilizando a função Millis().
 
O código está presente no arquivo com nome maincode.ino na página inicial.


### Etapa 2: Prototipagem

Na etapa prototipagem o projeto primeiramente foi montado apenas na protoboard, basicamente serviu para que o [Main Code](https://github.com/CaioMeira/Projeto_Integrador_II_2021/blob/main/main_code.ino) fosse testado devidamente, com todas as funções em conjunto, e foi aí que percebemos que precisariamos de uma fonte externa para o Servo motor, já que não havia corrente suficiente para todo os projeto.

Após isso foi elaborado a confecção da Maquete, confesso que durante o processo, diversar vezes percebi que não tomei as melhores decisões, sendo elas compra dos fios, escala, fiação... e por ai vai.

Mas é com os erros que se aprende.

Continuando... Após a confecção da maquete foi implementado todos os componentes, e depois de diversos pequenos ajustes, o projeto estava pronto.

Fotos da Maquete pronta:

![Foto 1](https://github.com/CaioMeira/Projeto_Integrador_II_2021/blob/main/Imagens/Foto_Maquete%201.jpg)

![Foto 2](https://github.com/CaioMeira/Projeto_Integrador_II_2021/blob/main/Imagens/Foto_Maquete%202.jpg)

![Foto 3](https://github.com/CaioMeira/Projeto_Integrador_II_2021/blob/main/Imagens/Foto_Maquete%203.jpg)

![Foto 4](https://github.com/CaioMeira/Projeto_Integrador_II_2021/blob/main/Imagens/Foto_Maquete%204.jpg)

Vídeo da Maquete: [Link Youtube](https://youtu.be/MbB66qjz00Y)

## Mapeamento de Instruções para o usuário:

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
- 'b' = Printa a informação do Sensor MQ2
- 'n' = printa na tela o valor de temperatura
- 'm' = printa na tela o valor de umidade

