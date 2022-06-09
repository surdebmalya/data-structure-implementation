// https://leetcode.com/problems/unique-binary-search-trees-ii/

// Medium

class Solution {
private:
    struct TreeNode *newNode(int val) {
        struct TreeNode *temp = new TreeNode();
        temp->val = val;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }
    vector<TreeNode *> f(int start, int end) {
        vector<TreeNode *> result;
        if (start > end)
            return {NULL};
        for (int i = start; i <= end; i++) {
            vector<TreeNode *> l = f(start, i - 1);
            vector<TreeNode *> r = f(i + 1, end);
            for (int j = 0; j < l.size(); j++) {
                for (int k = 0; k < r.size(); k++) {
                    TreeNode *root = newNode(i);
                    root->left = l[j];
                    root->right = r[k];
                    result.push_back(root);
                }
            }
        }
        return result;
    }

public:
    vector<TreeNode *> generateTrees(int n) {
        vector<TreeNode *> result;
        for (int i = 1; i <= n; i++) {
            vector<TreeNode *> l = f(1, i - 1);
            vector<TreeNode *> r = f(i + 1, n);
            for (int j = 0; j < l.size(); j++) {
                for (int k = 0; k < r.size(); k++) {
                    TreeNode *root = newNode(i);
                    root->left = l[j];
                    root->right = r[k];
                    result.push_back(root);
                }
            }
        }
        return result;
    }
};