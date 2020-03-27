/*
    PiscarLEDsSuave - Esse codigo pisca LEDs suavimente usando portas digitais. Os LEDs estao conectados da porta 2 ate a porta 13 e sao ligados um a um. Esse codigo foi escrito para o Arduino Mega e pode nao funcionar em outras versoes da placa

    O circuito:
    - LEDs conectados da porta digital 2 ate a porta digital 13 e o GND

    Exemplo original do Arduino:
    http://www.arduino.cc/en/Tutorial/AnalogWriteMega
*/

#include <Brino.h>

// Constantes
Constante Numero menorPino = 2;
Constante Numero maiorPino = 13;


Configuracao() {
    // Configuras as portas, da 2 ate a 13
    para (Numero essePino = menorPino; essePino <= maiorPino; essePino++) {
        definirModo(essePino, SAIDA);
    }
}

Principal() {
    // Atua em todos os pinos, um de cada vez
    para (Numero essePino = menorPino; essePino <= maiorPino; essePino++) {
        // Aumenta gradativamente o brilho do LED
        para (Numero brilho = 0; brilho < 255; brilho++) {
            escreverAnalogico(essePino, brilho);
            esperar(2);
        }
        // Diminui gradativamente o brilho do LED
        para (Numero brilho = 255; brilho >= 0; brilho--) {
            escreverAnalogico(essePino, brilho);
            esperar(2);
        }
    // Pausa entre os LEDs
    esperar(100);
    }
}
