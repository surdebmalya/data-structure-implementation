// https://leetcode.com/problems/binary-tree-cameras/

// Hard

class Solution {
private:
    int cameras = 0;
    int haveCamera = 1, covered = 0, notCovered = -1;
    int dfs(TreeNode *root) {
        if (root == NULL) {
            return covered;
        }
        int l = dfs(root->left);
        int r = dfs(root->right);
        if (l == covered and r == covered) {
            // tell its parent to have a camera
            return notCovered;
        } else if (l == notCovered or r == notCovered) {
            cameras++;
            return haveCamera;
        } else if (l == haveCamera or r == haveCamera) {
            return covered;
        }
        return -1;
    }

public:
    int minCameraCover(TreeNode *root) {
        int result = dfs(root);
        if (result == -1)
            cameras++;
        return cameras;
    }
};