/*
 * Brino exemplo
 * 
 * Março de 2020
 * 
 */

#include "Arduino.h"
#include "Brino.h"

blk_n::blk_n(int pin){
pinMode(pin, OUTPUT);
_pin = pin;

}

void blk_n::blk_led(int ms){
  digitalWrite(_pin, HIGH);
  delay(ms);
  digitalWrite(_pin, LOW);
  delay(ms);
}

// Pino 
void ligar(int porta){
	digitalWrite(porta, HIGH);
}
void desligar(int porta){
	digitalWrite(porta, LOW);
}

// Memoria
void apagarMemoriaToda(){
	for (int i = 0 ; i < EEPROM.length(); i++) 
		EEPROM.write(i, 0);
}