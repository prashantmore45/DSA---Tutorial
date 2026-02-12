#include<iostream>
using namespace std;

class Shape {
    public:
    virtual void draw() = 0;
};

class Circle : public Shape {
    public:
        void draw() {
            cout << "draw circle\n";
        }
};

class Square : public Shape {
    public:
        void draw() {
            cout << "draw square\n";
        }
};

int main() {
    Circle circle;
    circle.draw();

    Square square;
    square.draw();
    return 0;
}