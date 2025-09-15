//Print Inverted Star Pattern.

#include<iostream>
using namespace std;

int main(){

    int n=4;

    for(int i=n; i>=1; i--){
        for(int j=i; j>=1; j--){
            cout << "* ";

        }
        cout << endl;
    }
    
    //OR

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n-i+1; j++){
            cout << "* ";

        }
        cout << endl;
    }
    


    return 0;
}