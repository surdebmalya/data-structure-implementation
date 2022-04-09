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

void preorder_traversal(struct Node * root) {
    if (root!=NULL) {
        cout << root->value << " ";
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
    else {
        return;
    }
}

int height(struct Node * root) {
    if (root==NULL) {
        return 0;
    }
    else {
        return 1 + max(height(root->left), height(root->right));
    }
}

int number_of_leaf_nodes(struct Node * root) {
    if (root==NULL) {
        return 0;
    }
    else {
        if (root->left==NULL and root->right==NULL) {return 1;}
        int lleaf = 0, rleaf = 0;
        if (root->left!=NULL) {
            lleaf = number_of_leaf_nodes(root->left);
        }
        if (root->right!=NULL) {
            rleaf = number_of_leaf_nodes(root->right);
        }
        return lleaf + rleaf;
    }
}

void mirror(struct Node * root) {
    if (root==NULL) {
        return;
    }
    else {
        if (root->left!=NULL and root->right!=NULL) {
            mirror(root->left);
            mirror(root->right);
            struct Node * temp_left = root->left;
            struct Node * temp_right = root->right;
            root->left = temp_right;
            root->right = temp_left;
        }
        else if (root->left!=NULL and root->right==NULL) {
            mirror(root->left);
            root->right = root->left;
            root->left = NULL;
        }
        else if (root->left==NULL and root->right!=NULL) {
            mirror(root->right);
            root->left = root->right;
            root->right = NULL;
        }
        else {
            // it's a leaf node
            return;
        }
    }
}

int main() {
    struct Node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(4);

    cout << "Inorder Traversal: ";
    inorder_traversal(root);
    cout << endl;

    cout << "Height of the Tree: " << height(root) << endl;

    cout << "Number of leaf nodes: " << number_of_leaf_nodes(root) << endl;

    cout << "Mirror of current tree" << endl;

    mirror(root);
    cout << "Inorder Traversal: ";
    inorder_traversal(root);
    cout << endl;
    cout << "Preorder Traversal: ";
    preorder_traversal(root);
    cout << endl;

    return 0;
}