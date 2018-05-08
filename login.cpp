#include "login.h"
#include "draw.h"
#include "ui_login.h"

login::login(QWidget *parent) : QWidget(parent), ui(new Ui::login){ui->setupUi(this);}

login::~login(){delete ui;}

void login::on_lButton_clicked(){
    this->hide();
    d.setAdmin(true);
    d.show();
}

void login::on_gButton_clicked(){
    this->hide();
    d.setAdmin(false);
    d.show();
}
