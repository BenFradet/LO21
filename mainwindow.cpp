#include "mainwindow.h"
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

QString MainWindow::mode = "Entier";
QString MainWindow::angleMode = "Degre";
bool MainWindow::ComplexeMode = true;

MainWindow::MainWindow(Pile *P, QWidget *parent) : p(P), QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->actionStandard->setDisabled(true);

    ui->action_Reels->setChecked(true);
    ui->action_Reels->setDisabled(true);

    QShortcut* retour_arriere = new QShortcut(QKeySequence(Qt::Key_Backspace), ui->le_entree);


    afficher_std();

    QRect R(120,130,916, 370);
    MainWindow::setGeometry(R);

    QShortcut* bt0 = new QShortcut(QKeySequence(Qt::Key_0), ui->le_entree);
    QObject::connect(bt0, SIGNAL (activated()), this, SLOT (btn0pressed()));
    QObject::connect(ui->btn0, SIGNAL (clicked()), this, SLOT (btn0pressed()));

    QShortcut* bt1 = new QShortcut(QKeySequence(Qt::Key_1), ui->le_entree);
    QObject::connect(bt1, SIGNAL (activated()), this, SLOT (btn1pressed()));
    QObject::connect(ui->btn1, SIGNAL (clicked()), this, SLOT (btn1pressed()));

    QShortcut* bt2 = new QShortcut(QKeySequence(Qt::Key_2), ui->le_entree);
    QObject::connect(bt2, SIGNAL (activated()), this, SLOT (btn2pressed()));
    QObject::connect(ui->btn2, SIGNAL (clicked()), this, SLOT (btn2pressed()));

    QShortcut* bt3 = new QShortcut(QKeySequence(Qt::Key_3), ui->le_entree);
    QObject::connect(bt3, SIGNAL (activated()), this, SLOT (btn3pressed()));
    QObject::connect(ui->btn3, SIGNAL (clicked()), this, SLOT (btn3pressed()));

    QShortcut* bt4 = new QShortcut(QKeySequence(Qt::Key_4), ui->le_entree);
    QObject::connect(bt4, SIGNAL (activated()), this, SLOT (btn4pressed()));
    QObject::connect(ui->btn4, SIGNAL (clicked()), this, SLOT (btn4pressed()));

    QShortcut* bt5 = new QShortcut(QKeySequence(Qt::Key_5), ui->le_entree);
    QObject::connect(bt5, SIGNAL (activated()), this, SLOT (btn5pressed()));
    QObject::connect(ui->btn5, SIGNAL (clicked()), this, SLOT (btn5pressed()));

    QShortcut* bt6 = new QShortcut(QKeySequence(Qt::Key_6), ui->le_entree);
    QObject::connect(bt6, SIGNAL (activated()), this, SLOT (btn6pressed()));
    QObject::connect(ui->btn6, SIGNAL (clicked()), this, SLOT (btn6pressed()));

    QShortcut* bt7 = new QShortcut(QKeySequence(Qt::Key_7), ui->le_entree);
    QObject::connect(bt7, SIGNAL (activated()), this, SLOT (btn7pressed()));
    QObject::connect(ui->btn7, SIGNAL (clicked()), this, SLOT (btn7pressed()));

    QShortcut* bt8 = new QShortcut(QKeySequence(Qt::Key_8), ui->le_entree);
    QObject::connect(bt8, SIGNAL (activated()), this, SLOT (btn8pressed()));
    QObject::connect(ui->btn8, SIGNAL (clicked()), this, SLOT (btn8pressed()));

    QShortcut* bt9 = new QShortcut(QKeySequence(Qt::Key_9), ui->le_entree);
    QObject::connect(bt9, SIGNAL (activated()), this, SLOT (btn9pressed()));
    QObject::connect(ui->btn9, SIGNAL (clicked()), this, SLOT (btn9pressed()));

    QShortcut* btAnn = new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Z), this);
    QObject::connect(btAnn, SIGNAL (activated()), this, SLOT (btnAnnulerpressed()));

    QShortcut* btRetab = new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Y), this);
    QObject::connect(btRetab, SIGNAL (activated()), this, SLOT (btnRetablirpressed()));

    QShortcut* mde = new QShortcut (QKeySequence(Qt::CTRL + Qt::Key_E), this);
    QObject::connect(mde, SIGNAL (activated()), this, SLOT (MODE_ENTIERS()));

    QShortcut* mdf = new QShortcut (QKeySequence(Qt::CTRL + Qt::Key_F), this);
    QObject::connect(mdf, SIGNAL (activated()), this, SLOT (MODE_RATIONNELS()));

    QShortcut* mdr = new QShortcut (QKeySequence(Qt::CTRL + Qt::Key_R), this);
    QObject::connect(mdr, SIGNAL (activated()), this, SLOT (MODE_REELS()));

    QShortcut* scien = new QShortcut (QKeySequence(Qt::CTRL + Qt::SHIFT + Qt::Key_S), this);
    QObject::connect(scien, SIGNAL (activated()), this, SLOT (affichage_scientifique()));

    QShortcut* std = new QShortcut (QKeySequence(Qt::CTRL + Qt::SHIFT + Qt::Key_W), this);
    QObject::connect(std, SIGNAL (activated()), this, SLOT (affichage_standard()));

    QShortcut* deg = new QShortcut (QKeySequence(Qt::CTRL + Qt::Key_D), this);
    QObject::connect(deg, SIGNAL (activated()), this, SLOT (MODE_DEGRES()));

    QShortcut* rad = new QShortcut (QKeySequence(Qt::CTRL + Qt::Key_A), this);
    QObject::connect(rad, SIGNAL (activated()), this, SLOT (MODE_RADIANS()));


    QObject::connect(ui->btnSPACE, SIGNAL (clicked()), this, SLOT(btnSPACEpressed()));
    QObject::connect(ui->btnAddi, SIGNAL (clicked()), this, SLOT(btnAddipressed()));
    QObject::connect(ui->btnSous, SIGNAL (clicked()), this, SLOT(btnSouspressed()));
    QObject::connect(ui->btnDivi, SIGNAL (clicked()), this, SLOT(btnDivipressed()));
    QObject::connect(ui->btnMult, SIGNAL (clicked()), this, SLOT(btnMultpressed()));
    QObject::connect(ui->btnINV, SIGNAL (clicked()), this, SLOT(btnINVpressed()));
    QObject::connect(ui->btnCOS, SIGNAL (clicked()), this, SLOT(btnCOSpressed()));
    QObject::connect(ui->btnSIN, SIGNAL (clicked()), this, SLOT(btnSINpressed()));
    QObject::connect(ui->btnTAN, SIGNAL (clicked()), this, SLOT(btnTANpressed()));
    QObject::connect(ui->btnCOSH, SIGNAL (clicked()), this, SLOT(btnCOSHpressed()));
    QObject::connect(ui->btnSINH, SIGNAL (clicked()), this, SLOT(btnSINHpressed()));
    QObject::connect(ui->btnTANH, SIGNAL (clicked()), this, SLOT(btnTANHpressed()));
    QObject::connect(ui->btnLOG, SIGNAL (clicked()), this, SLOT(btnLOGpressed()));
    QObject::connect(ui->btnLN, SIGNAL (clicked()), this, SLOT(btnLNpressed()));
    QObject::connect(ui->btnFACTO, SIGNAL (clicked()), this, SLOT(btnFACTOpressed()));
    QObject::connect(ui->btnSIGN, SIGNAL (clicked()), this, SLOT(btnSIGNpressed()));
    QObject::connect(ui->btnSQR, SIGNAL (clicked()), this, SLOT(btnSQRpressed()));
    QObject::connect(ui->btnSQRT, SIGNAL (clicked()), this, SLOT(btnSQRTpressed()));
    QObject::connect(ui->btnCUBE, SIGNAL (clicked()), this, SLOT(btnCUBEpressed()));
    QObject::connect(ui->btnCOMPLEXE, SIGNAL (clicked()), this, SLOT(btnCOMPLEXEpressed()));
    QObject::connect(ui->btnPOW, SIGNAL (clicked()), this, SLOT(btnPOWpressed()));
    QObject::connect(ui->btnMOD, SIGNAL (clicked()), this, SLOT(btnMODpressed()));
    QObject::connect(ui->actionAnnuler, SIGNAL(triggered()), this, SLOT(btnAnnulerpressed()));
    QObject::connect(ui->actionRetablir, SIGNAL(triggered()), this, SLOT(btnRetablirpressed()));
    QObject::connect(ui->actionScientifique, SIGNAL(triggered()), this, SLOT(affichage_scientifique()));
    QObject::connect(ui->actionStandard, SIGNAL(triggered()), this, SLOT(affichage_standard()));
    QObject::connect(ui->btnEVAL, SIGNAL (clicked()), this, SLOT(eval()));
    QObject::connect(ui->btnSWAP, SIGNAL (clicked()), this, SLOT(btnSWAPpressed()));
    QObject::connect(ui->btnSUM, SIGNAL (clicked()), this, SLOT(btnSUMpressed()));
    QObject::connect(ui->btnMEAN, SIGNAL (clicked()), this, SLOT(btnMEANpressed()));
    QObject::connect(ui->btnCLEAN, SIGNAL (clicked()), this, SLOT(btnCLEANpressed()));
    QObject::connect(ui->btnDUP, SIGNAL (clicked()), this, SLOT(btnDUPpressed()));
    QObject::connect(ui->btnDROP, SIGNAL (clicked()), this, SLOT(btnDROPpressed()));
    QObject::connect(ui->btnPOINT, SIGNAL (clicked()), this, SLOT(btnPOINTpressed()));
    QObject::connect(ui->action_Reels, SIGNAL (triggered()), this, SLOT(MODE_REELS()));
    QObject::connect(ui->action_Rationnels, SIGNAL (triggered()), this, SLOT(MODE_RATIONNELS()));
    QObject::connect(ui->action_Entiers, SIGNAL (triggered()), this, SLOT(MODE_ENTIERS()));
    QObject::connect(ui->btnRAZ, SIGNAL (clicked()), this, SLOT(btnRAZpressed()));
    QObject::connect(ui->checkComplexe, SIGNAL (stateChanged(int)), this, SLOT (COMPLEXE_MODE(int)));
    QObject::connect(ui->btnSENDSTACK, SIGNAL (clicked()), this, SLOT(envoi_pile()));
    QObject::connect(ui->actionQuitter, SIGNAL(triggered()), this, SLOT (close()));
    QObject::connect(retour_arriere,SIGNAL (activated()), this,SLOT (backspace()));
    QObject::connect(ui->action_Degres, SIGNAL (triggered()), this,SLOT (MODE_DEGRES()));
    QObject::connect(ui->action_Radians, SIGNAL (triggered()), this,SLOT (MODE_RADIANS()));
    QObject::connect(ui->checkClavier, SIGNAL(stateChanged(int)), this, SLOT (CLAVIER(int)));


    ui->arg1_SWAP->setText("1");
    ui->arg2_SWAP->setText("1");
    ui->arg_SUM->setText("1");
    ui->arg_MEAN->setText("1");
    ui->listView->setModel(p);

    QDomDocument doc ("CONFIGURATION");
    QFile file ("PILE.xml");
    if( !doc.setContent( &file ) )
    {
      file.close();
    }
    file.close();

    p->Parser(doc.firstChild().firstChild().firstChild().nodeValue());

    ui->le_entree->setText(doc.firstChild().childNodes().at(1).firstChild().nodeValue());

    QString moderecup = doc.firstChild().childNodes().at(2).firstChild().nodeValue();
    if(moderecup == "Entier")
    {
        setModeEntier();
    }
    else if (moderecup == "Rationnel")
    {
        setModeRationnel();
    }
    else if (moderecup == "Reel")
    {
        setModeReel();
    }
    else
    {
        setModeReel();
    }

    QString cxmod = doc.firstChild().childNodes().at(3).firstChild().nodeValue();
    if (cxmod == "true")
    {
            setComplexeMode(true);
            ui->checkComplexe->setChecked(true);
    }
    else if (cxmod == "false")
    {
        setComplexeMode(false);
        ui->checkComplexe->setChecked(false);
    }
    else
    {
        setComplexeMode(true);
        ui->checkComplexe->setChecked(true);
    }

    QString mode_affichage = doc.firstChild().childNodes().at(4).firstChild().nodeValue();
    if (mode_affichage == "Scientifique")
    {
        afficher_sc();
    }

    QString mode_angles = doc.firstChild().childNodes().at(5).firstChild().nodeValue();
    if (mode_angles == "Radian")
    {
        setModeRadian();
    }

    QString mode_clavier = doc.firstChild().childNodes().at(6).firstChild().nodeValue();
    if (mode_clavier == "Off")
    {
        ui->checkClavier->setChecked(false);
        unsetClavier();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::btn0pressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("0"));
}

void MainWindow::btn1pressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("1"));
}


void MainWindow::btn2pressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("2"));
}


void MainWindow::btn3pressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("3"));
}


void MainWindow::btn4pressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("4"));
}


void MainWindow::btn5pressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("5"));
}


void MainWindow::btn6pressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("6"));
}


void MainWindow::btn7pressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("7"));
}


void MainWindow::btn8pressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("8"));
}

void MainWindow::btn9pressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("9"));
}

void MainWindow::btnSPACEpressed()
{
    ui->le_entree->setText(ui->le_entree->text().append(" "));
}

void MainWindow::btnAddipressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("+"));
}

void MainWindow::btnSouspressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("-"));
}

void MainWindow::btnMultpressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("*"));
}

void MainWindow::btnDivipressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("/"));
}

void MainWindow::btnINVpressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("INV"));
}

void MainWindow::btnCOSpressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("COS"));
}

void MainWindow::btnSINpressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("SIN"));
}

void MainWindow::btnTANpressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("TAN"));
}

void MainWindow::btnCOSHpressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("COSH"));
}

void MainWindow::btnSINHpressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("SINH"));
}

void MainWindow::btnTANHpressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("TANH"));
}

void MainWindow::btnLOGpressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("LOG"));
}

void MainWindow::btnLNpressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("LN"));
}

void MainWindow::btnFACTOpressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("!"));
}

void MainWindow::btnSIGNpressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("SIGN"));
}

void MainWindow::btnSQRpressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("SQR"));
}

void MainWindow::btnSQRTpressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("SQRT"));
}

void MainWindow::btnCUBEpressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("CUBE"));
}

void MainWindow::btnCOMPLEXEpressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("$"));
}

void MainWindow::btnPOWpressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("POW"));
}

void MainWindow::btnMODpressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("MOD"));
}

void MainWindow::btnPOINTpressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("."));
}

void MainWindow::btnSWAPpressed()
{
    QRegExp test ("^[0-9]+$");
    QString arg1 = ui->arg1_SWAP->text();
    QString arg2 = ui->arg2_SWAP->text();

    if (arg1.contains(test) && arg2.contains(test))
    {
    int i = ui->arg1_SWAP->text().toInt();
    int j = ui->arg2_SWAP->text().toInt();

    if (i != 0 && j != 0)
    {
    p->Swap(i,j);
    ui->arg1_SWAP->setText("1");
    ui->arg2_SWAP->setText("1");
    ui->listView->reset();
    }
    ui->arg1_SWAP->setText("1");
    ui->arg2_SWAP->setText("1");
    }
    else
        throw CalcException("Au moins un des arguments est invalide.");
}

void MainWindow::btnSUMpressed()
{
   QRegExp test ("^[0-9]+$");
   QString arg1 = ui->arg_SUM->text();

   if (arg1.contains(test))
   {
       int i = ui->arg_SUM->text().toInt();
       p->Sum(i, MainWindow::getMode());
       ui->arg_SUM->setText("1");
       ui->listView->reset();
   }
   else
       throw CalcException("Au moins un des arguments est invalide.");

}

void MainWindow::btnMEANpressed()
{
   QRegExp test ("^[0-9]+$");
   QString arg1 = ui->arg_MEAN->text();

   if (arg1.contains(test))
   {
       int i = ui->arg_MEAN->text().toInt();
       p->Mean(i, MainWindow::getMode());
       ui->arg_MEAN->setText("1");
       ui->listView->reset();
   }
   else
       throw CalcException("Au moins un des arguments est invalide.");

}

void MainWindow::btnCLEANpressed()
{
    p->Clear();
    ui->listView->reset();
}

void MainWindow::btnDUPpressed()
{
    p->Dup();
    ui->listView->reset();
}

void MainWindow::btnDROPpressed()
{
   p->Drop();
   ui->listView->reset();
}

void MainWindow::btnAnnulerpressed()
{
    p->Annuler();
    ui->listView->reset();
}

void MainWindow::btnRetablirpressed()
{
    p->Retablir();
    ui->listView->reset();
}

void MainWindow::affichage_scientifique()
{
        afficher_sc();
}

void MainWindow::affichage_standard()
{
       afficher_std();
}

void MainWindow::eval()
{
    p->Parser(ui->le_entree->text());
    ui->listView->reset();
    ui->le_entree->clear();
}

void MainWindow::envoi_pile()
{
    QString entree(ui->le_entree->text());
    QStringList verif(entree.split(" "));
    bool test = false;
    for (int i = 0; i<verif.length(); i++)
        if (verif[i] == " " || verif[i] == "")
            test = true;

    if (!test)
    {

    if (verif.length() != 1)
    {

        if ( verif.length()%2 == 1  )
        {

        QString sortie("'");
        sortie.append(entree);
        sortie.append("'");
        ui->le_entree->setText(sortie);
        p->Parser(sortie);

        }
        else ui->le_entree->clear();
    }
    else
        p->Parser(entree);
    ui->listView->reset();
    ui->le_entree->clear();
    }
    else
        ui->le_entree->clear();



}


void MainWindow::MODE_RATIONNELS()
{
    setModeRationnel();
    ui->listView->reset();
}


void MainWindow::MODE_REELS()
{
    setModeReel();
    ui->listView->reset();
}


void MainWindow::MODE_ENTIERS()
{
    setModeEntier();
    ui->listView->reset();
}

void MainWindow::COMPLEXE_MODE(int b)
{
    if (b)
   {
        setComplexeMode(true);
        ui->btnCOMPLEXE->setEnabled(true);
   }

    else
     {

        setComplexeMode(false);
        ui->btnCOMPLEXE->setEnabled(false);
    }

}

void MainWindow::btnRAZpressed()
{
    ui->le_entree->clear();
}

void MainWindow::closeEvent(QCloseEvent * event)
{
    QMessageBox msgBox(this);
    msgBox.setWindowTitle("Fermeture..");
    msgBox.setText("Les informations vont être enregistrées.");
    msgBox.setStandardButtons(QMessageBox::Ok );
    msgBox.setDefaultButton(QMessageBox::Ok);
    msgBox.exec();

    QString etatpile;

    for ( int i =0; i < p->getSommet(); i++)
    {
        etatpile.append((QString)*p->getElement(i));
        etatpile.append(" ");
    }

    QDomDocument filesave ("CONFIGURATION");
    QDomElement racine = filesave.createElement("Pile");
    filesave.appendChild(racine);

    QDomElement pile = filesave.createElement("Etat");
    QDomText text = filesave.createTextNode(etatpile);
    pile.appendChild(text);
    racine.appendChild(pile);

    QDomElement lineedit = filesave.createElement("LigneEdit");
    QDomText le_entree = filesave.createTextNode(ui->le_entree->text());
    lineedit.appendChild(le_entree);
    racine.appendChild(lineedit);

    QDomElement modedeconstante = filesave.createElement("Mode");
    QDomText mdcst = filesave.createTextNode(getMode());
    modedeconstante.appendChild(mdcst);
    racine.appendChild(modedeconstante);

    QDomElement cx = filesave.createElement("Complexes");
    QString P;
    if (getComplexeMode())
        P = "true";
    else P = "false";
    QDomText cxx = filesave.createTextNode(P);
    cx.appendChild(cxx);
    racine.appendChild(cx);

    QDomElement affich = filesave.createElement("Affichage");
    QString Aff;
    if (ui->actionScientifique->isChecked())
        Aff = "Scientifique";
    else if (ui->actionStandard->isChecked())
        Aff = "Standard";
    QDomText affi = filesave.createTextNode(Aff);
    affich.appendChild(affi);
    racine.appendChild(affich);

    QDomElement angles = filesave.createElement("Mode_Angle");
    QDomText ang = filesave.createTextNode(getAngleMode());
    angles.appendChild(ang);
    racine.appendChild(angles);

    QDomElement clavier = filesave.createElement("Clavier");
    QString cla;
    if (ui->checkClavier->isChecked())
        cla = "On";
    else cla = "Off";

    QDomText keyb = filesave.createTextNode(cla);
    clavier.appendChild(keyb);
    racine.appendChild(clavier);

    QFile file( "PILE.xml" );
    if( !file.open( QIODevice::WriteOnly ) )
        throw CalcException("Le Fichier n'existe pas.");

    QTextStream ts( &file );
    ts << filesave.toString();

    file.close();

   QMainWindow::closeEvent(event);
}

void MainWindow::afficher_sc()
{
    ui->actionStandard->setCheckable(true);
    ui->actionStandard->setChecked(false);
    ui->actionStandard->setEnabled(true);
    ui->actionScientifique->setChecked(true);
    ui->actionScientifique->setDisabled(true);

    MainWindow::setMinimumHeight(560);
    MainWindow::setMinimumWidth(916);

    ui->btnCOS->setDisabled(false);
    ui->btnCOS->setHidden(false);
    ui->btnSIN->setDisabled(false);
    ui->btnSIN->setHidden(false);
    ui->btnTAN->setDisabled(false);
    ui->btnTAN->setHidden(false);
    ui->btnCOSH->setDisabled(false);
    ui->btnCOSH->setHidden(false);
    ui->btnSINH->setDisabled(false);
    ui->btnSINH->setHidden(false);
    ui->btnTANH->setDisabled(false);
    ui->btnTANH->setHidden(false);
    ui->btnINV->setDisabled(false);
    ui->btnINV->setHidden(false);
    ui->btnCUBE->setDisabled(false);
    ui->btnCUBE->setHidden(false);
    ui->btnSQR->setDisabled(false);
    ui->btnSQR->setHidden(false);
    ui->btnSQRT->setDisabled(false);
    ui->btnSQRT->setHidden(false);
    ui->btnFACTO->setDisabled(false);
    ui->btnFACTO->setHidden(false);
    ui->btnLN->setDisabled(false);
    ui->btnLN->setHidden(false);
    ui->btnLOG->setDisabled(false);
    ui->btnLOG->setHidden(false);

}

void MainWindow::afficher_std()
{
    ui->actionScientifique->setCheckable(true);
    ui->actionScientifique->setChecked(false);
    ui->actionScientifique->setEnabled(true);
    ui->actionStandard->setChecked(true);
    ui->actionStandard->setDisabled(true);
    MainWindow::setMinimumHeight(370);
    MainWindow::setMinimumWidth(916);

    MainWindow::setGeometry(geometry().left(),geometry().top(), 916, 370);

    ui->btnCOS->setDisabled(true);
    ui->btnCOS->setHidden(true);
    ui->btnSIN->setDisabled(true);
    ui->btnSIN->setHidden(true);
    ui->btnTAN->setDisabled(true);
    ui->btnTAN->setHidden(true);
    ui->btnCOSH->setDisabled(true);
    ui->btnCOSH->setHidden(true);
    ui->btnSINH->setDisabled(true);
    ui->btnSINH->setHidden(true);
    ui->btnTANH->setDisabled(true);
    ui->btnTANH->setHidden(true);
    ui->btnINV->setDisabled(true);
    ui->btnINV->setHidden(true);
    ui->btnCUBE->setDisabled(true);
    ui->btnCUBE->setHidden(true);
    ui->btnSQR->setDisabled(true);
    ui->btnSQR->setHidden(true);
    ui->btnSQRT->setDisabled(true);
    ui->btnSQRT->setHidden(true);
    ui->btnFACTO->setDisabled(true);
    ui->btnFACTO->setHidden(true);
    ui->btnLN->setDisabled(true);
    ui->btnLN->setHidden(true);
    ui->btnLOG->setDisabled(true);
    ui->btnLOG->setHidden(true);
}

void MainWindow::setModeEntier()
{
    MainWindow::setMode("Entier");
    ui->action_Entiers->setChecked(true);
    ui->action_Entiers->setDisabled(true);
    ui->action_Reels->setEnabled(true);
    ui->action_Reels->setChecked(false);
    ui->action_Rationnels->setEnabled(true);
    ui->action_Rationnels->setChecked(false);
}

void MainWindow::setModeRationnel()
{
    MainWindow::setMode("Rationnel");
    ui->action_Rationnels->setChecked(true);
    ui->action_Rationnels->setDisabled(true);
    ui->action_Reels->setEnabled(true);
    ui->action_Reels->setChecked(false);
    ui->action_Entiers->setEnabled(true);
    ui->action_Entiers->setChecked(false);
}

void MainWindow::setModeReel()
{
    MainWindow::setMode("Reel");
    ui->action_Reels->setChecked(true);
    ui->action_Reels->setDisabled(true);
    ui->action_Entiers->setEnabled(true);
    ui->action_Entiers->setChecked(false);
    ui->action_Rationnels->setEnabled(true);
    ui->action_Rationnels->setChecked(false);
}

void MainWindow::backspace()
{
    QString s1(ui->le_entree->text());
    int L = ui->le_entree->text().length();
    QString s2;
    for (int i=0; i < L-1; i++)
        s2[i] = s1[i];
    ui->le_entree->setText(s2);
}

void MainWindow::MODE_DEGRES()
{
    setAngleMode("Degre");
    ui->action_Degres->setChecked(true);
    ui->action_Degres->setDisabled(true);
    ui->action_Radians->setChecked(false);
    ui->action_Radians->setEnabled(true);
    ui->listView->reset();
}

void MainWindow::MODE_RADIANS()
{
    setModeRadian();
    ui->listView->reset();

}

void MainWindow::setModeRadian()
{
    setAngleMode("Radian");
    ui->action_Radians->setChecked(true);
    ui->action_Radians->setDisabled(true);
    ui->action_Degres->setChecked(false);
    ui->action_Degres->setEnabled(true);
}

void MainWindow::CLAVIER(int b)

{
    if (b)
    {
        setClavier();
    }
    else
    {
        unsetClavier();

    }

}

void MainWindow::setClavier()
{

    ui->btn0->setHidden(false);
    ui->btn1->setHidden(false);
    ui->btn2->setHidden(false);
    ui->btn3->setHidden(false);
    ui->btn4->setHidden(false);
    ui->btn5->setHidden(false);
    ui->btn6->setHidden(false);
    ui->btn7->setHidden(false);
    ui->btn8->setHidden(false);
    ui->btn9->setHidden(false);


}

void MainWindow::unsetClavier()
{



    ui->btn0->setHidden(true);
    ui->btn1->setHidden(true);
    ui->btn2->setHidden(true);
    ui->btn3->setHidden(true);
    ui->btn4->setHidden(true);
    ui->btn5->setHidden(true);
    ui->btn6->setHidden(true);
    ui->btn7->setHidden(true);
    ui->btn8->setHidden(true);
    ui->btn9->setHidden(true);





}
