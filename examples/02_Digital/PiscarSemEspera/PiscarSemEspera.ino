/*
  PiscarSemEsperar - Liga e desliga um LED conectado a uma porta digital sem usar esperar(). Isso signifiva que outro codigo pode rodar ao mesmo tempo sem interromper o LED.
	
    O circuito
    - LED interno
    - Nota: A maioria dos Arduinos possuem um LED on-board que pode ser controlado. No UNO e no Leonardo, ele esta conectado a porta digital 13. Se voce nao sabe em qual porta ele esta conectado em seu Arduino, leia a documentacao no site: arduino.cc
    
    http://www.arduino.cc/en/Tutorial/BlinkWithoutDelay
*/

#include <Brino.h>

// Porta do LED
Constante Numero LED =  13;

// Variavel para o estado do LED
Numero estadoLED = DESLIGADO;

// Variavel para armazenar o momento da ultima mudanca de estado. Usamos o modulo pois o numero ira crescer muito rapidamente
Modulo NumeroLongo millisAnterior = 0;

// Intervalo entre as piscadas
Constante Numero INTERVALO = 1000;

Configuracao() {
    // Define a porta do LED como uma saida
    definirModo(LED, SAIDA);
}
Principal() {
    // Colocamos aqui o codigo que queremos que rode simultaneamente

    // Pega o momento atual e compara com o antigo para piscar no momento correto
    Modulo NumeroLongo millisAtual = millis();
    se (millisAtual - millisAnterior >= INTERVALO) {
        // Salva a ultima vez em que piscou
        millisAnterior = millisAtual;

        // Inverte o estado do LED
        se (estadoLED == DESLIGADO) {
            estadoLED = LIGADO;
        } senao {
            estadoLED = DESLIGADO;
        }
        escreverDigital(LED, estadoLED);
    }
}