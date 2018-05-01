#include "customersup.h"
#include "ui_customersup.h"

customerSup::customerSup(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::customerSup)
{
    ui->setupUi(this);
}

customerSup::~customerSup()
{
    delete ui;
}
