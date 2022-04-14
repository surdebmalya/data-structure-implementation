#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

struct Node {
    struct Node *left;
    struct Node *right;
    int data;
};

struct Node *newNode(int value) {
    struct Node *temp = new Node();
    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
};

void inorder_traversal(struct Node *root) {
    if (root == NULL) {
        return;
    }
    inorder_traversal(root->left);
    cout << root->data << " ";
    inorder_traversal(root->right);
}

void preorder_traversal(struct Node *root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

void print_inorder_preorder(struct Node *root) {
    cout << "Inorder Traversal of the Tree is: ";
    inorder_traversal(root);
    cout << endl;
    cout << "Preorder Traversal of the Tree is: ";
    preorder_traversal(root);
    cout << endl;
}

struct Node *maxValue(struct Node *root) {
    while (root != NULL and root->right != NULL) {
        root = root->right;
    }
    return root;
}

struct Node *delete_node(struct Node *root, int target) {
    if (root == NULL) {
        return root;
    } else if (root->data > target) {
        root->left = delete_node(root->left, target);
    } else if (root->data < target) {
        root->right = delete_node(root->right, target);
    } else {
        // by default delete inorder predecessor
        if (root->left == NULL and root->right == NULL) {
            return NULL;
        } else if (root->left != NULL) {
            struct Node *temp = maxValue(root->left);
            root->data = temp->data;
            root->left = delete_node(root->left, temp->data);
        } else {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
    }
    return root;
}

int main() {
    struct Node *root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(11);
    root->left->left = newNode(1);
    root->left->right = newNode(7);
    print_inorder_preorder(root);

    root = delete_node(root, 7);
    print_inorder_preorder(root);

    root = delete_node(root, 5);
    print_inorder_preorder(root);

    return 0;
}