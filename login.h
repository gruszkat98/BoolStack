#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "draw.h"

namespace Ui {class login;}

class login : public QWidget{
    Q_OBJECT
public:
    explicit login(QWidget *parent = 0);
    ~login();
private slots:
    void on_lButton_clicked();
    void on_gButton_clicked();
private:
    Ui::login *ui;
    Draw d;
};

#endif // LOGIN_H
