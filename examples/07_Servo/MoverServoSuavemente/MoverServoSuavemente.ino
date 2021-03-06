/*
    MoverServoSuavemente - Movimenta um servo motor 9g conectado a porta digital 9 suavimente do angulo 0 ate o angulo 180 e depois volta para o angulo 0

    O circuito:
    - Um servo motor conectado a alimentacao e o sinal dele na porta digital 9

    Codigo original para Arduino:
    http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Brino.h>
#include <Servo.h>

// Cria um objeto para controlar o motor
Servo meuServo;

// Variavel para armazenar o angulo
numero pos = 0;

configuracao() {
  // Informa que o servo esta conectado na porta digital 9
  meuServo.conectarServo(9);
}

principal() {
  // Movimenta o servo do angulo 0 ate o angulo 180 de um a um grau
  para (pos = 0; pos <= 180; pos += 1) {
    // Movimenta o servo para o angulo especificado
    meuServo.escreverAngulo(pos);
    // Espera o motor se mover
    esperar(15);
  }
  // Movimenta o servo do angulo 180 ate o angulo 0 de um a um grau
  para (pos = 180; pos >= 0; pos -= 1) {
    // Movimenta o servo para o angulo especificado
    meuServo.escreverAngulo(pos);
    // Espera o motor se mover
    esperar(15);
  }
}