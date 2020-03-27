/*
    LerVoltagemAnalogica - Le a entrada analogica do pino 0 e apresenta a voltagem no monitor serial. conecte o pino central de um potenciometro a porta A0 e os pinos externos dele as portas de alimentacao 5V e ao GND.
*/

#include <Brino.h>

// Parte do codigo de configuracao
Configuracao() { // Inicia a comunicacao serial padrao pelo USB com a taxa de transmissao em 9600.
  USB.conectar(9600);
}

// Loop que se repete indefinidamente
Principal() {
  // Le a entrada da porta analogica A0:
  Numero leitura = lerAnalogico(A0);
  // Converte a entrada analogica(que vai de 0 a 1023) na voltagem que esta entrando (0 - 5V):
  NumeroDecimal voltagem = leitura * (5.0 / 1023.0);
  // Apresenta no monitor serial a voltagem:
  USB.enviar(voltagem);
  USB.enviarln(" V");
  //tempo entre uma medida e outra
  esperar(200);
}