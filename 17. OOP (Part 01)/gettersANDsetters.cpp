#include<iostream>
using namespace std;


class Student {
    private:
        string name;
        float cgpa;

    public:
        void getPercentage() {
            cout << "Percentage: " << ((12 * cgpa) - 25) << "%" << endl;
        }

        void setName(string nameVal) {
            name = nameVal;
        }

        void setCgpa(float cgpaVal) {
            cgpa = cgpaVal;
        }

        string getName() {
            return name;
        }

        float getCgpa() {
            return cgpa;
        }
    
};

int main() {
    Student s1;
    s1.setName("Prashant");
    s1.setCgpa(8.29);

    cout << "Name: " << s1.getName() << endl;
    cout << "CGPA: " << s1.getCgpa() << endl;
    s1.getPercentage();
    return 0;
}