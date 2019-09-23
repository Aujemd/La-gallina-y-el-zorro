#include <iostream>
#include <fstream>
using namespace std;

class Tablero{
		
	public:
	int tablero[5][5];
						
	int casaX;
	int casaY;
		Tablero();
		void buscarCasa();
		void imprimir();
		void inicializarTablero();
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
			else if(this->tablero[i][j] == 6){
				cout<<"C";
			}
			else if(this->tablero[i][j] == 2){
				cout<<"G";
			}
			else if(this->tablero[i][j] == 4){
				cout<<"Z";
			}
		}
		cout<<"|";
		cout<<endl;
	}
	cout<<"\t\t\t\t";
	cout<<"\n\n\n\n\n\n"<<endl;
}

void Tablero::inicializarTablero(){
	
	fstream archivo;
	
	archivo.open("tablero.txt", ios::in);
	
	char linea[5];
	
	for(int  i = 0; i < 5; i++){
		archivo.getline(linea, 6, '\n');
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
