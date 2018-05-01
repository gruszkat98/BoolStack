//
//  shapes.h
//  Proj_Shape
//
//  Created by Tomek Gruszka on 4/12/18.
//  Copyright © 2018 Tomek Gruszka. All rights reserved.
//

#ifndef shapes_h
#define shapes_h

#include "OpVector.h"
struct point{
    double x;
    double y;
    bool inSet(const OpVector<point>& set){
        for (int i = 0; i<set.NumElemSize(); i++){
            if(set.elemAt(i).x == x && set.elemAt(i).y == y)
                return true;
        }
        return false;
    }
};

double distance(const point& a, const point& b);
OpVector<point> convex_hull(const OpVector<point>& RHS);
int leftiness (const point& a, const point& b, const point& Check);
double convexArea(const OpVector<point>& temp);


class shape{
protected:
    int ID;
    string SaveAs;
    shape(int input){ID = input;};
public:
    
    friend void save(OpVector<shape*> SaveThis);
    virtual void draw()const{};
    virtual double area()const{return 0;};
    virtual double perimeter()const{return 0;};
    int getID()const{return ID;};
};

class polygon: public shape{
    OpVector<point> P;
public:
    polygon();
    polygon(const OpVector<point>& temp);
    void operator + (const point& temp);
    
    virtual void draw()const{};
    virtual double area()const;
    virtual double perimeter()const;
};

class elipse: public shape{
    point center;
    double majorAxis;
    double minorAxis;
public:
    elipse();
    elipse(const point& c, double r);
    elipse(const point& c, double r1, double r2);
    
    virtual void draw()const{};
    virtual double area()const;
    virtual double perimeter()const;
};

class line: public shape{
    point a, b;
public:
    line();
    line(const point& temp1, const point& temp2);
    
    virtual void draw()const{};
    virtual double perimeter()const;
};


OpVector<shape*> read();
void save(OpVector<shape*> SaveThis);

#endif /* shapes_h */
