#include <iostream>
#include "Complex.h"

using namespace std;

int main(){

    double a0,a1;
    double b0,b1;
    cout << "Enter the first complex number: " << endl;
    cin >> a0 >> a1;
    cout << "Enter the second complex number:" << endl;
    cin >> b0 >> b1;

    Complex a(a0,a1);
    Complex b(b0,b1);


    cout << "(" << a.toString() << ")" << " + " << "(" << b.toString() << ")" << " = " << (a+b).toString() << endl;
    cout << "(" << a.toString() << ")" << " - " << "(" << b.toString() << ")" << " = " << (a-b).toString() << endl;
    cout << "(" << a.toString() << ")" << " * " << "(" << b.toString() << ")" << " = " << (a*b).toString() << endl;
    cout << "(" << a.toString() << ")" << " / " << "(" << b.toString() << ")" << " = " << (a/b).toString() << endl;
    cout << "|" << a.toString() << "|" << " = " << a.abs() << endl;

    return 0;
}