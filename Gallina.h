#ifndef GALLINA_H
#define GALLINA_H
#include "Personaje.h"

class Gallina : public Personaje{
	
	public:
	const int valor = 2;
	Gallina(int X, int Y);
	Gallina(Punto);
};

Gallina::Gallina(int X, int Y):Personaje(X, Y){
	
}

Gallina::Gallina(Punto p):Personaje(p){

}
#endif
