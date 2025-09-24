//Question 3 : Write a program to Find Transpose of a Matrix. 

#include<iostream>
using namespace std;

void transposeMatrix(int mat[][3], int n, int m){

    cout << "The original matrix is : " << "\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
        
    }

    cout << "The transpose of the matrix is: " << "\n";

    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n; i++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    
    
}

int main(){

    int matrix[2][3] = {{4, 7, 5},
                        {3, 2, 9}
    };

    transposeMatrix(matrix, 2, 3);

    return 0;

}