#include<iostream>
using namespace std;

class Animal {
public:
    string color;

    void Eat() {
        cout << "eats\n";
    }

    void Breathe() {
        cout << "breathes\n";
    }
};

class Fish : public Animal {
public:
    int fins;

    void Swim() {
        cout << "swims\n";
    }
};


int main() {

    Fish f1;
    f1.color = "white";
    f1.fins = 4;

    cout << f1.color << endl;
    cout << f1.fins << endl;
    f1.Eat();
    f1.Breathe();
    f1.Swim();
    return 0;
}