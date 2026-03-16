/*
Question 1 : Given the head of a singly linked list, return true if it is a
Palindrome or false otherwise.
Examples :
Input: head = [1,2,2,1]
Output: true
Input: head = [1,2,3]
Output: false
Note - Use a stack to solve this problem.
*/

#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

        Node(int val) {
            data = val;
            next = NULL;
        }
};

class Stack {
    Node* head;
    public:
        Stack() {
            head = NULL;
        }

        void push(int val) {
            Node* newNode = new Node(val);
            newNode->next = head;
            head = newNode;
        }

        void pop() {
            if (head == NULL) {
                return;
            }

            Node* temp = head;
            head = head->next;
            delete temp;
        }

        int top() {
            if(head == NULL) return -1;
            return head->data;
        }

        bool isEmpty() {
            return head == NULL;
        }
};

bool isPalindrome(Node* head) {
    Stack s;
    Node* temp = head;

    while (temp != NULL) {
        s.push(temp->data);
        temp = temp->next;
    } 

    temp = head;

    while (temp != NULL) {
        if (temp->data != s.top()) {
            return false;
        }
        s.pop();
        temp = temp->next;
    }

    return true;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(2);
    head->next->next->next = new Node(1);

    cout << isPalindrome(head) << endl;
    return 0;
}