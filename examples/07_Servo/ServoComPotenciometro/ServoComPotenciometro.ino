/*
    ServoComPotenciometro - Esse codigo exemplifica o controle da posicao de um servo motor com base na leitura de um potenciometro

    O circuito:
    - Potentiometro ligado ao 5V e ao GND com as pernas externas e a central conectada a porta analogica 0
    - Um servo motor conectado a alimentacao e o sinal dele na porta digital 9

   Codigo original para Arduino:
   http://www.arduino.cc/en/Tutorial/Knob
*/

#include <Brino.h>
#include <Servo.h>

// Cria um objeto para controlar o motor
Servo meuServo;

// Porta em que o sensor esta conectado
Constante numero SENSOR = A0;
// Variavel que armazena as leituras do sensor
numero leitura;

configuracao() {
  // Informa que o servo esta conectado na porta digital 9
  meuServo.conectarServo(9);
}

principal() {
  // Executa a leitura do sensor e armazena o valor na variavel "leitura"
  leitura = lerAnalogico(SENSOR);
  // Proporciona a leitura do sensor no angulo do motor
  leitura = proporcionar(leitura, 0, 1023, 0, 180);
  // Movimenta o servo para o angulo referente a leitura
  meuServo.escreverAngulo(leitura);
  // Espera o motor se mover
  esperar(15);
}