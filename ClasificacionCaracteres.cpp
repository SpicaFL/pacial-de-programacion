#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string frase;
    cout << "Ingrese una frase: ";
    getline(cin, frase);

    int vocales = 0, consonantes = 0, digitos = 0, espacios = 0, otros = 0;

    for (char c : frase) {
        char m = static_cast<char>(tolower(static_cast<unsigned char>(c)));
        
        if (m == 'a' || m == 'e' || m == 'i' || m == 'o' || m == 'u') {
            vocales++;
        } else if (isalpha(static_cast<unsigned char>(c))) {  
            consonantes++;
        } else if (isdigit(static_cast<unsigned char>(c))) {
            digitos++;
        } else if (c == ' ') {
            espacios++;
        } else {
            otros++;
        }
    }

    cout << "Vocales: " << vocales << endl;
    cout << "Consonantes: " << consonantes << endl;
    cout << "Digitos: " << digitos << endl;
    cout << "Espacios: " << espacios << endl;
    cout << "Otros simbolos: " << otros << endl;
    return 0;
}