// https://leetcode.com/problems/recover-binary-search-tree/

// Medium

class Solution {
private:
    TreeNode *first, *middle, *last, *prev;
    void f(TreeNode *root) {
        if (root == NULL)
            return;
        f(root->left);
        if (prev != NULL and (root->val < prev->val)) {
            if (first == NULL) {
                first = prev;
                middle = root;
            } else {
                last = root;
            }
        }
        prev = root;
        f(root->right);
    }

public:
    void recoverTree(TreeNode *root) {
        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN);
        f(root);
        if (first and last)
            swap(first->val, last->val);
        else if (first and middle)
            swap(first->val, middle->val);
    }
};