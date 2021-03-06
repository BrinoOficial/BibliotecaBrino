/*
   EntradaDigitalComResistor - Esse exemplo faz a leitura de um botao ligado a porta 2 usando a funcao Entrada_PULLUP.

   O circuito:
   * botao digado entre a porta 2 e o GND
   * LED on-board da porta 13

   Diferente da entrada normal, nao e necessario o uso de um resistor externo. Um resistor de 20K-ohm e ligado aos 5V quando usamos Entrada_PULLUP. Isso faz com que a leitura normal do leitor seja de ligado e quando ele e pressionado ele apresenta valor desligado
 
   Codigo original para o Arduino:
   http://www.arduino.cc/en/Tutorial/InputPullupSerial
 */

#include <Brino.h>

// Porta em que o botao esta conectado
Constante numero BOTAO = 2;   
// Porta do LED
Constante numero LED =  13;

configuracao() {
    //inicia a comunicacao serial
    USB.conectar(9600);
    //define a porta 2 como uma entrada e habilita seu resistor
    definirModo(BOTAO, ENTRADA_PULLUP);
    definirModo(LED, SAIDA);
}

principal() {
    //Le o estado do botao
    numero leitura = lerDigital(BOTAO);
    //Apresenta a leitura no monitor serial
    USB.enviarln(leitura);

    // Tenha em mente que o resultado de saida estara invertido.
    // isso quer dizer que ele estara ligado normalmente,
    // e desligado quando for apertado.
    // Controle do LED em funcao disso:
    se (leitura == LIGADO){
        desligar(LED);
    }
    senao {
        ligar(LED);
    }
}
