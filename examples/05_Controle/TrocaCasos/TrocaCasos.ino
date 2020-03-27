/*
  Chave seletora

  Demonstra o uso do seletor. O seletor e um comando que permite que voce escolha a partir
  de varios valores. E como uma serie de comparacoes.

  Para ver o codigo funcionando coloque-o na placa e o sensor uma sala bem iluminada,
  Entao abra o monitor USB e mova a sua mao gradativamente sore o sensor fazendo sombra

  O circuito:
  - LDR da porta analogica 0 para o +5V
  - Um resistor de 10K da porta analogica 0 pro GND

  Exemplo original do Arduino: http://www.arduino.cc/en/Tutorial/Switchcaso
*/

#include <Brino.h>

// Essas sao as constantes, elas nao mudam
// Elas delimitam a leitura minima e maxima do sensor
const Numero sensorMin = 0;      // Leitura minima, descoberta por experimentacao
const Numero sensorMax = 600;    // Leitura maxima, descoberta por experimentacao

Configuracao () {
  // Comeca uma comunicacao USB
  USB.conectar(9600);
}

Principal () {
  // Le o sensor:
  Numero leitura = lerAnalogico(A0);
  //Faz uma regra de tres com as leituras do sensor e seu minimo e maximo
  Numero intervalo = proporcionar(leitura, sensorMin, sensorMax, 0, 3);

  // Seleciona o que fazer de acordo com a entrada
  seletor (intervalo) {
caso 0:
    USB.enviarln("escuro");
    quebrar;
caso 1:
    USB.enviarln("penumbra");
    quebrar;
caso 2:
    USB.enviarln("medio");
    quebrar;
caso 3:
    USB.enviarln("claro");
    quebrar;
  }
  esperar(20);        // esperar entre as leituras
}