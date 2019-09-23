#ifndef PUNTO_H
#define PUNTO_H

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

#endif