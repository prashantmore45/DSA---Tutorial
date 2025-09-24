#include<iostream>
using namespace std;

void func(int mat[][4], int n, int m){

    cout << "0th row pointer: " << mat << endl;
    cout << "1st row pointer: " << mat + 1 << endl;
    cout << "2nd row pointer: " << mat + 2 << endl;
    cout << "3rd row pointer " << mat + 3 << endl;

    cout << "0th row value: " << *mat << endl;
    cout << "0th row value: " << *(mat + 1) << endl;
    cout << "0th row value: " << *(mat + 2) << endl;
    cout << "0th row value: " << *(mat + 3) << endl;

    cout << *(*(mat + 2) + 2) << endl;
    
}

void fuct2(int (*mat)[4], int n, int m){

}

int main(){

    int mat[4][4] = { {1, 2, 3, 4},
                      {5, 6, 7, 8},
                      {9, 10, 11, 12},
                      {13, 14, 15, 16}};
    func(mat, 4, 4);

    return 0;
}