#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

float converterKmParaMilhas(float km) {
   return km * 0.621371;
}

float converterMilhasParaKm(float milhas) {
   return milhas / 0.621371;
}

float converterMetroParaPe(float metros) {
   return metros * 3.28084;
}

float converterPeParaMetro(float pes) {
   return pes / 3.28084;
}

int main() {
   int opcao;
   float valor;

   cout << "Bem-vindo ao Conversor de Unidades!" << endl;

   do {
      cout << "Selecione uma opção:" << endl;
      cout << "1 - Converter quilômetros para milhas" << endl;
      cout << "2 - Converter milhas para quilômetros" << endl;
      cout << "3 - Converter metros para pés" << endl;
      cout << "4 - Converter pés para metros" << endl;
      cout << "5 - Sair" << endl;
      cin >> opcao;

      switch (opcao) {
         case 1:
            cout << "Digite o valor em quilômetros: ";
            cin >> valor;
            cout << valor << " quilômetro(s) é igual a " << converterKmParaMilhas(valor) << " milha(s)." << endl;
            break;
         case 2:
            cout << "Digite o valor em milhas: ";
            cin >> valor;
            cout << valor << " milha(s) é igual a " << converterMilhasParaKm(valor) << " quilômetro(s)." << endl;
            break;
         case 3:
            cout << "Digite o valor em metros: ";
            cin >> valor;
            cout << valor << " metro(s) é igual a " << converterMetroParaPe(valor) << " pé(s)." << endl;
            break;
         case 4:
            cout << "Digite o valor em pés: ";
            cin >> valor;
            cout << valor << " pé(s) é igual a " << converterPeParaMetro(valor) << " metro(s)." << endl;
            break;
         case 5:
            cout << "Encerrando o programa..." << endl;
            break;
         default:
            cout << "Opção inválida." << endl;
            break;
      }
   } while (opcao != 5);

   return 0;
}