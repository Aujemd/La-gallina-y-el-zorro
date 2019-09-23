#include <iostream>
#include "Gallina.h"
#include "Zorro.h"
#include "JugadaIA.h"
#include<time.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define ABAJO 80
#define ARRIBA 72
#define DERECHA 77
#define IZQUIERDA 75


using namespace std;

class Juego{
	
	public:
		Tablero tab;
		Gallina *g;
		Zorro *z;
		int fin = 0;
		
		Juego();
		void Comenzar();
		void GenerarPosG();
		void generarPosZ();
		void BucleDeJuego();
		bool ControlGallina(int accion);
		bool verificarFin();
				
};

Juego::Juego(){
	Juego::Comenzar();
	Juego::BucleDeJuego();
}

void Juego::Comenzar(){
	Juego::GenerarPosG();
	generarPosZ();
}

void Juego::GenerarPosG(){
	srand(time(NULL));
	
	int bandera = 0;
	do{
		int randX  = rand()%5;
		int randY = rand()%5;
		
		if(tab.tablero[randX][randY] == 0){
			
			g = new Gallina(Punto(randX, randY)); 
			tab.tablero[randX][randY] = g->valor;
			bandera = 1;
		}
			
	}while(bandera == 0);	
}

void Juego::generarPosZ(){
	srand(time(NULL));
	bool isIn = false;

	while(!isIn){
		const int randX  = rand()%5;
		const int randY = rand()%5;
		const int gallX = g->point.getX();
		const int gallY = g->point.getY();
		const bool isEmptyPos = (tab.tablero[randX][randY] == 0);
		const bool isNotNextX = ( randX != (gallX-1) && randX != (gallX+1) );
		const bool isNotNextY = ( randY != (gallY-1) && randY != (gallY+1) );
		
		if(isEmptyPos && isNotNextX && isNotNextY) {
			isIn = true;
			z = new Zorro(Punto(randX, randY));
			tab.tablero[randX][randY] = z->valor;
		}
	}
}

void Juego::BucleDeJuego(){
	
	int accion;
			
	tab.imprimir();

	do{
		
		accion = getch();
		accion = getch();
		const bool didMove = Juego::ControlGallina(accion);
		if(didMove){
			JugadaIA ia;
			Tablero tempTab = tab;
			tab.tablero[tab.zorroPunto.getX()][tab.zorroPunto.getY()] = 0;
			Punto p = ia.generarMovimiento(&tempTab);
			z->setMovPoint(p);
			tab.tablero[z->getMovPoint().getX()][z->getMovPoint().getY()] = z->valor;
			tab.zorroPunto = p;
			if(verificarFin()){
				fin = 1;
			}
		}
		tab.imprimir();
		
	}while(this->fin  == 0);
	
}

bool Juego::ControlGallina(int accion){
	bool didMove = false;
	switch(accion){
		
		case ABAJO:{
			
			if(tab.tablero[g->X + 1][g->Y] == 0 || tab.tablero[g->X + 1][g->Y] == 6 || tab.tablero[g->X][g->Y - 1] == 4){
				tab.tablero[g->X][g->Y] = 0;
				didMove = g->MoverDerecha();
				tab.tablero[g->X][g->Y] = g->valor;
				tab.gallinaPunto.setX(g->X);
				tab.gallinaPunto.setY(g->Y);

				
				if( verificarFin() ){
					fin = 1;
					return false;
				}
			}
			
			break;
		}
		
		case ARRIBA:{
			
			if(tab.tablero[g->X - 1][g->Y] == 0 || tab.tablero[g->X - 1][g->Y] == 6 || tab.tablero[g->X][g->Y - 1] == 4){ 
				tab.tablero[g->X][g->Y] = 0;
				didMove = g->MoverIzquierda();
				tab.tablero[g->X][g->Y] = g->valor;
				tab.gallinaPunto.setX(g->X);
				tab.gallinaPunto.setY(g->Y);

				
				if(verificarFin()){
					fin = 1;
					return false;
				}
			}
			
			break;
		}
		
		case DERECHA:{
			if(tab.tablero[g->X][g->Y + 1] == 0 || tab.tablero[g->X][g->Y + 1] == 6 || tab.tablero[g->X][g->Y - 1] == 4){
				tab.tablero[g->X][g->Y] = 0;
				didMove = g->MoverAbajo();
				tab.tablero[g->X][g->Y] = g->valor;
				tab.gallinaPunto.setX(g->X);
				tab.gallinaPunto.setY(g->Y);
				
				if(verificarFin()){
					fin = 1;
					return false;
				}
			}
			break;
		}
		
		case IZQUIERDA:{
			if(tab.tablero[g->X][g->Y - 1] == 0 || tab.tablero[g->X][g->Y - 1] == 6 || tab.tablero[g->X][g->Y - 1] == 4){
				tab.tablero[g->X][g->Y] = 0;
				didMove = g->MoverArriba();
				tab.tablero[g->X][g->Y] = g->valor;
				tab.gallinaPunto.setX(g->X);
				tab.gallinaPunto.setY(g->Y);


				if(verificarFin()){
					fin = 1;
					return false;
				}
			}
			break;
		}
			
	}
	return didMove;
}

bool Juego::verificarFin(){
	return (tab.gallinaPunto == tab.zorroPunto) || (tab.casaPunto == tab.gallinaPunto) ;
}
