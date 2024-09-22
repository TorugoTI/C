#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main() {
   float num1, num2, resultado;
   int operador;

   cout << "Digite o primeiro número: ";
   cin >> num1;

   cout << "Digite o segundo número: ";
   cin >> num2;

   cout << "Selecione o operador:\n";
   cout << "1 - Adição\n";
   cout << "2 - Subtração\n";
   cout << "3 - Multiplicação\n";
   cout << "4 - Divisão\n";
   cin >> operador;

   switch (operador) {
      case 1:
         resultado = num1 + num2;
         cout << "Resultado: " << resultado << endl;
         break;
      case 2:
         resultado = num1 - num2;
         cout << "Resultado: " << resultado << endl;
         break;
      case 3:
         resultado = num1 * num2;
         cout << "Resultado: " << resultado << endl;
         break;
      case 4:
         if (num2 != 0) {
            resultado = num1 / num2;
            cout << "Resultado: " << resultado << endl;
         } else {
            cout << "Divisão por zero não é permitida." << endl;
         }
         break;
      default:
         cout << "Operador inválido." << endl;
         break;
   }

   return 0;
}