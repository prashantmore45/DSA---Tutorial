/*
Question 1 : Create a class to store Complex numbers. Using operator overloading, 
create the logic to subtract one complex number from another.

Note - In Complex numbers, the real part of 1st gets subtracted from the real part of 
2nd number. Same goes for the imaginary part.
*/

#include<iostream>
using namespace std;

class Complex {
    public:
    int real;
    int img;

    Complex(int r, int i) {
        real = r;
        img = i;
    }

    void showNum() {
        cout << "( " << real << " )" << " - " << "( " << img << " )" << "i" << endl;
    }

    void operator - (Complex &c2) {
        int resReal =  c2.real - this->real;
        int resImg =  c2.img - this->img;
        Complex c3(resReal, resImg);
        cout << "Result = ";
        c3.showNum();
    }
};

int main() {
    Complex c1(3, 4);
    Complex c2(1, 2);

    c1.showNum();
    c2.showNum();

    c1 - c2;
    return 0;
}