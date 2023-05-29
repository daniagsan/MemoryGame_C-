#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <locale.h>
#include <time.h>

using namespace std;

int matriz[5][4] = {0};
int numero = 0;
int pares = 0;

void crearMatriz(int userx, int usery){


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
}

void imprimirMatriz(){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 4; j++){
            cout <<matriz[i][j]<<" ";
        }
        cout << endl;
    }
}

int main()
{
    int userx = 0, usery = 0;
    bool userState = true;

    crearMatriz(userx, usery);

    while(userState){
        imprimirMatriz();
        cout << "Ingrese la fila: ";
        cin >> userx;
        cout << "Ingrese la columna: ";
        cin >> usery;

        system("cls");
    }


    return 0;
}
