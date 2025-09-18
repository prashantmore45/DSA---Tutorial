#include<iostream>
using namespace std;

int sum(int a, int b){
    cout << a + b <<endl;
    return a + b;
}
int sum(double a, double b){
    cout << a + b << endl;
    return a + b;

}
int sum(int a, int b, int c){
    cout << a + b + c << endl;
    return a + b + c;
}

int main(){

    sum(5, 7);
    sum(5.6, 4.5);
    sum(4, 5, 6);
    
    return 0;
}