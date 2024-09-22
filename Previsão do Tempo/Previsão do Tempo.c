#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <curl/curl.h>
#include <json-c/json.h>

struct MemoryStruct {
   char* memory;
   size_t size;
};

size_t escreverDados(void* contents, size_t size, size_t nmemb, struct MemoryStruct* userp) {
   size_t realsize = size * nmemb;
   userp->memory = realloc(userp->memory, userp->size + realsize + 1);
   if (userp->memory == NULL) {
      cout << "Erro de alocação de memória." << endl;
      return 0;
   }
   memcpy(&(userp->memory[userp->size]), contents, realsize);
   userp->size += realsize;
   userp->memory[userp->size] = 0;

   return realsize;
}

void obterPrevisaoTempo(char* cidade) {
   CURL* curl;
   CURLcode res;

   struct MemoryStruct dados;
   dados.memory = (char*)malloc(1);
   dados.size = 0;

   char url[1000];
   sprintf(url, "https://api.hgbrasil.com/weather", cidade);

   curl_global_init(CURL_GLOBAL_DEFAULT);
   curl = curl_easy_init();

   if (curl) {
      curl_easy_setopt(curl, CURLOPT_URL, url);
      curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, escreverDados);
      curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void*)&dados);

      res = curl_easy_perform(curl);

      if (res != CURLE_OK) {
         cout << "Erro ao fazer a requisição: " << curl_easy_strerror(res) << endl;
      } else {
         struct json_object* jsonObject = json_tokener_parse(dados.memory);

         if (jsonObject == NULL) {
            cout << "Erro ao analisar os dados da previsão do tempo." << endl;
         } else {
            struct json_object* nomeObj;
            struct json_object* mainObj;
            struct json_object* tempObj;
            struct json_object* weatherObj;
            struct json_object* descricaoObj;

            json_object_object_get_ex(jsonObject, "name", &nomeObj);
            json_object_object_get_ex(jsonObject, "main", &mainObj);
            json_object_object_get_ex(mainObj, "temp", &tempObj);
            json_object_object_get_ex(jsonObject, "weather", &weatherObj);
            json_object_array_get_idx(weatherObj, 0, &descricaoObj);

            cout << "Previsão do tempo para " << json_object_get_string(nomeObj) << ":" << endl;
            cout << "Temperatura: " << json_object_get_double(tempObj) - 273.15 << "°C" << endl;
            cout << "Descrição: " << json_object_get_string(descricaoObj) << endl;

            json_object_put(jsonObject);
         }
      }

      curl_easy_cleanup(curl);
   }

   curl_global_cleanup();
   free(dados.memory);
}

int main() {
   char cidade[100];

   cout << "Bem-vindo ao Aplicativo de Previsão do Tempo!" << endl;

   cout << "Iremos mostrar a previsão de São Paulo: ";
   cin.ignore();
   obterPrevisaoTempo(cidade);

   return 0;
}
