#include<iostream>
#include<list>
#include<iterator>
using namespace std;

void printList(list<int> ll) {
    list<int>::iterator itr;
    for (itr=ll.begin(); itr != ll.end(); itr++) {
        cout << (*itr) << " -> ";
    }
    cout << "NULL" << endl;
}

int main() {
    list<int> ll;
    ll.push_front(2);
    ll.push_front(1);
    ll.push_back(3);
    ll.push_back(4);

    printList(ll);  //1 -> 2 -> 3 -> 4 -> NULL
    cout << ll.size() << endl; //4

    cout << "Head = " << ll.front() << "\n";  //1
    cout << "Tail = " << ll.back() << "\n"; //4

    ll.pop_front(); 
    printList(ll); //2 -> 3 -> 4 -> NULL

    ll.pop_back(); 
    printList(ll); //1 -> 2 -> 3 -> NULL

    return 0;
}