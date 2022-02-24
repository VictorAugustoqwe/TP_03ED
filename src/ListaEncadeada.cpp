#include "ListaEncadeada.h"

//Construtor
ListaEncadeada::ListaEncadeada(){
    primeiro = new NoLista();
    ultimo = primeiro;
}

//Destrutor
ListaEncadeada::~ListaEncadeada(){
    limpa();
    delete primeiro;
}

//Insere dado no final da lista encadeada
void ListaEncadeada::insereFinal(std::string dado){
    NoLista *novo;

    novo = new NoLista(dado);
    ultimo->prox = novo;
    ultimo = novo;
}

//Converte uma string de número binário para número inteiro
int ListaEncadeada::stringBinariaParaInteiro(std::string numeroBinario){
    int numeroConvertido = 0;
    int length = numeroBinario.length() - 1;
    for(int i = 0; i <= length; i++){
        if(numeroBinario[length-i] == '1'){
            numeroConvertido = numeroConvertido + pow(2,i);
        }
    }
    return numeroConvertido;
}

//Retorna soma de todos os números binários da lista convertidos para decimal
int ListaEncadeada::somaLista(){
    NoLista *percorre = primeiro->prox;
    int soma = 0;
    while (percorre != nullptr){
        soma = soma + stringBinariaParaInteiro(percorre->dado);
        percorre = percorre->prox;
    }
    return soma;
}

//Apaga todos os elementos da lista exceto o primeiro
void ListaEncadeada::limpa(){
    NoLista *aux;

    aux = primeiro->prox;
    while(aux != nullptr){
        primeiro->prox = aux->prox;
        delete aux;
        aux = primeiro->prox;
    }
    ultimo = primeiro;
}