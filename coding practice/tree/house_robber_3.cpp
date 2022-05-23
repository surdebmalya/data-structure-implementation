// https://leetcode.com/problems/house-robber-iii/

// Medium

class Solution {
private:
    pair<int, int> dfs(TreeNode *root) {
        // <taking the root, not taking the root>
        if (root == NULL)
            return make_pair(0, 0);
        else if (root->left == NULL and root->right == NULL)
            return make_pair(root->val, 0);
        pair<int, int> l = dfs(root->left);
        pair<int, int> r = dfs(root->right);
        int takingRoot = root->val + l.second + r.second;
        int withOutTakingRoot = max(l.second, l.first) + max(r.second, r.first);
        return make_pair(takingRoot, withOutTakingRoot);
    }

public:
    int rob(TreeNode *root) {
        if (root->left == NULL and root->right == NULL)
            return root->val;
        pair<int, int> resultLeft = dfs(root->left);
        pair<int, int> resultRight = dfs(root->right);
        int takingRoot = root->val + resultLeft.second + resultRight.second;
        int withOutTakingRoot = max(resultLeft.second, resultLeft.first) + max(resultRight.second, resultRight.first);
        return max(takingRoot, withOutTakingRoot);
    }
};