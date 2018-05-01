#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mainDraw.h"
#include "guestwindow.h"
#include "customersup.h"

const int SIZE = 10;

namespace Ui {
struct signIn{
    const QString username[SIZE] = {"Admin", "Admin1","Admin2", "Admin3","Admin4",
                                 "Admin5", "Admin6","Admin7", "Admin8","Admin9"};
    const QString password[SIZE] = {"Admin", "Admin1","Admin2", "Admin3","Admin4",
                                 "Admin5", "Admin6","Admin7", "Admin8","Admin9"};
};
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    bool checkSignIn(QString user, QString pass){
       for(int i= 0; i < SIZE; i++){
           if (user == a.username[i]) {
               if(pass == a.password[i])
                   return true;
           }
           else
                return false;
       }


    }
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_signInButton_clicked();

    void on_guestSignIn_clicked();

    void on_pushButton_clicked();

    void on_customerSupButton_clicked();

private:
    Ui::signIn a;
    Ui::MainWindow *ui;
    guestWindow *gd;
    mainDraw *md;
    customerSup *cs;
};

#endif // MAINWINDOW_H
