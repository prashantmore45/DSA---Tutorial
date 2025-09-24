#include<iostream>
using namespace std;

int main(){
    int arr[3][4];
    int n=3; int m=4;

    //Input of the 2D array:

    cout << "Enter the elements of the array: " << endl;

    for(int i=0; i<n; i++){

        for(int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }

    //Output of the 2D array:

    cout << "Output: " << "\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " "; 
        }
        cout << endl; 
    }
    
    return 0;
    
}