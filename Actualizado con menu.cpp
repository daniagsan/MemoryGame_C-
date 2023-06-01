#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

const int FILAS = 5;
const int COLUMNAS = 4;

int matriz[FILAS][COLUMNAS] = {0};
bool revelado[FILAS][COLUMNAS] = {false};
int paresEncontrados = 0;
int numAnteriorFila = -1;
int numAnteriorColumna = -1;

void crearMatriz() {
    int numero = 0;
    int pares = 0;

    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            matriz[i][j] = numero;
            pares++;
            if (pares == 2) {
                numero++;
                pares = 0;
            }
        }
    }

    // mezclar matriz
    srand(time(0));
    int totalElementos = FILAS * COLUMNAS;
    for (int i = totalElementos - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = matriz[i / COLUMNAS][i % COLUMNAS];
        matriz[i / COLUMNAS][i % COLUMNAS] = matriz[j / COLUMNAS][j % COLUMNAS];
        matriz[j / COLUMNAS][j % COLUMNAS] = temp;
    }
}

void imprimirMatriz() {
    cout << "    ";
    for (int j = 0; j < COLUMNAS; j++) {
        cout << j << "   ";
    }
    cout << endl;

    for (int i = 0; i < FILAS; i++) {
        cout << i << " | ";
        for (int j = 0; j < COLUMNAS; j++) {
            if (revelado[i][j]) {
                cout << matriz[i][j] << " ";
            } else {
                cout << "* ";
            }
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

void juegoMatriz(int fila, int columna) {
    if (fila >= 0 && fila < FILAS && columna >= 0 && columna < COLUMNAS) {
        if (revelado[fila][columna]) {
            cout << "Este número ya está revelado. Por favor, selecciona otro." << endl;
        } else {
            revelado[fila][columna] = true;
            imprimirMatriz();
            if (numAnteriorFila == -1 && numAnteriorColumna == -1) {
                numAnteriorFila = fila;
                numAnteriorColumna = columna;
            } else {
                if (matriz[fila][columna] == matriz[numAnteriorFila][numAnteriorColumna]) {
                    cout << "¡Has encontrado un par! Los números son iguales." << endl;
                    paresEncontrados++;
                } else {
                    revelado[fila][columna] = false;
                    revelado[numAnteriorFila][numAnteriorColumna] = false;
                    cout << "Los números no son iguales. Inténtalo de nuevo." << endl;
                }
                numAnteriorFila = -1;
                numAnteriorColumna = -1;
            }
        }
    } else {
        cout << "Selecciona una posición válida." << endl;
    }
}

int main() {
    int fila = 0, columna = 0;
    bool juegoTerminado = false;

    mostrarPortada();
    mostrarInstrucciones();

    crearMatriz();

    while (!juegoTerminado) {
        imprimirMatriz();
        cout << "Ingrese la fila: ";
        cin >> fila;
        cout << "Ingrese la columna: ";
        cin >> columna;

        juegoMatriz(fila, columna);

        system("pause");
        system("cls");

        if (paresEncontrados == (FILAS * COLUMNAS) / 2) {
            cout << "¡Felicidades! ¡Has encontrado todos los pares!" << endl;
            juegoTerminado = true;
        }
    }

    return 0;
}



