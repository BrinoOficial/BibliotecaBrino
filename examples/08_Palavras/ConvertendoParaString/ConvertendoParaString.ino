/*
    ConvertendoParaString - Exemplo de como converter outros tipos de dados em Palavra

    O circuito: Nenhum hardware alem de seu arduino sera nescessario

    Exemplo original do Arduino:
    http://www.arduino.cc/en/Tutorial/StringConstructors
*/

#include <Brino.h>

configuracao() {
    // Inicia a comunicacao com o computador
    USB.conectar(9600);
    enquanto (!USB) {
        ; // Espera a porta estar conectada
    }
    // Envia um titulo
    USB.enviarln("Convertendo dados para Palavra:\n");
}

principal() {
    // Usando uma Palavra constante
    Palavra fraseUm = "Frase ola";
    USB.enviarln(fraseUm);
    // Resultado "Frase ola"

    // Convertendo uma Letra constante em uma Palavra
    fraseUm =  Palavra('a');
    USB.enviarln(fraseUm);
    // Resultado "a"

    // Convertendo uma Palavra constante em um objeto Palavra
    Palavra fraseDois =  Palavra("Isso e uma frase");
    USB.enviarln(fraseDois);
    // Resultado "Isso e uma frase"

    // Juntando duas Palavras
    fraseUm =  Palavra(fraseDois + " com mais");
    USB.enviarln(fraseUm);
    // Resultado "Isso e uma frase com mais"  

    // Usando um numero constante
    fraseUm =  Palavra(13);
    USB.enviarln(fraseUm);
    // Resultado "13"

    // Usando um numero inteiro (numero) e uma base definida (Decimal)
    fraseUm =  Palavra(lerAnalogico(A0), DEC);
    USB.enviarln(fraseUm);
    // Resultado "Leitura sensor: 504" ou quaquer valor lido
    
    // Usando um numero inteiro (numero) e uma base definida (Hexadecimal)
    fraseUm =  Palavra(45, HEX);
    USB.enviarln(fraseUm);
    // Resultado "2d", que corresponde ao valor hexadecimal do numero decimal 45

    // Usando um numero inteiro (numero) e uma base definida (Binaria)
    fraseUm =  Palavra(255, BIN);
    USB.enviarln(fraseUm);
    // Resultado "11111111" que e o valor binario do valor decimal 255

    // Usando um numeroLongo e uma base definida (decimal)
    fraseUm =  Palavra(cronometro(), DEC);
    USB.enviarln(fraseUm);
    // Resultado "52" ou qualquer valor correspondente ao cronometro

    // Usando um numeroDecimal e um numero especifico de casas decimais
    fraseUm = String(5.698, 3);
    USB.enviarln(fraseUm);
    // Resultado "5.698"

    // Usando um numeroDecimal e um numero menor de casas decimais para arredondar
    fraseUm = Palavra(5.698, 2);
    USB.enviarln(fraseUm);
    // Resultado "5.70"

    // Para o codigo
    enquanto (VERDADEIRO);
}
