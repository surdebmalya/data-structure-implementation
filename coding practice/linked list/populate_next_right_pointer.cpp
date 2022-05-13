// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/

// Medium

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node *connect(Node *root) {
        if (root == NULL) {
            return root;
        }

        // examining except of root==NULL
        Node *currNode = root;
        Node *prevNode = NULL;
        int prevNodeLvl = 0;
        queue<pair<Node *, int>> q; // <Node*, levelOfTheNode>
        q.push(make_pair(currNode, 1));
        while (!(q.empty())) {
            pair<Node *, int> ele = q.front();
            q.pop();
            if (ele.second == 1) {
                prevNode = ele.first;
                prevNodeLvl = 1;

                // enqueue it children, first: left child and then right child
                if (ele.first->left != NULL) {
                    q.push(make_pair(ele.first->left, prevNodeLvl + 1));
                }
                if (ele.first->right != NULL) {
                    q.push(make_pair(ele.first->right, prevNodeLvl + 1));
                }
            } else {
                if (prevNodeLvl == ele.second) {
                    prevNode->next = ele.first;
                } else {
                    prevNode->next = NULL;
                }
                prevNode = ele.first;
                prevNodeLvl = ele.second;

                if (ele.first->left != NULL) {
                    q.push(make_pair(ele.first->left, prevNodeLvl + 1));
                }
                if (ele.first->right != NULL) {
                    q.push(make_pair(ele.first->right, prevNodeLvl + 1));
                }
            }
        }
        prevNode->next = NULL;
        return root;
    }
};