#include <iostream>
#include <fstream>
#include <string>

#include "Arvore.h"

using namespace std;

//Lê entradas e abre o arquivo executando as inserções na árvore e retiradas conforme as linhas.
int main(int argc, char* argv[]){
    int nlinhas, posEspaco;
    string nomeAtual, linha, dadoAtual;
    Arvore BST;
    try{
        if(argv[1] == NULL){
            cout << "Nome do Arquivo Faltando!" << endl;
            return 1;
        }
        ifstream arquivo(argv[1]);
        getline(arquivo, linha);
        nlinhas = stoi(linha);

        if(nlinhas < 0){
            cout << "Numero de Linhas Incorreto!" << endl;
            return 1;
        }
        for(int i = 0; i < nlinhas; i++){
            getline(arquivo, linha);
            posEspaco = linha.find(" ");
            nomeAtual = linha.substr(0,posEspaco);
            dadoAtual = linha.substr(posEspaco + 1,8);
            BST.Insere(nomeAtual, dadoAtual);
        }
        if(BST.raiz != nullptr)
            BST.ChavesInOrder();
        cout << endl;
        while(getline(arquivo, linha)){
            while(linha[linha.length()-1] == '\n' || linha[linha.length()-1] == '\r')
                linha = linha.substr(0, linha.length() - 1);
            nomeAtual = linha;
            if(nomeAtual.length() > 0){
                cout << nomeAtual << " " << BST.SomaDaChave(nomeAtual) << endl;
                BST.Remove(nomeAtual);
            }
        }
        if(BST.raiz != nullptr)
            BST.ChavesInOrder();
    }catch(const char* e){
        cerr << e;
        return 1;
    }
    return 0;
}