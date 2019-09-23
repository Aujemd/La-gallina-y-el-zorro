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
};

Movimiento::Movimiento(){

}

#endif
