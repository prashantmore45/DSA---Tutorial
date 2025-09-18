//Addition of two numbers.

#include<iostream>
using namespace std;

int sum(int a, int b){
    int sum = a + b;
    return sum;

}
int main(){
    int s = sum(34, 45);
    cout << " sum = " << s << endl; 
    return 0;
}
