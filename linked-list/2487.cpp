/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;
        ListNode* pre = nullptr;
        ListNode* nxt;

        while (cur) {
            nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }

    ListNode* removeNodes(ListNode* head) {
        ListNode* rl = reverseList(head);
        ListNode* cur = rl;
        int maxVal = cur->val;
        while (cur && cur->next) {
            if (cur->next->val < maxVal) {
                cur->next = cur->next->next;
            } else {
                maxVal = max(maxVal, cur->next->val);
                cur = cur->next;
            }
        }
        ListNode* ans = reverseList(rl);
        return ans;
    }
};