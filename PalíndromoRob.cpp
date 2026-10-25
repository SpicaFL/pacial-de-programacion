#include <iostream>
#include <string>
#include <cctype>
using namespace std;
 
int main() {
    string frase;
    cout << "Ingrese una frase: ";
    getline(cin, frase);
 
    int i = 0;                        // índice que avanza desde el inicio
    int j = (int)frase.size() - 1;    // índice que retrocede desde el final
    bool esPalindromo = true;
 
    while (i < j) {
        if (!isalnum((unsigned char)frase[i])) {
            i++;                      // ignora espacios y signos al inicio
        } else if (!isalnum((unsigned char)frase[j])) {
            j--;                      // ignora espacios y signos al final
        } else {
            if (tolower(frase[i]) != tolower(frase[j])) {
                esPalindromo = false;
                break;
            }
            i++;
            j--;
        }
    }
 
    if (esPalindromo) {
        cout << "Es palindromo." << endl;
    } else {
        cout << "No es palindromo." << endl;
    }
    return 0;
}