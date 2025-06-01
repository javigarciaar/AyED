#include <iostream>

using namespace std;

class Torre{
	private:
	
	int cantidadDiscos; //size
	int* discos;
	
	public:
	string nombre;
		Torre(string nombre, int cantidadDiscos){
			this->nombre = nombre;
			this->cantidadDiscos = cantidadDiscos;
			this->discos = new int[cantidadDiscos + 1];
			for(int i= cantidadDiscos; i> 0 ; i--){
				discos[i]=cantidadDiscos + 1 - i;
			}
		}
		
		void append( int disco){ //"anade al final"
			
			this->cantidadDiscos++;
			discos[cantidadDiscos] = disco;
			
		}
		
		void remove(){ //"elimina" el ultimo
			
			this->cantidadDiscos--;
		}
		
		int size(){
			return this->cantidadDiscos;
		}
		
		int getTop(){
			return discos[cantidadDiscos];
		}
		
		void print(){
			cout<<this->nombre<<" ";
			for(int i= 1; i<= cantidadDiscos; i++){
				cout<<discos[i]<<" ";
			}
			cout<<endl;
		}
};

Torre A("A", 3), B("B", 0), C("C", 0);

int ALTS[]={1, 2, 3, 4, 5, 6};



string mover(Torre &origen, Torre &destino){
	string mov = "";
	mov = "muevo " + origen.nombre + " a " + destino.nombre;
	destino.append(origen.getTop());
	origen.remove();
	return mov;
}

void moverDisco(Torre &Origen, Torre& Destino){
	Destino.append(Origen.getTop());
	Origen.remove();
}

bool esSolucion(int N){
	return C.size() == N or B.size() == N;
}

bool NoEsMovAnterior(int alt, int movAnt){
	if(alt+movAnt==3 or alt+movAnt==7 or alt+movAnt==11){
		return false;
	}
	return true;
}

bool esValida(Torre O, Torre D, int alt, int movAnt){ //retorne si discOrig < discDest
	return D.getTop() > O.getTop() && NoEsMovAnterior(alt, movAnt);
}
/*
*/
int MOV =0;

bool altValida(int alt){
	bool valor;
	switch(alt){
		case 1:
			valor = esValida(A, B, alt, MOV);
			break;
		case 2:
			return esValida( B,  A, alt, MOV);
			break;
		case 3:
			return esValida( A,  C, alt, MOV);
			break;
		case 4:
			return esValida( C,  A, alt, MOV);
			break;
		case 5:
			return esValida( B,  C, alt, MOV);
			break;
		case 6:
			return esValida( C,  B, alt, MOV);
			break;
		default:
			return false;
	}
}



void aplicarMovimiento(int alt){
	switch(alt){
		MOV = alt;
		case 1:
			moverDisco( A,  B);
	
			break;
		case 2:
			moverDisco( B,  A);
		
			break;
		case 3:
			moverDisco( A,  C);
			
			break;
		case 4:
			moverDisco( C,  A);
			break;
		case 5:
			moverDisco( B,  C);
			break;
		case 6:
			moverDisco( C,  B);
			break;
		default:
			return;
	}
}

void TorresHanoi(Torre A, Torre B, Torre C, int Movanterior=1){
	int i=0;
	while(i<6){
		int alt = ALTS[i];
		if(altValida(alt)){
			aplicarMovimiento(alt);
			
			if(esSolucion(3)){
				A.print();
				B.print();
				C.print();
			}
		}
	}
}

int main(){
	Torre TorreA("A", 7);
	TorreA.print();
	cout<<TorreA.getTop()<<endl;
	TorreA.remove();
	TorreA.print();
	
	TorreA.append(-10);
	TorreA.print();
	Torre TorreB("B", 0);
	cout<<mover(TorreA, TorreB)<<endl;
	TorreA.print();
	TorreB.print();
	
	cout<<mover(TorreA, TorreB)<<endl;
	TorreA.print();
	TorreB.print();
	
	//cout<<esValida(TorreA, TorreB);
	TorresHanoi(A, B, C);
	return 0;
}
