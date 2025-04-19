/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

// time complexity: O(N)
// space complexity: O(1)
class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr)
            return nullptr;
        Node* cur = root;
        Node dummy;
        Node* nxt = &dummy;
        bool check = false;
        while (!check) {
            while (cur) {
                if (cur->left) {
                    nxt->next = cur->left;
                    nxt = cur->left;
                    check = true;
                }
                if (cur->right) {
                    nxt->next = cur->right;
                    nxt = cur->right;
                    check = true;
                }
                cur = cur->next;
            }

            check = check ? false : true;
            nxt = &dummy;
            cur = nxt->next;
        }
        return root;
    }
};