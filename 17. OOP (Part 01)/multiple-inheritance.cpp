#include<iostream>
using namespace std;

class Teacher{
    public:
        int salary;
        string subject;
};

class Student{
    public:
        int roll_no;
        float CGPA;
};

class TeachingAssistant: public Teacher, public Student{
    public:
        string name;
};

int main(){
    TeachingAssistant TA;
    TA.name = "Prashant More";
    TA.salary = 50000;
    TA.subject = "Data Structures";
    TA.roll_no = 48;
    TA.CGPA = 8.29;

    cout << "Name: " << TA.name << endl;
    cout << "Salary: " << TA.salary << endl;
    cout << "Subject: " << TA.subject << endl;
    cout << "Roll No: " << TA.roll_no << endl;
    cout << "CGPA: " << TA.CGPA << endl;

    return 0;
}