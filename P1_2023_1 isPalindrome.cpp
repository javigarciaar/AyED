/* Ejercicio Parcial 2023-1
Verificar si una string es palindrome o no: somos o no somos, luz azul
*/

#include <iostream>

using namespace std;

bool isPalindrome(string frase, int li, int ls){
	
	
	if(frase[li]==' ') li++;
	if(frase[ls]==' ') ls--;
	
	if(li == ls) return true;
	return frase[li] == frase[ls] && isPalindrome(frase, li+1, ls-1);
}

int main(){
	string s="somos o no somos";
	cout<<s.size()<<endl;
	cout<<isPalindrome(s,0, s.size()-1);

	return 0;
}
