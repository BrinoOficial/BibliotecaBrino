# Biblioteca Brino

Uma biblioteca que possibilita o uso dos termos da limguagem/IDE Br.ino na IDE do Arduino. 

## Conheça nossa IDE

## Os termos (documentação)

A lista completa dos comandos existentes na linguagem está disponível [aqui.](https://brino.cc/dicionario)
Infelizmente nem todos os comandos estão compativeis com a versãobiblioteca da linguagem. Segue abaixo a lista dos comandos não compativeis:


## Exemplos da limguagem

```c++
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
```

```c++
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
```
## Como instalar e usar essa biblioteca

## Contato

Nosso site: [https://brino.cc/](https://brino.cc/)

Email: contato@brino.cc


