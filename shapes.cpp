//
//  shapes.cpp
//  Proj_Shape
//
//  Created by Tomek Gruszka on 4/12/18.
//  Copyright © 2018 Tomek Gruszka. All rights reserved.
//

#include "shapes.h"


double distance(const point& a, const point& b){
    double rez=0;
    
    rez = (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
    rez = pow(rez, 0.5);
    
    return rez;
}

int leftiness (const point& a, const point& b, const point& Check){
    double rez = (Check.y - a.y) * (b.x - a.x) - (b.y - a.y)*(Check.x - a.x);
    
    if (rez > 0)
        return -1;
    else if (rez < 0)
        return 1;
    else return 0;
    
}

double convexArea(const OpVector<point>& temp){
    double result = 0;
    double s, a, b, c;
    
    point T1 = temp.elemAt(0), T2=temp.elemAt(1), T3=temp.elemAt(2);
    
    
    for (int i =0; i< temp.NumElemSize() - 2; i++){
        a = distance(T1, T2);
        b = distance(T1, T3);
        c = distance(T2, T3);
        
        s = (a + b + c) * 0.5;

        T2 = T3;
        T3 = temp.elemAt(i+3);
        
        result += pow(s * (s-a) * (s-b) * (s-c), 0.5);
    }
    
    return result;
}

OpVector<point> convex_hull(const OpVector<point>& RHS){
    OpVector<point> result;
    
    // find leftmost
    point start = RHS.elemAt(0);
    point next = RHS.elemAt(0);
    bool done = 0;
    
    for(int i = 1; i<RHS.NumElemSize(); i++){
        if (RHS.elemAt(i).x < start.x)
            start = RHS.elemAt(i);
    }
    result.PushBack(start);
    
    while(!done){
    
        for (int i = 0; i<RHS.NumElemSize(); i++){
            if (leftiness(start, next, RHS.elemAt(i)) == 1){
                next = RHS.elemAt(i);
            }else if (leftiness(start, next, RHS.elemAt(i)) == 0 && distance(start, next) < distance(start, RHS.elemAt(i))){
                next = RHS.elemAt(i);
            }
        }
    
        if (next.x == result.elemAt(0).x && next.y == result.elemAt(0).y){
            done = 1;
        }
        else {
            result.PushBack(next);
            start = next;
        }
    }

    
    return result;
}




polygon::polygon():shape(1){
    
}

polygon:: polygon(const OpVector<point>& temp):shape(1){
    
    P = temp;
}

void polygon:: operator + (const point& temp){
    P.PushBack(temp);
}

double polygon::area(){
    double result =0;
    
    //create a convex hull
    OpVector<point> HULL = convex_hull(P);
    
    if (HULL.NumElemSize() != P.NumElemSize()){
    // count number of holes, save them as polygons
        OpVector<polygon> holes;
        int start = 0;
    
        for(int i = 1; i<P.NumElemSize(); i++){
            if (P.elemAt(i).x < P.elemAt(start).x)
                start = i;
        }
        
        polygon temp;
        
        
        int current = start;
        int next = start +1;
        
        if (next == P.NumElemSize())
            next = 0;
       
        do{
            if (P[current].inSet(HULL) &&  !(P[next].inSet(HULL))){
                temp + P[current];
            }
            else if(!(P[current].inSet(HULL)) && !(P[next].inSet(HULL))){
                temp + P[current];
            }
            else if(!(P[current].inSet(HULL)) && (P[next].inSet(HULL))){
                temp + P[current];
                temp + P[next];
        
                holes.PushBack(temp);
                temp = polygon();
            }
            current ++;
            if (current == P.NumElemSize())
                current = 0;
            
            next = current +1;
            if (next == P.NumElemSize())
                next = 0;
            
    
        
        }while (current != start);
        
        for (int i =0; i<holes.NumElemSize(); i++){
            result += holes.elemAt(i).area();
        }
        
        return convexArea(HULL) - result;
    }else
        return convexArea(HULL);
}

double polygon:: perimeter(){
    double rez = 0;
    
    for (int i = 0; i<P.NumElemSize(); i++){
        if (i+1 != P.NumElemSize())
            rez += distance(P.elemAt(i), P.elemAt(i+1));
        else
            rez += distance(P.elemAt(i), P.elemAt(0));
    }
    
    
    return rez;
}




elipse:: elipse():shape(2){
    
    majorAxis = 0;
    minorAxis = 0;
}

elipse:: elipse(const point& c, double r):shape(2){
    
    center = c;
    majorAxis = r;
    minorAxis = r;
    
}

elipse:: elipse(const point& c, double r1, double r2):shape(2){
    
    center = c;
    majorAxis = r1;
    minorAxis = r2;
}

double elipse:: area(){
    return M_PI * minorAxis * majorAxis;
}

double elipse:: perimeter(){
    
    double h = (minorAxis - majorAxis)/ (minorAxis + majorAxis);
    h = pow(h, 2);
    
    
    return M_PI* (minorAxis + majorAxis) * (1 + 3*h/(10 + pow((4 - 3*h), 0.5 )));
}




//class line: public shape{
//    point a, b;
//public:
//    line();
//    line(point temp1, point temp2);
    
//    virtual void draw(){};
//    virtual double perimeter();
//    virtual double area();
//};


line:: line():shape(3){
    
}

line:: line(const point& temp1, const point& temp2):shape(3){
    a = temp1;
    b = temp2;
}

double line::perimeter(){
    return distance(a, b);
}



