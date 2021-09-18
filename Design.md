## Design

A fase **Design** remete-se a parte onde elaboramos uma idealização do projeto, como por exemplo:
 - Como será elaborado a maquete (materiais, idéias....);
 - Componentes utilizados (quantidade e especificações);
 - Mapeamento dos circuitos
 - entre outros.


### Maquete

Para a confecção da maquete da planta baixa definida na concepção iremos utilizar:

 - 2x placas de isopor largura aproximadamente 1cm;
 - 2x placas de isopor largura aproximadamente 3cm;
 - 1x Saco de palitos de picolé para maquete;
 - 2x caixas de palito de dente;
 - 1x tubo de cola de isopor (menor que tiver);
 - 1x tubo de super-cola (menor que tiver);
 - 1x caixa de tintas para pintura;
 - 1x fita adesiva;
 - 1x rolo de linha (de preferencia de diâmetro fino);
 
 Ferramentas:
  - Estilete;
  - Pincel;
  - Régua;
  - Caneta para marcação;



### Eletrônica

Para a parte eletrônica do projeto usaremos:

 - 1x Servo motor:  MG995 Lofty Ambition;
 - 8x LED Difuso 5mm Vermelho;
 - 1x Sensor de Gás MQ-2 Inflamável e Fumaça;
 - 1x Sensor de Umidade e Temperatura DHT11;
 - 1x Protoboard 830 Pontos;
 - 3x Kit Jumpers 10cm x120 Unidades
 - 5x Pilhas AA 1,5V
 - 1x Res 10k;
 - 8x Res 330Ohm  (no projeto foi usado de 470Ω, mas recomendo o de 330Ω para trabalhar com Leds vermelhos);
 - 1x Suporte para 4 pilhas AA;
 - 1x Arduino Mega 2560 R3.


### Informações sobre os Componentes

**Arduino:** [Placa MEGA 2560 R3 + Cabo USB para Arduino](https://www.filipeflop.com/produto/placa-mega-2560-r3-cabo-usb-para-arduino/)
      --> Coração do projeto, responsável pelos interpretar todos os dados recebidos pelos componentes e do teclado/computador, e realizar as funções definidas no código.

**Servo Motor:** [Servo TowerPro MG995 Metálico](https://www.filipeflop.com/produto/servo-towerpro-mg995-metalico/)
      --> ServoMotor, utilizado no controle do portão eletrônico, recebe um sinal digital do arduino e gira conforme uma instrução de posição.

**LEDS:** [LED Difuso 5mm Vermelho](https://www.filipeflop.com/produto/led-difuso-5mm-vermelho-x10-unidades/)
      --> Diodos emissores de luz, que simulam as lâmpadas em uma residência.

**Sensor de Gás:** [Sensor de Gas MQ-2 Inflamável e Fumaça](https://www.filipeflop.com/produto/sensor-de-gas-mq-2-inflamavel-e-fumaca/)
      --> Sensor de MQ2, é um sensor alimentado em 5V que emite um sinal Analógico pro arduino, que varia dependendo da quantidade de gás de cozinha ou fumaça detectado pelo sensor.

**Sensor de Temperatura e Umidade:** [Sensor de Umidade e Temperatura DHT11](https://www.filipeflop.com/produto/sensor-de-umidade-e-temperatura-dht11/)
      --> DHT11, é um sensor alimentado em 5V que envia um sinal digital para o arduino, com a temperatura e umidade detectado pelo mesmo.

**Protoboard:** [Protoboard 830 Pontos](https://www.filipeflop.com/produto/protoboard-830-pontos/)
      --> Protboard é uma placa utilizada em protótipos para fazer a ligação elétrica entre os componentes.

**Jumpers:** [Kit Jumpers 10cm x120 Unidades](https://www.filipeflop.com/produto/kit-jumpers-10cm-x120-unidades/)
      --> Fios para conexão elétrica.

**Pilhas:** [Pilha Alcalina AA](https://www.filipeflop.com/produto/pilha-alcalina-aa-elgin/)
      --> Pilhas de 1,5V que foram ligadas em séria para fornecer 6V para o servo motor.

**Resistor para DHT11:** [Resistor 10k](https://www.filipeflop.com/produto/resistor-10k%cf%89-14w-x20-unidades/)
      --> Resistor utilizado entre os pinos 1 e 2 do DHT11.

**Resistor para os Leds:** [Resistor 330](https://www.filipeflop.com/produto/resistor-330%cf%89-14w-x20-unidades/)
      --> Resistor utilizado para impedir que a corrente no pino digital do arduino ultrapassasse 10mA, o cálculo utilizado para definir essa especificação, foi uma simples lei de Ohm aplicada contando com a queda de tensão provida pelo Led escolhido ao fornecimento do Arduino.

**Suporte para Pilhas:** [Suporte 4 Pilhas AA](https://www.filipeflop.com/produto/suporte-4-pilhas-aa/)
      -->Durante a confecção do projeto foi elaborado um "substituto" pro suporte de pilhas, mas aconselho utilizar um suporte para evitar problemas de mal-conexão. 

### Maquete Eletrônica


![Maquete Eletrônica - versão 6.0:](https://github.com/CaioMeira/Projeto_Integrador_II_2021/blob/main/Imagens/Maquete%206.0.png)


Elaborado no Fritzing
