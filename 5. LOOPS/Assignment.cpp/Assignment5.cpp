/* For a positive N , WAP that prints the first N Fibonacci numbers. 
(Assume N >= 2*/

#include<iostream>
using namespace std;

int main(){

    int n;
    cout << "ENter a number:";
    cin >> n;

    int first = 0, sec = 1; 
    cout << first << " " << sec << " "; 
 
 
    for(int i=2; i<n; i++) { 
        int third = first + sec; 
        cout << third << " "; 
        first = sec; 
        sec = third;
    }
    cout << "\n";
    return 0;
       
}