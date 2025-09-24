#include<iostream>
using namespace std;

//Time complexity: O(n^2)

int diaginalSum(int mat[][4], int n, int m){

    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == j)
            {
                sum += mat[i][j];
            }
            else if ( j == n-i-1)
            {
                sum += mat[i][j];
                
            }
            
            
        }
        
    }

    cout << "Sum = " << sum << endl;
    return sum;

    
}

//Another way to solve the problem: O(n) time complexity

void diagonalSum1(int mat[][4], int n, int m){
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += mat[i][i];
        
        if (i!=n-i-1){
            sum += mat[i][n-i-1];
        }

    }
    cout << "Sum = " << sum << endl;

}

int main(){

    int matrix[4][4] = {{1, 2, 3, 4},
                        {5, 6, 7, 8},
                        {9, 10, 11, 12},
                        {13, 14, 15, 16}};
    diaginalSum(matrix, 4, 4);

    diagonalSum1(matrix, 4, 4);

    return 0;
}