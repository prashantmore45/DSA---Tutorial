/*
Question 3 : Swapping Nodes in a Linked List
We have a linked list and two keys in it, swap nodes for two given keys. Nodes should be swapped by changing links. Swapping data of nodes may be 
expensive in many situations when data contains many fields. It may be assumed that all keys in the linked list are distinct.

Sample Input 1 : 1->2->3->4, x = 2, y = 4
Sample Output 1 : 1->4->3->2
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

class List {
public:
    Node* head;

    List() {
        head = NULL;
    }

    void push_front(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void printList() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

void swapNodes(Node* &head, int x, int y) {

    if (x == y) return;

    Node *prevX = NULL, *currX = head;
    Node *prevY = NULL, *currY = head;

    // Find x
    while (currX != NULL && currX->data != x) {
        prevX = currX;
        currX = currX->next;
    }

    // Find y
    while (currY != NULL && currY->data != y) {
        prevY = currY;
        currY = currY->next;
    }

    // If either not found
    if (currX == NULL || currY == NULL)
        return;

    // If x is not head
    if (prevX != NULL)
        prevX->next = currY;
    else
        head = currY;

    // If y is not head
    if (prevY != NULL)
        prevY->next = currX;
    else
        head = currX;

    // Swap next pointers
    Node* temp = currX->next;
    currX->next = currY->next;
    currY->next = temp;
}

int main() {

    List ll;

    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);

    cout << "Before swap: ";
    ll.printList();

    swapNodes(ll.head, 2, 4);

    cout << "After swap: ";
    ll.printList();

    return 0;
}