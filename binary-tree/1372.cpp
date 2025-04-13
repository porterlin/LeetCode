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

    void dfs(TreeNode* root, bool direction, int length) {
        ans = max(ans, length);

        if (!direction) {
            if (root->left)
                dfs(root->left, 1, length + 1);
            if (root->right)
                dfs(root->right, 0, 1);
        } else {
            if (root->right)
                dfs(root->right, 0, length + 1);
            if (root->left)
                dfs(root->left, 1, 1);
        }
    }

    int longestZigZag(TreeNode* root) {
        dfs(root, 0, 0);
        dfs(root, 1, 0);
        return ans;
    }
};