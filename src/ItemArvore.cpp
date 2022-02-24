#include "ItemArvore.h"

//Construtor
ItemArvore::ItemArvore(){
    lista = new ListaEncadeada();
};

//Destrutor
ItemArvore::~ItemArvore(){
    delete lista;
}
