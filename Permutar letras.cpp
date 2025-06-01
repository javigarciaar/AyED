/*
Generar todas las permutaciones de un string
*/

#include <iostream>

using namespace std;

string gsol[10]={""};
int i=0;

void permutar(string text, int size, int index=0, string sol=""){
	if(index == size){
		gsol[i++]=sol;
		return;
	}
	for(int j=index; j<size; j++){
		swap(text[index], text[j]);
		permutar(text, size, index +1, sol + text[index]);
	}
}

int main(){
	string palabra ="abc";
	int size = palabra.size();
	permutar(palabra, size);
	for(int i; i<10; i++){
		cout<<gsol[i]<<" ";
	}

	return 0;
}
