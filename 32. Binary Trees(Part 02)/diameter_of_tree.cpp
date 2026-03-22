#include<iostream>
#include<vector>
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

int height(Node* root) {
    if (root == NULL) {
        return 0;
    }

    int leftHt = height(root->left);
    int rightHt = height(root->right);

    int currHt = max(leftHt, rightHt) + 1;

    return currHt;
} 

//approach 1 => O(n^2)
int diam1(Node* root) {  
    if (root == NULL) {
        return 0;
    }

    int currDiam = height(root->left) + height(root->right) + 1;
    int leftDiam = diam1(root->left);
    int rightDiam = diam1(root->right);

    return max(currDiam, max(leftDiam, rightDiam));
}

//approach 2 => O(n)
pair<int, int> diam2(Node* root) { /
    if (root == NULL) {
        return make_pair(0, 0);
    }

    // pair => (diameter, height)
    pair<int, int> leftInfo = diam2(root->left); // (LD, LH)
    pair<int, int> rightInfo = diam2(root->right); // (RD, RH)

    int currDiam = leftInfo.second + rightInfo.second + 1;

    int finalDiam = max(currDiam, max(leftInfo.first, rightInfo.first));
    int finalHt = max(leftInfo.second, rightInfo.second) + 1;

    return make_pair(finalDiam, finalHt);
}

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node* root = buildTree(nodes);

    cout << "Diamter of tree = " << diam1(root) << endl; //5

    cout << "Diameter of tree = " << diam2(root).first << endl; //5
    //cout << "Height of tree = " << diam2(root).second << endl; //3
    return 0;
}