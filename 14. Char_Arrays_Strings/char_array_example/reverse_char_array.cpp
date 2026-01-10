#include <iostream>
// #include <cstring>
using namespace std;

void reverseCharArray(char arr[], int n) {
    int start = 0;
    int end = n - 1;
    while (start < end) {
        // Swap characters
        // char temp = arr[start];
        // arr[start] = arr[end];
        // arr[end] = temp;

        swap(arr[start], arr[end]);

        start++;
        end--;
    }
}

int main() {
    char arr[] = "HelloWorld";
    int n = 10;

    reverseCharArray(arr, n);
    // reverseCharArray(arr, strlen(arr));

    cout << "Reversed array: " << arr << endl;
    return 0;
}