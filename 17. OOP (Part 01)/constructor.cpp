#include<iostream>
using namespace std;

class Car {
    private:
        string name;
        string color;

    public:

        // Non-Parametrized Constructor
        Car() {
            cout << "constructor without parameters" << endl;
        }

        // Parametrized Constructor
        Car(string name, string color) {
            this -> name = name;
            this -> color = color;
            cout << "construtor with parameters" << endl;
        }

        void start() {
            cout << "Car has started..." << endl;
        }

        void stop() {
            cout << "Car is stopped" << endl;
        }

        //Getter

        string getName() {
            return name;
        }

        string getColor() {
            return color;
        }
};

int main() {
    Car c0;
    Car c1("SUV 200", "BLACK");
    
    c1.start();
    c1.stop();
    cout << "Name: " << c1.getName() << endl;
    cout << "Color: " << c1.getColor() << endl;
    return 0;
}