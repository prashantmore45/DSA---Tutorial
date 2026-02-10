 #include<iostream>
 using namespace std;

bool isPowerOfTwo(int num) {
    if (!(num & (num - 1))) {
        return true;
    } else {
        return false;
    }
}

 int main() {
    cout << isPowerOfTwo(4) << endl; // Output: 1 (true)
    cout << isPowerOfTwo(16) << endl; // Output: 1 (true)
    cout << isPowerOfTwo(13) << endl; // Output: 0 (false)
    cout << isPowerOfTwo(7) << endl; // Output: 0 (false)
    cout << isPowerOfTwo(18) << endl; // Output: 0 (false)
    return 0;
 }