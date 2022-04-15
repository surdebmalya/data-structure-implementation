// https://practice.geeksforgeeks.org/problems/construct-binary-tree-from-parent-array/1/

// Medium

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

void sort_and_print(vector<int> &v) {
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    v.clear();
}

void printLevelOrder(struct Node *root) {
    vector<int> v;
    queue<Node *> q;

    q.push(root);

    Node *next_row = NULL;

    while (!q.empty()) {
        Node *n = q.front();
        q.pop();

        if (n == next_row) {
            sort_and_print(v);
            next_row = NULL;
        }

        v.push_back(n->data);

        if (n->left) {
            q.push(n->left);
            if (next_row == NULL)
                next_row = n->left;
        }

        if (n->right) {
            q.push(n->right);
            if (next_row == NULL)
                next_row = n->right;
        }
    }
    sort_and_print(v);
}

Node *createTree(int parent[], int n);

/* Driver program to test above function*/

// } Driver Code Ends
/* node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

class Solution {
public:
    // Function to construct binary tree from parent array.
    Node *createTree(int parent[], int N) {
        map<int, vector<int>> nodes;
        for (int index = 0; index < N; index++) {
            if (nodes.find(parent[index]) == nodes.end()) {
                // new entry
                vector<int> temp;
                temp.push_back(index);
                nodes[parent[index]] = temp;
            } else {
                nodes[parent[index]].push_back(index);
            }
        }

        queue<struct Node *> q;
        struct Node *root = new Node(nodes[-1][0]);
        q.push(root);
        while (q.empty() == false) {
            struct Node *curr = q.front();
            q.pop();
            if (nodes.find(curr->data) != nodes.end()) {
                if (nodes[curr->data].size() == 2) {
                    struct Node *temp1 = new Node(nodes[curr->data][0]);
                    curr->left = temp1;
                    q.push(temp1);
                    struct Node *temp2 = new Node(nodes[curr->data][1]);
                    curr->right = temp2;
                    q.push(temp2);
                } else {
                    // size 1, only left child
                    struct Node *temp1 = new Node(nodes[curr->data][0]);
                    curr->left = temp1;
                    q.push(temp1);
                }
            }
        }
        return root;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;

        Node *res = ob.createTree(a, n);

        printLevelOrder(res);
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends