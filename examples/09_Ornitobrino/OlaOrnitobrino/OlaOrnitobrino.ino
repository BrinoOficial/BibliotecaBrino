#include <Brino.h>
#include <Stepper.h>				//Chama a biblioteca externa do motor de step

#define diametro 4.3344		//Define o diametro das rodas

Constante Numero PPR = 512;	//Total de steps por rotação

Stepper esq( PPR, 8, 10, 9, 11);	//Define as portas de conexão do motor esquerdo
Stepper dir( PPR, 2, 4, 3, 5);	//Define as portas de conexão do motor direito

Configuracao(){
	esq.setSpeed(60);		//define a velocidade do motor esquerdo
	dir.setSpeed(60);		//Define a velocidade do motor direito

}

Principal(){
	andarFrente(10);		//Chama a função andarFrente e da 10 steps
	andarDireita(90);		//Chama a função andarDireitra e da 10 steps
}

SemRetorno andarFrente(NumeroDecimal distancia){	//Define a função andarFrente
	NumeroDecimal comp = 3.14159265*diametro;
	NumeroDecimal voltas = distancia/comp;
	Numero steps = voltas*2048;
	para(Numero i = 0; i < steps; i++){
		dir.step(-1);
		esq.step(1);
		esperar(2);
	}
}

SemRetorno andarDireita(NumeroDecimal angulo){	//Define a função andarDireita
	NumeroDecimal rad = (angulo/180)*3.14159265;
	Numero comp = rad*(diametro/2)*3.5;
	NumeroDecimal voltas = comp/(3.14159265*diametro);
	Numero steps = voltas*2048;
	para(Numero i = 0; i < steps; i++){
		dir.step(1);
		esq.step(1);
		esperar(2);
	}
}