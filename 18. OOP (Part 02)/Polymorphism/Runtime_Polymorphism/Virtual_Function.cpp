#include<iostream>
using namespace std;

class Parent {
    public:

        virtual void hello() {
            cout << "parent hello\n";
        }
};

class Child : public Parent {
    public:
        
        void hello() {
            cout << "child hello\n";
        }
};

int main() {
    Child child;
    Parent *ptr;

    ptr = &child;
    ptr->hello();
    return 0;
}