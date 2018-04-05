#ifndef complex_h
#define complex_h

#include <iostream>
#include <cmath>

using namespace std;

class complex{
private:
    
    double im;
    double re;
    
public:
    // CONSTRUCTORS
    complex(double a, double b);
    complex();
    complex(double a);
    
    //OPERATORS
    complex operator ++();
    complex operator ++(int n);
    complex operator --();
    complex operator --(int n);
    
    complex operator + (const complex& temp)const;
    complex operator + (double temp)const;
    friend complex operator + (double temp1, const complex& temp2);
    
    void operator += (double temp);
    void operator += (const complex& temp);
    
    complex operator - (const complex& temp)const;
    complex operator - (double temp)const;
    friend complex operator - (double temp1, const complex& temp2);
    
    void operator -= (double temp);
    void operator -= (const complex& temp);
    
    complex operator * (const complex& temp)const;
    complex operator * (double temp)const;
    friend complex operator * (double temp1, const complex& temp2);
    
    complex operator / (const complex& temp)const;
    complex operator / (double temp)const;
    friend complex operator / (double temp1, const complex& temp2);
    
    friend ostream& operator << (ostream& out, const complex& temp);
    
    
    bool operator == (const complex& temp)const;
    bool operator != (const complex& temp)const;
    bool operator > (const complex& temp)const;
    bool operator >= (const complex& temp)const;
    bool operator < (const complex& temp)const;
    bool operator <= (const complex& temp)const;
    
    complex& operator = (double temp);
    
    
    //METHODS
    double mod()const;
    double mod(double power)const;
    double arg()const;
    complex c_arg()const;
    complex conjugate()const;
    double getR()const;
    double getI()const;
}const i(0, 1);


const double pi =3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679;

complex exp(const complex& temp);
complex log(const complex& temp);
complex sin(const complex& temp);
complex sinh(const complex& temp);
complex cosh(const complex& temp);
complex cos(const complex& temp);
complex pow(const complex& temp, double power);
complex pow(const complex& temp, const complex& power);
complex pow(double temp, const complex& power);
complex zeta(const complex& temp);
double arcsin(const double temp);
double arcsinh(const double temp);
double arccos(const double temp);


#endif
