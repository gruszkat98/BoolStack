#include "shapes.h"


string directory = "/Users/tomekgruszka/Desktop/Proj_Shape/shapes.txt";


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
    shape:: SaveAs = "1 0 ";
}

polygon:: polygon(const OpVector<point>& temp):shape(1){
    shape:: SaveAs = "1 0 ";
    
    for (int i=0; i<temp.NumElemSize(); i++){
        *this + temp.elemAt(i);
    }
}

void polygon:: operator + (const point& temp){
    string demp;
    
    demp = to_string(temp.x);
    demp += " ";
    demp += to_string(temp.y);
    demp += " ";
    
    shape::SaveAs += demp;
    
    int femp = static_cast<int>(shape::SaveAs.at(2));
    femp++;
    
    shape::SaveAs.at(2) = femp;
    
    P.PushBack(temp);
}


double polygon::area()const{
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
            if (P.elemAt(current).inSet(HULL) &&  !(P.elemAt(next).inSet(HULL))){
                temp + P.elemAt(current);
            }
            else if(!(P.elemAt(current).inSet(HULL)) && !(P.elemAt(next).inSet(HULL))){
                temp + P.elemAt(current);
            }
            else if(!(P.elemAt(current).inSet(HULL)) && (P.elemAt(next).inSet(HULL))){
                temp + P.elemAt(current);
                temp + P.elemAt(next);
        
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

double polygon:: perimeter()const{
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
    shape::SaveAs = "2 0 0 0 0";
    
    majorAxis = 0;
    minorAxis = 0;
}

elipse:: elipse(const point& c, double r):shape(2){
    shape::SaveAs = "2 ";
    shape::SaveAs += to_string(c.x);
    shape::SaveAs += " ";
    shape::SaveAs += to_string(c.y);
    shape::SaveAs += " ";
    shape::SaveAs += to_string(r);
    shape::SaveAs += " ";
    shape::SaveAs += to_string(r);
    
    center = c;
    majorAxis = r;
    minorAxis = r;
    
}

elipse:: elipse(const point& c, double r1, double r2):shape(2){
    shape::SaveAs = "2 ";
    shape::SaveAs += to_string(c.x);
    shape::SaveAs += " ";
    shape::SaveAs += to_string(c.y);
    shape::SaveAs += " ";
    shape::SaveAs += to_string(r1);
    shape::SaveAs += " ";
    shape::SaveAs += to_string(r2);
    
    center = c;
    majorAxis = r1;
    minorAxis = r2;
}

double elipse:: area()const{
    return M_PI * minorAxis * majorAxis;
}

double elipse:: perimeter()const{
    
    double h = (minorAxis - majorAxis)/ (minorAxis + majorAxis);
    h = pow(h, 2);
    
    
    return M_PI* (minorAxis + majorAxis) * (1 + 3*h/(10 + pow((4 - 3*h), 0.5 )));
}


line:: line():shape(3){
    shape::SaveAs = "3 0 0 0 0";
}

line:: line(const point& temp1, const point& temp2):shape(3){
    shape::SaveAs = "3 ";
    shape::SaveAs += to_string(temp1.x);
    shape::SaveAs += " ";
    shape::SaveAs += to_string(temp1.y);
    shape::SaveAs += " ";
    shape::SaveAs += to_string(temp2.x);
    shape::SaveAs += " ";
    shape::SaveAs += to_string(temp2.y);
    
    a = temp1;
    b = temp2;
}

double line::perimeter()const{
    return distance(a, b);
}


OpVector<shape*> read(){
    
    ifstream inFile;
    OpVector<shape*> result;
    int numOfLines;
    
    
    int temp_ID;
    int temp_NOP;
    double temp_D1;
    double temp_D2;
    
    point temp_P;
    OpVector<point> temp_V;
    
    
    inFile.open(directory);
    inFile >> numOfLines;
    
    
    for (int i = 0; i<numOfLines; i++){
        inFile >> temp_ID;
        switch(temp_ID){
            case 1:
                inFile >> temp_NOP;
                for (int j = 0; j<temp_NOP; j++){
                    inFile >> temp_P.x >> temp_P.y;
                    temp_V.PushBack(temp_P);
                }
                
                result.PushBack(new polygon(temp_V));
                temp_V.clear();
                
                break;
            case 2:
                inFile >> temp_P.x >> temp_P.y >> temp_D1 >> temp_D2;
                
                result.PushBack(new elipse(temp_P, temp_D1, temp_D2));
                break;
                
            case 3:
                inFile >> temp_P.x >> temp_P.y;
                temp_V.PushBack(temp_P);
                inFile >> temp_P.x >> temp_P.y;
                temp_V.PushBack(temp_P);
                
                result.PushBack(new line(temp_V.elemAt(0), temp_V.elemAt(1)));
                temp_V.clear();
                
                break;
        }
    }
    
    inFile.close();
    
    return result;
    
}

void save(OpVector<shape*> SaveThis){
    
    ofstream outFile;
    
    outFile.open(directory);
    
    outFile << SaveThis.NumElemSize() <<endl;
    for (int i=0; i<SaveThis.NumElemSize(); i++){
        outFile << SaveThis.elemAt(i)->SaveAs <<endl;
    }
    
}



