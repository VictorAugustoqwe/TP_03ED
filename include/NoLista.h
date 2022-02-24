#ifndef NOLISTA_H
#define NOLISTA_H

#include <iostream>

class NoLista{
    public:
        //Construtor
        NoLista();
        //Construtor com parâmetro
        NoLista(std::string _dado);

        std::string dado;
        NoLista *prox; 
};

#endif