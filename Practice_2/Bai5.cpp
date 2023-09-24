#include <iostream>
#include <ostream>
#include <iomanip>
#include <math.h>

using namespace std;

struct Complex{
    double real;
    double imag;
};

Complex operator + (Complex a, Complex b){
    return Complex{a.real+b.real, a.imag + b.imag};
}

Complex operator - (Complex a, Complex b){
    return Complex{a.real-b.real, a.imag - b.imag};
}

Complex operator * (Complex a, Complex b){
    return Complex{a.real*b.real - a.imag*b.imag, a.real*b.imag + a.imag*b.real};
}

Complex operator / (Complex a, Complex b){
    double mauso = b.real*b.real + b.imag*b.imag;
    return Complex{(a.real*b.real+a.imag+b.imag)/mauso, (a.imag*b.real-a.real*b.imag)/mauso};
}

ostream& operator<<(ostream& out, const Complex &a){
    out << '(' << setprecision(2) << a.real << (a.imag>=0? '+':'-') << setprecision(2) << fabs(a.imag)<<"i)";
    return out;
}

int main(){
    double real_a, real_b, img_a,img_b;
    cin >> real_a >> img_a;
    cin >> real_b >> img_b;

    Complex a{real_a, img_a};
    Complex b{real_b, img_b};

    cout << a << " + " << b << " = " << a+b <<endl;
    cout << a << " - " << b << " = " << a-b <<endl;
    cout << a << " * " << b << " = " << a*b <<endl;
    cout << a << " / " << b << " = " << a/b <<endl;
}

