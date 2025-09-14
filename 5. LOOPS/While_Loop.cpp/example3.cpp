//Print the digits of a given number in reverse using while loop:

#include<iostream>
using namespace std;

int main(){
    int n = 10829;
    int lastdig;
    while(n>0){
        lastdig = n % 10;
        cout<<lastdig<<endl;
        n /= 10;
    }
    return 0;

}