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

    // ~Node() {
    //     cout << "~Node " << data << endl;
    //     if (next != NULL) {
    //         delete next;
    //         next = NULL;
    //     }
    // }
};

class List {
    Node* head;
    Node* tail;

public:
    List() {
        head = NULL;
        tail = NULL;
    }

    // ~List() {
    //     cout << "~List\n";
    //     if (head != NULL) {
    //         delete head;
    //         head = NULL;
    //     }
    // }

    void push_front(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
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

    void insert(int val, int pos) {
        Node* newNode = new Node(val);

        Node* temp = head;

        for (int i=0; i<pos-1; i++) {
            if (temp == NULL) {
                cout << "position is INVALID!\n";
                return;
            }
            temp = temp->next;
        }

        //now temp is at pos-1 i.e. prev/left
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void pop_front() {
        if (head == NULL) {
            cout << "LL is Empty\n";
            return;
        }

        Node* temp = head;
        head = head->next;

        temp->next = NULL;
        delete temp;
    }

    void pop_back() {
        Node* temp = head;

        while (temp->next->next != NULL) {
            temp = temp->next;
        }

        temp->next = NULL; // temp = tail's prev
        delete tail;
        tail = temp;
    }
};

int main() {
    List LL;

    LL.push_front(3);
    LL.push_front(2);
    LL.push_front(1); 
    // 1->2->3->NULL

    LL.push_back(4);
    LL.push_back(5); 
    // 1->2->3->4->5->NULL

    LL.printList(); // 1 -> 2 -> 3 -> 4 -> 5 -> NULL

    LL.insert(100, 2);
    LL.printList(); // 1 -> 2 -> 100 -> 3 -> 4 -> 5 -> NULL

    LL.pop_front();
    LL.printList(); // 2 -> 100 -> 3 -> 4 -> 5 -> NULL

    LL.pop_back();
    LL.printList(); // 2 -> 100 -> 3 -> 4 -> NULL

    return 0;
}