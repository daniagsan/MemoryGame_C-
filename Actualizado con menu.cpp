#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <Windows.h>

using namespace std;

const int FILAS = 5;
const int COLUMNAS = 4;

int matriz[FILAS][COLUMNAS] = {0};
bool revelado[FILAS][COLUMNAS] = {false};
int paresEncontrados = 0;
int numAnteriorFila = -1;
int numAnteriorColumna = -1;

void crearMatriz()
{
    int numero = 0;
    int pares = 0;

    for (int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < COLUMNAS; j++)
        {
            matriz[i][j] = numero;
            pares++;
            if (pares == 2)
            {
                numero++;
                pares = 0;
            }
        }
    }

    // mezclar matriz
    srand(time(0));
    int totalElementos = FILAS * COLUMNAS;
    for (int i = totalElementos - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        int temp = matriz[i / COLUMNAS][i % COLUMNAS];
        matriz[i / COLUMNAS][i % COLUMNAS] = matriz[j / COLUMNAS][j % COLUMNAS];
        matriz[j / COLUMNAS][j % COLUMNAS] = temp;
    }
}

void imprimirMatriz()
{
    cout << "    ";
    for (int j = 0; j < COLUMNAS; j++)
    {
        cout << j << " ";
    }
    cout << endl;

    for (int i = 0; i < FILAS; i++)
    {
        cout << i << " | ";
        for (int j = 0; j < COLUMNAS; j++)
        {
            if (revelado[i][j])
            {
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                int color = matriz[i][j] % 15 + 1;
                SetConsoleTextAttribute(hConsole, color);
                cout << matriz[i][j] << " ";
                SetConsoleTextAttribute(hConsole, 15);
            }
            else
            {
                cout << "* ";
            }
        }
        cout << endl;
    }
}

void mostrarPortada()
{
    srand(time(0));
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int color1 = rand() % 15 + 1;
    int color2 = rand() % 15 + 1;

    SetConsoleTextAttribute(hConsole, color1);
    cout << "=========================================================" << endl;
    cout << "                          MEMORAMA                       " << endl;
    cout << "=========================================================" << endl;
    SetConsoleTextAttribute(hConsole, color2);
    cout << " Realizado por: Daniel Aguilera & \n                                  Brayan Torres" << endl;
    SetConsoleTextAttribute(hConsole, 15);
    cout << "=========================================================" << endl;
    cout << endl;
    cout << "Presiona ENTER para comenzar el juego..." << endl;
    cin.ignore();
}


void mostrarInstrucciones()
{
    srand(time(0));
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int color1 = rand() % 15 + 1;
    int color2 = rand() % 15 + 1;

    SetConsoleTextAttribute(hConsole, color1);

    system("cls");



    cout << "=================================================================================" << endl;
    cout << "                                   Instrucciones                                 " << endl;
    cout << "=================================================================================" << endl;

    SetConsoleTextAttribute(hConsole, 15);
    cout << "El objetivo del juego es encontrar todos los pares de números.                   " << endl;
    cout << "En cada turno, selecciona una posición en la matriz ingresando su fila y columna." << endl;
    cout << "Se revelará el número en esa posición.                                           " << endl;
    cout << "Luego, selecciona otra posición para intentar encontrar el par del número anterior," << endl;
    cout << "Si los números son iguales, has encontrado un par y se mantendrán revelados." << endl;
    cout << "Si los números son diferentes, se volverán a ocultar," << endl;
    cout << "Continúa hasta encontrar todos los pares." << endl;
    cout << endl;
    cout << "Presiona ENTER para volver al juego..." << endl;

    cin.ignore();
    system("cls");
}

void juegoMatriz(int fila, int columna)
{
    if (fila >= 0 && fila < FILAS && columna >= 0 && columna < COLUMNAS)
    {
        if (revelado[fila][columna])
        {
            cout << "Este número ya está revelado. Por favor, selecciona otro." << endl;
        }
        else
        {
            revelado[fila][columna] = true;
            imprimirMatriz();
            if (numAnteriorFila == -1 && numAnteriorColumna == -1)
            {
                numAnteriorFila = fila;
                numAnteriorColumna = columna;
            }
            else
            {
                if (matriz[fila][columna] == matriz[numAnteriorFila][numAnteriorColumna])
                {
                    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                    int color = matriz[fila][columna] % 15 + 1;
                    SetConsoleTextAttribute(hConsole, color);
                    cout << "¡Has encontrado un par! Los números son iguales." << endl;
                    SetConsoleTextAttribute(hConsole, 15);
                    paresEncontrados++;
                }
                else
                {
                    revelado[fila][columna] = false;
                    revelado[numAnteriorFila][numAnteriorColumna] = false;
                    cout << "Los números no son iguales. Inténtalo de nuevo." << endl;
                }
                numAnteriorFila = -1;
                numAnteriorColumna = -1;
            }
        }
    }
    else
    {
        cout << "Selecciona una posición válida." << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "");
    int fila = 0, columna = 0;
    bool juegoTerminado = false;

    mostrarPortada();
    mostrarInstrucciones();

    crearMatriz();

    while (!juegoTerminado)
    {
        imprimirMatriz();
        cout << "Ingrese la fila: ";
        cin >> fila;
        cout << "Ingrese la columna: ";
        cin >> columna;

        juegoMatriz(fila, columna);

        system("pause");
        system("cls");

        if (paresEncontrados == (FILAS * COLUMNAS) / 2)
        {
            
                string indent = "                                         ";
                cout << indent << "       \\`\"-. " << endl;
                cout << indent << "        )  _`-. " << endl;
                cout << indent << "       ,  : `. \\ " << endl;
                cout << indent << "       : _   '  \\ " << endl;
                cout << indent << "       ; *` _.   `--._ " << endl;
                cout << indent << "       `-.-'          `-. " << endl;
                cout << indent << "         |       `       `. " << endl;
                cout << indent << "         :.       .        \\ " << endl;
                cout << indent << "         | \\  .   :   .-'   . " << endl;
                cout << indent << "         :  )-.;  ;  /      : " << endl;
                cout << indent << "         :  ;  | :  :       ;-. " << endl;
                cout << indent << "         ; /   : |`-:     _ `- ) " << endl;
                cout << indent << "      ,-' /  ,-' ; .-`- .' `--' " << endl;
                cout << indent << "      `--'   `---' `---' " << endl;
            cout << "¡Felicidades! ¡Has encontrado todos los pares! " << endl;
            juegoTerminado = true;
        }
    }

    return 0;
}

