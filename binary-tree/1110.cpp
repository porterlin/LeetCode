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
    unordered_set<int> mset;
    vector<TreeNode*> ans;

    TreeNode* dfs(TreeNode* root) {
        if (root == nullptr)
            return nullptr;

        root->left = dfs(root->left);
        root->right = dfs(root->right);

        if (!mset.count(root->val))
            return root;

        if (root->left)
            ans.push_back(root->left);
        if (root->right)
            ans.push_back(root->right);
        
        return nullptr;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for (auto d : to_delete)
            mset.insert(d);

        if (dfs(root))
            ans.push_back(root);

        return ans;
    }
};