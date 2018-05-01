#include "guestwindow.h"
#include "ui_guestwindow.h"

guestWindow::guestWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::guestWindow)
{
    ui->setupUi(this);
}

guestWindow::~guestWindow()
{
    delete ui;
}
