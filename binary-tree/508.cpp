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
    vector<int> ans;
    int check = 0;
    unordered_map<int, int> mp;
    int dfs(TreeNode* root) {
        if (!root)
            return 0;

        int val = dfs(root->left) + dfs(root->right) + root->val;
        mp[val]++;
        if (mp[val] == check) {
            ans.push_back(val);
        } else if (mp[val] > check) {
            ans.clear();
            ans.push_back(val);
            check++;
        }

        return val;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
};