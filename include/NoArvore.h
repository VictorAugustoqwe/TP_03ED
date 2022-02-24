#ifndef NOARVORE_H
#define NOARVORE_H

#include "ItemArvore.h"

class NoArvore{
    public:
        //Construtor
        NoArvore();
        //Destrutor
        ~NoArvore();

        ItemArvore *item;
        NoArvore *esq;
        NoArvore *dir;
};

#endif