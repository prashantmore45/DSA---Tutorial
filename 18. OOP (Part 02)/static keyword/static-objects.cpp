#include<iostream>
using namespace std;

class Example {
    public:

        Example() {
            cout << "constructor..\n";
        }

        ~Example() {
            cout << "destructor..\n";
        }
};

int main() {
    int x = 0;
    if(x == 0) {
        static Example eg1;
    }

    cout << "code ending..";
    return 0;
}