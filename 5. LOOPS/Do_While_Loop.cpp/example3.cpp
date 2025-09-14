//Wap to show number entered by user except multiples of 10:

#include<iostream>
using namespace std;

int main(){
    int n;
    do {
        cout<<"Enter Number : ";
        cin>>n;
        if (n % 10 == 0){
            continue;
        }
        cout<<"You Entered "<< n <<endl;

    }while (true);
    return 0;
}