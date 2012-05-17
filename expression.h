#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <string>
#include "constante.h"

using namespace std;

class Expression: public Constante
{
    string exp;
public:
    Expression(string s): Constante(), exp(s){}
    ~Expression(){}

    Constante& GetVal()const;
};

#endif // EXPRESSION_H
