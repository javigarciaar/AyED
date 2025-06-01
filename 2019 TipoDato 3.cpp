/* Practica #1: Tipos de Datos (Guia 2019)
3) Defina una estructura de datos que permita almacenar eventos de un calendario. Esta no
debe registrar eventos de fechas inexistentes. Asuma que su calendario funciona para un
sólo año. Además se desea conocer el día de la semana en que ocurre el evento.
*/

#include <iostream>
using namespace std;

class Calendario{
	int dia, mes, anio;
	//string diaSem;
	public:
	Calendario(int dia=1, int mes=1, int anio=1): dia(dia), mes(mes), anio(anio) {
	}
	
	int bisiesto(int anio){
		return (anio%4==0 and anio%100!=0) or (anio%400==0);
	}
	
	int cantDiasMes(int mes, int anio){
		if(mes== 2) return 28 + bisiesto(anio); //si es bisiesto->true (1) 28+1 = 29
		if(mes== 3 or mes==4 or mes==6 or mes==9 or mes==11) return 30;
		return 31;
	}
	
	bool esFechaValida(int dia, int mes, int anio){
		if(dia<1 or dia>31 or mes<1 or mes>12 or anio<1) return false;
		if(dia > cantDiasMes(mes, anio)) return false;
		return true;
	}
	
	void registrar(){
		do{
		   cout<<"Ingrese una fecha (dia, mes, anio): ";
		   int dia, mes, anio;
		   cin>>dia>>mes>>anio;
		   if(esFechaValida(dia, mes, anio)){
			  this->dia=dia;
			  this->mes=mes;
			  this->anio=anio;
			  break;
		   } else {
		   	 cout<<"fecha invalida"<<endl;
		   }	
		} while(true);
		
	}
	
	string getDiaSem(){ 
	    int auxDias=0;
		for(int i=1; i<this->mes; i++) auxDias+=cantDiasMes(i, this->anio);
		string diasSem[]={"Dom", "Lun", "Mar", "Mie", "Jue", "Vie", "Sab"}; //1er dia del ano comienza el domingo
		return diasSem[auxDias%7];
	}
	
	int getDiasTranscurridos(){
		int auxDias=0;
		for(int i=1; i<this->mes; i++) auxDias+=cantDiasMes(i, this->anio);
		return auxDias + this->dia;
	}
	
};

int main(){
	Calendario fecha;
	fecha.registrar();
	cout<<"El dia de la semana es "<<fecha.getDiaSem();
	cout<<"Dias transcurridos "<<fecha.getDiasTranscurridos();
	return 0;
}

