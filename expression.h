#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <string>
#include "include.h"
#include <QString>

using namespace std;

class Expression: public Constante
{
    string exp;
public:
    Expression(string s): Constante(), exp(s){}
    ~Expression(){}

    operator int()const;
    operator float()const;
    operator Entier()const;
    operator Rationnel()const;
    operator Reel()const;
    operator Complexe()const;

    Constante& GetVal()const;
    operator QString(); // crée un QString à partir d'une expression
};

#endif // EXPRESSION_H
