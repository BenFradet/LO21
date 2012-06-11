#ifndef LOG_H
#define LOG_H

#include <QString>
#include <QFile>
#include <QTextStream>
#include <QTime>

class Log
{
public:
    Log(){}
    static void WriteLogs(QString string);
};

#endif // LOG_H
