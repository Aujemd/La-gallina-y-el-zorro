#include <iostream>
#include <fstream>
using namespace std;

#include "Punto.h"

class Tablero{
		
	public:
	int tablero[5][5];
	Punto casaPunto;	
	Punto gallinaPunto;
	Punto zorroPunto;	
	int casaX;
	int casaY;
	Tablero();
	void buscarCasa();
	void imprimir();
	void inicializarTablero();
	void operator=(Tablero t){
		for (int i = 0; i < 5; i++){
			for (int j = 0; j < 5; j++){
				this->tablero[i][j] = t.tablero[i][j];
			}
		}
		
		this->casaPunto = t.casaPunto;
		this->gallinaPunto = t.gallinaPunto;
		this->zorroPunto = t.zorroPunto;
	}
};

Tablero::Tablero(){	
	Tablero::inicializarTablero();
	Tablero::buscarCasa();
}

void Tablero::buscarCasa(){
	for(int  i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			if(this->tablero[i][j] == 6){
				this->casaX = i;
				this->casaY = j;
				this->casaPunto = Punto(casaX, casaY);
				break;
			}
		}
	}
}
void Tablero::imprimir(){
	system("CLS");
	cout<<"\n\n\n\n\n\n"<<endl;
	for(int i = 0; i < 5; i++){
		cout<<"\t\t\t\t";
		cout<<"|";
		for(int j = 0; j < 5; j++){
			if(this->tablero[i][j] == 0){
				cout<<" ";
			}
			else if(this->tablero[i][j] == 1){
				cout<<"*";
			}
			else if(this->tablero[i][j] == 2){
				cout<<"G";
				this->gallinaPunto = Punto(i, j);
			}
			else if(this->tablero[i][j] == 4){
				cout<<"Z";
				this->zorroPunto = Punto(i, j);
			}
			else if(this->tablero[i][j] == 6){
				cout<<"C";
			}
		}
		cout<<"|";
		cout<<endl;
	}
	if(tablero[casaPunto.getX()][casaPunto.getY()] == 0){
		tablero[casaPunto.getX()][casaPunto.getY()] = 6;
	}
	cout<<"\t\t\t\t";
	cout<<"\n\n\n\n\n\n"<<endl;
}

void Tablero::inicializarTablero(){
	
	fstream archivo;
	
	archivo.open("tablero.txt", ios::in);
	
	char linea[6];
	
	for(int  i = 0; i < 5; i++){
		archivo.getline(linea, 7, '\n');
			for(int j = 0; j < 5; j++){
				if(linea[j] == ' '){
					this->tablero[i][j] = 0;
				}else if( linea[j] == '*'){
					this->tablero[i][j] = 1;
				}else if(linea[j] == 'C'){
					this->tablero[i][j] = 6;
				}
			}
	}
	
	archivo.close();
	
}
