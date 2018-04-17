//
//  main.cpp
//  Proj_Shape
//
//  Created by Tomek Gruszka on 4/12/18.
//  Copyright © 2018 Tomek Gruszka. All rights reserved.
//

#include "shapes.h"

int main() {
    
    point a1 {2, 0};
    point a {1, 0};
    point c2 {0, 2};
    point c3 {1, 2};
    point c4 {1, 4};
    point c5 {3, 4};
    point c6 {3, 2};
    point c7 {2, 2};
    
    
    vector<point> d {a1, a, c2, c3, c4, c5, c6, c7};
    
    polygon square(d);
    
    cout << square.area() <<endl;
    cout << square.perimeter() <<endl;

    
    
    return 0;
}
