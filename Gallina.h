#include "Personaje.h"

class Gallina : public Personaje{
	
	public:
	int valor = 2;
	Gallina(int X, int Y);
	
};

Gallina::Gallina(int X, int Y):Personaje(X, Y){
	
}
