#include <iostream>
using namespace std;

class Animal {
    public:
        
        void Eat() {
            cout << "eats\n";
        }

        void Breathe() {
            cout << "breathes\n";
        }

};

class Mamals : public Animal {
    public:
        string bloodType;

        Mamals() {
            bloodType = "worm";
        }
};

class Dog : public Mamals {
    public: 

    void TailWag() {
        cout << "A dog wags its tail\n";
    }
};

int main() {
    Dog d1;
    d1.TailWag();
    cout << d1.bloodType << endl;
    d1.Breathe();
    d1.Eat();

    return 0;
}