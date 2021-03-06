/*
    ComecaComETerminaCom - Aplica os comandos comecaCom() e terminaCom() em strings

    O circuito: Nenhum hardware alem de seu arduino sera nescessario

    Exemplo original do Arduino:
    http://www.arduino.cc/en/Tutorial/StringcomecaComterminaCom
*/

#include <Brino.h>

configuracao() {
  // Inicia a comunicacao com o computador
  USB.conectar(9600);
  enquanto (!USB) {
    ; // Espera a porta estar conectada
  }

  // Envia um titulo
  USB.enviarln("comecaCom() e terminaCom():\n");
}

principal() {
  // comecaCom() checa se uma String scomeca com uma substring em especifico
  Palavra frase = "HTTP/1.1 200 OK";
  USB.enviarln(frase);
  se (frase.comecaCom("HTTP/1.1")) {
    USB.enviarln("O servidor esta usando a versao 1.1");
  }

  // A funcao comecaCom() pode receber um argumento representando um deslocamento de onde deve comecar a procurar
  Palavra primeiraPalavra = "HTTP/1.1 200 OK";
  se (primeiraPalavra.comecaCom("200 OK", 9)) {
    USB.enviarln("Recebeu um do servidor");
  }

  // A funcao endWith() verifica se a string termina em um caractere em especifico
  Palavra leituraSensor = "sensor = ";
  leituraSensor += lerAnalogico(A0);
  USB.enviar(leituraSensor);
  se (leituraSensor.terminaCom("0")) {
    USB.enviarln(". Essa leitura é divisivel por dez");
  } senao {
    USB.enviarln(". Essa leitura nao é divisivel por dez");
  }

  // Para o codigo
  enquanto (VERDADEIRO);
}