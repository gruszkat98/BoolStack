#include "testimonialwindow.h"
#include "ui_testimonialwindow.h"

testimonialWindow::testimonialWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::testimonialWindow)
{
    ui->setupUi(this);
}

testimonialWindow::~testimonialWindow()
{
    delete ui;
}
