#include<iostream>
using namespace std;

class Car {
    public:
    string name;
    string color;
    int *mileage;

    Car(string name, string color) {
        this->name = name;
        this->color = color;
        mileage = new int; //Dynamic allocation
        *mileage = 12;
    }

    //Custom Copy Constructor for Shallow Copy
    // Car(Car &original) {
    //     cout << "copying original to new \n";
    //     name = original.name;
    //     color = original.color;
    //     mileage = original.mileage;
    // }

    //Custom Copy Constructor for Deep Copy
    Car(Car &original) {
        cout << "copying original to new \n";
        name = original.name;
        color = original.color;
        mileage = new int;
        *mileage = *original.mileage;
    }
}; 

int main() {
    Car c1("SUV 400", "Black");

    Car c2(c1);
    cout << c2.name << endl;
    cout << c2.color << endl;
    cout << *c2.mileage << endl;
    *c2.mileage = 10;

    cout << *c1.mileage << endl;
    return 0;
}