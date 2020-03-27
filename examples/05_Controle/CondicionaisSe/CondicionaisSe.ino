/*
    CondicionaisSe - Esse exemplo demonstra como usar a condicional
    se(). Esse codigo faz uma leitura analogica e decide se um LED
    deve ou nao acender comparando a leitura com um valor previamente
    estabelecido.

    O circuito:
    - Sensor analogico (como por exemplo um potenciometro) conectado
    a porta analogica 0
    - LED conectado na porta 13 e ao GND

    -Nota: Na maioria dos arduinos existe um LED interno conectado
    na porta 13

    Codigo original para o Arduino:
    http://www.arduino.cc/en/Tutorial/IfStatement
*/

#include <Brino.h>

// Constantes
// Porta na qual o sensor esta conctado
Constante Numero SENSOR = A0;
// Porta na qual o LED esta conectado
Constante Numero LED = 13;
// Referencial para a mudanca
Constante Numero LIMIAR = 400;

Configuracao() {
  // Define o LED como uma saida
  definirModo(LED, SAIDA);
  // Inicia a comunicacao com o computador
  USB.conectar(9600);
}

Principal() {
  // Faz a leitura do sensor e armazena em "leitura"
  Numero leitura = lerAnalogico(SENSOR);

  // Se a leitura for alta o bastante liga o LED
  se (leitura > LIMIAR) {
    ligar(LED);
    // Caso contrario desliga o LED
  } senao {
    desligar(LED);
  }

  // Mostra a leitura no monitor serial
  USB.enviarln(leitura);
  // Tempo entre as leituras
  esperar(1);
}