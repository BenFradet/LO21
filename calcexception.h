#ifndef CALCEXCEPTION_H
#define CALCEXCEPTION_H

#include "log.h"
#include <string>
#include <exception>
#include <QMessageBox>
#include <QIcon>

using namespace std;

//! La classe gerant les Exceptions.

/*! Elle repose sur la class exception de la bibliotheque standard.*/

class CalcException : public exception
{
    //! La chaine de caracteres designant l'exception.
    QString info;
public:
    //! Le constructeur de la classe.
    /*! Il prend en argument une string et grace au throw() ne peut renvoyer une exception.*/
    CalcException(const QString s)throw():info(s){}


    //const char* what() const {return "";}

    //! Getter pour l'attribut info
    /*! Acces en lecture, la valeur renvoyee n'est pas modifiable.
      \return La QString de l'objet CalcException
    */
    const QString GetInfo() const
    {
        return info;
    }

    //! Affichage de l'exception
    /*! L'affichage est fait sous la forme d'une QMessageBox affichant le message d'erreur.
      \sa GetInfo()
    */
    void alert()
    {
        Log::WriteLogs("Exception: " + GetInfo());
        QMessageBox msgBox(0);
        msgBox.setWindowTitle("Erreur!");
        msgBox.setText(GetInfo());
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setStandardButtons(QMessageBox::Ok );
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.exec();
    }
};

#endif // CALCEXCEPTION_H
