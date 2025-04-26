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
    vector<vector<int>> ans;
    vector<int> path;
public:
    void dfs(TreeNode* root, int targetSum) {
        if (root == nullptr)
            return;

        path.push_back(root->val);

        if (root->left == root->right)
            if (accumulate(path.begin(), path.end(), 0) == targetSum)
                ans.push_back(path);

        dfs(root->left, targetSum);
        dfs(root->right, targetSum);

        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum);
        return ans;
    }
};