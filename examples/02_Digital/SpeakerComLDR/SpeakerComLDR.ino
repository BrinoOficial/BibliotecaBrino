/*
    SpeakerComLDR - Toca um speaker baseado na estrada analogica de um LDR

    O circuito
    * 8-ohm speaker - buzzer - na porta digital 9
    * LDR, da porta analogica 0 para a +5V
    * resistor de 4.7K, do analogico 0 para o ground
 
    Esse exemplo esta em dominio publico em:
    http://www.arduino.cc/en/Tutorial/Tone2
 */

#include <Brino.h>

configuracao() {
    // inicializa a comunicacao serial(apenas para debugar):
    USB.conectar(9600);
}

principal() {
    // Le a entrada do LDR:
    numero leituraLDR = lerAnalogico(A0);
    // mostra na serial o seu valor, para voce saber a sua variacao
    USB.enviarln(leituraLDR);
    // Verifica a variacao da entrada analogica, (no caso, 400 - 1000 do LDR)
    // A saida do speacker varia de 120 a 1500Hz
    // Modifica os numeros maximo e minimo para os abaixo dependendo
    // da variacao medida pelo sensor.
    numero nota = proporcionar(leituraLDR, 400, 1000, 120, 1500);

    // toca a nota:
    soar(9, nota, 10);
    // Espera entre as leituras para aumentar a estabilidade
    esperar(1);
}
