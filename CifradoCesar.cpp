#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    char opcion;
    int k;
    string mensaje;

    cout << "Cifrar (C) o descifrar (D): ";
    cin >> opcion;
    
    opcion = static_cast<char>(toupper(static_cast<unsigned char>(opcion)));
    if (opcion != 'C' && opcion != 'D') {
        cout << "Opcion invalida." << endl;
        return 0;
    }

    cout << "Desplazamiento: ";
    cin >> k;
    cin.ignore(10000, '\n');         

    cout << "Mensa#ije: ";
    getline(cin, mensaje);

    if (opcion == 'D') {
        k = -k; 
    }


    k = k % 26;
    if (k < 0) {
        k += 26;
    }

    string resultado = "";
    for (char c : mensaje) {
        unsigned char uc = static_cast<unsigned char>(c);
        if (isupper(uc)) {
            resultado += static_cast<char>('A' + (c - 'A' + k) % 26);
        } else if (islower(uc)) {
            resultado += static_cast<char>('a' + (c - 'a' + k) % 26);
        } else {
            resultado += c;             
        }
    }

    cout << "Resultado: " << resultado << endl;
    return 0;
}