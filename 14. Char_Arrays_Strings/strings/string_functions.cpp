#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char str1[20] = "Hello, ";
    char str2[] = "World!";

    strcpy(str1, str2);
    cout << "After strcpy, str1: " << str1 << endl;

    strcpy(str1, "Hello, ");   // restore original
    strcat(str1, str2);
    cout << "After strcat, str1: " << str1 << endl;

    int result = strcmp(str1, str2);
    cout << "After strcmp, result: " << result << endl;

    return 0;
}
