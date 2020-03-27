/*
    Botao - Liga e desliga um LED conectado na porta digital 13 quando um botao, conectado a porta digital 2, for pressionado

    O circuito:
    -LED conectado a porta 13 e ao GND
    -Botao conectado a porta 2 e ao 5V
    -Resistor de 10K Conectado a porta 2 e ao GND

    -Nota: Na maioria dos arduinos existe um LED interno conectado na porta 13

    http://www.arduino.cc/en/Tutorial/Button
*/

#include <Brino.h>

// Porta em que o botao esta conectado
Constante Numero BOTAO = 2;   
// Porta em que o LED esta conectado 
Constante Numero LED =  13;  

// Variavel para o estado do botao
Numero estadoBotao = 0; 

Configuracao() {
    // Defini a porta "LED" como uma saida
    definirModo(LED, SAIDA);
    // Define a porta "BOTAO" como uma entrada
    definirModo(BOTAO, ENTRADA);
}

Principal() {
    // Le o estado do botao e salva na variavel "estadoBotao"
    estadoBotao = lerDigital(BOTAO);

    // Verifica se o botao foi pressionado
    se (estadoBotao == LIGADO) {
        // Liga o LED
        ligar(LED);
    } senao {
        // Desliga o LED
        desligar(LED);
    }
}