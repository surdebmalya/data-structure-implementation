#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    struct Node * left;
    int value;
    struct Node * right;
};

struct Node * newNode (int data) {
    struct Node * temp = new struct Node();
    temp->left=NULL;
    temp->value=data;
    temp->right=NULL;

    return temp;
};

void inorder_traversal(struct Node * root) {
    if (root!=NULL) {
        inorder_traversal(root->left);
        cout << root->value << " ";
        inorder_traversal(root->right);
    }
    else {
        return;
    }
}

int main() {
    struct Node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);

    inorder_traversal(root);

    return 0;
}