#include<iostream>
#include<vector>
using namespace std;

//Recursion

int lcsRec(string str1, string str2) {
    int n = str1.size();
    int m = str2.size();

    if (n == 0 || m == 0) {
        return 0;
    }

    if (str1[n-1] == str2[m-1]) {
        return lcsRec(str1.substr(0, n-1), str2.substr(0, m-1)) + 1;
    } else {
        int ans1 = lcsRec(str1.substr(0, n-1), str2);
        int ans2 = lcsRec(str1, str2.substr(0, m-1));

        return max(ans1, ans2);
    }
}


int main() {
    string str1 = "abcdge";
    string str2 = "abedg";

    cout << lcsRec(str1, str2) << endl; //4

    return 0;
}