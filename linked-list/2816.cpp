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
    ListNode* doubleIt(ListNode* head) {
        ListNode* rl = reverseList(head);
        ListNode* cur = rl;
        int carry = 0;
        int buf = 0;

        while (cur) {
            buf = cur->val * 2;
            cur->val = buf % 10 + carry;
            carry = buf / 10;
            if (!cur->next)
                break;
            cur = cur->next;
        }
        if (carry > 0) {
            ListNode* newNode = new ListNode(carry);
            cur->next = newNode;
        }
        return reverseList(rl);
    }
};