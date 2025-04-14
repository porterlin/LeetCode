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
    vector<int> a;
    void dfs(TreeNode* root) {
        if (root == nullptr)
            return;
        
        dfs(root->left);
        a.push_back(root->val);
        dfs(root->right);
    }

    int search(int target) {
        int left = 0;
        int right = a.size() - 1;
        int mid;
        while (left <= right) {
            mid = (left + right) / 2;
            if (a[mid] >= target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return left;
    }

    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        int n = queries.size();
        dfs(root);

        vector<vector<int>> ans;
        int mn;
        int mx;
        
        for (int i = 0; i < n; i++) {
            int j = search(queries[i]);
            mx = j < a.size() ? a[j] : -1;

            if (j == a.size() || a[j] != queries[i])
                j--;
            
            mn = j >= 0 ? a[j] : -1;
            ans.push_back({mn, mx});
        }

        return ans;
    }
};