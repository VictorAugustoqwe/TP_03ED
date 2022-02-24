#ifndef ARVORE_H
#define ARVORE_H

#include "NoArvore.h"

class Arvore{
    public:
        //Construtor
        Arvore();
        //Destrutor
        ~Arvore();

        //Apaga todos os elementos e reinicia raiz
        void Limpa();
        //Auxilia Limpa
        void ApagaRecursivo(NoArvore *p);
        //Insere chave e dado na árvore conforme necessário
        void Insere(std::string _chave, std::string _dado);
        //Auxilia Insere
        void InsereRecursivo(NoArvore* &p, std::string _chave, std::string _dado);
        //Remove da árvore o elemento com a chave passada
        void Remove(std::string _chave);
        //Auxilia Remove
        void ApagarRecursivo(NoArvore* &atual, std::string _chave);
        //Seleciona o elemento que vai substituir o removido
        void Antecessor(NoArvore* removido, NoArvore* &percorre);
        //imprime chaves percorrendo a árvore em ordem
        void ChavesInOrder();
        //auxilia chavesInOrder
        void ChavesInOrderRecursivo(NoArvore *p, NoArvore *menor);
        //Retorna soma dos dados referentes a chava 
        int SomaDaChave(std::string _chave);
        //Auxilia SomaDaChave
        int SomaDaChaveRecursivo(NoArvore *atual, std::string _chave);

        NoArvore *raiz;
};

#endif