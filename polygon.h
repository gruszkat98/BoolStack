//
//  polygon.h
//  Wolfram
//
//  Created by Tomek Gruszka on 4/3/18.
//  Copyright © 2018 Tomek Gruszka. All rights reserved.
//

#ifndef polygon_h
#define polygon_h

#include "complex.h"
#include <iostream>
#include <vector>

using namespace std;

template <int N> class Reg_Polygon{
private:
    double side;
    
public:
    Reg_Polygon(){
        side = 0;
    }
    Reg_Polygon(double s){
        side = s;
    }

    double area(){
        double result;
        
        result = side*side;
        result *= N;
        result *= 0.25;
        result *= cos(M_PI/N);
        result *= pow(sin(M_PI/N), -1);
        
        return result;
    }
    double perimeter(){
        return side*N;
    }
    
};


class triangle{
private:
    complex p[3];
public:
    triangle(complex p1, complex p2, complex p3){
        p[0] = p1;
        p[1] = p2;
        p[2] = p3;
    }
    triangle(complex temp[3]){
        p[0] = temp[0];
        p[1] = temp[1];
        p[2] = temp[2];
    }
    triangle(){
        p[0] = 0;
        p[1] = 1;
        p[2] = 2;
    }
    
    void setVal(complex temp[3]){
        p[0] = temp[0];
        p[1] = temp[1];
        p[2] = temp[2];
    }
    
    double area(){
        double s[3];
        
        s[0] = (p[0] - p[1]).mod();
        s[1] = (p[1] - p[2]).mod();
        s[2] = (p[2] - p[0]).mod();
        
        double P = (s[0] + s[1] + s[2])/2;
        
        return pow(P * (P-s[0]) * (P-s[1]) * (P-s[2]), 0.5);
        
    }
    
    double perimeter(){
        double s[3];
        
        s[0] = (p[0] - p[1]).mod();
        s[1] = (p[1] - p[2]).mod();
        s[2] = (p[2] - p[0]).mod();
        
        return s[0] + s[1] + s[2];
    }
};

template <int N> class CONVEX_Polygon{
private:
    complex p[N];
public:
    CONVEX_Polygon(vector<complex> P){
        for (int i = 0; i <N; i++)
            p[i] = P[i];
    }
    
    double area(){
        triangle SPLIT[N-2];
        complex ARRAY[3]{p[0], p[1], p[2]};
        double result = 0;
        
        for (int i = 0; i<N-2; i++){
            SPLIT[i].setVal(ARRAY);
            ARRAY[1] = ARRAY[2];
            ARRAY[2] = p[i+3];
        }
        
        for (int i = 0; i<N-2; i++){
            result += SPLIT[i].area();
            
        }
        
        return result; 
    }
};

vector<complex> CONVEX_HULL(const vector<complex>& point){
    vector<complex> convex_hull;
    
    
    bool done = false;
    
    // FINDING LEFT MOST POINT
    
    int starter = 0;
    for (int i = 1; i < point.size(); i++)
        if (point[i].getR() < point[starter].getR())
            starter = i;
    
    
    //
    
    convex_hull.push_back(point[starter]);
    int ender;
    
    
    
    while (!done){
    
        if (starter == point.size() - 1)
            ender = 0;
        else
            ender = starter + 1;
    
    
    
        for (int i = 0; i < starter; i++){
            if (((point[i]-point[starter]) / (point[ender]-point[starter])).getI() >= 0)
                ender = i;
        }
    
        for (int i = starter + 1; i < point.size(); i++){
            if (((point[i]-point[starter]) / (point[ender]-point[starter])).getI() >= 0)
                ender = i;
        }
    
    
    
        done = (point[ender] == convex_hull[0]);
    
        if(! done){
            convex_hull.push_back(point[ender]);
            starter = ender;
        }
    }
    
    
    
    
    
    
    
    return convex_hull;
}

#endif /* polygon_h */
