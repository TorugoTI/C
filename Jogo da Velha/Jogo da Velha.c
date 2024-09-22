#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

char tabuleiro[3][3] = {
   {' ', ' ', ' '},
   {' ', ' ', ' '},
   {' ', ' ', ' '}
};

void exibirTabuleiro() {
   cout << "  1   2   3" << endl;
   cout << "1 " << tabuleiro[0][0] << " | " << tabuleiro[0][1] << " | " << tabuleiro[0][2] << endl;
   cout << "  ---------" << endl;
   cout << "2 " << tabuleiro[1][0] << " | " << tabuleiro[1][1] << " | " << tabuleiro[1][2] << endl;
   cout << "  ---------" << endl;
   cout << "3 " << tabuleiro[2][0] << " | " << tabuleiro[2][1] << " | " << tabuleiro[2][2] << endl;
}

bool verificarVencedor(char jogador) {
   // Verificar linhas
   for (int i = 0; i < 3; i++) {
      if (tabuleiro[i][0] == jogador && tabuleiro[i][1] == jogador && tabuleiro[i][2] == jogador) {
         return true;
      }
   }

   // Verificar colunas
   for (int j = 0; j < 3; j++) {
      if (tabuleiro[0][j] == jogador && tabuleiro[1][j] == jogador && tabuleiro[2][j] == jogador) {
         return true;
      }
   }

   // Verificar diagonais
   if ((tabuleiro[0][0] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][2] == jogador) ||
       (tabuleiro[0][2] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][0] == jogador)) {
      return true;
   }

   return false;
}

bool verificarEmpate() {
   for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
         if (tabuleiro[i][j] == ' ') {
            return false;
         }
      }
   }
   return true;
}

bool fazerJogada(char jogador, int linha, int coluna) {
   if (linha >= 1 && linha <= 3 && coluna >= 1 && coluna <= 3 && tabuleiro[linha - 1][coluna - 1] == ' ') {
      tabuleiro[linha - 1][coluna - 1] = jogador;
      return true;
   } else {
      return false;
   }
}

int main() {
   char jogadorAtual = 'X';
   int linha, coluna;

   cout << "Bem-vindo ao Jogo da Velha!" << endl;

   do {
      exibirTabuleiro();

      cout << "Jogador " << jogadorAtual << ", faça sua jogada." << endl;
      cout << "Digite a linha (1-3): ";
      cin >> linha;
      cout << "Digite a coluna (1-3): ";
      cin >> coluna;

      if (fazerJogada(jogadorAtual, linha, coluna)) {
         if (verificarVencedor(jogadorAtual)) {
            exibirTabuleiro();
            cout << "Jogador " << jogadorAtual << " venceu o jogo!" << endl;
            break;
         } else if (verificarEmpate()) {
            exibirTabuleiro();
            cout << "O jogo terminou em empate!" << endl;
            break;
         } else {
            jogadorAtual = (jogadorAtual == 'X') ? 'O' : 'X';
         }
      } else {
         cout << "Jogada inválida. Tente novamente." << endl;
      }
   } while (true);

   return 0;
}