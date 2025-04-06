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
    bool dfs(TreeNode* root, int targetSum, int sum) {
        if (!root)
            return false;
        
        sum += root->val;
        bool left = dfs(root->left, targetSum, sum);
        bool right = dfs(root->right, targetSum, sum);
        
        if (!root->left && !root->right && sum == targetSum)
            return true;
        if (left || right)
            return true;
        return false;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        return dfs(root, targetSum, 0);
    }
};