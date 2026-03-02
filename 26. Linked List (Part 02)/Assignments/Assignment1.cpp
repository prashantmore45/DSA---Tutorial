/*
Question 1 :Intersection of Two Linked Lists
In a system there are two singly linked list. By some programming error, the end node of one of the linked lists got linked to the second list, 
forming an inverted Y-shaped list. Write a program to get the point where two linked lists merge.

List A:   1 → 2 → 3
                   \
                    6 → 7
                   /
List B:       4 → 5

We have to find the intersection part in this system.
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
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int getLength(Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

Node* findIntersec(Node* head1, Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    Node* ptr1 = head1;
    Node* ptr2 = head2;

    if (len1 > len2) {
        for (int i = 0; i < len1 - len2; i++)
            ptr1 = ptr1->next;
    } else {
        for (int i = 0; i < len2 - len1; i++)
            ptr2 = ptr2->next;
    }

    while (ptr1 != NULL && ptr2 != NULL && ptr1 != ptr2) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return ptr1;
}

int main() {

    List ll1;
    List ll2;

    ll1.push_front(3);
    ll1.push_front(2);
    ll1.push_front(1);

    ll2.push_front(5);
    ll2.push_front(4);

    Node* common = new Node(6);
    common->next = new Node(7);

    ll1.tail->next = common;
    ll2.tail->next = common;

    ll1.tail = common->next;
    ll2.tail = common->next;

    cout << "List 1: ";
    ll1.printList();

    cout << "List 2: ";
    ll2.printList();

    Node* result = findIntersec(ll1.head, ll2.head);

    if (result != NULL)
        cout << "Intersection point: " << result->data << endl;
    else
        cout << "No intersection found." << endl;

    return 0;
}