#include <iostream>
#include "Gallina.h"
#include "Tablero.h"
#include<time.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>



using namespace std;

class Juego{
	
	public:
		Tablero tab;
		Gallina *g;
		int fin = 0;
		
		Juego();
		void Comenzar();
		void GenerarPosG();
		void BucleDeJuego();
		void ControlGallina(int accion);
				
};

Juego::Juego(){
	Juego::Comenzar();
	Juego::BucleDeJuego();
}

void Juego::Comenzar(){
	Juego::GenerarPosG();
}

void Juego::GenerarPosG(){
	srand(time(NULL));
	
	int bandera = 0;
	do{
		int randX  = rand()%5;
		int randY = rand()%5;
		
		if(tab.tablero[randX][randY] == 0){
			
			g = new Gallina(randX, randY); 
			tab.tablero[randX][randY] = g->valor;
			bandera = 1;
		}
			
	}while(bandera == 0);	
}

void Juego::BucleDeJuego(){
	
	int accion;
			
	tab.imprimir();

	do{
		
		accion = getch();
		accion = getch();
		Juego::ControlGallina(accion);
		tab.imprimir();
		
	}while(this->fin  == 0);
	
}

void Juego::ControlGallina(int accion){

	switch(accion){
		
		case 80:{
			
			if(tab.tablero[g->X + 1][g->Y] == 0 || tab.tablero[g->X + 1][g->Y] == 10){
				tab.tablero[g->X][g->Y] = 0;
				g->MoverAbajo();
				tab.tablero[g->X][g->Y] = g->valor;
				
				if(g->X == tab.casaX && g->Y == tab.casaY){
					fin = 1;
				}
			}
			
			break;
		}
		
		case 72:{
			
			if(tab.tablero[g->X - 1][g->Y] == 0 || tab.tablero[g->X - 1][g->Y] == 10){
				tab.tablero[g->X][g->Y] = 0;
				g->MoverArriba();
				tab.tablero[g->X][g->Y] = g->valor;
				
				if(g->X == tab.casaX && g->Y == tab.casaY){
					fin = 1;
				}
			}
			
			break;
		}
		
		case 77:{
			if(tab.tablero[g->X][g->Y + 1] == 0 || tab.tablero[g->X][g->Y + 1] == 10){
				tab.tablero[g->X][g->Y] = 0;
				g->MoverDerecha();
				tab.tablero[g->X][g->Y] = g->valor;
				
				if(g->X == tab.casaX && g->Y == tab.casaY){
					fin = 1;
				}
			}
			break;
		}
		
		case 75:{
			if(tab.tablero[g->X][g->Y - 1] == 0 || tab.tablero[g->X][g->Y - 1] == 10){
				tab.tablero[g->X][g->Y] = 0;
				g->MoverIzquierda();
				tab.tablero[g->X][g->Y] = g->valor;

				if(g->X == tab.casaX && g->Y == tab.casaY){
					fin = 1;
				}
			}
			break;
		}
			
	}
}
