#include "NoArvore.h"

//Construtor
NoArvore::NoArvore(){
    item = new ItemArvore();
    esq = nullptr;
    dir = nullptr;
}

//Destrutor
NoArvore::~NoArvore(){
    delete item;
}