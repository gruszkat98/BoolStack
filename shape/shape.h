#ifndef SHAPE_H
#define SHAPE_H

#include <QMainWindow>
#include <vector>
#include <QBrush>
#include <QPen>
#include <QPainter>
#include <QApplication>
#include <QFont>
#include <QtGui>
#include <QtCore>

using namespace std;

namespace Ui {
class MainWindow;


//********* Shape A class ***************************************************************
class Shape{
public:
    enum class shapeType{
        Line, Polyline, Polygon, Rectangle, Ellipse, Text, empty
    };

    Shape();
    Shape(QPaintDevice* device = nullptr, int id = -80, shapeType shape = shapeType::empty);
    virtual ~Shape(){}


    //Getters
    shapeType getShape()const;
    int getId()const;
    const QPen& getPen()const;
    const QBrush& getBrush()const;

    //Setters
    void setShape(shapeType shape);
    void setPen(Qt::GlobalColor color);
    void setPen(Qt::GlobalColor color, int width, Qt::PenStyle pStyle, Qt::PenCapStyle pCstyle, Qt::PenJoinStyle pJstyle);
    void setBrush(Qt::GlobalColor color, Qt::BrushStyle bStyle);

    virtual void draw(const int pX, const int pY) = 0;

protected:
    QPainter& getQpainter(); //painter object

private:
    QPainter qPainter;
    shapeType shape;
    int id;
    QPen pen;
    QBrush brush;

}; //End abstract Shape class
//***************************************************************************************

//********* Line class ******************************************************************
class Line : public Shape
{
public:
    Line();
    Line(QPaintDevice* device = nullptr, int id = -1) :
        Shape(device, id, shapeType::Line){}

    ~Line()override{} //poly virtual

    //getters
    const QPoint& getPointA()const;
    const QPoint& getPointB()const;

    //setters
    void setLine(const QPoint& pointA, const QPoint& pointB);
    void draw(const int pX = 0, const int pY = 0)override; //inhe poly

private:
    QPoint pointA;
    QPoint pointB;
};//End class Line
//***************************************************************************************

//*********** Polyline class ************************************************************
class Polyline : public Shape
{
public:
    Polyline();
    Polyline(QPaintDevice* device = nullptr, int id = -1) : Shape(device, id, shapeType::Polyline){}

    ~Polyline()override{}

    //Setters
    void setPolyline(const QPoint& point);
    void draw(const int pX = 0, const int pY = 0)override; //inhe poly

private:
    vector<QPoint> points; //set of points
};//End class Polyline
//***************************************************************************************

//*********** Polygon class *************************************************************
class Polygon : public Shape
{
public:
    Polygon();
    Polygon(QPaintDevice* device = nullptr, int id = -1) :
        Shape(device, id, shapeType::Polygon){}

    ~Polygon()override{}

    void setPolygon(const QPoint& point);
    void draw(const int pX = 0, const int pY = 0)override; //inhe poly
private:
    vector<QPoint> points;  //set of points
};//End class polygon
//***************************************************************************************

//********** Rectangle class ************************************************************
class Rectangle : public Shape
{
public:
    Rectangle();
    Rectangle(QPaintDevice* device = nullptr, int id = -1) :
        Shape(device, id, shapeType::Rectangle){}

    ~Rectangle()override{}

    //getter
    const QRect& getRectangle()const;

    //setters
    void setRectangle(const QRect& rectangle);
    bool isSquare()const;
    void draw(const int pX = 0, const int pY = 0)override; //inhe poly

private:
    QRect rectangle;

};
//***************************************************************************************

//***********  Ellipse class ************************************************************
class Ellipse : public Shape
{
    Ellipse();
    Ellipse(QPaintDevice* device = nullptr, int id = -1) :
        Shape(device, id, shapeType::Ellipse){}

    ~Ellipse()override{}

    //getter
    //const QRect& getRectangle()const;

    //setters
    //void setEllipse(const QEllipse rectangle);

    void setRectangle(const QRect& rectangle);
    bool isCircle()const;

    void draw(const int pX = 0, const int pY = 0)override; //inhe poly

private:
    QRect rectangle;

};
//***************************************************************************************

//************** Text class *************************************************************

//... needs declaration

//***************************************************************************************

//*************** EmptyShape class ******************************************************

//... needs declaration

//***************************************************************************************

}




class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

protected:
    void paintEvent(QPaintEvent *e);
};

#endif // SHAPE_H
