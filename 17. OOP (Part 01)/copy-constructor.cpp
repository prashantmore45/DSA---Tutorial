#include<iostream>
using namespace std;

class Car {
    public:
    string name;
    string color;

    Car(string name, string color) {
        this->name = name;
        this->color = color;
    }

    //Custom Copy Constructor
    Car(Car &original) {
        cout << "copying original to new \n";
        name = original.name;
        color = original.color;
    }
}; 

int main() {
    Car c1("SUV 400", "Black");
    Car c2(c1);

    cout << c2.name << endl;
    cout << c2.color << endl;
    return 0;
}