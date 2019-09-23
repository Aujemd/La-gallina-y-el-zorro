#ifndef PERSONAJE_H
#define PERSONAJE_H

#include "Movimiento.h"

class Personaje : public Movimiento{
	public:
		int X;
		int Y;
		Punto point;
		Personaje(int X, int Y);
		Personaje(Punto);
		bool MoverArriba();
		bool MoverAbajo();
		bool MoverDerecha();
		bool MoverIzquierda();
};

Personaje::Personaje(int X, int Y):Movimiento(){
	this->X = X;
	this->Y = Y;
	this->point = Punto(X, Y);
}

Personaje::Personaje(Punto p):Movimiento(){
	this->X = p.getX();
	this->Y = p.getY();
	this->point = Punto(X, Y);
}

bool Personaje::MoverArriba(){
	if(this->X > 0){
		this->X -= 1;
		return true;
	}
	return false;
}

bool Personaje::MoverAbajo(){
	if(this->X < 4){
		this->X += 1;	
		return true;
	}
	return false;
}

bool Personaje::MoverDerecha(){
	if(this->Y < 4){
		this->Y += 1;	
		return true;
	}
	return false;
}

bool Personaje::MoverIzquierda(){
	if(this->Y > 0){
		this->Y -= 1;
		return true;
	}
	return false;
}

#endif