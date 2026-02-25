/*
Qs. Given the head of a singly linked list, return true if it is a Palindrome or false
otherwise.

Input: head = [1,2,2,1] // Linked List : 1->2->2->1
Output: true

Input: head = [1,2] //Linked List : 1->2
Output: false
*/

#include <iostream>
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

class List {
public:
    Node* head;
    Node* tail;

    List() {
        head = NULL;
        tail = NULL;
    }

    void push_front(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void printList() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data;
            if (temp->next != NULL) {
                cout << " -> ";
            }
            temp = temp->next;
        }
        cout << endl;
    }

    // helper function to reverse a list from given node
    Node* reverse(Node* start) {
        Node* prev = NULL;
        Node* curr = start;

        while (curr != NULL) {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    bool isPalindrome() {
        if (head == NULL || head->next == NULL)
            return true;

        // Step 1: find middle
        Node* slow = head;
        Node* fast = head;

        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: reverse second half
        Node* secondHalf = reverse(slow->next);

        // Step 3: compare
        Node* first = head;
        Node* second = secondHalf;

        bool result = true;
        while (second != NULL) {
            if (first->data != second->data) {
                result = false;
                break;
            }
            first = first->next;
            second = second->next;
        }

        // Step 4: restore the list
        slow->next = reverse(secondHalf);

        return result;
    }
};

int main() {
    List ll1;
    List ll2;

    ll1.push_front(1);
    ll1.push_front(2);
    ll1.push_front(2);
    ll1.push_front(1);

    ll1.printList();
    cout << (ll1.isPalindrome() ? "true" : "false") << endl;
    ll1.printList();  

    ll2.push_front(1);
    ll2.push_front(2);

    ll2.printList();
    cout << (ll2.isPalindrome() ? "true" : "false") << endl;
    ll2.printList();   

    return 0;
}