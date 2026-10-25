#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string clave;
    cout << "Ingrese la contrasena: ";
    getline(cin, clave);

    bool hayMayuscula = false, hayMinuscula = false;
    bool hayDigito = false, haySimbolo = false;

    for (char c : clave) {
        unsigned char u = static_cast<unsigned char>(c);
        if (isupper(u)) {
            hayMayuscula = true;
        } else if (islower(u)) {
            hayMinuscula = true;
        } else if (isdigit(u)) {
            hayDigito = true;
        } else if (c != ' ') {
            haySimbolo = true;
        }
    }

    bool valida = true;

    if (clave.size() < 8) {
        cout << "Debe tener al menos 8 caracteres." << endl;
        valida = false;
    }
    if (!hayMayuscula) {
        cout << "Falta al menos una letra mayuscula." << endl;
        valida = false;
    }
    if (!hayMinuscula) {
        cout << "Falta al menos una letra minuscula." << endl;
        valida = false;
    }
    if (!hayDigito) {
        cout << "Falta al menos un digito." << endl;
        valida = false;
    }
    if (!haySimbolo) {
        cout << "Falta al menos un simbolo." << endl;
        valida = false;
    }

    if (valida) {
        cout << "Contrasena valida." << endl;
    } else {
        cout << "Contrasena invalida." << endl;
    }
    return 0;
}