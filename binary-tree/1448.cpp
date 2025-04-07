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
    int ans = 0;
    void dfs(TreeNode* root, int maxValue) {
        if (!root)
            return;
        
        maxValue = max(maxValue, root->val);

        dfs(root->left, maxValue);
        dfs(root->right, maxValue);

        if (root->val >= maxValue)
            ans++;
        return;
    }

    int goodNodes(TreeNode* root) {
        dfs(root, INT_MIN);
        return ans;
    }
};