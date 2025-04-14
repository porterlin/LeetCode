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
    int pre = INT_MIN;
    map<int, int> mp;

    void dfs(TreeNode* root) {
        if (!root)
            return;
        
        dfs(root->left);
        mp[root->val]++;
        dfs(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        dfs(root);

        auto temp = ranges::max_element(mp, [](const auto& a, const auto& b) {
            return a.second < b.second;
        });

        for (auto [key, value] : mp)
            if (value == temp->second)
                ans.push_back(key);
        
        return ans;
    }
};