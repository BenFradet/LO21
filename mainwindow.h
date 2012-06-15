#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "pile.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QDirModel>
#include <QListView>
#include <QRegExp>
#include <QMessageBox>
#include <QEvent>
#include <QFile>
#include <QtXml/QtXml>
#include <io.h>
#include <qfile.h>
#include <QIODevice>
#include <QtXml/QDomDocument>
#include <QShortcut>

namespace Ui {
class MainWindow;
}

class Pile;

//! La classe qui gere l'affichage de la calculatrice.
/*! Elle herite de la classe QMainWindow.*/

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:


    explicit MainWindow(Pile *P, QWidget *parent = 0);

    ~MainWindow();

    //! Getter permettant d'obtenir le mode en cours (Entier, Rationnel, Reel).
    /*! \return Le mode actuel de la calculatrice. */

    static QString getMode() {return mode;}


    //! Getter permettant de savoir si l'on utilise les complexes ou non.
    /*! \return L'etat du mode complexe (vrai/faux) */

    static bool getComplexeMode() {return ComplexeMode;}


    //! Setter permettant de modifier le mode de la calculatrice.
    /*! \param s Le mode a mettre en marche. */

    static void setMode(QString s) { mode = s;}

    //! Setter permettant de modifier d'activer ou de desactiver le mode complexe.
    /*! \param b Un booleen permettant d'activer ou desactiver. */

    static void setComplexeMode(bool b) { ComplexeMode = b;}

    //! Getter permettant de savoir si l'on calcule en degres ou radians.
    /*! \return Le mode pour les angles utilise. */

    static QString getAngleMode() {return angleMode;}

    //! Setter permettant de modifier le mode pour les angles utilise.
    /*! \param s Le nom du mode a mettre en marche. */

    static void setAngleMode(QString s) {angleMode = s; }


    void closeEvent(QCloseEvent * event);
    void afficher_sc ();
    void afficher_std();
    void setModeReel();
    void setModeRationnel();
    void setModeEntier();
    void setModeRadian();
    void setClavier();
    void unsetClavier();
    
private:

    //! Un pointeur sur un objet de type MainWindow

    Ui::MainWindow *ui;

    //! Un pointeur sur Pile
    Pile* p;

    //! Le mode a utiliser (Entier, Rationnel, Reel) en statique.
    static QString mode;

    //! Le mode complexe a activer/desactiver en statique.
    static bool ComplexeMode;

    //! Le mode pour les angles a activer en statique.
    static QString angleMode;


private slots:

    void btn0pressed();
    void btn1pressed();
    void btn2pressed();
    void btn3pressed();
    void btn4pressed();
    void btn5pressed();
    void btn6pressed();
    void btn7pressed();
    void btn8pressed();
    void btn9pressed();
    void btnSPACEpressed();
    void btnAddipressed();
    void btnSouspressed();
    void btnMultpressed();
    void btnDivipressed();
    void btnINVpressed();
    void btnCOSpressed();
    void btnSINpressed();
    void btnTANpressed();
    void btnCOSHpressed();
    void btnSINHpressed();
    void btnTANHpressed();
    void btnLOGpressed();
    void btnLNpressed();
    void btnFACTOpressed();
    void btnSIGNpressed();
    void btnSQRpressed();
    void btnSQRTpressed();
    void btnCUBEpressed();
    void btnCOMPLEXEpressed();
    void btnPOWpressed();
    void btnMODpressed();
    void btnSWAPpressed();
    void btnSUMpressed();
    void btnMEANpressed();
    void btnCLEANpressed();
    void btnDUPpressed();
    void btnDROPpressed();
    void btnPOINTpressed();
    void affichage_scientifique();
    void affichage_standard();
    void btnAnnulerpressed();
    void btnRetablirpressed();
    void MODE_REELS();
    void MODE_RATIONNELS();
    void MODE_ENTIERS();
    void eval();
    void COMPLEXE_MODE(int b);
    void envoi_pile();
    void backspace();
    void MODE_DEGRES();
    void MODE_RADIANS();
    void btnRAZpressed();
    void CLAVIER(int);
    void eval_expression();
    void lettreApressed();
    void lettreBpressed();
    void lettreCpressed();
    void lettreDpressed();
    void lettreEpressed();
    void lettreGpressed();
    void lettreHpressed();
    void lettreIpressed();
    void lettreLpressed();
    void lettreMpressed();
    void lettreNpressed();
    void lettreOpressed();
    void lettrePpressed();
    void lettreQpressed();
    void lettreRpressed();
    void lettreSpressed();
    void lettreTpressed();
    void lettreUpressed();
    void lettreVpressed();
    void lettreWpressed();
    void modif_taille_pile();

};

#endif // MAINWINDOW_H
