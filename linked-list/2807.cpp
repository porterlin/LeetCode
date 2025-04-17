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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* cur = head;
        ListNode* nxt;
        int val;
        while (cur && cur->next) {
            nxt = cur->next;
            val = gcd(cur->val, nxt->val);
            ListNode* buf = new ListNode(val, nxt);
            cur->next = buf;
            cur = nxt;
        }
        return head;
    }
};