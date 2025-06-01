#include <iostream>
using namespace std;
long mod(int a, int b){
	if(a < b){
		return a;
	}
	mod(a-b, b);
}
long mod2(int a, int b){
	int mod =0;
	while(a>=b){
		mod=a-b;
		a=mod;	
	}
	return mod;
}
int main(){
	cout<<mod(1323454,20)<<endl<<mod2(1323454,20)<<endl<<1323454%20;
	return 0;
}

