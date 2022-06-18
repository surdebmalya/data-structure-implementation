// https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/

// Medium

class Solution {
private:
    int result = 0;
    void f(TreeNode *root, bool addCurr, bool addNext) {
        if (root == NULL)
            return;
        if (addCurr)
            result += root->val;
        bool addGrandChild = false;
        if ((root->val) % 2 == 0)
            addGrandChild = true;
        if (root->left != NULL)
            f(root->left, addNext, addGrandChild);
        if (root->right != NULL)
            f(root->right, addNext, addGrandChild);
    }

public:
    int sumEvenGrandparent(TreeNode *root) {
        bool addGrandChild = false;
        if ((root->val) % 2 == 0)
            addGrandChild = true;
        f(root->left, false, addGrandChild);
        f(root->right, false, addGrandChild);

        return result;
    }
};