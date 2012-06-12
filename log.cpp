#include "log.h"

void Log::WriteLogs(QString string)
{
    QFile file("logs.txt");
    if(!file.open(QFile::Append | QFile::Text))
        return;
    QTextStream stream(&file);
    stream.setCodec("UTF-8");
    stream << QDate::currentDate().toString("dd.MM.yyyy") << " " << QTime::currentTime().toString() << " " << string <<endl;
}
