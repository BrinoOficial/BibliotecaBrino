/*
    LeituraAnalogicaSerial - Le a entrada analogica do pino 0 e apresenta o valor no monitor serial. Conecte o pino central de um potenciometro a porta A0 e os pinos externos dele as portas de alimentacao 5V e ao GND.
*/

#include <Brino.h>

// Parte do codigo de configuracao
Configuracao() {     // Inicia a comunicacao serial padrao pelo USB com a taxa de transmissao em 9600.
  USB.conectar(9600);
}

// Loop que se repete indefinidamente
Principal() {
  // Le a entrada da porta analogica A0:
  Numero leitura = lerAnalogico(A0);
  // Apresenta no monitor serial o valor lido:
  USB.enviarln(leitura);
  //tempo entre uma medida e outra
  esperar(200);
}