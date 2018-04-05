
#include "complex.h"

// CONSTRUCTORS
complex:: complex(){
    im = 0;
    re = 0;
}
complex:: complex(double a, double b){
    re = a;
    im = b;
}
complex:: complex(double a){
    re = a;
    im = 0;
}



// GETTERS
double complex:: getR()const{
    return re;
}
double complex:: getI()const{
    return im;
}


// OPERATORS
// INCREMENTATION
complex complex:: operator ++(){
    re = re+1;
    
    return *this;
}
complex complex:: operator ++(int n){
    im = im+1;
    
    return *this;
}
complex complex:: operator --(){
    re = re-1;
    
    return *this;
}
complex complex:: operator --(int n){
    im = im-1;
    
    return *this;
}

// ADDITION
complex complex :: operator + (const complex& temp)const{
    complex result;
    result.re = re + temp.re;
    result.im = im + temp.im;
    return result;
}
complex complex :: operator + (double temp)const{
    complex result;
    result.re = re + temp;
    result.im = im;
    return result;
}
complex operator + (double temp1, const complex& temp2){
    complex result;
    result = temp2 + temp1;
    return result;
}

void complex:: operator += (double temp){
    re += temp;
}
void complex:: operator += (const complex& temp){
    re += temp.getR();
    im += temp.getI();
}

// SUBTRACTION
complex complex :: operator - (const complex& temp)const{
    complex result;
    result.re = re - temp.re;
    result.im = im - temp.im;
    return result;
}
complex complex :: operator - (double temp)const{
    complex result;
    result.im = im;
    result.re= re-temp;
    return result;
}
complex operator - (double temp1, const complex& temp2){
    complex result;
    result.re = temp1 - temp2.re;
    result.im = -temp2.im;
    return result;
}
void complex:: operator -= (double temp){
    re -= temp;
}
void complex:: operator -= (const complex& temp){
    re -= temp.getR();
    im -= temp.getI();
}

// MULTIPLICATION
complex complex :: operator * (const complex& temp)const{
    complex result;
    result.re = (re * temp.re) - (im * temp.im);
    result.im = (re * temp.im) + (im * temp.re);
    return result;
}
complex complex :: operator * (double temp)const{
    complex result;
    result.re = temp* re;
    result.im = temp* im;
    return result;
}
complex operator * (double temp1, const complex& temp2){
    complex result;
    result = temp2 * temp1;
    return result;
}

// DIVISION
complex complex:: operator/(const complex& temp)const{
    complex result(re, im);
    result = result * temp.conjugate() * temp.mod(-2);
    return result;
}
complex complex:: operator/(double temp)const{
    complex result(re, im);
    result = result * pow(temp, -1);
    return result;
}
complex operator/(double temp1, const complex& temp2){
    complex result;
    result  = (temp1 * temp2.conjugate()) * (temp2.mod(-2));
    return result;
}

// OTPUT
ostream& operator << (ostream& out, const complex& temp){
    if (temp.im > 0 && temp.re != 0){
        out << temp.re << "+"<< temp.im << "i";
    }else if(temp.im != 0 && temp.re == 0){
        out << temp.im << "i";
    }else if(temp.im < 0 && temp.re != 0){
        out << temp.re << "-"<<-temp.im << "i";
    }else {
        out << temp.re;
    }
    return out;
}

// COMPARE OPERATORs
bool complex:: operator == (const complex& temp)const{
    if (re == temp.re && im == temp.im){
        return true;
    }else {
        return false;
    }
}
bool complex:: operator != (const complex& temp)const{
    if (re == temp.re && im == temp.im){
        return false;
    }else{
        return true;
    }
}
bool complex:: operator > (const complex& temp)const{
    if (mod() > temp.mod())
        return true;
    else
        return false;
}
bool complex:: operator >= (const complex& temp)const{
    if (mod() >= temp.mod())
        return true;
    else
        return false;
}
bool complex:: operator < (const complex& temp)const{
    if(mod() < temp.mod())
        return true;
    else
        return false;
}
bool complex:: operator <= (const complex& temp)const{
    if(mod() <= temp.mod())
       return true;
    else
        return false;
}

complex& complex:: operator = (double temp){
    re = temp;
    im = 0;
    
    return *this;
}

//METHODS
double complex:: mod()const{
    double result;
    result = re * re + im * im;
    result = pow(result, 0.5);
    return result;
}
double complex:: mod(double power)const{
    double result;
    result = re * re + im * im;
    result = pow(result, power*0.5);
    return result;
}
double complex :: arg()const{
    if (re >=0){
        return arcsin(im*mod(-1));
    }
    else if(im >=0){
        return arccos(re*mod(-1));
    }
    else{
        return -arccos(re*mod(-1));
    }
}
complex complex :: c_arg()const{
    
    return (*this)*mod(-1);
}
complex complex:: conjugate()const{
    complex result;
    result.im = -im;
    result.re = re;
    return result;
}


//EXTRAS
complex exp(const complex& temp){
    complex result;
    result = exp(temp.getR()) * (cos(temp.getI()) + sin(temp.getI())*i);
    return result;
}
complex log(const complex& temp){
    complex result(log(temp.mod()), temp.arg());
    return result;
}
complex sin(const complex& temp){
    complex result;
    result = sin(temp.getR()) * cosh(temp.getI()) + sinh(temp.getI())*cos(temp.getR()) * i;
    return result;
}
complex sinh(const complex& temp){
    return 0.5*exp(temp) - 0.5*exp(-1*temp);
}
complex cos(const complex& temp){
    complex result;
    result = cos(temp.getR()) * cosh(temp.getI()) - sin(temp.getR()) * sinh(temp.getI()) *i;
    return result;
}
complex cosh(const complex& temp){
    return 0.5*exp(temp) + 0.5*exp(-1*temp);
}
complex pow(const complex& temp, double power){
    double magnitude = temp.mod(power);
    double angle = temp.arg()*power;
    return magnitude * exp(i*angle);
}
complex pow(const complex& temp, const complex& power){
    double magnitude = temp.mod(power.getR())*exp(-temp.arg()*power.getI());
    double angle = temp.arg()*power.getR();
    angle += log(temp.mod())*power.getI();
    return magnitude*exp(i*angle);
}
complex pow(double temp, const complex& power){
    double magnitude = pow(temp, power.getR());
    double angle = log(temp) * power.getI();
    return magnitude * exp(i*angle);
}
complex zeta(const complex& temp){
    complex result;
    for (int i = 1; i<100000000; i++){
        result = result + pow(i, -1*temp);
    }
    return result;
}
double arcsin(const double temp){
    if (temp > 1 || temp < -1){
        cout << "ERROR!!";
        return 0;
    }
    double value=0;
    for (double i = 1; i<1000; i++){
        if (sin(value) == temp){
            return value;
        }
        else if (sin(value) < temp){
            value = value + pi * pow(2, -i);
        }
        else{
            value = value - pi * pow(2, -i);
        }
    }
    return value;
}
double arcsinh(const double temp){
    double value = 0;
    bool boysOut = 1;
    int i = 0;
    while (boysOut){
        if (temp <= sinh(14*(i+1)) && temp >= sinh(14*i)){
            boysOut = 0;
            value = 14*i + 7;
        }else if (temp < -1*sinh(14*i) && temp > -1*sinh(14*(i+1))){
            boysOut = 0;
            value = -14*i - 7;
        }
        i++;
    }
    for (double i = 1; i<10000000; i++){
        if (sinh(value) == temp){
            return value;
        }
        else if (sinh(value) < temp){
            value = value + pow(i, -1);
        }
        else {
            value = value - pow(i, -1);
        }
    }
    return value;
}
double arccos(const double temp){
    if (temp > 1 || temp < -1){
        cout << "ERROR!!";
    }
    double value=pi*0.5;
    for (double i = 1; i<1000; i++){
        if (cos(value) == temp){
            return value;
        }
        else if (cos(value) < temp){
            value = value - pi * pow(2, -i);
        }
        else{
            value = value + pi * pow(2, -i);
        }
    }
    return value;
}


