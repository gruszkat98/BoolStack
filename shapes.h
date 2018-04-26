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
double convexArea(const vector<point>& temp);


class shape{
protected:
    int ID;
    shape(int input){ID = input;};
    virtual void draw(){};
    virtual double area(){return 0;};
    virtual double perimeter(){return 0;};
public:
    int getID(){return ID;};
};




class polygon: public shape{
    OpVector<point> P;
public:
    polygon();
    polygon(const OpVector<point>& temp);
    void operator + (const point& temp);
    
    virtual void draw(){};
    virtual double area();
    virtual double perimeter();
};

class elipse: public shape{
    point center;
    double majorAxis;
    double minorAxis;
public:
    elipse();
    elipse(const point& c, double r);
    elipse(const point& c, double r1, double r2);
    
    virtual void draw(){};
    virtual double area();
    virtual double perimeter();
};

class line: public shape{
    point a, b;
public:
    line();
    line(const point& temp1, const point& temp2);
    
    virtual void draw(){};
    virtual double perimeter();
};





OpVector<shape*> read(){
    return OpVector<shape*>();
}





#endif /* shapes_h */
