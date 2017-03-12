//
// Created by blue on 16-12-9.
//

#ifndef COMPLEXCLASS_COMPLEX_H
#define COMPLEXCLASS_COMPLEX_H

#include "iostream"
#include "sstream"
#include <string>

class Complex {
private:
    double realPart;
    double virtualPart;

public:
    Complex add(const Complex &c);
    Complex subtract(const Complex &c);
    Complex multiply(const Complex &c);
    Complex divide(const Complex &c);
    double abs();
    std::string toString();

public:
    Complex operator+(const Complex &c);
    Complex operator-(const Complex &c);
    Complex operator*(const Complex &c);
    Complex operator/(const Complex &c);
    Complex operator+=(const Complex &c);
    Complex operator-=(const Complex &c);
    Complex operator*=(const Complex &c);
    Complex operator/=(const Complex &c);
    double operator[](const int &index);
    Complex operator+();
    Complex operator-();
    Complex operator++(); //前置版本
    Complex operator--(); //前置版本
    Complex operator++(int t); //后置版本
    Complex operator--(int t); //后置版本
    friend std::ostream& operator<<(std::ostream &os,const Complex &c); //输出运算附
    friend std::istream& operator>>(std::istream &is,Complex c); //输入运算符

public:
    Complex();
    Complex(double realPart);

    Complex(double realPart, double virtualPart);

    double getRealPart() const;

    void setRealPart(double realPart);

    double getVirtualPart() const;

    void setVirtualPart(double virtualPart);

};


#endif //COMPLEXCLASS_COMPLEX_H
