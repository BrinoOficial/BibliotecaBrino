/*
    ComecaComETerminaCom - Aplica os comandos startsWith() e endsWith() em strings

    O circuito: Nenhum hardware alem de seu arduino sera nescessario

    Exemplo original do Arduino:
    http://www.arduino.cc/en/Tutorial/StringStartsWithEndsWith
*/

#include <Brino.h>

Configuracao() {
  // Inicia a comunicacao com o computador
  USB.conectar(9600);
  enquanto (!USB) {
    ; // Espera a porta estar conectada
  }

  // Envia um titulo
  USB.enviarln("startsWith() e endsWith():\n");
}

Principal() {
  // startsWith() checa se uma String scomeca com uma substring em especifico
  Palavra frase = "HTTP/1.1 200 OK";
  USB.enviarln(frase);
  se (frase.startsWith("HTTP/1.1")) {
    USB.enviarln("O servidor esta usando a versao 1.1");
  }

  // A funcao startsWith() pode receber um argumento representando um deslocamento de onde deve comecar a procurar
  Palavra primeiraPalavra = "HTTP/1.1 200 OK";
  se (primeiraPalavra.startsWith("200 OK", 9)) {
    USB.enviarln("Recebeu um do servidor");
  }

  // A funcao endWith() verifica se a string termina em um caractere em especifico
  Palavra leituraSensor = "sensor = ";
  leituraSensor += lerAnalogico(A0);
  USB.enviar(leituraSensor);
  se (leituraSensor.endsWith("0")) {
    USB.enviarln(". Essa leitura é divisivel por dez");
  } senao {
    USB.enviarln(". Essa leitura nao é divisivel por dez");
  }

  // Para o codigo
  enquanto (VERDADEIRO);
}