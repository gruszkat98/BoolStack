#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "customersup.h"
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_signInButton_clicked()
{
    QString userName = ui->usernameLe->text();
    QString password = ui->passwordLe->text();

    if (this->checkSignIn(userName, password)){
        md = new mainDraw(this);
        md->show();
        this->hide();
    }
}

void MainWindow::on_guestSignIn_clicked()
{
    gd = new guestWindow();
    gd->show();
    this->hide();
    return;
}

void MainWindow::on_customerSupButton_clicked()
{
    cs = new customerSup();
    cs->show();
    return;
}

void MainWindow::on_pushButton_clicked()
{

}
