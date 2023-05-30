#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <locale.h>
#include <time.h>

using namespace std;

int matriz[5][4] = {0};
int numero = 0;
int pares = 0;
int parfound = 0;
int numIgual = 0;

void crearMatriz(int userx, int usery){

    // llenar arreglo
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

    // mezclar matriz
    srand(time(0));
    int totalElementos = 5 * 4;
    for(int i = totalElementos - 1; i > 0; i--){
        int j = rand() % (i + 1);
        int temp = matriz[i / 4][i % 4];
        matriz[i / 4][i % 4] = matriz[j / 4][j % 4];
        matriz[j / 4][j % 4] = temp;
    }
}

void imprimirMatriz(){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 4; j++){
            cout <<matriz[i][j] << " ";
        }
        cout << endl;
    }
}

void mostrarPortada() {
    cout << "==================================" << endl;
    cout << "             MEMORAMA             " << endl;
    cout << "==================================" << endl;
    cout << "    Realizado por: Dani y Gama    " << endl;
    cout << "==================================" << endl;
    cout << endl;
    cout << "Presiona ENTER para comenzar el juego..." << endl;
    cin.ignore();
}

void mostrarInstrucciones() {
    system("cls");
    cout << "==================================" << endl;
    cout << "          Instrucciones           " << endl;
    cout << "==================================" << endl;
    cout << "Instrucciones del juego..." << endl;
    cout << endl;
    cout << "Presiona ENTER para volver al juego..." << endl;
    cin.ignore();
    system("cls");
}

void juegoMatriz(int userx, int usery){


    if(userx < 4 && usery < 5 && parfound == 0){
        cout<<"Usted a seleccionado el numero: "<<matriz[userx][usery]<<endl;
        parfound++;
        numIgual = matriz[userx][usery];


    if(parfound == 1){
        cout<<"Ingrese otras coordenadas para encontrar el par!"<<endl<<endl;
    }

    if(matriz[userx][usery] == numIgual){
        cout << "USTED HA ENCONTRADO UN PAR!";
        parfound = 0;
    }


    }else if(userx > 4 && usery > 5){
        cout <<"Ingrese coordenadas del 0 al 3 para la fila y del 0 al 4 para la columna"<<endl;
    }

}

int main()
{
    int userx = 0, usery = 0;
    bool userState = true;

    mostrarPortada();
    mostrarInstrucciones();

    crearMatriz(userx, usery);

    while(userState){
        imprimirMatriz();
        cout << "Ingrese la fila: ";
        cin >> userx;
        cout << "Ingrese la columna: ";
        cin >> usery;

        juegoMatriz(userx, usery);

        system("pause");
        system("cls");
    }

    return 0;
}
