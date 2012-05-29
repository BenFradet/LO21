#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <string>
#include "constante.h"
#include "include.h"
#include <QString>

using namespace std;

class Expression: public Constante
{
    string exp;
public:
    Expression(string s): Constante(), exp(s){}
    ~Expression(){}

    Constante& GetVal()const;
    QString ToQString(); // crée un QString à partir d'une expression
};

#endif // EXPRESSION_H
