/*
Question 5 : Merge k Sorted Lists
We have K sorted linked lists of size N each, merge them and print the sorted output.

Sample Input 1 : k = 2, n = 2
l1 = 1->3->NULL
l2 = 6->8->NULL 
l3 = 9->10->NULL

Sample Output 1 : 1>3->6->8->9->10->NULL
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

// Merge two sorted lists
Node* mergeTwoLists(Node* l1, Node* l2) {

    if (!l1) return l2;
    if (!l2) return l1;

    Node* result = NULL;

    if (l1->data <= l2->data) {
        result = l1;
        result->next = mergeTwoLists(l1->next, l2);
    } else {
        result = l2;
        result->next = mergeTwoLists(l1, l2->next);
    }

    return result;
}

// Merge K lists (one by one)
Node* mergeKLists(Node* arr[], int k) {

    Node* result = NULL;

    for (int i = 0; i < k; i++) {
        result = mergeTwoLists(result, arr[i]);
    }

    return result;
}

// Print list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {

    int k = 3;

    // list 1: 1 -> 3
    Node* l1 = new Node(1);
    l1->next = new Node(3);

    // list 2: 6 -> 8
    Node* l2 = new Node(6);
    l2->next = new Node(8);

    // list 3: 9 -> 10
    Node* l3 = new Node(9);
    l3->next = new Node(10);

    Node* arr[] = {l1, l2, l3};

    Node* merged = mergeKLists(arr, k);

    cout << "Merged List: ";
    printList(merged);

    return 0;
}