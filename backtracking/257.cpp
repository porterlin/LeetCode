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
    vector<string> ans;
    vector<int> path;
    int rootVal;
public:
    void dfs(TreeNode* root) {
        path.push_back(root->val);

        if (root->left == root->right) {
            string buf;
            buf += to_string(path[0]);
            for (int i = 1; i < path.size(); i++) {
                buf += "->";
                buf += to_string(path[i]);
            }
            ans.push_back(buf);
            path.pop_back();
            return;
        }
        
        if (root->left)
            dfs(root->left);
        if (root->right)
            dfs(root->right);

        path.pop_back();
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root);
        return ans;
    }
};