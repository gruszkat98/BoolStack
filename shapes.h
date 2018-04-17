//
//  shapes.h
//  Proj_Shape
//
//  Created by Tomek Gruszka on 4/12/18.
//  Copyright © 2018 Tomek Gruszka. All rights reserved.
//

#ifndef shapes_h
#define shapes_h

#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

struct point{
    double x;
    double y;
    bool inSet(const vector<point>& set){
        for (int i = 0; i<set.size(); i++){
            if(set[i].x == x && set[i].y == y)
                return true;
        }
        return false;
    }
};

double distance(const point& a, const point& b);
vector<point> convex_hull(const vector<point>& RHS);
int leftiness (const point& a, const point& b, const point& Check);
double convexArea(const vector<point>& temp);


class shape{
    int ID;
public:
    shape(){ID = 1;};
    virtual void draw(){};
    virtual double area(){return 0;};
    virtual double perimeter(){return 0;};
};




class polygon: public shape{
    vector<point> P;
public:
    polygon();
    polygon(const vector<point>& temp);
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






#endif /* shapes_h */
