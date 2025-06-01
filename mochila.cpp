#include <iostream>
using namespace std;

const int MAX_ITEMS = 100;

struct Item{
    int valor;
    int peso;
};

int primeraSolucion_val = -1;
bool primeraSolucion[MAX_ITEMS] = {false};

void printSolucion(bool seleccion_act[], Item items[], int numItems) {
    for (int i = 0; i < numItems; i++) {
        if (seleccion_act[i]) {
            cout << items[i].valor << " " << items[i].peso << endl;
        }
    }
}

void mochila(int index, int pesoMochila, Item items[], int numItems, bool seleccion_act[], int valorAct, int pesoAct) {
    if (pesoAct > pesoMochila) {
        return; // Exceeded the weight limit

    }
    /*
    if(primeraSolucion_val != -1){
        return; // Already found a solution
    } */
    else {
        //primeraSolucion_val = valorAct; // Store the value of the first solution
        for (int i = 0; i < numItems; i++) {
            primeraSolucion[i] = seleccion_act[i]; // Store the first solution
        }
    }
        // Exclude the item
        seleccion_act[index] = false;
        mochila(index + 1, pesoMochila, items, numItems, seleccion_act, valorAct, pesoAct);

        // Include the item
        seleccion_act[index] = true;
        /*
        valorSol += items[index].valor;
        pesoMochila -= items[i].peso;
        */
        mochila(index + 1, pesoMochila, items, numItems, seleccion_act, valorAct + items[index].valor, pesoAct + items[index].peso);
        
        /* Backtrack
        valorSol -= items[i].valor;
        pesoMochila += items[i].peso;
        */
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
    cout << "Primera solucion encontrada: ";
    printSolucion(seleccion_act, items, numItems); // Print the first solution
    return 0;
}