/*
    entrada analogica, saida analogica e saida serial - Le uma porta analogica, faz uma regra de 3 para o alcance de 0 a 255 e usa o seu resultado em uma saida PWM mostrando-o tambem pelo monitor serial.

    O circuito:
      Potenciometro, suas extremidades ligadas no ground e no 5V, e o
    pino central na porta analogica 0.
      LED, da porta digital 9 para o ground.
*/

#include <Brino.h>

// Essas sao as constantes, como o nome diz, elas nao mudam
// Abaixo estao numeradas as portas que serao usadas.
// Porta analogica do potenciometro
Constante Numero entradaPortaAnalogica = A0;
// Porta analogica em que o LED esta conectado
Constante Numero saidaPortaAnalogica = 9;

// Le o valor dado pelo potenciometro
Numero medidaSensor = 0;
// Valor de saida da porta PWM (LED)
Numero saidaPWM = 0;

Configuracao() {
  // Comeca uma comunicacao serial
  USB.conectar(9600);
}

Principal() {
  // Le o valor potenciometro:
  medidaSensor = lerAnalogico(entradaPortaAnalogica);
  // Faz uma regra de 3 com os possiveis valores de saida da porta PWM:
  saidaPWM = proporcionar(medidaSensor, 0, 1023, 0, 255);
  // Muda o valor da saida PWM:
  escreverAnalogico(saidaPortaAnalogica, saidaPWM);

  // Mostra os resultados pela serial:
  USB.enviar("sensor = " );
  USB.enviarln(medidaSensor);
  USB.enviar("saida = ");
  USB.enviarln(saidaPWM);

  // Espera 2 milisegundos antes de come�ar o proximo loop
  // Para converter do analogico pro digital depois da
  // Ultima leitura
  esperar(2);
}