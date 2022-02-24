#include "Arvore.h"
//Construtor
Arvore::Arvore(){
    raiz = nullptr;
}
//Destrutor
Arvore::~Arvore(){
    Limpa();
}
//Apaga todos os elementos e reinicia raiz
void Arvore::Limpa(){
    ApagaRecursivo(raiz);
    raiz = nullptr;
}
//Auxilia Limpa
void Arvore::ApagaRecursivo(NoArvore *p){
    if(p!=nullptr){
        ApagaRecursivo(p->esq);
        ApagaRecursivo(p->dir);
        delete p;
    }
}
//Insere chave e dado na árvore conforme necessário
void Arvore::Insere(std::string _chave, std::string _dado){
    InsereRecursivo(raiz, _chave, _dado);
}
//Auxilia Insere
void Arvore::InsereRecursivo(NoArvore *&p, std::string _chave, std::string _dado){
    if(p==nullptr){
        p = new NoArvore();
        p->item->chave = _chave;
        p->item->lista->insereFinal(_dado);
    }
    else{
        if(_chave == p->item->chave){
            p->item->lista->insereFinal(_dado);
        }
        else{
            if(_chave < p->item->chave)
                InsereRecursivo(p->esq, _chave, _dado);
            else
                InsereRecursivo(p->dir, _chave, _dado);
        }
    }
}
//Remove da árvore o elemento com a chave passada
void Arvore::Remove(std::string _chave){
    ApagarRecursivo(raiz, _chave);
}
//Auxilia Remove
void Arvore::ApagarRecursivo(NoArvore* &atual, std::string _chave){
    NoArvore *aux;

    if (atual == nullptr) {
        throw("Item nao está presente");
    }
    if (_chave < atual->item->chave)
        return ApagarRecursivo(atual->esq, _chave);
    else if (_chave > atual->item->chave)
        return ApagarRecursivo(atual->dir, _chave);
    else {
        if (atual->dir == nullptr) {
            aux = atual;
            atual = atual->esq;
            delete aux;
        }
        else if(atual->esq == nullptr) {
            aux = atual;
            atual = atual->dir;
            delete aux;
        }
        else
            Antecessor(atual, atual->esq);
    }
}

//Seleciona o elemento que vai substituir o removido
void Arvore::Antecessor(NoArvore* removido, NoArvore*& percorre){
    if(percorre->dir != nullptr) {
        Antecessor(removido, percorre->dir);
        return;
    }
    removido->item = percorre->item;
    removido = percorre;
    percorre = percorre->esq;
}
//imprime chaves percorrendo a árvore em ordem
void Arvore::ChavesInOrder(){
    NoArvore *menor = raiz;
    while (menor->esq != nullptr){
        menor = menor->esq;
    }
    ChavesInOrderRecursivo(raiz, menor);
}
//auxilia chavesInOrder
void Arvore::ChavesInOrderRecursivo(NoArvore *p, NoArvore *menor){
    if(p != nullptr){
        ChavesInOrderRecursivo(p->esq, menor);
        if(p != menor)
            std::cout << " ";
        std::cout << p->item->chave;
        ChavesInOrderRecursivo(p->dir, menor);
    }      
}
//Retorna soma dos dados referentes a chava 
int Arvore::SomaDaChave(std::string _chave){
    return SomaDaChaveRecursivo(raiz, _chave);
}
//Auxilia SomaDaChave
int Arvore::SomaDaChaveRecursivo(NoArvore *atual, std::string _chave){
    if (atual == nullptr) {
        throw("Item nao está presente");
    }
    if (_chave < atual->item->chave)
        return SomaDaChaveRecursivo(atual->esq, _chave);
    else if (_chave > atual->item->chave)
        return SomaDaChaveRecursivo(atual->dir, _chave);
    else {
        return atual->item->lista->somaLista();
    }
}