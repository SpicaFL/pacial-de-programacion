#include <iostream>
using namespace std;
 
int main() {
    int n;
    char simbolo;
 
    // Validación con do-while: se repite mientras n sea par, cero o negativo
    do {
        cout << "Ingrese la altura del rombo (entero impar positivo): ";
        cin >> n;
        if (n <= 0 || n % 2 == 0) {
            cout << "Valor invalido, intente de nuevo." << endl;
        }
    } while (n <= 0 || n % 2 == 0);
 
    cout << "Ingrese el caracter: ";
    cin >> simbolo;
 
    int centro = n / 2;   // índice de la fila central (empezando en 0)
 
    for (int fila = 0; fila < n; fila++) {
        // distancia de la fila actual a la fila central
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