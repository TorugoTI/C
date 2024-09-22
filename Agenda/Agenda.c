#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Evento {
   string titulo;
   string data;
   string hora;
   string descricao;
};

void adicionarEvento() {
   Evento evento;

   cout << "Digite o título do evento: ";
   cin.ignore();
   getline(cin, evento.titulo);

   cout << "Digite a data do evento (dd/mm/aaaa): ";
   getline(cin, evento.data);

   cout << "Digite a hora do evento (hh:mm): ";
   getline(cin, evento.hora);

   cout << "Digite a descrição do evento: ";
   getline(cin, evento.descricao);

   ofstream arquivo("agenda.txt", ios::app);

   if (arquivo.is_open()) {
      arquivo << evento.titulo << "," << evento.data << "," << evento.hora << "," << evento.descricao << endl;
      arquivo.close();

      cout << "Evento adicionado com sucesso." << endl;
   } else {
      cout << "Erro ao abrir o arquivo." << endl;
   }
}

void visualizarEventos() {
   ifstream arquivo("agenda.txt");

   if (arquivo.is_open()) {
      string linha;

      while (getline(arquivo, linha)) {
         cout << linha << endl;
      }

      arquivo.close();
   } else {
      cout << "Erro ao abrir o arquivo." << endl;
   }
}

void editarEvento() {
   string tituloAntigo;
   cout << "Digite o título do evento que deseja editar: ";
   cin.ignore();
   getline(cin, tituloAntigo);

   ifstream arquivoAntigo("agenda.txt");

   if (arquivoAntigo.is_open()) {
      string linha;
      string conteudoNovo;
      string arquivoTemporario = "temp.txt";

      ofstream arquivoNovo(arquivoTemporario, ios::app);

      if (arquivoNovo.is_open()) {
         while (getline(arquivoAntigo, linha)) {
            size_t posicao = linha.find(tituloAntigo);
            if (posicao != string::npos) {
               cout << "Digite o novo título do evento: ";
               getline(cin, conteudoNovo);
               linha.replace(posicao, tituloAntigo.length(), conteudoNovo);
            }
            arquivoNovo << linha << endl;
         }

         arquivoAntigo.close();
         arquivoNovo.close();

         remove("agenda.txt");
         rename("temp.txt", "agenda.txt");

         cout << "Evento editado com sucesso." << endl;
      } else {
         cout << "Erro ao abrir o arquivo temporário." << endl;
      }
   } else {
      cout << "Erro ao abrir o arquivo antigo." << endl;
   }
}

void excluirEvento() {
   string tituloEvento;
   cout << "Digite o título do evento que deseja excluir: ";
   cin.ignore();
   getline(cin, tituloEvento);

   ifstream arquivoAntigo("agenda.txt");

   if (arquivoAntigo.is_open()) {
      string linha;
      string arquivoTemporario = "temp.txt";

      ofstream arquivoNovo(arquivoTemporario, ios::app);

      if (arquivoNovo.is_open()) {
         while (getline(arquivoAntigo, linha)) {
            size_t posicao = linha.find(tituloEvento);
            if (posicao == string::npos) {
               arquivoNovo << linha << endl;
            }
         }

         arquivoAntigo.close();
         arquivoNovo.close();

         remove("agenda.txt");
         rename("temp.txt", "agenda.txt");

         cout << "Evento excluído com sucesso." << endl;
      } else {
         cout << "Erro ao abrir o arquivo temporário." << endl;
      }
   } else {
      cout << "Erro ao abrir o arquivo antigo." << endl;
   }
}

int main() {
   int opcao;

   cout << "Bem-vindo ao Aplicativo de Agenda!" << endl;

   do {
      cout << "Selecione uma opção:" << endl;
      cout << "1 - Adicionar evento" << endl;
      cout << "2 - Visualizar eventos" << endl;
      cout << "3 - Editar evento" << endl;
      cout << "4 - Excluir evento" << endl;
      cout << "5 - Sair" << endl;
      cin >> opcao;

      switch (opcao) {
         case 1:
            adicionarEvento();
            break;
         case 2:
            visualizarEventos();
            break;
         case 3:
            editarEvento();
            break;
         case 4:
            excluirEvento();
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