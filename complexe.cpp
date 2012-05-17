#include "complexe.h"

Constante& Complexe::GetVal()const
{
    Complexe c(pRe, pIm);
    return c;
}

