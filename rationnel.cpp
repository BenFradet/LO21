#include "rationnel.h"

Constante& Rationnel::GetVal()const
{
    Rationnel r(num, den);
    return r;
}

