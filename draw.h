#ifndef DRAW_H
#define DRAW_H

#include <QMainWindow>
#include "about.h"

namespace Ui {class Draw;}

class Draw : public QMainWindow{
    Q_OBJECT
public:
    explicit Draw(QWidget *parent = 0);
    void setAdmin(bool a);
    ~Draw();
private slots:
    void on_actionSave_triggered();
    void on_actionOpen_triggered();
    void on_actionAbout_triggered();
    void on_drawButton_clicked();
    void on_editButton_clicked();
    void on_deleteButton_clicked();
    void on_circleButton_clicked();
    void on_ellipseButton_clicked();
    void on_triangleButton_clicked();
    void on_squareButton_clicked();
    void on_rectangleButton_clicked();
    void on_polygonButton_clicked();
    void on_lineButton_clicked();
    void on_polylineButton_clicked();
    void on_textButton_clicked();
    void on_actionInfo_triggered();
    void on_actionLog_Out_triggered();

private:
    Ui::Draw *ui;
    bool admin;
    About a;
    enum pen_state{DRAW, EDIT, DELETE};
    enum shape_state{CIRCLE, ELLIPSE, TRIANGLE, SQUARE, RECTANGLE, POLYGON, LINE, POLYLINE, TEXT};
    pen_state pen;
    shape_state shape;
};

#endif // DRAW_H
