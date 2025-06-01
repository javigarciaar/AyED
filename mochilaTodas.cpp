#include <iostream>
using namespace std;

const int MAX_ITEMS = 10;

struct Item{
    int valor;
    int peso;
};

int primeraSolucion_val = -1;
bool primeraSolucion[MAX_ITEMS] = {false};
bool SOLUCION[10][MAX_ITEMS] = {false};
int numeroSol=0;

void imprimirSolucion(Item items[], int num_items, bool seleccion[], int valor, int peso) {
    cout << "Items: ";
    for (int i = 0; i < num_items; i++) {
        if (seleccion[i]) {
            cout << "Item" << i << " v:" << items[i].valor << ", p:" << items[i].peso << " ";
        }
    }
    cout << endl << endl;
}

void guardarSolucion(bool seleccion_act[], int numItems) {
    for (int i = 0; i < numItems; i++) {
        SOLUCION[numeroSol][i] = seleccion_act[i];
    }
    numeroSol++;
}

void mochila(int index, int pesoMochila, Item items[], int numItems, 
            bool seleccion_act[], int valorAct, int pesoAct) {
                cout<<"index: " << index << " - "<< pesoAct<<endl;
    if (pesoAct > pesoMochila) {
        //cout<<"xdd";
        //guardarSolucion(seleccion_act, numItems); // Store the current solution
        return; // Exceeded the weight limit
    }

    if(index == numItems) {
        if( pesoAct <= pesoMochila){
            cout << "Solucion #" << endl;
            imprimirSolucion(items, numItems, seleccion_act, valorAct, pesoAct);
        }
        return;
    }
        // Exclude the item
        seleccion_act[index] = false;
        mochila(index + 1, pesoMochila, items, numItems, seleccion_act, valorAct, pesoAct);

        // Include the item
        seleccion_act[index] = true;
        /**/
        valorAct += items[index].valor;
        pesoAct += items[index].peso;
        
        mochila(index + 1, pesoMochila, items, numItems, seleccion_act, valorAct, pesoAct);
        
        /* Backtrack*/
        valorAct -= items[index].valor;
        pesoAct -= items[index].peso;
        
    }


 
int main() {
    Item items[MAX_ITEMS]{
        {10, 5},
        {20, 10},
        {30, 15},
        {40, 20},
        {50, 25}
    };
    int numItems = 5; // Number of items
    int pesoMochila = 500; // Maximum weight of the knapsack
    bool seleccion_act[MAX_ITEMS] = {false}; // Current selection of items
    mochila(0, pesoMochila, items, numItems, seleccion_act, 0, 0); // Start the recursion
    //cout << "Primera solucion encontrada: ";
    //printSolucion(seleccion_act, items, numItems); // Print the first solution
    return 0;
}