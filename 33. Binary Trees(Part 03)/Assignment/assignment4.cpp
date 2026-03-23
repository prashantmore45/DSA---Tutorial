/*
Question 4 : Given the root of a binary tree, return all duplicate subtrees.
For each kind of duplicate subtree, you only need to return the root node of any one of them. Two trees are duplicate 
if they have the same structure with the same node values. 

Examples :
Input:

          1
         /  \
        2    3
      /     / \
     4     2   4
          /
         4

Output: [[2, 4], [4]]
First duplicate subtree with nodes [2, 4] Second duplicate subtree with node [4]
*/

#include<iostream>
#include<vector>
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

string duplicate(Node* root, unordered_map<string,int> &mp, vector<Node*> &v) {
    if(root == NULL) return "#";  

    string a = duplicate(root->left, mp, v);
    string b = duplicate(root->right, mp, v);

    string temp = to_string(root->data) + "," + a + "," + b;

    mp[temp]++;

    if(mp[temp] == 2) {
        v.push_back(root);
    }

    return temp;
}  

vector<Node*> findDuplicateSubtrees(Node* root) {
    unordered_map<string,int> mp;
    vector<Node*> v;

    duplicate(root, mp, v);

    return v;
}

void preorder(Node* root, vector<int> &temp) {
    if (root == NULL) return;

    temp.push_back(root->data);
    preorder(root->left, temp);
    preorder(root->right, temp);
}

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, -1, 3, 2, 4, -1, -1, -1, 4, -1, -1};
    idx = -1;
    Node* root = buildTree(nodes);

    vector<Node*> duplicates = findDuplicateSubtrees(root);

    cout << "Output: [";

    for (int i = 0; i < duplicates.size(); i++) {
        vector<int> temp;
        preorder(duplicates[i], temp);

        cout << "[";
        for (int j = 0; j < temp.size(); j++) {
            cout << temp[j];
            if (j != temp.size() - 1) cout << ", ";
        }
        cout << "]";

        if (i != duplicates.size() - 1) cout << ", ";
    }

    cout << "]" << endl;

    return 0;
}   