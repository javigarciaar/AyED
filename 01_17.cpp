/*
17. Suponga que solo cuenta con un lenguaje cuyas operaciones aritméticas son +, -, /; diseñe una función recursiva la
cual, dados dos reales A y B, retorne como resultado la evaluación de A * B.
Creditos a Angel
*/

#include <iostream>

using namespace std;

double multiplicar(double a, double b){
	if(b >= 1){
		return a + multiplicar(a, b-1);
	} else if(b <= -1){
		return -a + multiplicar(a, b+1);
	} else if(b==0){
		return 0;
	} else {
		return a/(1/b);
	}
}

int main(){
	cout<<multiplicar(2.3, 4.4)<<endl;
	cout<<multiplicar(2.3, -4.4)<<endl;
	cout<<multiplicar(-2.3, 4.4)<<endl;
	cout<<multiplicar(-2.3,-4.4)<<endl;

	return 0;
}
