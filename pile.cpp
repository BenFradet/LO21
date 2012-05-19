#include "pile.h"

Pile::Pile(int dim)
{
    taille = dim;
    sommet = 0;
    tabElmt = new Constante*[taille]();
}

Pile::~Pile()
{
}

void Pile::Empiler(Constante* c)
{
    if(sommet<taille)
        tabElmt[sommet++] = c;
    else;
        //erreur
}

Constante* Pile::Depiler()
{
    if(sommet>0)
        return tabElmt[--sommet];
    else;
        //erreur
}

Constante* Pile::Tete()const
{
    if(sommet>0)
        return tabElmt[sommet-1];
    else;
        //erreur
}

void Pile::Clear()
{
    sommet = 0;
}

void Pile::Dup()
{
    Constante* tmp = tabElmt[sommet-1];
    tabElmt[sommet++] = tmp;
}

void Pile::Drop()
{
    sommet--;
}

/*void Pile::Swap(int x, int y)
{
    if(sommet>x && sommet>y)
    {
        int tmp;
        tmp = tabElmt[x];
        tabElmt[x] = tabElemt[y];
        tabElmt[y] = tmp;
    }
    else;//erreur
}

int Pile::Sum(int x)
{
    int sum = 0;
    for(int i = 0; i<x; i++)
        sum += tabElmt[i];
    return sum;
}

float Pile::Sum(int x)
{
    float sum = 0;
    for(int i = 0; i<x; i++)
        sum += tabElmt[i];
    return sum;
}*/

/*Constante& Plus(Constante& a, Constante& b)
{
}*/
