#include<iostream>
using namespace std;

class Student {
    string name;
    float cgpa;

    void getPercentage() {
        cout << "Percentage: " << (cgpa * 10) << "%" << endl;
    }
};

int main() {
    Student s1;
    return 0;
}