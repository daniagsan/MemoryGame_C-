#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;


void crearMatriz(){

    const int filas = 4;
    const int columnas = 5;
    const int totalPares = 10;
    int matriz[filas][columnas] = {0};
    int numero = 0;
    int pares = 0;

    //llenar arreglo
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 4; j++){
            matriz[i][j] = numero;
            pares++;
            if(pares == 2){
                numero++;
                pares = 0;
            }
        }
    }

    int casilla = 1;
    //imprimir arreglo
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 4; j++){
            cout <<matriz[i][j]<<" ";
            casilla++;
        }
        cout << endl;
    }
}

int main()
{
    int userx = 0, usery = 0;
    int casillaUser;
    
    crearMatriz();
    cout << "Ingrese la fila: ";
    cin >> userx;
    cout << "Ingrese la columna: ";
    cin >> usery;

    return 0;
}
