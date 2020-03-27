/*
    AnalisarLetra - Usa operadores de analise de letras. ~Mande qualquer dado e ele ira analisa-lo.

    O circuito: Nenhum hardware alem de seu arduino sera nescessario

    Exemplo original do Arduino:
    http://www.arduino.cc/en/Tutorial/CharacterAnalysis
*/

#include <Brino.h>

Configuracao() {
  // Inicia a comunicacao com o computador
  USB.conectar(9600);
  enquanto (!USB) {
    ; // Espera a porta estar conectada
  }

  // Mostra um titulo
  USB.enviarln("Me envie uma letra e irei dizer tudo que eu conseguir sobre ela");
  USB.enviarln();
}

Principal() {
  // Pega o dado
  se (USB.disponivel() > 0) {
    Numero essaLetra = USB.read();

    // Informa o dado recebido
    USB.enviar("Voce enviou: \'");
    USB.escrever('essaLetra');
    USB.enviar("\'  valor ASCII: ");
    USB.enviarln(essaLetra);

    // Analisa
    se (isAlphaNumeric(essaLetra)) {
      USB.enviarln("E alphanumerica");
    }
    se (isAlpha(essaLetra)) {
      USB.enviarln("E alfabetica");
    }
    se (isAscii(essaLetra)) {
      USB.enviarln("E ASCII");
    }
    se (isWhitespace(essaLetra)) {
      USB.enviarln("E um espaco");
    }
    se (isControl(essaLetra)) {
      USB.enviarln("E a caractere de controle");
    }
    se (isDigit(essaLetra)) {
      USB.enviarln("E um digito numerico");
    }
    se (isGraph(essaLetra)) {
      USB.enviarln("E um caracter que pode ser mostrado, mas nao e um espaco");
    }
    se (isLowerCase(essaLetra)) {
      USB.enviarln("E minuscula");
    }
    se (isPrintable(essaLetra)) {
      USB.enviarln("Pode ser mostrada");
    }
    se (isPunct(essaLetra)) {
      USB.enviarln("E uma pontuacao");
    }
    se (isSpace(essaLetra)) {
      USB.enviarln("E um espaco");
    }
    se (isUpperCase(essaLetra)) {
      USB.enviarln("E maiuscula");
    }
    se (isHexadecimalDigit(essaLetra)) {
      USB.enviarln("E um digito hexadecimal valido (Ex.: 0 - 9, a - F, ou A - F)");
    }

    // Pede mais dados
    USB.enviarln();
    USB.enviarln("Me envie outra letra: ");
    USB.enviarln();
  }
}