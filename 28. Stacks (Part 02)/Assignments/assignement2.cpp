/*
Question 2 : Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the 
square brackets is being repeated exactly k times. Note that k is guaranteed to
be a positiveinteger.

You may assume that the input string is always valid; there are no extra white
spaces, square brackets are well-formed, etc. Furthermore, you may assume
that the original data does not contain any digits and that digits are only for 
those repeat numbers, k. For example, there will not be input like 3a or 2[4].

Examples :
Input: s = "3[a]2[bc]"
Output: "aaabcbc"
Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef
*/

#include<iostream>
#include<vector>
using namespace std;

template<class T>
class Stack {
    vector<T> vec;
public:
    void push(T val) {
        vec.push_back(val);
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
        }

        vec.pop_back();
    }

    T top() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
        }

        int lastIdx = vec.size() - 1;
        return vec[lastIdx];
    }

    bool isEmpty() {
        return vec.size() == 0;
    }
};

void decodedString(string str) {
    Stack<int> countStack;
    Stack<string> strStack;

    int num = 0;
    string curr = "";

    for (char ch : str) {
        if (isdigit(ch)) {
            num = num * 10 + (ch - '0');
        } 
        else if (ch == '[') {
            countStack.push(num);
            strStack.push(curr);
            num = 0;
            curr = "";
        }
        else if (ch == ']') {
            int repeat = countStack.top();
            countStack.pop();

            string temp = curr;
            curr = strStack.top();
            strStack.pop();

            while (repeat--) {
                curr += temp;
            }
        }
        else {
            curr += ch;
        }
    }
    
    cout << curr << endl;
}

int main() {
    string str1 = "3[a]2[bc]";
    string str2 = "2[abc]3[cd]ef";

    decodedString(str1);
    decodedString(str2);

    return 0;
}