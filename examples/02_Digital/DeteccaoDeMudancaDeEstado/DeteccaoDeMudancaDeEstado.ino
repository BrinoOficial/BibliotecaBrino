/*
    Deteccao de mudanca de estado (contador botao) - Normalmente, nao e necessario saber o estado do pino digital o tempo todo, basta saber quando ha mudanca de estado (ligado/ deligado). Por exemplo, deseja-se saber quando e quantas vezes um botao e acionado, isso e chamado deteccao de mudanca de estado. Esse exemplo mostra como detectar quando um botao e pressionado

    O circuito:
    * Botao de pressionar, da porta 2 para +5V
    * Resistor de 10k, da porta 2 para o ground 
    * LED, da porta 13 para o ground ou LED acoplado na placa(presente na maioria dos arduinos)

    Esse codigo esta em dominio publico em:
    http://www.arduino.cc/en/Tutorial/ButtonStateChange
 */

#include <Brino.h>

//Essas sao as constantes, como o nome sugere, elas nao mudam
Constante numero  botao = 2;    // porta em que o botao deve ser conectado
Constante numero LED = 13;      // porta em que o LED deve ser conectado

// Essas sao as variaveis, como o nome sugere, elas irao mudar
numero contadorBotao = 0;   //conta quantas vezes o botão foi acionado
numero estadoBotao = 0;         // verifica se o estado do botao (ligado/deligado)
numero ultimoEstado = 0;     // armazena o ultimo estado do botao (ligado/deligado)

configuracao() {
    // Define o botao como uma entrada:
    definirModo(botao, ENTRADA);
    // Define o LED como uma saida:
    definirModo(LED, SAIDA);
    // Inicia uma comunicacao serial:
    USB.conectar(9600);
}


principal() {
    // le a entrada do botao:
    estadoBotao = lerDigital(botao);

    // compara o estado do botao com o seu ultimo estado
    se (estadoBotao != ultimoEstado){
        // Se o estado ter mudado, soma um ao medidor)
        se (estadoBotao == LIGADO){
            // Se o estado do botao for ligado ele
            // muda do "desligado" pro "ligado"
            contadorBotao++;
            USB.enviarln("ligado");
            USB.enviarln("o botao foi acionado:  ");
            USB.enviarln(contadorBotao);
        }
        senao{
            // Se o estado do botao for desligado, ele
	       // muda do "desligado" pro "ligado"
            USB.enviarln("desligado");
        }
        // esperar para evitar ruidos:
        esperar(50);
    }
    // Salva o estado atual como o ultimo estado do botao
    // para o proximo loop a ser executado
    ultimoEstado = estadoBotao;
    
    // Liga o LED a cada 4 vezes que o botao for precionado 
    // verificando o modulo do contador do botao
    se (contadorBotao % 4 == 0) {
        escreverDigital(LED, LIGADO);
    } senao {
        escreverDigital(LED, DESLIGADO);
    }
}