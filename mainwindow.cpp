#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
