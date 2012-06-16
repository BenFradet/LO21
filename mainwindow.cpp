#include "mainwindow.h"

QString MainWindow::mode = "Entier";
QString MainWindow::angleMode = "Degre";
bool MainWindow::ComplexeMode = true;

//! Constructeur principal de la classe MainWindow
/*! Ce constructeur prend en parametre une pile et un parent, qui vaut 0 s'il n'y en a pas.
    Il cree une fenetre via setupUi.
    Il active les parametres de l'interface par défaut.
    Il cree les raccourcis clavier pour toutes les touches necessaires tels A, B, C, 0, 1, etc.
    Il connecte ensuite tous les boutons de l'interface a un slot particulier.
    Enfin, il charge les parametres de l'interface situes dans un fichier xml. Si ce fichier n'existe pas
    il laisse les parametres par defaut.
    \param P Un pointeur sur la pile a laquelle l'interface sera reliee.
    \param parent Un pointeur sur un eventuel parent de type QWidget.*/


MainWindow::MainWindow(Pile *P, QWidget *parent) : p(P), QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->actionStandard->setDisabled(true);

    ui->action_Reels->setChecked(true);
    ui->action_Reels->setDisabled(true);
    ui->label_angles->setText("Angles : Degrés");
    ui->label_mode->setText("Mode : Entiers");


    ui->label_taille->setText("Taille pile: " + QString::number(p->getTaille()));

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

    QShortcut* lettre_A = new QShortcut (QKeySequence(Qt::Key_A), this);
    QObject::connect(lettre_A, SIGNAL (activated()), this, SLOT (lettreApressed()));

    QShortcut* lettre_B = new QShortcut (QKeySequence(Qt::Key_B), this);
    QObject::connect(lettre_B, SIGNAL (activated()), this, SLOT (lettreBpressed()));

    QShortcut* lettre_C = new QShortcut (QKeySequence(Qt::Key_C), this);
    QObject::connect(lettre_C, SIGNAL (activated()), this, SLOT (lettreCpressed()));

    QShortcut* lettre_D = new QShortcut (QKeySequence(Qt::Key_D), this);
    QObject::connect(lettre_D, SIGNAL (activated()), this, SLOT (lettreDpressed()));

    QShortcut* lettre_E = new QShortcut (QKeySequence(Qt::Key_E), this);
    QObject::connect(lettre_E, SIGNAL (activated()), this, SLOT (lettreEpressed()));

    QShortcut* lettre_G = new QShortcut (QKeySequence(Qt::Key_G), this);
    QObject::connect(lettre_G, SIGNAL (activated()), this, SLOT (lettreGpressed()));

    QShortcut* lettre_H = new QShortcut (QKeySequence(Qt::Key_H), this);
    QObject::connect(lettre_H, SIGNAL (activated()), this, SLOT (lettreHpressed()));

    QShortcut* lettre_I = new QShortcut (QKeySequence(Qt::Key_I), this);
    QObject::connect(lettre_I, SIGNAL (activated()), this, SLOT (lettreIpressed()));

    QShortcut* lettre_L = new QShortcut (QKeySequence(Qt::Key_L), this);
    QObject::connect(lettre_L, SIGNAL (activated()), this, SLOT (lettreLpressed()));

    QShortcut* lettre_M = new QShortcut (QKeySequence(Qt::Key_M), this);
    QObject::connect(lettre_M, SIGNAL (activated()), this, SLOT (lettreMpressed()));

    QShortcut* lettre_N = new QShortcut (QKeySequence(Qt::Key_N), this);
    QObject::connect(lettre_N, SIGNAL (activated()), this, SLOT (lettreNpressed()));

    QShortcut* lettre_O = new QShortcut (QKeySequence(Qt::Key_O), this);
    QObject::connect(lettre_O, SIGNAL (activated()), this, SLOT (lettreOpressed()));

    QShortcut* lettre_P = new QShortcut (QKeySequence(Qt::Key_P), this);
    QObject::connect(lettre_P, SIGNAL (activated()), this, SLOT (lettrePpressed()));

    QShortcut* lettre_Q = new QShortcut (QKeySequence(Qt::Key_Q), this);
    QObject::connect(lettre_Q, SIGNAL (activated()), this, SLOT (lettreQpressed()));

    QShortcut* lettre_R = new QShortcut (QKeySequence(Qt::Key_R), this);
    QObject::connect(lettre_R, SIGNAL (activated()), this, SLOT (lettreRpressed()));

    QShortcut* lettre_S = new QShortcut (QKeySequence(Qt::Key_S), this);
    QObject::connect(lettre_S, SIGNAL (activated()), this, SLOT (lettreSpressed()));

    QShortcut* lettre_T = new QShortcut (QKeySequence(Qt::Key_T), this);
    QObject::connect(lettre_T, SIGNAL (activated()), this, SLOT (lettreTpressed()));

    QShortcut* lettre_U = new QShortcut (QKeySequence(Qt::Key_U), this);
    QObject::connect(lettre_U, SIGNAL (activated()), this, SLOT (lettreUpressed()));

    QShortcut* lettre_V = new QShortcut (QKeySequence(Qt::Key_V), this);
    QObject::connect(lettre_V, SIGNAL (activated()), this, SLOT (lettreVpressed()));

    QShortcut* lettre_W = new QShortcut (QKeySequence(Qt::Key_W), this);
    QObject::connect(lettre_W, SIGNAL (activated()), this, SLOT (lettreWpressed()));


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
    QObject::connect(ui->btnEvalExp, SIGNAL (clicked()), this, SLOT(eval_expression()));
    QObject::connect(ui->btnModifTaille, SIGNAL (clicked()), this, SLOT (modif_taille_pile()));


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

//! Destructeur de la classe MainWindow

MainWindow::~MainWindow()
{
    delete ui;
}


//! Slot qui permet d'ajouter un 0 en entree.

void MainWindow::btn0pressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("0"));
}


//! Slot qui permet d'ajouter un 1 en entree.

void MainWindow::btn1pressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("1"));
}


//! Slot qui permet d'ajouter un 2 en entree.

void MainWindow::btn2pressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("2"));
}


//! Slot qui permet d'ajouter un 3 en entree.

void MainWindow::btn3pressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("3"));
}


//! Slot qui permet d'ajouter un 4 en entree.

void MainWindow::btn4pressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("4"));
}


//! Slot qui permet d'ajouter un 5 en entree.

void MainWindow::btn5pressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("5"));
}


//! Slot qui permet d'ajouter un 6 en entree.

void MainWindow::btn6pressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("6"));
}


//! Slot qui permet d'ajouter un 7 en entree.

void MainWindow::btn7pressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("7"));
}


//! Slot qui permet d'ajouter un 8 en entree.

void MainWindow::btn8pressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("8"));
}


//! Slot qui permet d'ajouter un 9 en entree.

void MainWindow::btn9pressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("9"));
}


//! Slot qui permet d'ajouter un espace en entree.

void MainWindow::btnSPACEpressed()
{
    ui->le_entree->setText(ui->le_entree->text().append(" "));
}


//! Slot qui permet d'ajouter un + en entree.

void MainWindow::btnAddipressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("+"));
}


//! Slot qui permet d'ajouter un - en entree.

void MainWindow::btnSouspressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("-"));
}


//! Slot qui permet d'ajouter une * en entree.

void MainWindow::btnMultpressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("*"));
}


//! Slot qui permet d'ajouter un / en entree.

void MainWindow::btnDivipressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("/"));
}


//! Slot qui permet d'ajouter INV en entree.

void MainWindow::btnINVpressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("INV"));
}


//! Slot qui permet d'ajouter COS en entree.

void MainWindow::btnCOSpressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("COS"));
}


//! Slot qui permet d'ajouter SIN en entree.

void MainWindow::btnSINpressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("SIN"));
}


//! Slot qui permet d'ajouter TAN en entree.

void MainWindow::btnTANpressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("TAN"));
}


//! Slot qui permet d'ajouter COSH en entree.

void MainWindow::btnCOSHpressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("COSH"));
}


//! Slot qui permet d'ajouter SINH en entree.

void MainWindow::btnSINHpressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("SINH"));
}


//! Slot qui permet d'ajouter TANH en entree.

void MainWindow::btnTANHpressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("TANH"));
}


//! Slot qui permet d'ajouter LOG en entree.

void MainWindow::btnLOGpressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("LOG"));
}


//! Slot qui permet d'ajouter LN en entree.

void MainWindow::btnLNpressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("LN"));
}


//! Slot qui permet d'ajouter ! en entree.

void MainWindow::btnFACTOpressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("!"));
}


//! Slot qui permet d'ajouter SIGN en entree.

void MainWindow::btnSIGNpressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("SIGN"));
}


//! Slot qui permet d'ajouter SQR en entree.

void MainWindow::btnSQRpressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("SQR"));
}


//! Slot qui permet d'ajouter SQRT en entree.

void MainWindow::btnSQRTpressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("SQRT"));
}


//! Slot qui permet d'ajouter CUBE en entree.

void MainWindow::btnCUBEpressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("CUBE"));
}


//! Slot qui permet d'ajouter $ en entree.

void MainWindow::btnCOMPLEXEpressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("$"));
}


//! Slot qui permet d'ajouter POW en entree.

void MainWindow::btnPOWpressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("POW"));
}


//! Slot qui permet d'ajouter MOD en entree.

void MainWindow::btnMODpressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("MOD"));
}


//! Slot qui permet d'ajouter un point en entree.

void MainWindow::btnPOINTpressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("."));
}


//! Slot qui permet d'ajouter un A en entree.

void MainWindow::lettreApressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("A"));
}


//! Slot qui permet d'ajouter un B en entree.

void MainWindow::lettreBpressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("B"));
}


//! Slot qui permet d'ajouter un C en entree.

void MainWindow::lettreCpressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("C"));
}


//! Slot qui permet d'ajouter un D en entree.

void MainWindow::lettreDpressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("D"));
}


//! Slot qui permet d'ajouter un E en entree.

void MainWindow::lettreEpressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("E"));
}


//! Slot qui permet d'ajouter un G en entree.

void MainWindow::lettreGpressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("G"));
}


//! Slot qui permet d'ajouter un H en entree.

void MainWindow::lettreHpressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("H"));
}


//! Slot qui permet d'ajouter un I en entree.

void MainWindow::lettreIpressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("I"));
}


//! Slot qui permet d'ajouter un L en entree.

void MainWindow::lettreLpressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("L"));
}


//! Slot qui permet d'ajouter un M en entree.

void MainWindow::lettreMpressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("M"));
}


//! Slot qui permet d'ajouter un N en entree.

void MainWindow::lettreNpressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("N"));
}


//! Slot qui permet d'ajouter un O en entree.

void MainWindow::lettreOpressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("O"));
}


//! Slot qui permet d'ajouter un P en entree.

void MainWindow::lettrePpressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("P"));
}


//! Slot qui permet d'ajouter un Q en entree.

void MainWindow::lettreQpressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("Q"));
}


//! Slot qui permet d'ajouter un R en entree.

void MainWindow::lettreRpressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("R"));
}


//! Slot qui permet d'ajouter un S en entree.

void MainWindow::lettreSpressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("S"));
}


//! Slot qui permet d'ajouter un T en entree.

void MainWindow::lettreTpressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("T"));
}


//! Slot qui permet d'ajouter un U en entree.

void MainWindow::lettreUpressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("U"));
}


//! Slot qui permet d'ajouter un V en entree.

void MainWindow::lettreVpressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("V"));
}


//! Slot qui permet d'ajouter un W en entree.

void MainWindow::lettreWpressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("W"));
}

//! Slot d'inverser les places de deux elements de la pile.
/*! Cette fonction va chercher les valeurs contenues dans 2 line edit
    et appelle la fonction Swap de la pile*/

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


//! Slot qui permet de faire la somme d'un nombre donne d'elements.
/*! Cette fonction prend la valeur contenue par une line dit et
    et appelle ensuite la fonction Sum de la pile. */

void MainWindow::btnSUMpressed()
{
   QRegExp test ("^[0-9]+$");
   QString arg1 = ui->arg_SUM->text();

   if (arg1.contains(test))
   {
       int i = ui->arg_SUM->text().toInt();
       p->Sum(i, MainWindow::getMode(), MainWindow::getComplexeMode());
       ui->arg_SUM->setText("1");
       ui->listView->reset();
   }
   else
       throw CalcException("Au moins un des arguments est invalide.");

}


//! Slot qui permet de calculer la moyenne des X premiers elements.
/*! Cette fonction utilise la valeur contenue dans une line edit et
    appelle ensuite la fonction Mean de la pile. */

void MainWindow::btnMEANpressed()
{
   QRegExp test ("^[0-9]+$");
   QString arg1 = ui->arg_MEAN->text();

   if (arg1.contains(test))
   {
       int i = ui->arg_MEAN->text().toInt();
       p->Mean(i, MainWindow::getMode(), MainWindow::getComplexeMode());
       ui->arg_MEAN->setText("1");
       ui->listView->reset();
   }
   else
       throw CalcException("Au moins un des arguments est invalide.");

}


//! Slot qui permet de vider la pile en appelant la fonction Clear de la pile.

void MainWindow::btnCLEANpressed()
{
    p->Clear();
    ui->listView->reset();
}


//! Slot qui permet de dupliquer le dernier element de la pile en appelant la fonction Dup de la pile.

void MainWindow::btnDUPpressed()
{
    p->Dup();
    ui->listView->reset();
}


//! Slot qui permet d'enlever le dernier element de la pile en appelant la fonction Drop de la pile.

void MainWindow::btnDROPpressed()
{
   p->Drop();
   ui->listView->reset();
}


//! Slot qui permet d'annuler les dernieres actions en appelant la fonction Annuler de la pile.

void MainWindow::btnAnnulerpressed()
{
    p->Annuler();
    ui->listView->reset();
}


//! Slot qui permet de retablir les dernieres actions en appelant la fonction Retablir de la pile.

void MainWindow::btnRetablirpressed()
{
    p->Retablir();
    ui->listView->reset();
}


//! Slot qui permet de mettre la calculatrice en mode Scientifique en appelant une fonction de MainWindow.

void MainWindow::affichage_scientifique()
{
        afficher_sc();
}


//! Slot qui permet de mettre la calculatrice en mode Standard en appelant une fonction de MainWindow.

void MainWindow::affichage_standard()
{
       afficher_std();
}


//! Slot qui permet d'evaluer une expression en entree.
/*! Il appelle le Parser de la pile, puis actualise la listview et efface la ligne d'entree.*/

void MainWindow::eval()
{
    p->Parser(ui->le_entree->text());
    ui->listView->reset();
    ui->le_entree->clear();
}


//! Slot qui envoie une expression dans la pile, ou un seul caractere.

void MainWindow::envoi_pile()
{
    QString entree(ui->le_entree->text());
    QStringList verif(entree.split(" "));

    if (verif.length() != 1)
    {
        QString sortie("'");
        sortie.append(entree);
        sortie.append("'");
        ui->le_entree->setText(sortie);
        p->Parser(sortie);
    }
    else
        p->Parser(entree);
    ui->listView->reset();
    ui->le_entree->clear();
}


//! Slot qui permet de mettre la calculatrice en mode Rationnel en appelant une fonction de MainWindow.

void MainWindow::MODE_RATIONNELS()
{
    setModeRationnel();
    ui->listView->reset();
}


//! Slot qui permet de mettre la calculatrice en mode Reel en appelant une fonction de MainWindow.

void MainWindow::MODE_REELS()
{
    setModeReel();
    ui->listView->reset();
}


//! Slot qui permet de mettre la calculatrice en mode Entier en appelant une fonction de MainWindow.

void MainWindow::MODE_ENTIERS()
{
    setModeEntier();
    ui->listView->reset();
}


//! Slot qui permet de mettre la calculatrice en mode Complexe ou de l'enlever.
/*! \param b Indique l'etat de la checkbox. Si b est active, alors il faut mettre le mode Complexe. */

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


//! Slot qui permet d'effacer la ligne d'entree.

void MainWindow::btnRAZpressed()
{
    ui->le_entree->clear();
}


//! Fonction publique de MainWindow qui déclenche une procedure a la fermeture de la fenetre.
/*! Cette fonction permet d'avertir l'utilisateur a la fermeture du logiciel que les modifications
    de l'interface seront sauvegardees.
    La sauvegarde des parametres se fait egalement dans cette fonction. On ouvre le ficher Pile.xml, et on
    effectue les sauvegardes successives de tous les elements. Si le fichier n'existe pas, alors il est cree.
    \param event Un evenement qui se declenche quand la fenetre se ferme.*/

void MainWindow::closeEvent(QCloseEvent * event)
{
    QMessageBox msgBox(this);
    msgBox.setWindowTitle("Fermeture..");
    msgBox.setText("Les informations vont être enregistrées.");
    msgBox.setIcon(QMessageBox::Information);
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

    QDomElement taillepile = filesave.createElement("Taille_Pile");
    QDomText tp = filesave.createTextNode(QString::number(p->getTaille()));
    taillepile.appendChild(tp);
    racine.appendChild(taillepile);

    QFile file( "PILE.xml" );
    if( !file.open( QIODevice::WriteOnly ) )
        throw CalcException("Le Fichier n'existe pas.");

    QTextStream ts( &file );
    ts << filesave.toString();

    file.close();

   QMainWindow::closeEvent(event);
}


//! Fonction publique de MainWindow qui permet un affichage Scientifique.
/*! Elle permet d'activer certains elements de l'interface, comme des boutons
    et d'agrandir la taille de la fenetre.*/

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


//! Fonction publique de MainWindow qui permet un affichage non Scientifique.
/*! Elle permet de desactiver certains elements de l'interface, comme des boutons
    et de reduire la taille de la fenetre.*/

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


//! Fonction qui permet de la calculatrice en mode Entier.
/*! Cette fonction change le label, le mode, et l'etat de plusieurs boutons.*/

void MainWindow::setModeEntier()
{
    MainWindow::setMode("Entier");
    ui->label_mode->setText("Mode : Entiers");
    ui->action_Entiers->setChecked(true);
    ui->action_Entiers->setDisabled(true);
    ui->action_Reels->setEnabled(true);
    ui->action_Reels->setChecked(false);
    ui->action_Rationnels->setEnabled(true);
    ui->action_Rationnels->setChecked(false);
}


//! Fonction qui permet de la calculatrice en mode Rationnel.
/*! Cette fonction change le label, le mode, et l'etat de plusieurs boutons.*/

void MainWindow::setModeRationnel()
{
    MainWindow::setMode("Rationnel");
    ui->label_mode->setText("Mode : Rationnels");
    ui->action_Rationnels->setChecked(true);
    ui->action_Rationnels->setDisabled(true);
    ui->action_Reels->setEnabled(true);
    ui->action_Reels->setChecked(false);
    ui->action_Entiers->setEnabled(true);
    ui->action_Entiers->setChecked(false);
}


//! Fonction qui permet de la calculatrice en mode Reel.
/*! Cette fonction change le label, le mode, et l'etat de plusieurs boutons.*/

void MainWindow::setModeReel()
{
    MainWindow::setMode("Reel");
    ui->label_mode->setText("Mode : Réels");
    ui->action_Reels->setChecked(true);
    ui->action_Reels->setDisabled(true);
    ui->action_Entiers->setEnabled(true);
    ui->action_Entiers->setChecked(false);
    ui->action_Rationnels->setEnabled(true);
    ui->action_Rationnels->setChecked(false);
}

//! Slot permettant d'effectuer un retour arriere dans la ligne d'entree.

void MainWindow::backspace()
{
    QString s1(ui->le_entree->text());
    int L = ui->le_entree->text().length();
    QString s2;
    for (int i=0; i < L-1; i++)
        s2[i] = s1[i];
    ui->le_entree->setText(s2);
}


//! Slot qui permet d'activer le mode Degres.
/*! Il modifie toutes les informations necessaires telles le label, ou l'etat du mode et de boutons.*/

void MainWindow::MODE_DEGRES()
{
    setAngleMode("Degre");
    ui->label_angles->setText("Angles : Degrés");
    ui->action_Degres->setChecked(true);
    ui->action_Degres->setDisabled(true);
    ui->action_Radians->setChecked(false);
    ui->action_Radians->setEnabled(true);
    ui->listView->reset();
}


//! Slot qui permet d'activer le mode Radians.

void MainWindow::MODE_RADIANS()
{
    setModeRadian();
    ui->listView->reset();

}


//! Fonction qui permet de la calculatrice en mode Radian.
/*! Cette fonction change le label, le mode, et l'etat de plusieurs boutons.*/

void MainWindow::setModeRadian()
{
    setAngleMode("Radian");
    ui->label_angles->setText("Angles : Radians");
    ui->action_Radians->setChecked(true);
    ui->action_Radians->setDisabled(true);
    ui->action_Degres->setChecked(false);
    ui->action_Degres->setEnabled(true);
}


//! Slot permettant d'afficher ou de cacher le clavier en appelant des fonctions de MainWindow.

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


//! Fonction permettant d'afficher le clavier numerique.

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


//! Fonction permettant de desactiver le clavier numerique.

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


//! Slot permettant de calculer la resultat d'une expression situee sur le sommet de la pile.
/*! La fonction depile la constante se trouvant sur le sommet. Si c'est une expression, alors
    appelle la fonction Parser de la pile. */

void MainWindow::eval_expression()
{
    try {
    Constante* expression = p->Depiler();
    QString exp = (QString) *expression;
    QStringList liste(exp.split("'"));

    if (liste.length() != 0 || liste.length() != 1)
    {
        exp ="";
        for (int i = 0; i < liste.length(); i++)
            exp.append(liste[i] + " ");
        p->Parser(exp);
        ui->listView->reset();

    }
    else throw CalcException("Expression invalide.");
}
    catch (CalcException c)
    {
        c.alert();
    }

}


//! Slot permettant de modifier la taille maximale de la pile.
/*! La fonction recupere la valeur contenue dans une line edit
    puis appelle la fonction setTaille de la pile.
    Le label est mis a jour, la listview est actualisee et l'argument est efface.*/

void MainWindow::modif_taille_pile()
{
    QRegExp c ("^[0-9]+$");
    if (ui->arg_pile->text().contains(c))
    {
    p->setTaille(ui->arg_pile->text().toInt());
    ui->label_taille->setText("Taille pile: " + QString::number(p->getTaille()));
    ui->listView->reset();
    ui->arg_pile->clear();
    }
    else
        ui->arg_pile->clear();
}
