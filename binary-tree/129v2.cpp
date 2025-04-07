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
    void dfs(TreeNode* root, int x) {
        if (!root)
            return;

        x = x * 10 + root->val;

        if (root->left == root->right) {
            ans += x;
            return;
        }
        
        dfs(root->left, x);
        dfs(root->right, x);
    }

    int sumNumbers(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
};