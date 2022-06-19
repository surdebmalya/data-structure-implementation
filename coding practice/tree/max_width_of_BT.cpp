// https://leetcode.com/problems/maximum-width-of-binary-tree/

// Medium

class Solution {
public:
    int widthOfBinaryTree(TreeNode *root) {
        int ans = 0;
        queue<pair<TreeNode *, long long>> q;
        q.push({root, 0});
        while (!(q.empty())) {
            int size = q.size();
            int mmin = q.front().second;
            int first, last;
            for (int i = 0; i < size; i++) {
                long long currId = q.front().second - mmin;
                TreeNode *node = q.front().first;
                q.pop();
                if (i == 0)
                    first = currId;
                if (i == size - 1)
                    last = currId;
                if (node->left)
                    q.push({node->left, 2 * currId + 1});
                if (node->right)
                    q.push({node->right, 2 * currId + 2});
            }
            ans = max(ans, last - first + 1);
        }
        return ans;
    }
};