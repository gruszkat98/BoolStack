
#include "ui_shape.h"
#include <QApplication>
#include<shape.h>

namespace Ui {
//********* Shape Abstract ********************************************
Shape::Shape(QPaintDevice* device, int id, shapeType shape) : qPainter{device}, id{id}, shape{shape}
{
    pen = Qt::SolidLine;
    brush = Qt::NoBrush;
}

QPainter& Shape::getQpainter(){ return qPainter; }
Shape::shapeType Shape::getShape() const{ return shape; }
const QPen& Shape::getPen() const { return pen; }
const QBrush& Shape::getBrush() const { return brush; }

void Shape::setShape(shapeType shape){ this->shape = shape; }
//*********************************************************************

//********* Line ******************************************************
void Line::setLine(const QPoint &pointA, const QPoint& pointB){
    this->pointA = pointA;
    this->pointB = pointB;
}

void Line::draw(const int pX, const int pY){
    getQpainter().setPen(getPen());
    getQpainter().setBrush(getBrush());
    getQpainter().save();
    getQpainter().translate(pX, pY);
    getQpainter().drawLine(pointA, pointB);
    getQpainter().restore();
}
//*********************************************************************

//********* Polyline **************************************************

//... needs implementation

//*********************************************************************

//********* Polygon ***************************************************

//... needs implementation

//*********************************************************************

//********* Rectangle *************************************************

bool Rectangle::isSquare()const{
    return rectangle.width() == rectangle.height();
}

void Rectangle::setRectangle(const QRect &rectangle){
    this->rectangle = rectangle;
}

void Rectangle::draw(const int pX, const int pY){

    getQpainter().setPen(getPen());
    getQpainter().setBrush(getBrush());
    getQpainter().save();
    getQpainter().translate(pX, pY);
    getQpainter().drawRect(rectangle);
    getQpainter().restore();
}
//... double check triangle implementations ***

//*********************************************************************

//********* Ellipse ***************************************************
bool Ellipse::isCircle()const{
    return rectangle.width() == rectangle.height();
}

void Ellipse::setRectangle(const QRect &rectangle){
    this->rectangle = rectangle;
}

void Ellipse::draw(const int pX, const int pY){
    getQpainter().setPen(getPen());
    getQpainter().setBrush(getBrush());
    getQpainter().save();
    getQpainter().translate(pX, pY);
    getQpainter().drawEllipse(rectangle);
    getQpainter().restore();

}
//*********************************************************************

//*********** Text ****************************************************

//... needs implementation

//*********************************************************************
}

//********* Empty *****************************************************

//... needs implementation

//*********************************************************************

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{


    ui->setupUi(this);
}

MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *e)
{

    Ui::Line line(this);
    line.setLine(QPoint(40, 80), QPoint(120, 40));
    line.setPen(Qt::red, 3, Qt::DashLine, Qt::FlatCap, Qt::MiterJoin);
    line.draw();
}
