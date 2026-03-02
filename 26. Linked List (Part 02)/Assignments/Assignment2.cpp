/*
Question 2 : Delete N Nodes After M Nodes of a Linked List
We have a linked list and two integers M and N. Traverse the linked list such that you 
retain M nodes then delete next N nodes, continue the same till end of the linked list. 
Difficulty Level: Rookie.

Sample Input 1 : M=2 N=2 LL: 1->2->3->4->5->6->7->8
Sample Output 1 : 1->2->5->6

Sample Input 2 : M=3 N=2 LL: 1->2->3->4->5->6->7->8->9->10
Sample Output 2 : 1->2->3->6->7->8
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

    void push_back(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
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

void deleteNafterM(Node*& head, int M, int N) {

    Node* curr = head;

    while (curr != NULL) {

        // Skip M-1 nodes
        for (int i = 1; i < M && curr != NULL; i++) {
            curr = curr->next;
        }

        if (curr == NULL)
            return;

        // Start deleting next N nodes
        Node* temp = curr->next;

        for (int i = 0; i < N && temp != NULL; i++) {
            Node* nextNode = temp->next;
            delete temp;          // free memory
            temp = nextNode;
        }

        // Connect
        curr->next = temp;

        // Move curr forward
        curr = temp;
    }
}

int main() {

    List ll;

    // Sample Input 1
    int M = 2;
    int N = 2;

    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);
    ll.push_back(6);
    ll.push_back(7);
    ll.push_back(8);

    cout << "Original List: ";
    ll.printList();

    deleteNafterM(ll.head, M, N);

    cout << "Modified List: ";
    ll.printList();

    return 0;
}