#include <iostream>
using namespace std;

class Student {
    public:
        string name;
        float cgpa;

        void getPercentage() {
            cout << "Percentage: " << ((12 * cgpa) - 25) << "%" << endl;
        }
};

int main() {
    Student s1;
    s1.name = "Prashant More";
    s1.cgpa = 8.29;
    s1.getPercentage();
    return 0;   
}