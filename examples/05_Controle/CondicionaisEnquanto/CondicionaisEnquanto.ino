/*
    CondicionaisEnquanto - Esse exemplo demonstra o uso do laco
    enquanto(). Enquanto um botao estiver pressionado ele entra
    em um codigo de calibracao que busca valores minimos e maximos
    de leitura. No resto do tempo ele aplica esses parametros e a
    leitura do sensor para controlar um LED.

    O circuito:
    - Sensor analogico (como por exemplo um LDR) conectado a porta
    analogica 0
    -LED conectado a porta 9 e ao GND
    -Botao conectado a porta 2 e ao 5V
    -Resistor de 10K Conectado a porta 2 e ao GND

    Codigo original para o Arduino:
    http://www.arduino.cc/en/Tutorial/WhileLoop
*/

#include <Brino.h>

// Constantes
// Porta em que o sensor esta conectado
Constante numero SENSOR = A0;
// Porta em que o LED esta conectado
Constante numero LED = 9;
// Porta em que o LED que indica que ele esta calibrando esta conectado
Constante numero LEDDEINDICACAO = 13;
// Porta em que o botao esta conectado
Constante numero BOTAO = 2;

// Variaveis
// variavel para guardar a menor leitura do sensor
numero leituraMin = 1023;
// variavel para guardar a maior leitura do sensor
numero leituraMax = 0;
// variavel para guardar a leitura do sensor
numero leitura = 0;

configuracao() {
  // Configura as portas
  definirModo(LEDDEINDICACAO, SAIDA);
  definirModo(LED, SAIDA);
  definirModo(BOTAO, ENTRADA);
}

principal() {
  // Enquanto o botao estiver pressionado ele entra na funcao calibrar() que foi declarada mais adiante
  enquanto (lerDigital(BOTAO) == LIGADO) {
    calibrar();
  }
  // Apaga o LED indicando o fim da calibracao
  desligar(LEDDEINDICACAO);

  // Efetua a leitura do sensor e guarda o valor em "leitura"
  leitura = lerAnalogico(SENSOR);

  // Aplica a calibracao
  leitura = proporcionar(leitura, leituraMin, leituraMax, 0, 255);

  // Obriga o valor a estar dentro dos parametros
  leitura = constrain(leitura, 0, 255);

  // Ajusta o brilho do LED
  escreverAnalogico(LED, leitura);
}

semRetorno calibrar() {
  // Liga o LED para indicar que esta acontecendo a calibracao
  ligar(LEDDEINDICACAO);
  // Executa a leitura do sensor e armazena em "leitura"
  leitura = lerAnalogico(SENSOR);

  // Salva a maior leitura
  se (leitura > leituraMax) {
    leituraMax = leitura;
  }

  // Salva a menor leitura
  se (leitura < leituraMin) {
    leituraMin = leitura;
  }
}