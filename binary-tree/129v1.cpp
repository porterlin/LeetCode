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
    vector<int> vec;
    int ans = 0;
    void dfs(TreeNode* root) {
        if (!root)
            return;
        
        vec.push_back(root->val);
        dfs(root->left);
        dfs(root->right);

        if (root->left == root->right) { // leaf node
            for (int i = 0; i < vec.size(); i++)
                ans += vec[i] * pow(10, vec.size() - i - 1);
        }
        vec.pop_back();
    }

    int sumNumbers(TreeNode* root) {
        dfs(root);
        return ans;
    }
};