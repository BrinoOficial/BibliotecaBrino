/*
    Suavizar - Executa uma serie de leituras analogicas e mostra a media delas no monitor serial. As medidas tambem sao mantidas em um vetor.

    O circuito:
    - Sensor analogico (como por exemplo um potenciometro) conectado a porta analogica 0

    Exemplo original do Arduino:
    http://www.arduino.cc/en/Tutorial/Smoothing
*/

#include <Brino.h>

// Define o numero de medidas que devem ser feitas. Quanto maior esse numero mais estavel deve ser a saida
Constante numero numeroDeMedidas = 10;

numero leituras[numeroDeMedidas];
numero indiceLeitura = 0;
numero total = 0;
numero media = 0;

numero pinoEntrada = A0;

configuracao() {
  // Inicializa a comunicacao serial
  USB.conectar(9600);
  // Inicializa as medidas em 0
  para (numero esssaLeitura = 0; esssaLeitura < numeroDeMedidas; esssaLeitura++) {
    leituras[esssaLeitura] = 0;
  }
}

principal() {
  // Subtrai a ultima medida
  total = total - leituras[indiceLeitura];
  // Faz a leitura do sensor
  leituras[indiceLeitura] = lerAnalogico(pinoEntrada);
  // Soma a leitura ao total
  total = total + leituras[indiceLeitura];
  // Passa pra proxima posicao do vetor
  indiceLeitura = indiceLeitura + 1;

  // Quando atingimos o final do vetor
  se (indiceLeitura >= numeroDeMedidas) {
    // Recomeca o indice
    indiceLeitura = 0;
  }

  // Calcular a media
  media = total / numeroDeMedidas;
  // Manda o resultado para o monitor serial
  USB.enviarln(media);
  // Esperar entre as medidas para estabiliza-las
  esperar(1);
}