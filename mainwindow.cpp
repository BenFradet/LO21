#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(Pile *P, QWidget *parent) : p(P),
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->actionStandard->setDisabled(true);

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
    MainWindow::setMinimumHeight(370);
    MainWindow::setMinimumWidth(916);

    QRect R(100,200,916, 370);
    MainWindow::setGeometry(R);
    QObject::connect(ui->btn0, SIGNAL(clicked()), this, SLOT(btn0pressed()));
    QObject::connect(ui->btn1, SIGNAL(clicked()), this, SLOT(btn1pressed()));
    QObject::connect(ui->btn2, SIGNAL(clicked()), this, SLOT(btn2pressed()));
    QObject::connect(ui->btn3, SIGNAL(clicked()), this, SLOT(btn3pressed()));
    QObject::connect(ui->btn4, SIGNAL(clicked()), this, SLOT(btn4pressed()));
    QObject::connect(ui->btn5, SIGNAL(clicked()), this, SLOT(btn5pressed()));
    QObject::connect(ui->btn6, SIGNAL(clicked()), this, SLOT(btn6pressed()));
    QObject::connect(ui->btn7, SIGNAL(clicked()), this, SLOT(btn7pressed()));
    QObject::connect(ui->btn8, SIGNAL(clicked()), this, SLOT(btn8pressed()));
    QObject::connect(ui->btn9, SIGNAL(clicked()), this, SLOT(btn9pressed()));
    QObject::connect(ui->btnAnnuler, SIGNAL(clicked()), this, SLOT(btnAnnulerpressed()));
    QObject::connect(ui->actionScientifique, SIGNAL(triggered()), this, SLOT(affichage_scientifique()));
    QObject::connect(ui->actionStandard, SIGNAL(triggered()), this, SLOT(affichage_standard()));
    QObject::connect(ui->btnSENDSTACK, SIGNAL (clicked()), this, SLOT(envoi_pile()));

ui->listView->setModel(p);


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


void MainWindow::btnAnnulerpressed()
{
    ui->le_entree->setText(ui->le_entree->text().append("Annuler"));
}

void MainWindow::affichage_scientifique()
{


    if (ui->actionScientifique->isChecked() == true)
{
    ui->actionStandard->setCheckable(true);
    ui->actionStandard->setChecked(false);
    ui->actionStandard->setEnabled(true);
    ui->actionScientifique->setChecked(true);
    ui->actionScientifique->setDisabled(true);

    MainWindow::setMinimumHeight(500);
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

}

void MainWindow::affichage_standard()
{
    {
        if (ui->actionStandard->isChecked() == true)
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

    }

}

void MainWindow::envoi_pile()
{
    ui->listView->setModel(p);

}

