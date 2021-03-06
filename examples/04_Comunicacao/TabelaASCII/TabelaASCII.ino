/*
    TabelaASCII - Mostra um valor em todos os formatos:
    - Como binario
    - Seguindo o padrao ASCII em decimal, octadecimal, hexadecimal e binario.

    Para saber mais sobre ASCII (ingles), acesse http://www.asciitable.com e http://en.wikipedia.org/wiki/ASCII

    O circuito: Nenhum hardware alem de seu arduino sera nescessario

    Exemplo original do Arduino:
    http://www.arduino.cc/en/Tutorial/ASCIITable
*/

#include <Brino.h>

configuracao() {
  // Inicia a comunicacao com o computador
  USB.conectar(9600);
  enquanto (!USB) {
    ; // Espera ate que a porta esteja conectada
  }
  // Envia o titulo
  USB.enviarln("Tabela ASCII ~ Mapa de caracteres");
}

// O primeiro caracter ASCII visivel é o '!' que possui numero 33
numero esseByte = 33;
// Caracteres ASCII tambem podem ser escritos entre aspas simples '', ou seja, digitar 33 ou '!' surtem o mesmo efeito. O comando poderia ter sido:
// numero esseByte = '!';

principal() {
  // Envia o valor sem alteracoes para ser interpretado como um caracter ASCII, o primeiro seria uma '!'
  USB.write(esseByte);

  USB.enviar(", dec: ");
  // Mostra o valor do caracter na base decimal (base 10). A base decimal e a padrao do USB.enviar() e do USB.enviarln(), entao nao sao nescessarios modificadores
  USB.enviar(esseByte);
  // Se preferir tambem pode ser usado o modificador "DEC" como no comentario:
  // USB.enviar(esseByte, DEC);

  USB.enviar(", hex: ");
  // Mostra o valor do caracter na base hexadecimal (base 16)
  USB.enviar(esseByte, HEX);

  USB.enviar(", oct: ");
  // Mostra o valor do caracter na base octadecimal (base 8)
  USB.enviar(esseByte, OCT);

  USB.enviar(", bin: ");
  // Mostra o valor do caracter na base binaria (base 2) e quebra a linha
  USB.enviarln(esseByte, BIN);

  // Se o ultimo caracter visivel '~' tiver sido enviado, pare
  // Usar '~' no lugar de 126 causaria o mesmo efeito
  se (esseByte == 126) {
    // Esse laco e infinito e nao faz nada
    enquanto (VERDADEIRO) {
      continue;
    }
  }
  // Segue para o proximo caractere
  esseByte++;
}