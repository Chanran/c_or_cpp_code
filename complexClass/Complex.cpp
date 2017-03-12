//
// Created by blue on 16-12-9.
//

#include "iostream"
#include "sstream"
#include "Complex.h"
#include <math.h>

/*方法*/
Complex Complex:: add(const Complex &c){
    Complex temp;
    temp.setRealPart(Complex::getRealPart()+c.getRealPart());
    temp.setVirtualPart(Complex::getVirtualPart()+c.getVirtualPart());
    return temp;
}
Complex Complex::subtract(const Complex &c){
    Complex temp;
    temp.setRealPart(Complex::getRealPart()-c.getRealPart());
    temp.setVirtualPart(Complex::getVirtualPart()-c.getVirtualPart());
    return temp;
}
Complex Complex::multiply(const Complex &c){
    Complex temp;
    temp.setRealPart(Complex::getRealPart()*c.getRealPart()-Complex::getVirtualPart()*c.getVirtualPart());
    temp.setVirtualPart(Complex::getVirtualPart()*c.getRealPart()+Complex::getRealPart()*c.getVirtualPart());
    return temp;
}
Complex Complex::divide(const Complex &c){
    Complex temp;
    temp.setRealPart((Complex::getRealPart()*c.getRealPart()+Complex::getVirtualPart()*c.getVirtualPart())/(pow(c.getRealPart(),2)+pow(c.getVirtualPart(),2)));
    temp.setVirtualPart((Complex::getVirtualPart()*c.getRealPart()-Complex::getRealPart()*c.getVirtualPart())/(pow(c.getRealPart(),2)+pow(c.getVirtualPart(),2)));
    return temp;
}
double Complex::abs(){
    return sqrt(pow(Complex::getRealPart(),2)+pow(Complex::getVirtualPart(),2));
}
std::string Complex::toString(){
    std::ostringstream ostring;

    if (Complex::getVirtualPart() == 0){
        ostring << Complex::getRealPart();
    }else if (Complex::getVirtualPart() < 0){
        ostring << Complex::getRealPart() << "-" << fabs(Complex::getVirtualPart()) << "i";
    }else{
        ostring << Complex::getRealPart() << "+" << Complex::getVirtualPart() << "i";
    }

    return ostring.str();
}

/*运算符重载*/
Complex Complex::operator+(const Complex &c){
    Complex tmp;
    tmp.setRealPart(Complex::getRealPart()+c.getRealPart());
    tmp.setVirtualPart(Complex::getVirtualPart()+c.getVirtualPart());
    return tmp;
}
Complex Complex::operator-(const Complex &c){
    Complex tmp;
    tmp.setRealPart(Complex::getRealPart()-c.getRealPart());
    tmp.setVirtualPart(Complex::getVirtualPart()-c.getVirtualPart());
    return tmp;
}
Complex Complex::operator*(const Complex &c){
    Complex tmp(Complex::getRealPart(),Complex::getVirtualPart());
    tmp.setRealPart(Complex::getRealPart()*c.getRealPart()-Complex::getVirtualPart()*c.getVirtualPart());
    tmp.setVirtualPart(Complex::getVirtualPart()*c.getRealPart()+Complex::getRealPart()*c.getVirtualPart());
    return tmp;
}
Complex Complex::operator/(const Complex &c){
    Complex temp;
    temp.setRealPart((Complex::getRealPart()*c.getRealPart()+Complex::getVirtualPart()*c.getVirtualPart())/(pow(c.getRealPart(),2)+pow(c.getVirtualPart(),2)));
    temp.setVirtualPart((Complex::getVirtualPart()*c.getRealPart()-Complex::getRealPart()*c.getVirtualPart())/(pow(c.getRealPart(),2)+pow(c.getVirtualPart(),2)));
    return temp;
}
Complex Complex::operator+=(const Complex &c){
    double a = Complex::getRealPart();
    double b = Complex::getVirtualPart();
    Complex::setRealPart((a*c.getRealPart()+b*c.getVirtualPart())/(pow(c.getRealPart(),2)+pow(c.getVirtualPart(),2)));
    Complex::setVirtualPart((b*c.getRealPart()-a*c.getVirtualPart())/(pow(c.getRealPart(),2)+pow(c.getVirtualPart(),2)));
    return *this;
}
Complex Complex::operator-=(const Complex &c){
    double a = Complex::getRealPart();
    double b = Complex::getVirtualPart();
    Complex::setRealPart(a-c.getRealPart());
    Complex::setVirtualPart(b-c.getVirtualPart());
    return *this;
}
Complex Complex::operator*=(const Complex &c){
    double a = Complex::getRealPart();
    double b = Complex::getVirtualPart();
    Complex::setRealPart(a*c.getRealPart()-b*c.getVirtualPart());
    Complex::setVirtualPart(b*c.getRealPart()+a*c.getVirtualPart());
    return *this;
}
Complex Complex::operator/=(const Complex &c){
    double a = Complex::getRealPart();
    double b = Complex::getVirtualPart();
    Complex::setRealPart((a*c.getRealPart()+b*c.getVirtualPart())/(pow(c.getRealPart(),2)+pow(c.getVirtualPart(),2)));
    Complex::setVirtualPart((a*c.getRealPart()-b*c.getVirtualPart())/(pow(c.getRealPart(),2)+pow(c.getVirtualPart(),2)));
    return *this;
}
double Complex::operator[](const int &index){
    if (index == 0){
        return Complex::getRealPart();
    }else if(index == 1){
        return Complex::getVirtualPart();
    }else{
        std::cout << "Invalid Index." << std::endl;
    }
}
Complex Complex::operator+(){
    Complex::setRealPart(fabs(Complex::getRealPart()));
    Complex::setVirtualPart(fabs(Complex::getVirtualPart()));
    return *this;
}
Complex Complex::operator-(){
    Complex::setRealPart(-Complex::getRealPart());
    Complex::setVirtualPart(-Complex::getVirtualPart());
    return *this;
}
Complex Complex::operator++(){ //前置版本
    Complex::setRealPart(Complex::getRealPart()+1);
    Complex::setVirtualPart(Complex::getRealPart()+1);
    return *this;
}
Complex Complex::operator--(){ //前置版本
    Complex::setRealPart(Complex::getRealPart()-1);
    Complex::setVirtualPart(Complex::getRealPart()-1);
    return *this;
}
Complex Complex::operator++(int t){ //后置版本
    Complex tmp(Complex::getRealPart(),Complex::getVirtualPart());
    this->setRealPart(this->getRealPart()+1);
    this->setVirtualPart(this->getVirtualPart()+1);
    return tmp;
}
Complex Complex::operator--(int t){ //后置版本
    Complex tmp(Complex::getRealPart(),Complex::getVirtualPart());
    this->setRealPart(this->getRealPart()-1);
    this->setVirtualPart(this->getVirtualPart()-1);
    return tmp;
}

/*输入输出重载*/
std::ostream& operator<<(std::ostream &os,const Complex &c){ //输出运算符
    if (c.getVirtualPart() > 0){
        os << c.getRealPart() << "+" << c.getVirtualPart() << "i";
    }else if(c.getVirtualPart() == 0){
        os << c.getRealPart();
    }else{
        os << c.getRealPart() << "-" << fabs(c.getVirtualPart()) << "i";
    }
    return os;
}
std::istream& operator>>(std::istream &is,Complex c){ //输入运算符
    double t1,t2;
    is >> t1 >> t2;
    c.setRealPart(t1);
    c.setVirtualPart(t2);
    return is;
}

/*构造函数,getter,setter*/
Complex::Complex() {
    Complex::realPart = 0;
    Complex::virtualPart = 0;
}

Complex::Complex(double realPart) : realPart(realPart) {
    Complex::realPart = realPart;
    Complex::virtualPart = 0;
}

Complex::Complex(double realPart, double virtualPart) : realPart(realPart), virtualPart(virtualPart) {
    Complex::realPart = realPart;
    Complex::virtualPart = virtualPart;
}


double Complex::getRealPart() const {
    return realPart;
}

void Complex::setRealPart(double realPart) {
    Complex::realPart = realPart;
}

double Complex::getVirtualPart() const {
    return virtualPart;
}

void Complex::setVirtualPart(double virtualPart) {
    Complex::virtualPart = virtualPart;
}
