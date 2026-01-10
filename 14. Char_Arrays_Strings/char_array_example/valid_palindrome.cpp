#include<iostream>
// #include<cstring> // Uncomment if using strlen
using namespace std;

bool isPalindrome(char str[], int n) {
    int start = 0;
    int end = n - 1;

    while (start < end) {
        if (str[start] != str[end]) {
            return false; // Not a palindrome
        }
        start++;
        end--;
    }
    return true; // Is a palindrome
}

int main() {
    char str[] = "madam";
    int n = 5;
    cout << isPalindrome(str, n) << endl;

    // Alternative test case
    // char str[] = "hello";
    // int n = strlen(str); // Alternatively, use this to get length
    // if (isPalindrome(str, n)) {
    //     cout << "\"" << str << "\" is a palindrome." << endl;
    // } else {
    //     cout << "\"" << str << "\" is not a palindrome." << endl;
    // }

    return 0;
}