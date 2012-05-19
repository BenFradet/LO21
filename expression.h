#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <string>
#include "constante.h"
#include "include.h"

using namespace std;

class Expression: public Constante
{
    string exp;
public:
    Expression(string s): Constante(), exp(s){}
    ~Expression(){}

    Constante& GetVal()const;

    Constante& operator+(const Constante& c);
    Constante& operator-(const Constante& c);
    Constante& operator*(const Constante& c);
    Constante& operator/(const Constante& c);
};

#endif // EXPRESSION_H
