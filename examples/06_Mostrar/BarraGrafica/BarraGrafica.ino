/*
    BarraGrafica - Controla uma serie de LEDs com base na leitura de um sensor analogico.
	Essa eh uma forma simples de fazer uma barra grafica. Essa barra utiliza 10 LEDs, voce
	pode usar qualquer quantidade ao mudar o numeroDeLEDs e os pinos do vetor

	Esse metodo pode ser utilizado para controlar qualquer tipo de pino digital de saidas
	com base em uma analogica

    O circuito:
    - Sensor analogico (como por exemplo um potenciometro) conectado a porta analogica 0
    - LEDs conectados do pino 2 ate ao 11 e ao GND

    Exemplo original do Arduino:
    http://www.arduino.cc/en/Tutorial/BarGraph
*/

#include <Brino.h>

// Constantes
// Porta em que o sensor esta conectado
Constante numero SENSOR = A0;
// Quantidade de LEDs na barra
Constante numero numeroDeLEDs = 10;

// Portas em que os LEDs da barra estao conectados
numero portasLEDs[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};


configuracao() {
  // Configura todos os LEDs como saidas
  para (numero esseLED = 0; esseLED < numeroDeLEDs; esseLED++) {
    definirModo(portasLEDs[esseLED], SAIDA);
  }
}

principal() {
  // Le o sensor
  numero leitura = lerAnalogico(SENSOR);
  // Mapeia a leitura para dentro do numero de LEDs
  numero nivel = proporcionar(leitura, 0, 1023, 0, numeroDeLEDs);

  // Loop para interagir com todos os LEDs
  para (numero esseLED = 0; esseLED < numeroDeLEDs; esseLED++) {
    // Se o LED estiver abaixo do nivel ele deve acender
    se (esseLED < nivel) {
      ligar(portasLEDs[esseLED]);
    }
    // Desliga os demais LEDs
    senao {
      desligar(portasLEDs[esseLED]);
    }
  }
}