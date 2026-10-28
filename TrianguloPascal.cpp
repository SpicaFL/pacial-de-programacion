#include <iostream>
#include <iomanip>
using namespace std;
 
int main() {
    int n;
    cout << "Numero de filas (1 a 15): ";
    cin >> n;
 
    if (n < 1 || n > 15) {
        cout << "Numero fuera de rango." << endl;
        return 0;
    }
 
    const int ANCHO = 6;               
 
    for (int fila = 0; fila < n; fila++) {
        
        cout << setw((n - 1 - fila) * (ANCHO / 2)) << "";
 
        long long c = 1;               
        for (int k = 0; k <= fila; k++) {
            cout << setw(ANCHO) << c;
            c = c * (fila - k) / (k + 1);  
        }
        cout << endl;
    }
    return 0;
}