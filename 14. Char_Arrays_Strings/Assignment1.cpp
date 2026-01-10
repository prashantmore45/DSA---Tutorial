/*Question 1 : Count how many times lowercase vowels occurred in a String entered 
by the user.  */

#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    int count = 0;

    cout << "Enter a string: ";
    getline(cin, str);
    
    for (char c : str) {
        if (c == 'a' || c == 'e' || c == 'i' ||
            c == 'o' || c == 'u') {
            count++;
        }
    }

    cout << "Number of lowercase vowels: " << count << endl;
    return 0;
}
