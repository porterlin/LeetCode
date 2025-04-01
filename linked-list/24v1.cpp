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
    ListNode* swapPairs(ListNode* head) {
        ListNode* cur = head;
        int n = 0;
        while (cur) {
            n++;
            cur = cur->next;
        }

        ListNode dummyNode(0, head);
        ListNode* pre = &dummyNode;
        ListNode* p0 = &dummyNode;
        cur = head;
        ListNode* nxt;
        while (n >= 2) {
            n -= 2;
            for (int i = 0; i < 2; i++) {
                nxt = cur->next;
                cur->next = pre;
                pre = cur;
                cur = nxt;
            }
            p0->next->next = cur;
            p0->next = pre;
            p0 = pre->next;
        }
        return dummyNode.next;
    }
};