#ifndef JUGADA_IA
#define JUGADA_IA

#include "Tablero.h"
#include "Personaje.h"
#include "DynamicLinealStructure.h"
const int ARRIBA = 0;
const int ABAJO = 1;
const int DERECHA = 2;
const int IZQUIERDA = 3;

class JugadaIA{
private:
    const int GANA_JUGADOR = -10;
    const int GANA_IA = 10;
    const int NO_HAY_GANADOR = 0;
    const int POSIBLES_NUM_MOVS = 4;
    Punto nuevaJugada;
    int minimax(Tablero *t, int profundidad, bool);
    int puntaje(Tablero*, int);
    bool acercandoseGallina(const int, const int);
    bool acercandoseCasa(const int, const int);
    DynamicLinealStructure<Punto> generarMovimientos(Tablero*, bool);
public:
    JugadaIA();
    Punto generarMovimiento(Tablero*);
};

JugadaIA::JugadaIA(){
}

Punto JugadaIA::generarMovimiento(Tablero* t){
    minimax(t, 0, true);
    return this->nuevaJugada;
}

int JugadaIA::minimax(Tablero *t, int profundidad, bool isIa = true){
    if( t->gallinaPunto == t->zorroPunto || t->gallinaPunto == t->casaPunto){
        return puntaje(t, profundidad);
    }
    profundidad += 1;
    DynamicLinealStructure<int> scores;
    DynamicLinealStructure<Punto> movimientosMinMax;

    DynamicLinealStructure<Punto> movimientos = generarMovimientos(t, isIa);
    
    const int size = movimientos.getSize();
    Punto nuevoMovimiento;
    for (int i = 0; i < size; i++){
        movimientos.pop(nuevoMovimiento);
        if(isIa){
            t->tablero[t->zorroPunto.getX()][t->zorroPunto.getY()] = 0;
            t->tablero[nuevoMovimiento.getX()][nuevoMovimiento.getY()] = 4;
            t->zorroPunto = nuevoMovimiento;
        }
        else{
            t->tablero[t->gallinaPunto.getX()][t->gallinaPunto.getY()] = 0;
            t->tablero[nuevoMovimiento.getX()][nuevoMovimiento.getY()] = 2;
            t->gallinaPunto = nuevoMovimiento;
        }
        int score = minimax(t, profundidad, !isIa);
        scores.push(score);
        movimientosMinMax.push(nuevoMovimiento);
    }

    int maximo = 0;
    int index = 0;
    int tempScore;
    const int scoresSize = scores.getSize();

    if(!isIa){
        for (int i = 0; i < scoresSize; i++){
            scores.pop(tempScore);
            if(tempScore > maximo){
                maximo = tempScore;
                index = i;
            }
        }
    }
    else {
        maximo = 9999;
        for (int i = 0; i < scoresSize; i++){
            scores.pop(tempScore);
            if(tempScore < maximo){
                maximo = tempScore;
                index = i;
            }
        }
    }
    if(scoresSize>0){    
        Punto tempPunto;
        movimientosMinMax.getAt(index, tempPunto);
        nuevaJugada.setX(tempPunto.getX());
        nuevaJugada.setY(tempPunto.getY());
        return maximo;
    }
    return puntaje(t, profundidad);
}

int JugadaIA::puntaje(Tablero *t, int depth){
    if(t->gallinaPunto == t->zorroPunto) return GANA_IA - depth;
    else if(t->gallinaPunto == t->casaPunto) return depth - GANA_JUGADOR;
    else return NO_HAY_GANADOR;
}

DynamicLinealStructure<Punto> JugadaIA::generarMovimientos(Tablero *t, bool isIa){
     DynamicLinealStructure<Punto> movimientos;
     Personaje *temp = NULL;
     const int gallinaPosX = t->gallinaPunto.getX();
     const int gallinaPosY = t->gallinaPunto.getY();
     const int zorroPosX = t->zorroPunto.getX();
     const int zorroPosY = t->zorroPunto.getY();

     for (int i = 0; i < POSIBLES_NUM_MOVS; i++){
         if(isIa){
             temp = new Personaje(zorroPosX, zorroPosY);
         }
         else{
            temp = new Personaje(gallinaPosX, gallinaPosY);
         }
         if(temp){
            switch (i){
            case DERECHA:
                if(temp->MoverDerecha() && t->tablero[temp->point.getX()][temp->point.getY()] != 1){
                    if(isIa && acercandoseGallina(temp->point.getX(), gallinaPosX)){
                        Punto p(temp->point);
                        movimientos.push(p);
                    }
                    else if(!isIa && acercandoseCasa(temp->point.getX(), t->casaPunto.getX())){
                        Punto p(temp->point);
                        movimientos.push(p);
                    }
                }
            break;
            case IZQUIERDA:
                if(temp->MoverIzquierda() && t->tablero[temp->point.getX()][temp->point.getY()] != 1){
                    if(isIa && acercandoseGallina(gallinaPosX, temp->point.getX())){
                        Punto p(temp->point);
                        movimientos.push(p);
                    }
                    else if(!isIa && acercandoseCasa(t->casaPunto.getX(), temp->point.getX())){
                        Punto p(temp->point);
                        movimientos.push(p);
                    }
                }
            break;
            case ABAJO:
                if(temp->MoverAbajo() && t->tablero[temp->point.getX()][temp->point.getY()] != 1){
                    if(isIa && acercandoseGallina(temp->point.getY(), gallinaPosY)){
                        Punto p(temp->point);
                        movimientos.push(p);
                    }
                    else if(!isIa && acercandoseCasa(temp->point.getY(), t->casaPunto.getY())){
                        Punto p(temp->point);
                        movimientos.push(p);
                    }
                }
            break;
            case ARRIBA:
                if(temp->MoverArriba() && t->tablero[temp->point.getX()][temp->point.getY()] != 1){
                    if(isIa && acercandoseGallina(gallinaPosY, temp->point.getY())){
                        Punto p(temp->point);
                        movimientos.push(p);
                    }
                    else if(!isIa && acercandoseCasa(t->casaPunto.getY(), temp->point.getY())){
                        Punto p(temp->point);
                        movimientos.push(p);
                    }
                }
            break;
            default:
                break;
            }
         }
     }
     delete temp;
     return movimientos;
 }

bool JugadaIA::acercandoseGallina(const int newZorroPos, const int gallinaPos){
    return newZorroPos <= gallinaPos;
}

bool JugadaIA::acercandoseCasa(const int newGallinaPos, const int casaPos){
    return newGallinaPos <= casaPos;   
}

bool acercandose(const int valor1, const int valor2){
	
}

#endif
