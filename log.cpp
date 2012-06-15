#include "log.h"

//! Methode statique en charge d'ecrire une QString dans un ficher texte ainsi que sur la console.
/*! On ouvre le fichier en mode append (on se retrouve directement à la fin du fichier).
  On cree un QTextStream a partir du fichier.
  On ecrit notre QString avec la date et l'heure pour pouvoir utiliser ce systeme a des fins de maintenance.
  Pour eviter de surcharger la console, on n'y ecrit que les CalcException.
  \param string La QString que l'on va ecrire dans le fichier et sur la console
  \param degre Un int representant le degre d'importance du message, typiquement s'il vaut 1, cette methode a ete appelee par une exception donc on l'ecrit aussi dans la console.
  \sa <a href="http://qt-project.org/doc/qt-4.8/QString.html">QString</a>
  \sa <a href="http://qt-project.org/doc/qt-4.8/QFile.html">QFile</a>
  \sa <a href="http://qt-project.org/doc/qt-4.8/QTextStream.html">QTextStream</a>
  \sa <a href="http://qt-project.org/doc/qt-4.8/QTime.html">QTime</a>
  \sa <a href="http://qt-project.org/doc/qt-4.8/QDate.html">QDate</a>
  \sa <a href="http://www.cplusplus.com/reference/iostream/cerr/">cerr</a>
*/
void Log::WriteLogs(QString string, int degre)
{
    QFile file("logs.txt");
    if(!file.open(QFile::Append | QFile::Text))
        return;
    QTextStream stream(&file);
    stream.setCodec("UTF-8");
    stream << "[" << QDate::currentDate().toString("dd.MM.yyyy") << " " << QTime::currentTime().toString() << "]: " << string <<endl;
    if(degre == 1)
        std::cerr << "[" << QDate::currentDate().toString("dd.MM.yyyy").toStdString() << " " << QTime::currentTime().toString().toStdString() << "]: " << string.toStdString() <<endl;
}

//! Methode statique en charge d'ecrire une QString dans un ficher texte.
/*! Meme methode que la precedente a l'exception qu'ici on n'ecrit pas sur la console, notamment pour les actions courrantes.
  \param string La QString que l'on va ecrire dans le fichier.
  \sa <a href="http://qt-project.org/doc/qt-4.8/QString.html">QString</a>
  \sa <a href="http://qt-project.org/doc/qt-4.8/QFile.html">QFile</a>
  \sa <a href="http://qt-project.org/doc/qt-4.8/QTextStream.html">QTextStream</a>
  \sa <a href="http://qt-project.org/doc/qt-4.8/QTime.html">QTime</a>
  \sa <a href="http://qt-project.org/doc/qt-4.8/QDate.html">QDate</a>
*/
void Log::WriteLogs(QString string)
{
    QFile file("logs.txt");
    if(!file.open(QFile::Append | QFile::Text))
        return;
    QTextStream stream(&file);
    stream.setCodec("UTF-8");
    stream << "[" << QDate::currentDate().toString("dd.MM.yyyy") << " " << QTime::currentTime().toString() << "]: " << string <<endl;
}
