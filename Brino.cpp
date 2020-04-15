/*
 * Brino exemplo
 * 
 * Março de 2020
 * 
 */

#include "Arduino.h"
#include "Brino.h"

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
