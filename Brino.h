/*
 * Brino exemplo
 * 
 * Março de 2020
 * 
 */

#ifndef Brino_n
#define Brino_n

#include "Arduino.h" //Comando para utilizar os comandos do proprio arduino
#include <EEPROM.h>

// Tipos de variavel
#define Numero int
#define NumeroDecimal float
#define NumeroLongo long
#define Letra char
#define Palavra String
#define Condicao boolean
#define Procedimento void

// Modificadores
#define Modulo unsigned
#define Constante const

// Funcoes
#define soar tone
#define pararSoar noTone
#define esperar delay
#define proporcionar map
#define enviarBinario shiftOut
#define tamanho length
#define remover remove

// Fucoes essenciais
#define Configuracao void setup
#define Principal void loop

// USB
#define USB Serial
#define conectar begin
#define enviar print
#define enviarrf println
#define enviarln println
#define disponivel available
#define ler read
#define descarregar flush


// Pino
#define definirModo pinMode
#define escreverDigital digitalWrite
#define escreverAnalogico analogWrite
#define lerDigital digitalRead
#define lerAnalogico analogRead
void ligar(int porta);
void desligar(int porta);
#define pulsoEm pulseIn


// Memoria
#define Memoria EEPROM
#define lerMemoria read
#define escreverMemoria write
#define tamanho length
void apagarMemoriaToda();
#define formatar() read(); apagarMemoriaToda();

// Arquivos
#define arquivo file
#define abrir open


// LCD
#define LCD LiquidCrystal 
#define posicao setCursor
#define limpar clear

// Servo
#define conectarServo attach
#define escreverAngulo write
#define escreverMicros writeMicroeconds
#define SERVOFRENTE 1700
#define SERVOPARAR 1500
#define SERVOTRAS 1300

// I2C
#define I2C Wire
#define transmitir beginTransmission
#define pararTransmitir endTransmission
#define escreverI2C write
#define disponivel available
#define solicitar requestFrom
#define solicitado onRequest
#define recebido onReceive

// Interruptor
#define conectarInterruptor attachInterruptor
#define desconectarInterruptor detachInterruptor
#define desligarInterruptores noInterrupts
#define ligarInterruptores interrupts
#define MUDANDO CHANGING

// Aleatorio
#define geradorAleatorio randomSeed
#define numeroAleatorio random

// Instrucoes de controle
#define caso case
#define enquanto while
#define para for
#define quebrar break
#define se if
#define senao else
#define seletor switch

// Comparadores
#define e &&
#define ou ||

// Palavras chave
#define VERDADEIRO True
#define FALSO False
#define responder return
#define Entrada INPUT
#define ENTRADA INPUT
#define Entrada_PULLUP
#define ENTRADA_PULLUP
#define Saida OUTPUT
#define SAIDA OUTPUT
#define Ligado HIGH
#define LIGADO HIGH
#define Desligado LOW
#define DESLIGADO LOW
#define Ligando RISING
#define LIGANDO RISING
#define Desligando FALLING
#define DESLIGANDO FALLING
#define Direito LSBFIRST
#define DIREITO LSBFIRST
#define Esquerdo MSBFIRST
#define ESQUERDO MSBFIRST




// Testar dps
#define definir #define
#define usar #include<biblioteca.h>


class blk_n{
  public: //O que sera acessivel para o usuario
    blk_n(int pin); //Define o pino do blink LED
    void blk_led(int ms); //Tempo de piscar o LED
  private: //Nao disponivel para o usuario
    int _pin;
};



#endif
