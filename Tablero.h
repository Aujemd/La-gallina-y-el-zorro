#include <iostream>

using namespace std;

class Tablero{
		
	public:
	int tablero[7][7] = {
							{0,0,0,1,1},
							{0,1,0,0,0},
							{0,1,10,0,1},
							{0,1,0,0,0},
							{0,0,0,1,0},
						};
						
	int casaX;
	int casaY;
		Tablero();
		void buscarCasa();
		void imprimir();
};

Tablero::Tablero(){	
	Tablero::buscarCasa();
}

void Tablero::buscarCasa(){
	for(int  i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			if(this->tablero[i][j] == 10){
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
			else if(this->tablero[i][j] == 10){
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
