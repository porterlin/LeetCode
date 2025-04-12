/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxValue = 0;
    int dfs(TreeNode* root, int maxAnc, int minAnc) {
        if (!root)
            return 0;

        dfs(root->left, max(maxAnc, root->val), min(minAnc, root->val));
        dfs(root->right, max(maxAnc, root->val), min(minAnc, root->val));

        int buf = max(abs(minAnc - root->val), abs(maxAnc - root->val));
        maxValue = max(maxValue, buf);

        return maxValue;
    }

    int maxAncestorDiff(TreeNode* root) {
        return dfs(root, root->val, root->val);
    }
};