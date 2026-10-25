#include <iostream>
#include <string>
using namespace std;
 
int main() {
    int numero;
    cout << "Ingrese un entero entre 1 y 3999: ";
    cin >> numero;
 
    if (numero < 1 || numero > 3999) {
        cout << "Numero fuera de rango." << endl;
        return 0;
    }
 
    int n = numero;     
    string romano = "";
 
   
    while (n >= 1000) { romano += "M";  n -= 1000; }
    while (n >= 900)  { romano += "CM"; n -= 900;  }
    while (n >= 500)  { romano += "D";  n -= 500;  }
    while (n >= 400)  { romano += "CD"; n -= 400;  }
    while (n >= 100)  { romano += "C";  n -= 100;  }
    while (n >= 90)   { romano += "XC"; n -= 90;   }
    while (n >= 50)   { romano += "L";  n -= 50;   }
    while (n >= 40)   { romano += "XL"; n -= 40;   }
    while (n >= 10)   { romano += "X";  n -= 10;   }
    while (n >= 9)    { romano += "IX"; n -= 9;    }
    while (n >= 5)    { romano += "V";  n -= 5;    }
    while (n >= 4)    { romano += "IV"; n -= 4;    }
    while (n >= 1)    { romano += "I";  n -= 1;    }
 
    cout << numero << " = " << romano << endl;
    return 0;
}