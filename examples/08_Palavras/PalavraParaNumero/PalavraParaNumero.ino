/*
    PalavraParanumero - Converte uma palavra em um valor numerico. Faz a
    leitura de caracteres pela porta USB ate o ponto final '.' e mostra
    o valor numerico correspondente. Em outras palavras, esse codigo
    junta os numeros e ignora as letras e, ao receber um ponto final '.'
    apresennta o resultado obtido.
  
    O circuito: Nenhum hardware alem de seu arduino sera nescessario

    Exemplo original do Arduino:
    http://www.arduino.cc/en/Tutorial/StringToInt
*/

#include <Brino.h>

// Palavra para armazenar a entrada
Palavra palavraEntrada = "";

configuracao() {
    // Inicia a comunicacao serial
    USB.conectar(9600);
    enquanto (!USB) {
        ; // Espera a porta estar conectada
    }

    // Envia um titulo
    USB.enviarln("Converte palavra em numero \n\n Obs.: coloque um ponto final ao terminar!\n\n");
}

principal() {
    // Le a porta USB
    enquanto (USB.disponivel() > 0) {
        numero letraEntrada = USB.ler();
        se (isDigit(letraEntrada)) {
            // Converte a entrada para Letra e adiciona ela a Palavra
            // ignora o entre do envio
            palavraEntrada += (char)letraEntrada;
        }
        // Mostra o resultado quando pegar um '.'
        se (letraEntrada == '.') {
            USB.enviar("Valor:");
            USB.enviarln(palavraEntrada.toInt());
            USB.enviar("Recebi a palavra: ");
            USB.enviarln(palavraEntrada);
            // Limpa a entrada para a proxima execucao
            palavraEntrada = "";
        }
    }
}