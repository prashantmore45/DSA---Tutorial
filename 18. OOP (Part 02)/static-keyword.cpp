#include<iostream>
using namespace std;

class Example {
    public:
        static int x;
};

int Example::x = 0;

void Counter() {
    static int count = 0;
    count++;
    cout << "Count: "  << count << endl;
}

int main() {
    Example eg1;
    Example eg2;
    Example eg3;

    cout << eg1.x++ << endl;
    cout << eg2.x++ << endl;
    cout << eg3.x++ << endl;
    cout << "\n";

    Counter();
    Counter();
    Counter();

   return 0; 
}