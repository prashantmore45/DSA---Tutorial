/*
Question 1 : Bottom View of a Binary Tree
The top view of a binary tree is the set of nodes visible when the tree is viewed from the top.
Given a binary tree, print the bottom view of it. The output nodes can be printed in any order.
Sample Input :
         20
        /  \
       8    22
      / \     \
     5   3     25
        / \
       10 14

Sample Output : 5 10 3 14 25

Hint : Use the concept of Vertical Order
*/

#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

static int idx = -1;

Node* buildTree(vector<int> nodes) {
    idx++;

    if (nodes[idx] == -1) {
        return NULL;
    }

    Node* currNode = new Node(nodes[idx]);
    currNode->left = buildTree(nodes);
    currNode->right = buildTree(nodes);

    return currNode;
}

void bottomView(Node* root) {
    queue<pair<Node*, int>> Q; // (node, HD)
    unordered_map<int, int> m; // (HD, node->data)

    Q.push(make_pair(root, 0));

    while (!Q.empty()) {
        pair<Node*, int> curr = Q.front();
        Q.pop();

        Node* currNode = curr.first;
        int currHD = curr.second;

        m[currHD] = currNode->data;

        if (currNode->left != NULL) {
            pair<Node*, int> left = make_pair(currNode->left, currHD-1);
            Q.push(left);
        }

        if (currNode->right != NULL) {
            pair<Node*, int> right = make_pair(currNode->right, currHD+1);
            Q.push(right);
        }
    }

    for (auto it : m) {
        cout << it.second <<  " ";
    }
    cout << endl;
}


int main() {
    vector<int> nodes = {20, 8, 5, -1, -1, 3, 10, -1, -1, 14, -1, -1, 22, -1, 25, -1, -1}; //preorder
    Node* root = buildTree(nodes);

    bottomView(root); //5 10 3 14 25
    return 0;
}