/*Write a function to check if a number is a palindrome in C++. 
(121 is a palindrome, 321 is not) 
A number is called a palindrome if the number is equal to the reverse of a number. 
Eg : 121 is a palindrome because the reverse of 121 is 121 itself. On the other hand, 321 
is not a palindrome because the reverse of 321 is 123, which is not equal to 321. 
*/


#include <iostream>
using namespace std;

int reverse(int n) {
    int res = 0;
    while (n > 0) {
        int lastdig = n % 10;
        res = res * 10 + lastdig;
        n = n / 10;
    }
    return res;
}

bool isPalindrome(int num) {
    return num == reverse(num); // Check if original number is equal to its reverse
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (isPalindrome(num)) {
        cout << num << " is a palindrome." << endl;
    } else {
        cout << num << " is not a palindrome." << endl;
    }

    return 0;
}


