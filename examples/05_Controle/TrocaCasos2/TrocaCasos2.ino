/*
    TrocaCasos2 - switch com o monitor serial. Demonstra o uso
    do swich, um valor e comparado com casos possiveis, caso nao
    se encaixe em nenhum ele executa a opcao padrao.
    Esse codigo recebe dados pela serial, se for 'a', 'b', 'c',
    'd' ou 'e' ele liga um led em especifico. Caso seja qualquer
    outro valor os LEDs serao apagados.

    O circuito
    - Cinco LEDs conectados da porta 2 a 6 e ao GND

    Codigo original para o Arduino:
    http://www.arduino.cc/en/Tutorial/SwitchCase2
*/

#include <Brino.h>

configuracao() {
  // Inicia a comunicacao serial
  USB.conectar(9600);
  // Configura as portas dos LEDs como saidas
  para (numero essaPorta = 2; essaPorta < 7; essaPorta++) {
    definirModo(essaPorta, Saida);
  }
  USB.enviarln("Ligue e desligue os LEDs!\nEnvie alguma letra eveja o resultado\n\n");
}

principal() {
  // Le se existem dados disponiveis na serial
  se (USB.disponivel() > 0) {
    numero entrada = USB.ler();
    // Faz coisas diferentes para cada valor recebido
    seletor (entrada) {
    caso 'a':
      ligar(2);
      quebrar;
    caso 'b':
      ligar(3);
      quebrar;
    caso 'c':
      ligar(4);
      quebrar;
    caso 'd':
      ligar(5);
      quebrar;
    caso 'e':
      ligar(6);
    caso '\n':
      esperar(10);
      quebrar;
      // Se o valor nao se encaixou em nenhum dos casos anteriores,
      // essa parte e executada
    padrao:
      // Desliga todos os LEDs
      para (numero essaPorta = 2; essaPorta < 7; essaPorta++) {
        desligar(essaPorta);
      }
    }
  }
}