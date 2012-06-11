#ifndef CALCEXCEPTION_H
#define CALCEXCEPTION_H

#include <string>
#include <exception>
#include <QMessageBox>
#include <QIcon>

using namespace std;

class CalcException : public std::exception
{
    QString info;
public:
    CalcException(const QString s):info(s)
    {
    }

    const char* what() const {return "";}

    const QString GetInfo() const
    {
        return info;
    }

    void alert()
    {
        QMessageBox msgBox(0);
        msgBox.setWindowTitle("Erreur !");
        msgBox.setText(GetInfo());
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setStandardButtons(QMessageBox::Ok );
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.exec();
    }
};

#endif // CALCEXCEPTION_H
