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
	this->setMovPoint(this->point);
}

Personaje::Personaje(Punto p):Movimiento(){
	this->X = p.getX();
	this->Y = p.getY();
	this->point = Punto(X, Y);
	this->setMovPoint(this->point);
}

bool Personaje::MoverIzquierda(){
	if(this->X > 0){
		this->X -= 1;
		this->point.setX(this->X);
		return true;
	}
	return false;
}

bool Personaje::MoverDerecha(){
	if(this->X < 4){
		this->X += 1;
		this->point.setX(this->X);
		return true;
	}
	return false;
}

bool Personaje::MoverAbajo(){
	if(this->Y < 4){
		this->Y += 1;
		this->point.setY(this->Y);
		return true;
	}
	return false;
}

bool Personaje::MoverArriba(){
	if(this->Y > 0){
		this->Y -= 1;
		this->point.setY(this->Y);
		return true;
	}
	return false;
}

#endif
