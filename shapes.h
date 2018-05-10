#ifndef shapes_h
#define shapes_h

#include "OpVector.h"
struct point{
    int x;
    int y;
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
    
    
    int LineWeight;
    double Rotation;
    int LineColor_R;
    int LineColor_G;
    int LineColor_B;
    
    
    int FillColor_R;
    int FillColor_G;
    int FillColor_B;

    shape(int input, int weight, double rot, int LR, int LG, int LB, int FR, int FG, int FB){
        ID = input;
        setWeight(weight);
        setRotation(rot);
        setFill(FR, FG, FB);
        setLine(LR, LG, LB);
    }
    
    
    
public:
    
    
    
    friend void save(OpVector<shape*> SaveThis);
    
    
    virtual void move(const point& shift){};
    
    void setFill(int R, int G, int B){
        FillColor_R = R;
        FillColor_G = G;
        FillColor_B = B;
    }
    void setLine(int R, int G, int B){
        LineColor_R = R;
        LineColor_G = G;
        LineColor_B = B;
    }
    void setWeight(int weight){
        LineWeight = weight;
    }
    void setRotation(double rot){
        Rotation = rot;
    }
    
    
    virtual void draw()const{};
    virtual double area()const{return 0;};
    virtual double perimeter()const{return 0;};
    virtual void setMessege(string messege){};
    virtual string getMessege(){return string();};
    int getID()const{return ID;};
    
    bool operator == (const shape& rhs)const{
        if (ID == rhs.ID)
            return true;
        else return false;
    }
    
    bool operator != (const shape& rhs)const{
        return !(*this == rhs);
    }
};


class polygon: public shape{
    OpVector<point> P;
    void operator + (const point& temp);

public:
    polygon();
    polygon(const OpVector<point>& temp, int temp_weight, double temp_rotation, int color1, int color2, int color3, int colorF1, int colorF2, int colorF3);
    
    virtual void move(const point& shift);
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
    elipse(const point& c, double r, int temp_weight, double temp_rotation, int color1, int color2, int color3, int colorF1, int colorF2, int colorF3);
    elipse(const point& c, double r1, double r2, int temp_weight, double temp_rotation, int color1, int color2, int color3, int colorF1, int colorF2, int colorF3);
    
    virtual void move(const point& shift);
    virtual void draw()const{};
    virtual double area()const;
    virtual double perimeter()const;
};

class line: public shape{
    point a, b;
public:
    line();
    line(const point& temp1, const point& temp2, int temp_weight, double temp_rotation, int color1, int color2, int color3, int colorF1, int colorF2, int colorF3);
    
    virtual void move(const point& shift);
    virtual void draw()const{};
    virtual double perimeter()const;
};

class text: public shape{
    point LTcorner;
    string Mes;
public:
    text ();
    text(string messege, const point& temp, int temp_weight, double temp_rotation, int color1, int color2, int color3, int colorF1, int colorF2, int colorF3);
    
    virtual void move(const point& shift);
    virtual void setMessege(string messege);
    virtual string getMessege();
    virtual void draw()const{}
};

class polyline: public shape{
    OpVector<point> P;
public:
    polyline();
    polyline(const OpVector<point> temp, int temp_weight, double temp_rotation, int color1, int color2, int color3, int colorF1, int colorF2, int colorF3);
    
    virtual void move(const point& shift);
    virtual void draw()const{}
};


class rectangle: public shape{
    point LTcorner;
    double w, l;
    
public:
    rectangle();
    rectangle(const point& temp, double width, double length, int temp_weight, double temp_rotation, int color1, int color2, int color3, int colorF1, int colorF2, int colorF3);
    
    virtual void move(const point& shift);
    virtual void draw() const{}
    virtual double area()const {return (w*l);}
    virtual double perimeter()const {return 2*(w+l);}
};




OpVector<shape*> read();


OpVector<shape*> sort(const OpVector<shape*>& rhs, bool (*algorithm)(shape* temp1, shape* temp2));

bool sortByPerimeter(shape* temp1, shape* temp2);
bool sortByArea(shape* temp1, shape* temp2);




#endif /* shapes_h */
