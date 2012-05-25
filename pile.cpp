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
        this->Empiler(&res);
        return res;
    }
    else;//erreur
}

Constante& Pile::Sign()
{
    Constante* a = this->Depiler();
    Entier e(2);
    Constante& res = *a - e*(*a);
    return res;
}

Constante& Pile::Sinus()
{
    Constante* a = this->Depiler();
    a->sinus();
    this->Empiler(a);
    return *a;
}

Constante& Pile::Cosinus()
{
    Constante* a = this->Depiler();
    a->cosinus();
    this->Empiler(a);
    return *a;
}

Constante& Pile::Tangente()
{
    Constante* a = this->Depiler();
    a->tangente();
    this->Empiler(a);
    return *a;
}

Constante& Pile::Sinush()
{
    Constante* a = this->Depiler();
    a->sinush();
    this->Empiler(a);
    return *a;
}

Constante& Pile::Cosinush()
{
    Constante* a = this->Depiler();
    a->cosinush();
    this->Empiler(a);
    return *a;
}

Constante& Pile::Tangenteh()
{
    Constante* a = this->Depiler();
    a->tangenteh();
    this->Empiler(a);
    return *a;
}

Constante& Pile::LogaNep()
{
    Constante* a = this->Depiler();
    a->lognep();
    this->Empiler(a);
    return *a;
}

Constante& Pile::LogaDec()
{
    Constante* a = this->Depiler();
    a->logdec();
    this->Empiler(a);
    return *a;
}

Constante& Pile::Inverse()
{
    Constante* a = this->Depiler();
    a->inverse();
    this->Empiler(a);
    return *a;
}

Constante& Pile::Racine()
{
    Constante* a = this->Depiler();
    a->racine();
    this->Empiler(a);
    return *a;
}

Constante& Pile::Carree()
{
    Constante* a = this->Depiler();
    a->carree();
    this->Empiler(a);
    return *a;
}

Constante& Pile::Cube()
{
    Constante* a = this->Depiler();
    a->cube();
    this->Empiler(a);
    return *a;
}

Constante& Pile::Factorielle()
{
    Constante* a = this->Depiler();
    const Entier* e = dynamic_cast<const Entier*>(a);
    if(e!=0)
    {
        Constante& res = !*e;
        this->Empiler(&res);
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
