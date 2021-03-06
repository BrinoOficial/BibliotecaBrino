/*
    Piscar - Acende um LED por um segundo e o apaga, repetidamente.
    A maioria dos Arduinos possuem um LED on-board que pode ser controlado.
    No UNO e no Leonardo, ele esta conectado a porta digital 13. Se voce nao
    sabe em qual porta ele esta conectado em seu Arduino, leia a documentacao
    no site: arduino.cc
*/

#include <Brino.h>

// Parte do codigo de configuracao
configuracao() {
  // inicia a porta digital 13 como uma saida(OUTPUT)
  definirModo(13, SAIDA);
}

// Loop que se repete indefinidamente
principal() {
  ligar(13);
  // liga a porta digital acedendo o LED
  esperar(1000);
  // espera por um segundo
  desligar(13);
  // desliga a porta digital apagando o LED
  esperar(1000);
  // espera por um segundo
}