#include<iostream>
using namespace std;

void spiralMatrix(int mat[][4], int n, int m){

    int srow = 0; int scol = 0;
    int erow = n-1; int ecol = m-1;;

    while(srow<=erow && scol<=ecol){

        //Top row:

        for(int j=srow; j<=ecol; j++){
            cout << mat[srow][j] << ' ';
        }

        //Right Column:

        for(int i=srow+1; i<=erow; i++){
            cout << mat[i][ecol] << " ";

        }

        //Bottom row:

        for(int j=ecol-1; j>=scol; j--){
            if (srow == erow){
                break;
            }
            cout << mat[erow][j] << " ";
        }

        //Left column:

        for(int i=ecol-1; i>=srow+1; i--){
            if (scol == ecol){
                break;
            }
            cout << mat[i][scol] << " ";
        }

        srow++; scol++; 

        erow--; ecol--;

    }
    cout << endl;

}

int main(){

    int matrix[4][4] = {{1, 2, 3, 4},
                        {5, 6, 7, 8},
                        {9, 10, 11, 12},
                        {13, 14, 15, 16}
    };

    spiralMatrix(matrix, 4, 4);

    return 0;

}