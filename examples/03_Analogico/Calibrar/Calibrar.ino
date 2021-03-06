/*
  Calibrar - Demonstra uma tecnica de calibrar a entrada de um sensor. As entradas do sensor sao usadas pelos primeiros cinco segundos para definir os parametros minimos e maximos que serao usados.

    O circuito:
    - Sensor analogico (como por exemplo um potenciometro) conectado a porta analogica 0
    - LED conectado na porta 9 e ao GND

    Exemplo original do Arduino:
    http://www.arduino.cc/en/Tutorial/Calibration
*/

#include <Brino.h>

// Constantes:
Constante numero SENSOR = A0;
Constante numero LED = 9;

// Variaveis:
numero leitura = 0;
numero leitueaMin = 1023;
numero leituraMax = 0;


configuracao() {
  // Liga o LED para indicar que esta no periodo de calibracao
  definirModo(13, SAIDA);
  ligar(13);

  // calibra durante os primeiros cinco segundos
  enquanto (cronometro() < 5000) {
    leitura = lerAnalogico(SENSOR);

    // Armazena o maior valor encontrado em "leituraMax"
    se (leitura > leituraMax) {
      leituraMax = leitura;
    }

    // Armazena o menor valor encontrado em "leituraMin"
    se (leitura < leitueaMin) {
      leitueaMin = leitura;
    }
  }

  // Desliga o LED indicando o fim da calibracao
  desligar(13);
}

principal() {
  // Faz a leitura do sensor
  leitura = lerAnalogico(SENSOR);

  // Aplica a calibracao
  leitura = proporcionar(leitura, leitueaMin, leituraMax, 0, 255);

  // Para caso o valor esteja fora do intervalo
  leitura = constrain(leitura, 0, 255);

  // Indica o valor com base no brilho do LED
  escreverAnalogico(LED, leitura);
}