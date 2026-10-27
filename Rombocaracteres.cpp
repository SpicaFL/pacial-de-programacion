#include <iostream>
using namespace std;
 
int main() {
    int n;
    char simbolo;
 
    do {
        cout << "Ingrese la altura del rombo (entero impar positivo): ";
        cin >> n;
        if (n <= 0 || n % 2 == 0) {
            cout << "Valor invalido, intente de nuevo." << endl;
        }
    } while (n <= 0 || n % 2 == 0);
 
    cout << "Ingrese el caracter: ";
    cin >> simbolo;
 
    int centro = n / 2;   
 
    for (int fila = 0; fila < n; fila++) {
     
        int distancia;
        if (fila <= centro) {
            distancia = centro - fila;
        } else {
            distancia = fila - centro;
        }
 
        int espacios = distancia;
        int simbolos = n - 2 * distancia;
 
        for (int i = 0; i < espacios; i++) cout << ' ';
        for (int i = 0; i < simbolos; i++) cout << simbolo;
        cout << endl;
    }
    return 0;
}