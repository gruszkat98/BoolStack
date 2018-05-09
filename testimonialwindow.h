#ifndef TESTIMONIALWINDOW_H
#define TESTIMONIALWINDOW_H
//
#include <QMainWindow>

namespace Ui {
class testimonialWindow;
}

class testimonialWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit testimonialWindow(QWidget *parent = 0);
    ~testimonialWindow();

private:
    Ui::testimonialWindow *ui;
};

#endif // TESTIMONIALWINDOW_H
