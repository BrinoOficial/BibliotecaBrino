/*
    EntradaAnalogica - Demonstra a leitura analogica da porta A0 por meio de um LED que acende a apaga. O tempo que ele permanece em cada estado depende da leitura.

    O circuito:
      Potentiometro  ligado ao 5V e ao GND com as pernas externas
    e a central conectada a porta analogica 0
      LED conectado a porta 13 e ao GND

      Nota: A maioria dos Arduinos possuem um LED on-board que pode ser controlado. No UNO e no Leonardo, ele esta conectado a porta digital 13.

     Codigo original para Arduino:
     http://arduino.cc/en/Tutorial/AnalogInput
*/

#include <Brino.h>

// Entrada do sensor
numero sensor = A0;
// Porta onde o LED esta ligado
numero LED = 13;
// Variavel para armazenar a leitura do sensor
numero leitura = 0;

configuracao() {
  // Declara o LED como saida:
  definirModo(LED, SAIDA);
}

principal() {
  // Le o sensor e armazena o valor:
  leitura = lerAnalogico(sensor);
  // Acende o LED
  ligar(LED);
  // Espera o valor da leitura em millisegundos
  esperar(leitura);
  // Desliga o LED
  desligar(LED);
  // Espera o valor da leitura em millisegundos
  esperar(leitura);
}