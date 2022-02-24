#ifndef ITEMARVORE_H
#define ITEMARVORE_H

#include "ListaEncadeada.h"

class ItemArvore{
    public:
        //Construtor
        ItemArvore();
        //Destrutor
        ~ItemArvore();
        std::string chave;
        ListaEncadeada* lista;
        
};

#endif