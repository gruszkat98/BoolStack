#include "mainDraw.h"
#include "ui_mainDraw.h"

mainDraw::mainDraw(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mainDraw)
{
    ui->setupUi(this);
}

mainDraw::~mainDraw()
{
    delete ui;
}
