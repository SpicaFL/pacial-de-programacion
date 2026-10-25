#include <iostream>
using namespace std;
 
int main() {
    int N;
    cout << "Ingrese N (>= 1): ";
    cin >> N;
 
    if (N < 1) {
        cout << "N debe ser mayor o igual a 1." << endl;
        return 0;
    }
 
    int mejorNumero = 1;
    int mejorPasos = -1;               // -1 para que el primer número siempre quede registrado
    long long mejorMaximo = 1;
 
    for (int inicio = 1; inicio <= N; inicio++) {
        long long x = inicio;
        int pasos = 0;
        long long maximo = x;
 
        while (x != 1) {
            if (x % 2 == 0) {
                x = x / 2;
            } else {
                x = 3 * x + 1;
            }
            pasos++;
            if (x > maximo) {
                maximo = x;
            }
        }
 
        // ">" estricto: en caso de empate se conserva el primero encontrado
        if (pasos > mejorPasos) {
            mejorPasos = pasos;
            mejorNumero = inicio;
            mejorMaximo = maximo;
        }
    }
 
    cout << "Numero con la secuencia mas larga: " << mejorNumero << endl;
    cout << "Pasos: " << mejorPasos << endl;
    cout << "Valor maximo alcanzado: " << mejorMaximo << endl;
    return 0;
}