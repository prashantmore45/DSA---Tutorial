/*Question 1 : Print the number of all 7’s that are in the 2d array. 
Example : 
Input - int arr[ ][ ] = { {4,7,8}, {8,8,7} }; n = 2, m = 3 
Output - 2 */

#include<iostream>
using namespace std;

int main(){

    int matrix[2][3] = {{4, 7, 8},
                        {8, 8, 7}};
    int n=2; int m=3;
    int count = 0;

    for (int i = 0; i < n; i++)

    {
        for(int j=0; j<m; j++){

            if (matrix[i][j] == 7){

                count++;


            }
        }

    }
    cout << "Total number of 7's in the matrix is: " << count << endl;
    

    return 0;
}