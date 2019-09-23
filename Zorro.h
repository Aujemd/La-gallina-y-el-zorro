#ifndef ZORRO_H
#define ZORRO_H
#include "Personaje.h"

class Zorro : public Personaje{
	
	public:
	int valor = 4;
	Zorro(int X, int Y);
	
};

Zorro::Zorro(int X, int Y):Personaje(X, Y){
	
}

#endif
