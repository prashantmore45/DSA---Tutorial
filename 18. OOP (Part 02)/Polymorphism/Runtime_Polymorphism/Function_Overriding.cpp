#include<iostream>
using namespace std;

class Parent {
    public:
        void show() {
            cout << "parent class show..\n";
        }
};

class Child : public Parent {
    public:
        void show() {
            cout << "child class show..\n";
        }
};

int main() {
    Child childobj;
    childobj.show();
    return 0;
}