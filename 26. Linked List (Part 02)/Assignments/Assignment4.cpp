/*
Question 4 : Odd Even Linked List
We have a Linked List of integers, write a function to modify the linked list such that all even numbers appear before all the odd numbers 
in the modified linked list. Also, keep the order of even and odd numbers same.

Sample Input 1 : 8->12->10->5->4->1->6->NULL
Sample Output 1 : 8->12->10->4->6->5->1->NULL

Sample Input 2 : 1->3->5->7->NULL
Sample Output 2 : 1->3->5->7->NULL
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

void modifyList(Node* &head) {
    if (head == NULL) {
        return;
    }

    Node* evenHead = NULL;
    Node* evenTail = NULL;
    Node* oddHead = NULL;
    Node* oddTail = NULL;

    Node* curr = head;

    while (curr != NULL) {
            
        if (curr->data % 2 == 0) {
            //Even Node
            if (evenHead == NULL) {
                evenHead = evenTail = curr;
            } else {
                evenTail->next = curr;
                evenTail = curr;
            }
        } else {
            //Odd Node
            if (oddHead == NULL) {
                oddHead = oddTail = curr;
            } else {
                oddTail->next = curr;
                oddTail = curr;
            }
        }

        curr = curr->next;
    }

    //if no even numbers
    if (evenHead == NULL) {
        head = oddHead;
        return;
    }

    //connect even list with odd list
    evenTail->next = oddHead;

    if (oddTail != NULL) {
        oddTail->next = NULL;
    }

    head = evenHead;
};

int main() {
    List ll;

    ll.push_back(8);
    ll.push_back(12);
    ll.push_back(10);
    ll.push_back(5);
    ll.push_back(4);
    ll.push_back(1);
    ll.push_back(6);

    cout << "Before modification List: ";
    ll.printList();

    cout << "After modification List: ";
    modifyList(ll.head);
    ll.printList();

    return 0;
}