#ifndef MAINDRAW_H
#define MAINDRAW_H

#include <QMainWindow>

namespace Ui {
class mainDraw;
}

class mainDraw : public QMainWindow
{
    Q_OBJECT

public:
    explicit mainDraw(QWidget *parent = 0);
    ~mainDraw();

private:
    Ui::mainDraw *ui;
};

#endif // MAINDRAW_H
