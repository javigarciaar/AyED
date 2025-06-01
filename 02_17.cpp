/* 2 17) La ferretería TheFerro vende cabilla. Los clientes suelen pedir distintas cantidades de metros de cabilla, por lo que siempre quedan 
segmentos cortos sin vender. Todos esos segmentos van quedando "frios" en la ferretería, por lo que se ha decidido soldarlos para 
vender cabillas repotenciadas de 100 metros, a un precio razonablemente menor. El dueño de la ferretería entiende que este 
problema es complejo, pues tiene que tomar un conjunto que pedazos de cabilla que sumen EXACTAMENTE 100 metros, y que 
generen la menor cantidad de soldaduras posible. Una vez intentó hacerlo, y tardó 7 días en encontrar la configuración deseada, lo 
cual le trajo pérdidas en el negocio. Se recurre a loS estudiantes de la UCV para que le resuelvan su problema, que en resumen 
consiste en: dada las longitudes de cada uno de los N segmentos de cabilla, indicar si se puede construir otra de 100 metros 
mediante soldadura, en cuyo caso, se desea obtener UNA configuración de longitudes de cabilla que requiere la MENOR cantidad de 
soldaduras posibles. 
(c) oscar*/
#include <iostream>
using namespace std;
int n; int *solucion; int indice=101;
bool verificar(int *arr){
    int suma=0;                           //esto es para verificar si en el arreglo
    for(int i=0; i<n; i++){               
        suma+=arr[i];
        if(suma==100) return true;
    }
    return false;
}
void soldadura(int *arr, int i){
    if(verificar(arr)){
        int suma=0, j=0;
        while(suma!=100){
            suma+= arr[j];
            j++;
        }
        if(j<=indice){
        for(int i=0; i<j; i++){
            solucion[i]= arr[i];
        }
        indice= j;}
    }
    if(i+1<n){ // me ahorro la ultima iter que hace sawp(n-1,n-1)
        for(int k=i; k<n; k++){
            swap(arr[i], arr[k]);
            soldadura(arr, i+1);
            swap(arr[i], arr[k]);
        }
    }
    return;
    }
int main(){
    cin>>n;              //pido tamaño de trozos
    int *arr;           
    arr= new int[n];          //creo arreglo a permutar de tamaño cantidad de trozos
    solucion= new int[n];       // creo otro arreglo para almacenar la solucion
    for(int i=0; i<n; i++){
        cin>>arr[i];               //relleno el primer arreglo con la longitud de cada trozo
    }
    soldadura(arr, 0);                  //llamado al backtracking
    for(int i=0; i<indice; i++){         
        cout<<solucion[i]<<" ";                 //mostrar solucion
    }
    cout<<"hacen falta "<<indice-1<<" soldaduras";
}
