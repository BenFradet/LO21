#include "entier.h"

Constante& Entier::GetVal()const
{
    Entier e(value);
    return e;
}

