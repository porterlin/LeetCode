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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* rl1 = reverseList(l1);
        ListNode* rl2 = reverseList(l2);

        ListNode* head = new ListNode(0);
        ListNode* cur = head;
        ListNode* pre;
        int buf;

        while (rl1 || rl2) {
            if (rl1 && rl2)
                cur->val += (rl1->val + rl2->val);
            else if (!rl2)
                cur->val += rl1->val;
            else
                cur->val += rl2->val;

            buf = cur->val / 10;
            cur->val %= 10;

            ListNode* newNode = new ListNode(buf);
            cur->next = newNode;
            pre = cur;
            cur = cur->next;

            if (rl1)
                rl1 = rl1->next;
            if (rl2)
                rl2 = rl2->next;
        }
        if (cur->val == 0)
            pre->next = nullptr;
        return reverseList(head);
    }
};