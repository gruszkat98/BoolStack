#ifndef GUESTWINDOW_H
#define GUESTWINDOW_H

#include <QMainWindow>

namespace Ui {
class guestWindow;
}

class guestWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit guestWindow(QWidget *parent = 0);
    ~guestWindow();

private:
    Ui::guestWindow *ui;
};

#endif // GUESTWINDOW_H
