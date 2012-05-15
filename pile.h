#ifndef PILE_H
#define PILE_H

#include "constante.h"

class Pile
{
    int taille;
    int sommet;
    Constante** tabElmt;
public:
    Pile(int dim);
    ~Pile();

    void Empiler(Constante* c);
    Constante* Depiler();
    Constante* Tete()const;

    void Swap(int x, int y);
    int Sum(int x);//somme des x premiers éléments (N, Q, R, C)         TEMPLATE METHOD
    int Mean(int x);//moyenne des x premiers éléments (N, Q, R, C)

    void Clear();
    void Dup();//duplique le dernier élément
    void Drop();//supprime le dernier élément
};

#endif // PILE_H
