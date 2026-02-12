#include<iostream>
using namespace std;

class Print {
    public:
        void show(int n) {
            cout << "int: "<< n << endl;
        }

        void show(string str) {
            cout << "string: "<< str << endl;
        }

};

int main() {
    Print p1;
    p1.show(4);
    p1.show("Prashant");
    return 0;
}