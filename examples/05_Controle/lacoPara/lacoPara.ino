/*
    lacoPara - Demonstra o uso de um laco para() piscando um
    conjunto de LEDs. Primeiro eles serao piscados em uma ordem
    e, em seguida, em uma ordem contraria

    O circuito:
    - LEDs conectados da porta digital 2 ate a porta digital 7 e
    o GND

    Exemplo original do Arduino:
    http://www.arduino.cc/en/Tutorial/ForLoop
*/

#include <Brino.h>

// Tempo pelo qual cada LED vai ficar ligado
numero tempo = 100;

configuracao() {
  // Um laco para() e usado para configurar as portas
  para (numero essePino = 2; essePino < 8; essePino++) {
    definirModo(essePino, Saida);
  }
}

principal() {
  // Laco para() do primeiro LED ate o ultimo
  para (numero essePino = 2; essePino < 8; essePino++) {
    // Liga o LED
    ligar(essePino);
    esperar(tempo);
    // Desliga o LED
    desligar(essePino);
  }

  // Laco para() do ultimo ate o primeiro
  para (numero essePino = 7; essePino >= 2; essePino--) {
    // Liga o LED
    ligar(essePino);
    esperar(tempo);
    // Desliga o LED
    desligar(essePino);
  }
}