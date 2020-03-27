/*
    LeituraDigitalSerial - Le a entrada digital do pino 2 e apresenta o valor no monitor serial.
*/

#include <Brino.h>

// possui um botao conectado a porta digital 2. Vamos dar um nome a ele:
Numero botao = 2;

// Parte do codigo de configuracao
Configuracao() {      // Inicia a comunicacao serial padrao com a taxa de transmissao em 9600
  USB.conectar(9600);
  // define o botao como uma entrada:
  definirModo(botao, ENTRADA);
}

// Loop que se repete indefinidamente
Principal() {
  // Le o pino de entrada
  Numero estadoBotao = lerDigital(botao);
  // Apresenta no monitor serial o estado do botao:
  USB.enviarln(estadoBotao);
  //tempo entre uma medida e outra
  esperar(500);
}