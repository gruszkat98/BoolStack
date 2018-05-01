#ifndef CUSTOMERSUP_H
#define CUSTOMERSUP_H

#include <QMainWindow>

namespace Ui {
class customerSup;
}

class customerSup : public QMainWindow
{
    Q_OBJECT

public:
    explicit customerSup(QWidget *parent = 0);
    ~customerSup();

private:
    Ui::customerSup *ui;
};

#endif // CUSTOMERSUP_H
