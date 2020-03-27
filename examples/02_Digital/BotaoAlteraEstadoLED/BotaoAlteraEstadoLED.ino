/*
    BotaoAlteraEstadoLED - Sempre que um botao e pressionado uma saida tem seu estado alterado. Essa mudanca possui um tempo minimo para acontecer novamente.

    O circuito:
    -LED conectado a porta 13 e ao GND
    -Botao conectado a porta 2 e ao 5V
    -Resistor de 10K Conectado a porta 2 e ao GND

    -Nota: Na maioria dos arduinos existe um LED interno conectado na porta 13
    
    http://www.arduino.cc/en/Tutorial/Debounce
*/

#include <Brino.h>

Constante Numero BOTAO = 2;
Constante Numero LED = 13;

Numero estadoLED = LIGADO;
Numero estadoBotao;
// A leitura anterior do botao
Numero ultimoEstadoBotao = DESLIGADO;


// Variavel para armazenar o momento da ultima mudanca de estado. Usamos o modulo pois o numero ira crescer muito rapidamente
Modulo NumeroLongo tempoUltimaMudanca = 0;
Modulo NumeroLongo tempoMudanca = 100;

Configuracao() {
    definirModo(BOTAO, ENTRADA);
    definirModo(LED, SAIDA);
}

Principal() {
    // Le o estado do botao e armazena na variavel "leitura"
    Numero leitura = lerDigital(BOTAO);

    // Se o estado do botao tiver mudado
    se (leitura != ultimoEstadoBotao) {
        // Recalcula o tempo
        ultimoEstadoBotao = millis();
    }

    se ((millis() - tempoUltimaMudanca) > tempoMudanca) {
        // Se o estado do botao tiver mudado
        se (leitura != estadoBotao) {
            estadoBotao = leitura;

            // So liga o LED se o novo estado do botao for LIgado
            se (estadoBotao == Ligado) {
                estadoLED = !estadoLED;
            }
        }
    }

    // Aplica o estado do LED
    escreverDigital(LED, estadoLED);

    // Salva a leitura
    ultimoEstadoBotao = leitura;
}