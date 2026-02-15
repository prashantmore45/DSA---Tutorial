#include<iostream>
using namespace std;

int FriendsPairing(int n) {

    if (n == 1 || n == 2) {
        return n;
    }

    return FriendsPairing(n-1) + ((n-1) * FriendsPairing(n-2));
}

int main() {
    cout << FriendsPairing(3) << endl;
    return 0;
}