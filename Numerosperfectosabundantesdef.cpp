#include <iostream>
using namespace std;
int main() {
    int a, b;
    cout << "Ingrese a y b (1 <= a <= b): ";
    cin >> a >> b;
    if (a < 1 || a > b) {
        cout << "Rango invalido." << endl;
        return 0;
    }
    int perfectos = 0, abundantes = 0, deficientes = 0;

    for (int n = a; n <= b; n++) {
      
        int suma = 0;
        for (int d = 1; d <= n / 2; d++) {
            if (n % d == 0) {
                suma += d;
            }
        }
 
        cout << n << ": ";
        if (suma == n) {
            cout << "perfecto";
            perfectos++;
        } else if (suma > n) {
            cout << "abundante";
            abundantes++;
        } else {
            cout << "deficiente";
            deficientes++;
        }
        cout << " (suma de divisores = " << suma << ")" << endl;
    }
 
    cout << "Perfectos: " << perfectos << ", abundantes: " << abundantes
         << ", deficientes: " << deficientes << endl;
    return 0;
}