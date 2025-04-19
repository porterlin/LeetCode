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
    TreeNode* reverseOddLevels(TreeNode* root) {
        deque<int> dq;
        dq.push_back(root->val);
        queue<TreeNode*> q;
        q.push(root);
        int layer = 0;
        while (!q.empty()) {
            if (layer % 2 == 1)
                ranges::reverse(dq);
            for (int n = q.size(); n > 0; n--) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left) {
                    q.push(node->left);
                    dq.push_back(node->left->val);
                }
                if (node->right) {
                    q.push(node->right);
                    dq.push_back(node->right->val);
                }
                node->val = dq.front();
                dq.pop_front();
            }
            layer++;
        }
        return root;
    }
};