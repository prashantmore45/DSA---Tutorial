#include<iostream>
using namespace std;

int main() {
    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    int* *matrix = new int*[rows]; // Dynamically allocate array of pointers

    for (int i=0; i<rows; i++) {
        matrix[i] = new int[cols]; // Dynamically allocate each row
    }

    //Data store
    int x = 1;
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            matrix[i][j] = x;
            x++;
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << matrix[2][2] << endl;
    cout << *(*(matrix + 2) + 2) << endl;

    return 0;    
}