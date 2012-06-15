#ifndef CALCEXCEPTION_H
#define CALCEXCEPTION_H

#include "log.h"
#include <string>
#include <exception>
#include <QMessageBox>
#include <QIcon>

using namespace std;

//! La classe gerant les CalcException.

/*! Elle repose sur la class exception de la bibliotheque standard.
    \sa <a href="http://www.cplusplus.com/reference/std/exception/exception/">exception</a>
*/

class CalcException : public exception
{
    //! La chaine de caracteres designant l'exception.
    /*! \sa <a href="http://qt-project.org/doc/qt-4.8/QString.html">QString</a> */
    QString info;
public:
    //! Le constructeur de la classe.
    /*! Il prend en argument une string et grace au throw() ne peut renvoyer une exception.
    \param s Une QString constante.
    \sa <a href="http://qt-project.org/doc/qt-4.8/QString.html">QString</a>
    */
    CalcException(const QString s)throw():info(s){}

    //! Getter pour l'attribut info
    /*! Acces en lecture, la valeur renvoyee n'est pas modifiable.
      \return La QString de l'objet CalcException
      \sa <a href="http://qt-project.org/doc/qt-4.8/QString.html">QString</a>
    */
    const QString GetInfo() const
    {
        return info;
    }

    //! Affichage de l'exception
    /*! L'affichage est fait sous la forme d'une QMessageBox affichant le message d'erreur.
      \sa GetInfo()
      \sa Log::WriteLogs(QString string)
      \sa <a href="http://qt-project.org/doc/qt-4.8/QString.html">QString</a>
      \sa <a href="http://qt-project.org/doc/qt-4.8/QMessageBox.html">QMessageBox</a>
    */
    void alert()
    {
        Log::WriteLogs("Exception: " + GetInfo(), 1);
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
