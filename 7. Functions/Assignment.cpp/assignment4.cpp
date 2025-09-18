//  Write a function that prints the largest of 3 numbers.

#include <iostream>
using namespace std;

int largest(int a, int b, int c){

    if (a >= b && a >= c){

        cout << " Largest is " << a <<endl;
        return a;

    }else if (b >= c){
        cout << " Largest is " << b << endl;
        return b;

    }else{
        cout << " Largest is " << c << endl;        
        return c;
    }


}
int main(){
    largest(5, 3, 6);
    return 0;
}