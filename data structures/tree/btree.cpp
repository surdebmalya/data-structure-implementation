#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <vector>

using namespace std;

struct Node {
    struct Node *left;
    int value;
    struct Node *right;
};

struct Node *newNode(int data) {
    struct Node *temp = new struct Node();
    temp->left = NULL;
    temp->value = data;
    temp->right = NULL;

    return temp;
};

void inorder_traversal(struct Node *root) {
    if (root != NULL) {
        inorder_traversal(root->left);
        cout << root->value << " ";
        inorder_traversal(root->right);
    } else {
        return;
    }
}

void preorder_traversal(struct Node *root) {
    if (root != NULL) {
        cout << root->value << " ";
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    } else {
        return;
    }
}

void vertical_order(struct Node *root, map<int, vector<int>> &veritcal_order_map, int curr_order) {
    if (root == NULL) {
        return;
    }

    if (veritcal_order_map.find(curr_order) != veritcal_order_map.end()) {
        veritcal_order_map[curr_order].push_back(root->value);
    } else {
        vector<int> temp_vec = {root->value};
        veritcal_order_map[curr_order] = temp_vec;
    }

    vertical_order(root->left, veritcal_order_map, curr_order - 1);
    vertical_order(root->right, veritcal_order_map, curr_order + 1);
}

void print_vertical_order(map<int, vector<int>> &vertical_order_map) {
    auto it = vertical_order_map.begin();
    while (it != vertical_order_map.end()) {
        for (int index = 0; index < (it->second).size(); index++) {
            cout << (it->second)[index] << " ";
        }
        cout << endl;
        it++;
    }
}

int height(struct Node *root) {
    if (root == NULL) {
        return 0;
    } else {
        return 1 + max(height(root->left), height(root->right));
    }
}

int number_of_leaf_nodes(struct Node *root) {
    if (root == NULL) {
        return 0;
    } else {
        if (root->left == NULL and root->right == NULL) {
            return 1;
        }
        int lleaf = 0, rleaf = 0;
        if (root->left != NULL) {
            lleaf = number_of_leaf_nodes(root->left);
        }
        if (root->right != NULL) {
            rleaf = number_of_leaf_nodes(root->right);
        }
        return lleaf + rleaf;
    }
}

void mirror(struct Node *root) {
    if (root == NULL) {
        return;
    } else {
        if (root->left != NULL and root->right != NULL) {
            mirror(root->left);
            mirror(root->right);
            struct Node *temp_left = root->left;
            struct Node *temp_right = root->right;
            root->left = temp_right;
            root->right = temp_left;
        } else if (root->left != NULL and root->right == NULL) {
            mirror(root->left);
            root->right = root->left;
            root->left = NULL;
        } else if (root->left == NULL and root->right != NULL) {
            mirror(root->right);
            root->left = root->right;
            root->right = NULL;
        } else {
            // it's a leaf node
            return;
        }
    }
}

class Queue {
    list<struct Node *> queue;
    int size = 0;

public:
    bool isEmpty() {
        return size == 0;
    }

    void enqueue(struct Node *root) {
        queue.push_back(root);
        size++;
    }

    struct Node *dequeue() {
        struct Node *node = queue.front();
        queue.pop_front();
        size--;
        return node;
    }
};

void bfs(struct Node *root) {
    Queue queue;
    if (root == NULL) {
        return;
    }
    queue.enqueue(root);
    while (not(queue.isEmpty())) {
        struct Node *curr_node = queue.dequeue();
        cout << curr_node->value << " ";
        if (curr_node->left != NULL) {
            queue.enqueue(curr_node->left);
        }
        if (curr_node->right != NULL) {
            queue.enqueue(curr_node->right);
        }
    }
    cout << endl;
}

class CallStack {
    vector<struct Node *> stack;
    int size = 0;

public:
    bool isEmpty() {
        return size == 0;
    }

    void push(struct Node *root) {
        stack.push_back(root);
        size++;
    }

    struct Node *pop() {
        struct Node *ele = stack[size - 1];
        stack.pop_back();
        return ele;
    }
};

void dfs(struct Node *root) {
    CallStack cs;
    if (root == NULL) {
        return;
    } else {
        cs.push(root);
        cout << root->value << " ";
        dfs(root->left);
        dfs(root->right);
    }
}

void left_view(struct Node *root, int curr_level, int *max_level) {
    if (root == NULL) {
        return;
    }
    if (curr_level > *max_level) {
        cout << root->value << " ";
        *max_level = curr_level;
    }
    left_view(root->left, curr_level + 1, max_level);
    left_view(root->right, curr_level + 1, max_level);
}

void right_view(struct Node *root, int curr_level, int *max_level) {
    // level order traversal but right cchild first then left child
    if (root == NULL) {
        return;
    }
    if (curr_level > *max_level) {
        cout << root->value << " ";
        *max_level = curr_level;
    }
    right_view(root->right, curr_level + 1, max_level);
    right_view(root->left, curr_level + 1, max_level);
}

void top_view(struct Node *root) {
    map <int, vector <int>> veritcal_order_map;
    vertical_order(root, veritcal_order_map, 0);
    auto it = veritcal_order_map.begin();
    while (it != veritcal_order_map.end()) {
        cout << (it->second)[0] << " ";
        it++;
    }
    cout << endl;
}

int main() {
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->right->right = newNode(6);

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

    cout << "BFS Tree: ";
    bfs(root);

    cout << "DFS Tree: ";
    dfs(root);
    cout << endl;

    cout << "Left View: ";
    int max_level = 0;
    left_view(root, 1, &max_level);
    cout << endl;

    cout << "Right View: ";
    int maximum_level = 0;
    right_view(root, 1, &maximum_level);
    cout << endl;

    cout << "Vertical Order: " << endl;
    map<int, vector<int>> veritcal_order_map;
    vertical_order(root, veritcal_order_map, 0);
    print_vertical_order(veritcal_order_map);

    cout << "Top View: ";
    map<int, vector<int>> veritcal_order_map_top_view;
    top_view(root);

    return 0;
}