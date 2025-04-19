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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int layer = 0;
        TreeNode* node;
        while (!q.empty()) {
            for (int n = q.size(); n > 0; n--) {
                node = q.front();
                q.pop();
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
                
                if (layer % 2 == 0) {
                    if (node->val % 2 == 0) return false;
                    if (n != 1 && node->val >= q.front()->val) return false;
                } else {
                    if (node->val % 2 == 1) return false;
                    if (n != 1 && node->val <= q.front()->val) return false;
                }
            }
            if (layer % 2 == 0 && node->val % 2 == 0) return false;
            if (layer % 2 == 1 && node->val % 2 == 1) return false;
            layer++;
        }
        return true;
    }
};