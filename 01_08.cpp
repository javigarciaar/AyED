/*
8. Elabore una función recursiva la cual dado un arreglo de caracteres que forman una palabra retorne verdadero si
ésta es capicúa. Ejemplos palabras capicúas: salas, oro, arepera. 
*/

#include <iostream>

using namespace std;


bool esPalindrome(string palabra, int size, int index=0){
	if(size<=1) return true;
	
	if(palabra[index]!=palabra[size-1]) return false;
	
	return esPalindrome(palabra, size-1, index +1);
}

int main(){
	cout<<esPalindrome("ana", 3)<<endl;
	cout<<esPalindrome("arepera", 7)<<endl;
	cout<<esPalindrome("())(", 4)<<endl;
	cout<<esPalindrome("salas", 5)<<endl;

	return 0;
}
