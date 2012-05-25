#ifndef CALCEXCEPTION_H
#define CALCEXCEPTION_H

#include <string>

using namespace std;

class CalcException
{
    string info;
public:
    CalcException(const string s):info(s){}
    const string GetInfo() const
    {
        return info;
    }
};

#endif // CALCEXCEPTION_H
