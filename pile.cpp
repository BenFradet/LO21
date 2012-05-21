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

void Pile::Empiler(Constante* c)//test sur le sommet à faire
{
    //if(sommet<taille)
        tabElmt[sommet++] = c;
    //else;
        //erreur
}

Constante* Pile::Depiler()//test sur le sommet à faire
{
    //if(sommet>0)
        return tabElmt[--sommet];
    //else;
        //erreur
}

Constante* Pile::Tete()const//test sur le sommet à faire
{
    //if(sommet>0)
        return tabElmt[sommet-1];
    //else;
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

Constante& Pile::Plus()
{
    Constante* a = this->Depiler();
    Constante* b = this->Depiler();
    Constante& c = *a + *b;
    this->Empiler(&c);
    return c;
}

Constante& Pile::Moins()
{
    Constante* a = this->Depiler();
    Constante* b = this->Depiler();
    Constante& c = *a - *b;
    this->Empiler(&c);
    return c;
}

Constante& Pile::Multiplier()
{
    Constante* a = this->Depiler();
    Constante* b = this->Depiler();
    Constante& c = *a * *b;
    this->Empiler(&c);
    return c;
}

Constante& Pile::Diviser()
{
    Constante* a = this->Depiler();
    Constante* b = this->Depiler();
    Constante& c = *a * *b;
    this->Empiler(&c);
    return c;
}

Constante& Pile::Puissance()
{
    Constante* a = this->Depiler();
    Constante* b = this->Depiler();
    Constante& c = *a ^ *b;
    this->Empiler(&c);
    return c;
}

Constante& Pile::Modulo()
{
    Constante* a = this->Depiler();
    Constante* b = this->Depiler();
    const Entier* e1 = dynamic_cast<const Entier*>(a);
    const Entier* e2 = dynamic_cast<const Entier*>(b);
    if(e1 != NULL && e2 != NULL)
    {
        Constante& res = *e1 % *e2;
        return res;
    }
    else;//erreur
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
