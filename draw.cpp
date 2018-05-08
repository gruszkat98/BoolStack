#include "draw.h"
#include "ui_draw.h"
#include <QString>
#include <QDataStream>
#include <QFile>

Draw::Draw(QWidget *parent) : QMainWindow(parent), ui(new Ui::Draw){ui->setupUi(this);}
void Draw::setAdmin(bool a){admin = a;}
Draw::~Draw(){delete ui;}

//TAB EVENTS

void Draw::on_actionSave_triggered(){
    /*Qstring file = QFileDialog::getSaveFileName(this, tr("Save Drawing"), "", tr("Text File (*.txt)"));
    if(!file.isEmpty()){
        QFile out(file);
        if(out.open(NULL)){
            QDataStream out(& file);
            //out << current shape array/vector/container/whatever
        }
    }*/
}

void Draw::on_actionOpen_triggered(){}
void Draw::on_actionAbout_triggered(){a.show();}
void Draw::on_actionInfo_triggered(){}
void Draw::on_actionLog_Out_triggered(){
    admin = false;
    this->hide();
}

//PEN BUTTON EVENTS

void Draw::on_drawButton_clicked(){pen = DRAW;}
void Draw::on_editButton_clicked(){pen = EDIT;}
void Draw::on_deleteButton_clicked(){pen = DELETE;}

//SHAPE BUTTON EVENTS

void Draw::on_circleButton_clicked(){shape = CIRCLE;}
void Draw::on_ellipseButton_clicked(){shape = ELLIPSE;}
void Draw::on_triangleButton_clicked(){shape = TRIANGLE;}
void Draw::on_squareButton_clicked(){shape = SQUARE;}
void Draw::on_rectangleButton_clicked(){shape = RECTANGLE;}
void Draw::on_polygonButton_clicked(){shape = POLYGON;}
void Draw::on_lineButton_clicked(){shape = LINE;}
void Draw::on_polylineButton_clicked(){shape = POLYLINE;}
void Draw::on_textButton_clicked(){shape = TEXT;}

//DRAWAREA EVENTS

/*void Draw::paintEvent(QPaintEvent * e){
    QPainter painter(this);

}*/
