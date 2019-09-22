class Personaje{
	public:
		int X;
		int Y;
		Personaje(int X, int Y);
		void MoverArriba();
		void MoverAbajo();
		void MoverDerecha();
		void MoverIzquierda();
};

Personaje::Personaje(int X, int Y){
	this->X = X;
	this->Y = Y;
}

void Personaje::MoverArriba(){
	if(this->X > 0){
		this->X -= 1;
	}
}

void Personaje::MoverAbajo(){
	if(this->X < 4){
		this->X += 1;	
	}
	
}

void Personaje::MoverDerecha(){
	if(this->Y < 4){
		this->Y += 1;	
	}
	
}

void Personaje::MoverIzquierda(){
	if(this->Y > 0){
		this->Y -= 1;
	}
}


