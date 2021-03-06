/*
  Amortecer - Esse exemplo mostra como "graduar"  um LED ligado a porta 9
  fazendo com que ele se acenda e apague lentamente
  usando a funcao escreverAnalogivo(Porta, Valor).
*/

#include <Brino.h>

// A porta em que o Led esta ligado
numero LED = 9;
// variavel de brilho
numero brilho = 0;
// constante de mudanca
numero mudanca = 5;

// Parte do codigo de configuracao
configuracao() {
  // declara o pino 9 como uma saida
  definirModo(LED, Saida);
}

// Loop que se repete indefinidamente
principal() {
  // escreve o brilho do LED
  escreverAnalogico(LED, brilho);
  // Muda o brilho para a proxima passagem do loop
  brilho = brilho + mudanca;
  // Muda o "sentido" da mudanca quando ela chega em um dos extremos
  se (brilho == 0 ou brilho == 255) {
    mudanca = -mudanca;
  }

  // tempo para que seja possivel observar o efeito
  esperar(30);
}