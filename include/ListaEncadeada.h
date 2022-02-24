#ifndef LISTA_H
#define LISTA_H

#include <cmath>
#include "NoLista.h"

class ListaEncadeada{
    public:
        //Construtor
        ListaEncadeada();
        //Destrutor
        ~ListaEncadeada();

        //Insere dado no final da lista encadeada
        void insereFinal(std::string dado);
        //Converte uma string de número binário para número inteiro
        int stringBinariaParaInteiro(std::string numeroBinario);
        //Retorna soma de todos os números binários da lista convertidos para decimal
        int somaLista();
        //Apaga todos os elementos da lista exceto o primeiro
        void limpa();

    private:
        NoLista *primeiro;
        NoLista *ultimo;
};

#endif