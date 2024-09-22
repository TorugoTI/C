#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
   string palavraSecreta;
   vector<char> letrasTentadas;
   int numTentativas = 6;
   bool jogoAcabou = false;

   cout << "Bem-vindo ao Jogo da Forca!" << endl;
   cout << "Digite a palavra secreta: ";
   cin >> palavraSecreta;

   while (!jogoAcabou) {
      char letra;
      cout << "Digite uma letra: ";
      cin >> letra;

      letrasTentadas.push_back(letra);

      bool acertou = false;

      for (char c : palavraSecreta) {
         if (letra == c) {
            acertou = true;
            break;
         }
      }

      if (acertou) {
         cout << "Letra correta!" << endl;
      } else {
         numTentativas--;
         cout << "Letra incorreta! Você tem mais " << numTentativas << " tentativas." << endl;
      }

      if (numTentativas == 0) {
         cout << "Você perdeu! A palavra secreta era: " << palavraSecreta << endl;
         jogoAcabou = true;
      }

      bool todasLetrasDescobertas = true;

      for (char c : palavraSecreta) {
         if (find(letrasTentadas.begin(), letrasTentadas.end(), c) == letrasTentadas.end()) {
            todasLetrasDescobertas = false;
            break;
         }
      }

      if (todasLetrasDescobertas) {
         cout << "Parabéns! Você acertou a palavra secreta: " << palavraSecreta << endl;
         jogoAcabou = true;
      }
   }

   return 0;
}