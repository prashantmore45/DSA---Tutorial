//Example.

// #include<iostream>
// using namespace std;

// int main(){
//     int a = 10;
//     int &b = a;
//     b = 25;

//     cout << b << "\n";
//     cout << a << "\n";

//     return 0;
// }

//Use:

#include<iostream>
using namespace std;

void changeA(int &a){
    a = 20;
    cout << a << "\n";

}
int main(){
    int a = 10;
    changeA(a);
    cout << a << "\n";
    return 0;
}