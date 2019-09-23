#ifndef PUNTO_H
#define PUNTO_H

#include <iostream>

using namespace std;


class Punto
{
private:
    int X;
    int Y;
public:
    Punto();
    Punto(int, int);
    int getX();
    int getY();
    void setX(int);
    void setY(int);
    friend bool operator==(const Punto &p, const Punto &pp){
        return p.X == pp.X && p.Y == pp.Y;
    }
    void operator=(const Punto &p){
        this->X = p.X;
        this->Y = p.Y;
    }

    Punto* operator= (Punto *p){
        if(p != NULL) return new Punto(p->getX(), p->getY());
        else return NULL;
    }

    friend ostream & operator << (ostream &salida, Punto A){
        salida <<A.getX()<<","<<A.getY()<<endl;
        return salida;
    }
};

Punto::Punto(){
    this->X = 0;
    this->Y = 0;
}

Punto::Punto(int x, int y):X(x),Y(y){
    
}

int Punto::getX(){
    return this->X;
}

int Punto::getY(){
    return this->Y;
}

void Punto::setX(int x){
    this->X = x;
}

void Punto::setY(int y){
    this->Y = y;
}

#endif