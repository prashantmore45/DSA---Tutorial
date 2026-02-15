//Print all Binary Strings of size of N without any consecutive 1s

#include<iostream>
using namespace std;

//Method 1 
void printBinStrings(int n, int lastPlace, string ans) {

    if (n == 0) {
        cout << ans << endl;
        return;
    }

    if (lastPlace != 1) {
        printBinStrings(n-1, 0, ans + "0");
        printBinStrings(n-1, 1, ans + "1");
    } else {
        printBinStrings(n-1, 0, ans + "0");
    }
}

//Method 2
// void printBinStrings(int n, string ans) {

//     if (n == 0) {
//         cout << ans << endl;
//         return;
//     }

//     if (ans[ans.size() - 1] != '1') {
//         printBinStrings(n-1, ans + "0");
//         printBinStrings(n-1,ans + "1");
//     } else {
//         printBinStrings(n-1, ans + "0");
//     }
// }


int main() {
    string ans = "";
    printBinStrings(3, 0, ans); //Method 1 call
    cout << "\n";
    //printBinStrings(3, ans); //Method 2 call
    return 0;
}