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
    cin.ignore();                       // Limpia el \n que cin dejó tirado en el buffer como si nada
    cout << "Cadena: ";
    getline(cin, cadena);

    size_t n = cadena.size();           // Usamos size_t para que el compilador deje de llorar por los tipos

    if (opcion == 1) {
        // ---------- COMPRIMIR ----------
        bool hayDigitos = false;
        for (char c : cadena) {
            if (isdigit((unsigned char)c)) hayDigitos = true; // Si metieron un número, activamos el pánico
        }
        if (hayDigitos) {
            cout << "La cadena no debe contener digitos." << endl;
            return 0;                   // Abortar misión, el usuario no sabe seguir instrucciones
        }

        string comprimida = "";
        size_t i = 0;
        while (i < n) {
            char actual = cadena[i];
            size_t cuenta = 1;
            while (i + cuenta < n && cadena[i + cuenta] == actual) {
                cuenta++;               // Contar letras iguales como si tuviéramos infinita paciencia
            }
            comprimida += actual;
            comprimida += to_string(cuenta);
            i += cuenta;                // Pegar el salto cuántico para no volver a contar lo mismo
        }
        cout << "Comprimida: " << comprimida << endl;

    } else if (opcion == 2) {
        // ---------- DESCOMPRIMIR ----------
        string original = "";
        bool valido = (n > 0);
        size_t i = 0;

        while (i < n && valido) {
            char letra = cadena[i];
            if (isdigit((unsigned char)letra)) {      // Si empieza con un número, todo en esta vida está mal
                valido = false;
            } else {
                i++;
                if (i >= n || !isdigit((unsigned char)cadena[i])) {
                    valido = false;                   // Esperaba un número y no hay nada. Exijo un reembolso.
                } else {
                    size_t cantidad = 0;
                    while (i < n && isdigit((unsigned char)cadena[i])) {
                        cantidad = cantidad * 10 + (cadena[i] - '0');   // Matemáticas oscuras para convertir texto a número
                        i++;
                    }
                    if (cantidad == 0) {
                        valido = false;               // ¿Repetir 0 veces? Ni para qué empezamos
                    } else {
                        for (size_t k = 0; k < cantidad; k++) {
                            original += letra;        // Clavar la misma letra una y otra vez como spammear el teclado
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
        cout << "Opcion invalida." << endl; // Era elegir entre 1 y 2, tampoco es física de partículas
    }
    return 0; // Cero errores, nos fuimos a dormir
}