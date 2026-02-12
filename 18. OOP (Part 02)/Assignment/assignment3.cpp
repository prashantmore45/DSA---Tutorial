/*
Question 3 : Create a base class Person with attributes name and age.
Derive a class Student from Person and add an additional attribute studentID.
Implement a method displayStudentInfo( ) in the Student class to display all details.

In main function Student class object will be created in this format: 
Student student("Alice", 20, "S12345");

Note - When we initialize an object of a derived class, the base class part has to be 
constructed first.
If we don't initialize it ourselves in the derived class' constructor by calling one of its 
constructors, the compiler will attempt to use the default constructor of the base 
class.
To invoke the parent’s parameterized constructor in Child’s constructor, syntax is :
Child(int x) : Parent(x)
{ …… }
*/


#include<iostream>
using namespace std;

class Person {
    public:
        string name;
        int age;
    
    Person(string name, int age) {
        this->name = name;
        this->age = age;
    }
};

class Student : public Person {
    public:
        string studentID;

    Student(string name, int age, string studentID) : Person(name, age) {
        this->studentID = studentID;
    }

    void studentDetails() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Student ID: " << studentID << endl;
    }
};

int main() {
    Student student("Alice", 20, "S12345");
    student.studentDetails();
    return 0;
}