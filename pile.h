#ifndef PILE_H
#define PILE_H

#include "constante.h"
#include "entier.h"
#include "expression.h"
#include "complex"
#include "rationnel.h"
#include "reel.h"
#include <typeinfo>

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
    int Sum(int x);//somme des x premiers �l�ments (N, Q, R, C)         TEMPLATE METHOD
    int Mean(int x);//moyenne des x premiers �l�ments (N, Q, R, C)

    void Clear();
    void Dup();//duplique le dernier �l�ment
    void Drop();//supprime le dernier �l�ment

    Constante& Plus();//test sur les sommets et les types � faire
    Constante& Moins();
    Constante& Multiplier();
    Constante& Diviser();
    Constante& Puissance();
    Constante& Modulo();
};

#endif // PILE_H
