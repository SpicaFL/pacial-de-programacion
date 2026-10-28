#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    int opcion;
    string cadena;

    cout << "1. Comprimir" << endl;
    cout << "2. Descomprimir" << endl;
    cout << "Opcion: ";
    cin >> opcion;
    cin.ignore();                      
    cout << "Cadena: ";
    getline(cin, cadena);

    size_t n = cadena.size();         


    if (opcion == 1) {
    
        bool hayDigitos = false;
        for (char c : cadena) {
            if (isdigit((unsigned char)c)) hayDigitos = true;
        }
        if (hayDigitos) {
            cout << "La cadena no debe contener digitos." << endl;
            return 0;                  
        }

        string comprimida = "";
        size_t i = 0;
        while (i < n) {
            char actual = cadena[i];
            size_t cuenta = 1;
            while (i + cuenta < n && cadena[i + cuenta] == actual) {
                cuenta++;              
            }
            comprimida += actual;
            comprimida += to_string(cuenta);
            i += cuenta;            
        }
        cout << "Comprimida: " << comprimida << endl;

    } else if (opcion == 2) {
        
        string original = "";
        bool valido = (n > 0);
        size_t i = 0;

        while (i < n && valido) {
            char letra = cadena[i];
            if (isdigit((unsigned char)letra)) {     
                valido = false;
            } else {
                i++;
                if (i >= n || !isdigit((unsigned char)cadena[i])) {
                    valido = false;                 
                } else {
                    size_t cantidad = 0;
                    while (i < n && isdigit((unsigned char)cadena[i])) {
                        cantidad = cantidad * 10 + (cadena[i] - '0');  
                        i++;
                    }
                    if (cantidad == 0) {
                        valido = false;             
                    } else {
                        for (size_t k = 0; k < cantidad; k++) {
                            original += letra;       
                        }
                    }
                }
            }
        }

        if (valido) {
            cout << "Descomprimida: " << original << endl;
        } else {
            cout << "Formato invalido." << endl;
        }

    } else {
        cout << "Opcion invalida." << endl; 
    }
    return 0;
}