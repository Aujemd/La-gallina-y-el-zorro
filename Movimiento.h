#ifndef MOVIMIENTO_H
#define MOVIMIENTO_H

#include "Punto.h"

class Movimiento{
private:
    Punto movPoint;
public:
    Movimiento();
    virtual bool MoverArriba() = 0;
    virtual bool MoverAbajo() = 0;
    virtual bool MoverDerecha() = 0;
    virtual bool MoverIzquierda() = 0;
    Punto getMovPoint();
    void setMovPoint(Punto);
    friend bool operator==(const Movimiento &m, const Movimiento &m2){
        return m2.movPoint == m.movPoint;
    }
};

Movimiento::Movimiento(){

}

Punto Movimiento::getMovPoint(){
    return this->movPoint;
}

void Movimiento::setMovPoint(Punto p){
    this->movPoint = p;
}

#endif
